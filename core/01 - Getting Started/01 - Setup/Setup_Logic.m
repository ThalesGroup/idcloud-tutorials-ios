/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "Setup_Logic.h"
#import "Setup_Config.h"

@implementation Setup_Logic

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

        // OTP module is required for token management and OTP calculation.
        EMOtpConfiguration *otpCFG = [EMOtpConfiguration defaultConfiguration];
                
        // Configure core with given key and set of required modules.
        [EMCore configureWithActivationCode:CFG_ACTIVATION_CODE()
                             configurations:[NSSet setWithObject:otpCFG]];
    }
}

@end
