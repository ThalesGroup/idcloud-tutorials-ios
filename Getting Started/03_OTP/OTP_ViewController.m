//  MIT License
//
//  Copyright (c) 2019 Thales DIS
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

// IMPORTANT: This source code is intended to serve training information purposes only. Please make sure to review our IdCloud documentation, including security guidelines.

#import "OTP_ViewController.h"
#import "Provisioning_Logic.h"
#import "OTP_Logic.h"

@interface OTP_ViewController()

@property (weak, nonatomic) IBOutlet UIButton *buttonOTP;
@property (weak, nonatomic) IBOutlet UILabel *labelOTP;

@end

@implementation OTP_ViewController

// MARK: Override

- (id<EMOathToken>)updateGUI
{
    // All token related error is solved in previous chapter.
    id<EMOathToken> token = [super updateGUI];
    
    // To make demo simple we will just disable / enable UI.
    [_buttonOTP setEnabled:!self.isProvisioningInProgress && token];
    
    // Hide OTP if user remove token.
    if (!token)
        _labelOTP.hidden = YES;
    
    return token;
}

// MARK: - User interface

- (IBAction)onButtonPressedGenerateOTP:(UIButton *)sender
{
    NSError *internalErr = nil;
    id<EMOathToken> token = [Provisioning_Logic token:&internalErr];
    
    // Notify UI about possible issues.
    if (internalErr)
    {
        [self displayErrorIfPresent:internalErr];
        return;
    }
    
    // Display pin input dialog.
    [OTP_Logic getUserPin:self.navigationController completionHandler:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin) {
        if (firstPin)
        {
            // Calculate OTP for given pin and display result.
            NSError *internalErr = nil;
            id<EMSecureString> otp = [OTP_Logic generateOtp:token withAuthInput:firstPin error:&internalErr];
            if (internalErr)
                [self displayErrorIfPresent:internalErr];
            else
            {
                self.labelOTP.hidden = NO;
                self.labelOTP.text = otp.stringValue;
            }
            
            // All secure containers should be wiped asap.
            [firstPin wipe];
            [otp wipe];
        }
    }];
}

@end
