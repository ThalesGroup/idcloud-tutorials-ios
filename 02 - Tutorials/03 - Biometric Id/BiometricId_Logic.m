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
