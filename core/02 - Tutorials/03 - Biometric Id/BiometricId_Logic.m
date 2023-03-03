/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "BiometricId_Logic.h"
#import "Provisioning_Logic.h"

// Review: SNE document private methods
@implementation BiometricId_Logic

+ (TokenStatus)tokenStatus
{
    TokenStatus retValue;
    
    // Check all auth mode states so we can enable / disable proper buttons.
    id<EMOathToken>                     token               = [Provisioning_Logic token];
    EMAuthModule                        *authMoule          = [EMAuthModule authModule];
    EMSystemBioFingerprintAuthService   *touchService       = [EMSystemBioFingerprintAuthService serviceWithModule:authMoule];
    EMSystemFaceAuthService             *faceService        = [EMSystemFaceAuthService serviceWithModule:authMoule];
    
    retValue.isTouchSupported    = token && [touchService isSupported:nil]      && [touchService isConfigured:nil];
    retValue.isFaceSupported     = token && [faceService isSupported:nil]       && [faceService isConfigured:nil];
    retValue.isTouchEnabled      = retValue.isTouchSupported     ? [token isAuthModeActive:[touchService authMode]]   : NO;
    retValue.isFaceEnabled       = retValue.isFaceSupported      ? [token isAuthModeActive:[faceService authMode]]    : NO;

    return retValue;
}

+ (void)userTouchId:(id<EMOathToken>)token completionHandler:(AuthInputHandler)completionHandler
{
    EMSystemBioFingerprintAuthService   *service    = [EMSystemBioFingerprintAuthService serviceWithModule:[EMAuthModule authModule]];
    EMSystemBioFingerprintContainer     *container  = [EMSystemBioFingerprintContainer containerWithBioFingerprintAuthService:service];
    
    // Trigger system authentication
    [container authenticateUser:token
                    withMessage:NSLocalizedString(@"STRING_BIOMETRIC_TOUCH_ID_DESC", nil)
                  fallbackTitle:nil
              completionHandler:^(id<EMSystemBioFingerprintAuthInput> bioFpAuthInput, NSData *evaluatedPolicyDomainState, NSError *error)
     {
         // Call in UI thread.
         dispatch_async(dispatch_get_main_queue(), ^{
             completionHandler(bioFpAuthInput, error);
         });
     }];
}

+ (void)userFaceId:(id<EMOathToken>)token completionHandler:(AuthInputHandler)completionHandler
{
    EMSystemFaceAuthService     *service    = [EMSystemFaceAuthService serviceWithModule:[EMAuthModule authModule]];
    EMSystemFaceAuthContainer   *container  = [EMSystemFaceAuthContainer containerWithNativeFaceAuthService:service];
    
    // Trigger system authentication
    [container authenticateUser:token
                    withMessage:NSLocalizedString(@"STRING_BIOMETRIC_FACE_ID_DESC", nil)
                  fallbackTitle:nil
              completionHandler:^(id<EMSystemFaceAuthInput> faceAuthInput, NSData *evaluatedPolicyDomainState, NSError *error)
     {
         // Call in UI thread.
         dispatch_async(dispatch_get_main_queue(), ^{
             completionHandler(faceAuthInput, error);
         });
     }];
}

@end
