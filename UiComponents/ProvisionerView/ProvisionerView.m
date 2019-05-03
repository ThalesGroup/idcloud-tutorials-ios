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

#import "ProvisionerView.h"

@interface ProvisionerView() <UITextFieldDelegate>

@property (weak, nonatomic) IBOutlet UITextField    *textUserId;
@property (weak, nonatomic) IBOutlet UITextField    *textRegistrationCode;
@property (weak, nonatomic) IBOutlet UIButton       *buttonProvision;
@property (weak, nonatomic) IBOutlet UIButton       *buttonRemoveToken;

@end

@implementation ProvisionerView

// MARK: - Life Cycle

- (nullable instancetype)initWithCoder:(NSCoder *)decoder
{
    if (self = [super initWithCoder:decoder])
    {
        [self setupWithFrame:self.bounds];
    }
    
    return self;
}

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame])
    {
        [self setupWithFrame:frame];
    }
    
    return self;
}

- (void)setupWithFrame:(CGRect)frame
{
    // Color is used as placeholder in case of disabled IB_DESIGNABLE
    self.backgroundColor = [UIColor clearColor];
    
    // Get our view from storyboard.
    UIView *contentView = [[[NSBundle bundleForClass:self.class] loadNibNamed:@"ProvisionerView" owner:self options:nil] firstObject];
    contentView.frame = frame;
    
    // Add it as child of current View.
    [self addSubview:contentView];
    
    // Used to handle return key.
    [_textUserId            setDelegate:self];
    [_textRegistrationCode  setDelegate:self];
}

// MARK: - Public API

- (void)updateGUI:(BOOL)enabled token:(id<EMOathToken>)token;
{
    [_textUserId            setEnabled:enabled && !token];
    [_textRegistrationCode  setEnabled:enabled && !token];
    [_buttonProvision       setEnabled:enabled && !token];
    [_buttonRemoveToken     setEnabled:enabled && token];
    
    // Update token name
    [_textUserId setText:token ? token.name : @""];
    [_textRegistrationCode setText:@""];
}

// MARK: - UITextFieldDelegate

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    // Hide current keyboard.
    [textField resignFirstResponder];
    
    // Jump to next one.
    if ([textField isEqual:_textUserId])
        [_textRegistrationCode becomeFirstResponder];
    
    // All actions are allowed
    return YES;
}

// MARK: - User Interface

- (IBAction)onButtonPressedProvision:(UIButton *)sender
{
    // Check user input.
    if (!_textUserId.text.length) {
        [_delegate onDisplayMessage:NSLocalizedString(@"STRING_PROVISION_MISSING_USER_ID", nil)];
        return;
    } else if (!_textRegistrationCode.text.length) {
        [_delegate onDisplayMessage:NSLocalizedString(@"STRING_PROVISION_MISSING_REG_CODE", nil)];
        return;
    }
    
    // Secure data should be handled in secure containers and wiped once they are not needed.
    id<EMSecureString> regCode = [[[EMCore sharedInstance] secureContainerFactory] secureStringFromString:_textRegistrationCode.text];
    
    // Notify controller.
    [_delegate onProvision:_textUserId.text withRegistrationCode:regCode];
    
    // Wipe sensitive data.
    [regCode wipe];
}
- (IBAction)onButtonPressedRemoveToken:(UIButton *)sender
{
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:NSLocalizedString(@"STRING_PROVISION_REMOVE_TOKEN", nil)
                                                                   message:NSLocalizedString(@"STRING_PROVISION_REMOVE_TOKEN_MSG", nil)
                                                            preferredStyle:UIAlertControllerStyleAlert];
        
    [alert addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"STRING_OK", nil) style:UIAlertActionStyleDestructive handler:^(UIAlertAction * _Nonnull action) {
        [self.delegate onRemoveToken];
    }]];
    [alert addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"STRING_CANCEL", nil) style:UIAlertActionStyleCancel handler:nil]];
    
    [_delegate presentViewController:alert animated:true completion:^{}];
    
}

@end
