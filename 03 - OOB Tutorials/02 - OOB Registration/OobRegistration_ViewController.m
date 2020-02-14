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
