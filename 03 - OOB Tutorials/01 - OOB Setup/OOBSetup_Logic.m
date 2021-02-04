//  MIT License
//
//  Copyright (c) 2020 Thales DIS
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

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
