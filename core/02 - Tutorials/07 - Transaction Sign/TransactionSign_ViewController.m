/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "TransactionSign_ViewController.h"
#import "Provisioning_Logic.h"
#import "TransactionSign_Logic.h"

@interface TransactionSign_ViewController() <UITextFieldDelegate>

@property (weak, nonatomic) IBOutlet UITextField *textAmount;
@property (weak, nonatomic) IBOutlet UITextField *textBeneficiary;

@end

// Review: SNE document private methods
@implementation TransactionSign_ViewController

// MARK: - Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Used to handle return key.
    [_textAmount        setDelegate:self];
    [_textBeneficiary   setDelegate:self];
}

// MARK: - Shared

- (void)generateAndDisplaySignatureOtp:(id<EMOathToken>)token
                             authInput:(id<EMAuthInput>)authInput
                                amount:(NSString *)amount
                           beneficiary:(NSString *)beneficiary
{
    // Calculate OTP for given pin and display result.
    NSError     *internalErr    = nil;
    OTP_Value   *otpValue       = [TransactionSign_Logic generateOtp:token
                                                       withAuthInput:authInput
                                                              amount:amount
                                                         beneficiary:beneficiary
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

// MARK: - UITextFieldDelegate

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    // Hide current keyboard.
    [textField resignFirstResponder];
    
    // Jump to next one.
    if ([textField isEqual:_textAmount]) {
        [_textBeneficiary becomeFirstResponder];
    }
    
    // All actions are allowed
    return YES;
}

// MARK: - User interface

- (IBAction)onButtonPressedGenerateSignatureOtp:(UIButton *)sender
{
    [self userPinWithCompletionHandler:^(id<EMPinAuthInput> pin) {
        [self generateAndDisplaySignatureOtp:[Provisioning_Logic token]
                                   authInput:pin
                                      amount:self.textAmount.text
                                 beneficiary:self.textBeneficiary.text];
    }];
}


@end
