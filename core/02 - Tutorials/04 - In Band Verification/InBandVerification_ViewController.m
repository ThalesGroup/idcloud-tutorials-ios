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
