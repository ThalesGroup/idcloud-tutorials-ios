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

#import "OTP_ViewController.h"
#import "Provisioning_Logic.h"
#import "OTP_Logic.h"
#import "Setup_Config.h"

@interface OTP_ViewController()

/**
 All sample applications using OTP Result View ui should set this property so it can be handled automatically.
 */
@property (weak, nonatomic) IBOutlet ResultView *resultView;

@property (weak, nonatomic) IBOutlet UIButton   *buttonOTP;

@end

@implementation OTP_ViewController

// MARK: - Override

- (id<EMOathToken>)updateGUI
{
    // All token related error is solved in previous chapter.
    id<EMOathToken> token = [super updateGUI];
    
    // To make demo simple we will just disable / enable UI.
    [_buttonOTP setEnabled:![self loadingBarIsPresent] && token];
    
    // Hide OTP Result related value if user remove token.
    if (!token) {
        [_resultView hide];
    }
    
    return token;
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    // Hide current OTP Result related value.
    [_resultView hide];
}

// MARK: - Public API

- (void)displayMessageResult:(NSString *)message lifespan:(Lifespan)lifespan
{
    [_resultView show:message lifespan:lifespan];
}

- (void)generateAndDisplayOtp:(id<EMOathToken>)token authInput:(id<EMAuthInput>)authInput
{
    // Calculate OTP for given pin and display result.
    NSError     *internalErr    = nil;
    OTP_Value   *otpValue       = [OTP_Logic generateOtp:token
                                           withAuthInput:authInput
                                                   error:&internalErr];
    
    if (internalErr) {
        [self displayMessageDialogError:internalErr];
    } else {
        [self displayMessageResult:otpValue.otp.stringValue lifespan:otpValue.lifespan];
    }
    
    // All secure containers should be wiped asap.
    [authInput wipe];
    [otpValue wipe];
}

- (void)generateAndDisplayOtp_PinInput
{    
    // Display pin input dialog.
    [self userPinWithCompletionHandler:^(id<EMPinAuthInput> pin) {
        [self generateAndDisplayOtp:[Provisioning_Logic token] authInput:pin];
    }];
    
}

- (void)userPinWithCompletionHandler:(AuthPinHandler)completionHandler
{
    if (CFG_ACTIVATION_CODE()) {
        [self userPinSecureKeypad:completionHandler];
    } else {
        [self userPinFromPlainInput:completionHandler];
    }
    
    
}

- (void)userPinFromPlainInput:(AuthPinHandler)completionHandler {
    UIAlertController * alertController = [UIAlertController alertControllerWithTitle: @"Pin"
                                                                              message: @"Input pin for OTP calculation"
                                                                       preferredStyle:UIAlertControllerStyleAlert];
    [alertController addTextFieldWithConfigurationHandler:^(UITextField *textField) {
        textField.placeholder = @"pin";
        textField.textColor = [UIColor blueColor];
        textField.keyboardType = UIKeyboardTypeNumberPad;
        textField.clearButtonMode = UITextFieldViewModeWhileEditing;
        textField.borderStyle = UITextBorderStyleRoundedRect;
    }];
    [alertController addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
        UITextField *pinField = alertController.textFields.firstObject;
        if (!pinField.text.length) {
            [self displayMessageDialog:@"Pin entry can't be empty"];
            return;
        }
        
        NSError *error;
        EMPinAuthService *service = [EMPinAuthService serviceWithModule:[EMAuthModule authModule]];
        id<EMPinAuthInput> pin = [service createAuthInputWithString:pinField.text error:&error];
        if (pin && !error) {
            completionHandler(pin);
        } else {
            [self displayMessageDialogError:error];
        }
    }]];
    [alertController addAction:[UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:nil]];
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)userPinSecureKeypad:(AuthPinHandler)completionHandler {
    // Get secure keypad builder.
    id<EMSecureInputBuilder> builder = [[EMSecureInputService serviceWithModule:[EMUIModule uiModule]] secureInputBuilder];
    
    // Configure secure keypad behaviour and visual.
    [builder showNavigationBar:YES];
    
    // Build keypad and add handler.
    id<EMSecureInputUi> secureInput =
    [builder buildWithScrambling:NO
              isDoubleInputField:NO
                     displayMode:EMSecureInputUiDisplayModeFullScreen
                   onFinishBlock:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin)
     {
         // Wipe pinpad builder for security purpose.
         // This part is also important because of builder life cycle, otherwise this block will never be triggered!
         [builder wipe];
         
         // Dismiss the keypad and delete the secure input UI.
         [self.navigationController popViewControllerAnimated:YES];
         
         // Notify handler.
         completionHandler(firstPin);
     }];
    
    // Push in secure input UI view controller to the current view controller
    [self.navigationController pushViewController:secureInput.viewController animated:YES];
}


// MARK: - User interface

- (IBAction)onButtonPressedGenerateOTP:(UIButton *)sender
{
    [self generateAndDisplayOtp_PinInput];
}

@end
