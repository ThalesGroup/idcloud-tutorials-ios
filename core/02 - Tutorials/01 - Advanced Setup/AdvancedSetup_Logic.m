/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "AdvancedSetup_Logic.h"
#import "AdvancedSetup_Config.h"
#import "Setup_Config.h"

// Muttable string it's not compile-time constant. It will be created on first use.
static NSMutableString      *sLog           = nil;

// Notifications id's for notification center.
NSString * const C_NOTIFICATION_ID_LOG_STATE_CHANGED    = @"NotificationIdLogStateChanged";

// Review: SNE Document private methods
@implementation AdvancedSetup_Logic

// MARK: - Mobile Protector SDK setup

+ (void)setup
{
    // Make sure, that we will always check isConfigured first. Multiple call of init will cause crash / run time exception.
    if (![EMCore isConfigured]) {
        // Configure core with secure log.
        SecureLogConfig *secureLogConfig = [[SecureLogConfig alloc] initWithConfigComponentsBuilder:^(SecureLogConfigComponents * _Nonnull components) {
            components.publicKeyExponent = CFG_SECURE_LOG_RSA_KEY_EXPONENT();
            components.publicKeyModulus = CFG_SECURE_LOG_RSA_KEY_MODULUS();
        }];
        [EMCore configureSecureLog:secureLogConfig];

        NSError *error = nil;
        // Configure core with given key and set of required modules.
        EMCore *core = [EMCore configureWithActivationCode:CFG_ACTIVATION_CODE()
                                            configurations:[AdvancedSetup_Logic moduleConfigurations]];
        
        // Login so we can use secure storage, OOB etc..
        [core.passwordManager login:&error];
        
        // This should not happen. Usually it means, that someone try to login with different password than last time.
        [AdvancedSetup_Logic logError:error];
        assert(!error);
    }
}

+ (NSSet *)moduleConfigurations
{
    // OTP module is required for token management and OTP calculation.
    EMOtpConfiguration  *otpCFG = [EMOtpConfiguration configurationWithJailbreakPolicy:CFG_JAILBREAK_POLICY_OTP()];
    
    // Mobile Signing Protocol QR parsing, push messages etc..
    EMMspConfiguration *mspCFG = [EMMspConfiguration configurationWithObfuscationKeys:nil signatureKeys:nil];
    
    // Return all configurations.
    return [NSSet setWithObjects:otpCFG, mspCFG, nil];
}

// MARK: - Log

+ (NSString *)log
{
    return sLog ? [sLog copy] : @"";
}

+ (void)logMessage:(NSString *)log
{
    if (!sLog) {
        sLog = [NSMutableString stringWithString:log];
    } else {
        [sLog appendFormat:@"\n%@", log];
    }
    
    [[NSNotificationCenter defaultCenter] postNotificationName:C_NOTIFICATION_ID_LOG_STATE_CHANGED object:nil];
}

+ (void)logError:(NSError *)error
{
    if (error) {
        [AdvancedSetup_Logic logMessage:error.localizedDescription];
    }
}


@end
