/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "InBandVerification_ViewController.h"
#import "InBandVerification_Logic.h"
#import "Provisioning_Logic.h"

@interface InBandVerification_ViewController ()

@property (weak, nonatomic) IBOutlet UIButton   *buttonAuthenticate;

@end

@implementation InBandVerification_ViewController

// MARK: - Override

- (id<EMOathToken>)updateGUI
{
    // All token related error is solved in previous chapter.
    id<EMOathToken> token = [super updateGUI];
    
    // To make demo simple we will just disable / enable UI.
    [_buttonAuthenticate setEnabled:![self loadingBarIsPresent] && token];
    
    return token;
}

// MARK: - User interface

- (IBAction)onButtonPressedAuthenticate:(UIButton *)sender
{
    // Display pin input dialog.
    [self userPinWithCompletionHandler:^(id<EMPinAuthInput> pin) {
        // Lock UI and display progress bar.
        [self loadingBarShow:NSLocalizedString(@"STRING_AUTHENTICATION_LOADING", nil) animated:YES];
        // Call async method to verify auth input.
        [InBandVerification_Logic verifyWithToken:[Provisioning_Logic token]
                                        authInput:pin
                                completionHandler:^(BOOL success, NSString *result, Lifespan lifespan)
         {
             // Wipe auth input.
             [pin wipe];
             // Unlock UI and hide progress bar.
             [self loadingBarHide:YES];
             // Update result view with last otp lifespan.
             [self displayMessageResult:result lifespan:lifespan];
         }];
    }];
}
@end
