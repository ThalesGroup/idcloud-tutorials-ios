/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "ChangePin_ViewController.h"
#import "InBandVerification_Logic.h"
#import "Provisioning_Logic.h"
#import "ChangePin_Logic.h"

@interface ChangePin_ViewController ()

@property (weak, nonatomic) IBOutlet UIButton   *buttonChangePin;

@end

// Review: SNE document private methods
@implementation ChangePin_ViewController

// MARK: - Override

- (id<EMOathToken>)updateGUI
{
    // All token related error is solved in previous chapter.
    id<EMOathToken> token = [super updateGUI];
    
    // To make demo simple we will just disable / enable UI.
    [_buttonChangePin setEnabled:![self loadingBarIsPresent] && token];
    
    return token;
}

// MARK: - Public API

- (void)userPinInputsWithCompletionHandler:(EMSecureInputUiOnFinish)completionHandler
{
    // Get secure keypad builder.
    id<EMSecureInputBuilder> builder = [[EMSecureInputService serviceWithModule:[EMUIModule uiModule]] secureInputBuilder];
    
    // Configure secure keypad behaviour and visual.
    [builder showNavigationBar:YES];
    
    // Build keypad and add handler.
    id<EMSecureInputUi> secureInput =
    [builder buildWithScrambling:NO
              isDoubleInputField:YES
                     displayMode:EMSecureInputUiDisplayModeFullScreen
                   onFinishBlock:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin)
     {
         // Wipe pinpad builder for security purpose.
         // This part is also important because of builder life cycle, otherwise this block will never be triggered!
         [builder wipe];
         
         // Dismiss the keypad and delete the secure input UI.
         [self.navigationController popViewControllerAnimated:YES];
         
         // Notify handler.
         completionHandler(firstPin, secondPin);
     }];
    
    // Push in secure input UI view controller to the current view controller
    [self.navigationController pushViewController:secureInput.viewController animated:YES];
}

// MARK: - Private helpers

- (void)changePin_VerifyOldPin
{
    // Get the original PIN value from user
    [self userPinWithCompletionHandler:^(id<EMPinAuthInput> pin) {
        // Lock UI and display progress bar.
        [self loadingBarShow:NSLocalizedString(@"STRING_AUTHENTICATION_LOADING", nil) animated:YES];
        
        // Verify old pin validity first. Incorrect entry will invalidate token.
        [InBandVerification_Logic verifyWithToken:[Provisioning_Logic token]
                                        authInput:pin
                                completionHandler:^(BOOL success, NSString *result, Lifespan lifespan)
         {
             // Unlock UI and hide progress bar.
             [self loadingBarHide:YES];
             
             // Continue with change pin on successful verification.
             if (success) {
                 [self changePin_GetAndVerifyNewPin:pin lifespan:lifespan];
             } else {
                 [pin wipe];
                 
                 // Update result view with last otp lifespan.
                 [self displayMessageResult:result lifespan:lifespan];
             }
         }];
    }];
}

- (void)changePin_GetAndVerifyNewPin:(id<EMPinAuthInput>)oldPin lifespan:(Lifespan)lifespan
{
    // Display pin input dialog.
    [self userPinInputsWithCompletionHandler:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin) {
        [self displayMessageResult:[ChangePin_Logic changePin:[Provisioning_Logic token]
                                                       oldPin:oldPin
                                                       newPin:firstPin
                                                newPinConfirm:secondPin] lifespan:lifespan];
    }];
}


// MARK: - User interface

- (IBAction)onButtonPressedChangePin:(UIButton *)sender
{
    [self changePin_VerifyOldPin];
}

@end
