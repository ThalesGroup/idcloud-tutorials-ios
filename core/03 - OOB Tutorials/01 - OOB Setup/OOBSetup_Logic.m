/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "OOBSetup_Logic.h"
#import "OOBSetup_Config.h"
#import "Setup_Config.h"
#import "AdvancedSetup_Config.h"
#import "AdvancedSetup_Logic.h"

// Review: SNE document private methods
@implementation OOBSetup_Logic

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
                                            configurations:[OOBSetup_Logic moduleConfigurations]];
        
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
    
    // OOB module is required for push notifications.
    EMOobConfiguration  *oobCFG = [EMOobConfiguration configurationWithOptionalParameters:^(EMOobConfigurationBuilder *configurationBuilder) {
        // Jailbreak policy for OOB module. See EMOobJailbreakPolicyIgnore for more details.
        [configurationBuilder setJailbreakPolicy:CFG_JAILBREAK_POLICY_OOB()];
        // Device fingerprint is used for security reason. This way app can add some additional input for internal encryption mechanism.
        // This value must remain the same all the time. Othewise all provisioned tokens will not be valid any more.
        [configurationBuilder setDeviceFingerprintSource:CFG_DEVICE_FINGERPRINT_SOURCE()];
        // For debug and ONLY debug reasons we might lower some TLS configuration.
        [configurationBuilder setTlsConfiguration:CFG_TLS_CONFIGURATION()];
    }];
    
    // Mobile Signing Protocol QR parsing, push messages etc..
    EMMspConfiguration *mspCFG = [EMMspConfiguration configurationWithObfuscationKeys:nil signatureKeys:nil];
    
    // Return all configurations.
    return [NSSet setWithObjects:otpCFG, oobCFG, mspCFG, nil];
}

@end
