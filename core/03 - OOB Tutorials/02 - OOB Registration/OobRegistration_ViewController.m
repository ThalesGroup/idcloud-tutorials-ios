/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "OobRegistration_ViewController.h"
#import "OobRegistration_Logic.h"

@implementation OobRegistration_ViewController

// MARK: - ProvisionerViewDelegate

- (void)onProvision:(NSString *)userId withRegistrationCode:(id<EMSecureString>)regCode
{
    // Show registration process.
    [self loadingBarShow:NSLocalizedString(@"STRING_REGISTERING_LOADING", nil) animated:YES];
    
    // Register to OOB first. Only then continue with token.
    [OobRegistration_Logic registerToMsm:userId
                                 regCode:regCode
                       completionHandler:^(BOOL success, NSError *error)
     {
         // Hide registration process.
         [self loadingBarHide:YES];
         
         // OOB registration was succesfull.
         if (success) {
             // Registration code is wiped in super class once it's not needed.
             [super onProvision:userId withRegistrationCode:regCode];
         } else {
             // Wipe code.
             [regCode wipe];
             [self displayMessageDialogError:error];
         }
     }];
}

- (void)onRemoveToken
{
    // Show unregistration process.
    [self loadingBarShow:NSLocalizedString(@"STRING_UNREGISTERING_LOADING", nil) animated:YES];
    
    // First unregister from OOB, then continue with removing token
    [OobRegistration_Logic unregisterFromMsm:^(BOOL success, NSError *error) {
        
        // Hide unregistration process.
        [self loadingBarHide:YES];
        
        if (success) {
            [super onRemoveToken];
        } else {
            [self displayMessageDialogError:error];
        }
    }];
}

@end
