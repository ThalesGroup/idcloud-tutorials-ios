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

#import "AdvancedSetup_Logic.h"
#import "AdvancedSetup_Config.h"
#import "Setup_Config.h"

// Default face id state is undefined. It will be updated after calling setup in updateProtectorFaceIdStatus method.
static ProtectorFaceIdState sFaceIdState    = ProtectorFaceIdStateUndefined;
// Muttable string it's not compile-time constant. It will be created on first use.
static NSMutableString      *sLog           = nil;

// Notifications id's for notification center.
NSString * const C_NOTIFICATION_ID_FACE_STATE_CHANGED   = @"NotificationIdFaceStateChanged";
NSString * const C_NOTIFICATION_ID_LOG_STATE_CHANGED    = @"NotificationIdLogStateChanged";

// Review: SNE Document private methods
@implementation AdvancedSetup_Logic

// MARK: - Mobile Protector SDK setup

+ (void)setup
{
    // Make sure, that we will always check isConfigured first. Multiple call of init will cause crash / run time exception.
    if (![EMCore isConfigured]) {
        NSError *error = nil;
        EMCore *core = [EMCore configureWithActivationCode:CFG_ACTIVATION_CODE()
                                            configurations:[AdvancedSetup_Logic moduleConfigurations]];
        
        // Login so we can use secure storage, OOB etc..
        [core.passwordManager login:&error];
        
        // This should not happen. Usually it means, that someone try to login with different password than last time.
        [AdvancedSetup_Logic logError:error];
        assert(!error);
        
        // This will also register and activate license.
        [self updateProtectorFaceIdStatus];
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

// MARK: - Protector Face Id

+ (ProtectorFaceIdState)state
{
    return sFaceIdState;
}

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

#if USE_FACE_ID

+ (void)updateProtectorFaceIdStatus
{
    // Get protector face id service instance.
    EMFaceAuthService *faceIdService = [[EMFaceManager sharedInstance] service];
    
    // FaceId fallback. Future-proof method to identify upcoming devices face id capability.
    [EMSystemFaceAuthService setIsSupportedFallback:^BOOL(NSString *machineID) {
        return [machineID isEqualToString:@"iPhone11,3"] || [machineID isEqualToString:@"iPhone11,6"];
    }];
    
    // Initial service state as no operation was done yet.
    sFaceIdState = ProtectorFaceIdStateUndefined;
    
    // Ensure, that device can support protector face id feature.
    NSError *error = nil;
    if (![faceIdService isSupported:&error]) {
        [AdvancedSetup_Logic setFaceIdState:ProtectorFaceIdStateNotSupported];
        [AdvancedSetup_Logic logError:error];
        return;
    }
    
    // Allow app run without protector face id functionality.
    if (!CFG_FACE_ID_PRODUCT_KEY() || !CFG_FACE_ID_PRODUCT_KEY().length ||
        !CFG_FACE_ID_SERVER_URL() || !CFG_FACE_ID_SERVER_URL().length) {
        [AdvancedSetup_Logic setFaceIdState:ProtectorFaceIdStateUnlicensed];
        return;
    }
    
    // Register license. Based on current license state this call might require internet connection.
    [faceIdService configureLicense:^(EMFaceAuthLicenseBuilder *builder) {
        builder.productKey  = CFG_FACE_ID_PRODUCT_KEY();
        builder.serverUrl   = CFG_FACE_ID_SERVER_URL();
    } completion:^(BOOL success, NSError *error) {
        
        // Print out reason and exit.
        if (!success) {
            [AdvancedSetup_Logic setFaceIdState:ProtectorFaceIdStateUnlicensed];
            [AdvancedSetup_Logic logError:error];
            return;
        }
        sFaceIdState = ProtectorFaceIdStateLicensed;
        
        // After licensing it's time to initialise protector module.
        if ([faceIdService isInitialized]) {
            // Module is loaded. Check user face enrollment.
            [self updateProtectorFaceIdStatusConfigured:faceIdService];
        } else {
            // Initialise protector face id module.
            [[EMFaceManager sharedInstance] initialize:^(BOOL success, NSError *error) {
                if (success) {
                    // Module is loaded. Check user face enrollment.
                    [self updateProtectorFaceIdStatusConfigured:faceIdService];
                } else {
                    // Initialisation was unsuccessful. Log reason.
                    [AdvancedSetup_Logic setFaceIdState:ProtectorFaceIdStateInitFailed];
                    [AdvancedSetup_Logic logError:error];
                }
            }];
        }
    }];
}

+ (void)updateProtectorFaceIdStatusConfigured:(EMFaceAuthService *)authService
{
    NSError *error = nil;
    if ([authService isConfigured:&error]) {
        // User face is enrolled.
        [AdvancedSetup_Logic setFaceIdState:ProtectorFaceIdStateReadyToUse];
    } else {
        // User face is not yet enrolled.
        [AdvancedSetup_Logic setFaceIdState:ProtectorFaceIdStateInited];
    }
    
    // Notify about possible error.
    [AdvancedSetup_Logic logError:error];
}

// Helper method to set protector face id state and notify UI about it change.
+ (void)setFaceIdState:(ProtectorFaceIdState)state
{
    // Update face id state
    sFaceIdState = state;
    [[NSNotificationCenter defaultCenter] postNotificationName:C_NOTIFICATION_ID_FACE_STATE_CHANGED object:nil];

    // Log information
    NSString *log = [NSString stringWithFormat:NSLocalizedString(@"STRING_PROTECTOR_FACE_ID_STATE_CHANGED", nil), ProtectorFaceIdState_ToString(state)];
    [AdvancedSetup_Logic logMessage:log];
}

#else

+ (void)updateProtectorFaceIdStatus
{
    // Face id is disabled in build it self.
    [AdvancedSetup_Logic logMessage:NSLocalizedString(@"STRING_PROTECTOR_FACE_ID_STATE_DISABLED", nil)];
}

#endif


@end
