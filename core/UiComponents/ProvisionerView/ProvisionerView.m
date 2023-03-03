/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "ProvisionerView.h"

@implementation UIButtonAutoSize

- (CGSize)intrinsicContentSize
{
    return self.isHidden ? CGSizeZero : [super intrinsicContentSize];
}

@end

@interface ProvisionerView() <UITextFieldDelegate>

@property (weak, nonatomic) IBOutlet UITextField    *textUserId;
@property (weak, nonatomic) IBOutlet UITextField    *textRegistrationCode;

@property (weak, nonatomic) IBOutlet UIButton       *buttonProvision;
@property (weak, nonatomic) IBOutlet UIButton       *buttonProvisionUsingQr;
@property (weak, nonatomic) IBOutlet UIButton       *buttonRemoveToken;

@end

@implementation ProvisionerView

// MARK: - Life Cycle

- (instancetype)initWithCoder:(NSCoder *)decoder
{
    if (self = [super initWithCoder:decoder]) {
        [self setupWithFrame:self.bounds];
    }
    
    return self;
}

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        [self setupWithFrame:frame];
    }
    
    return self;
}

- (void)setupWithFrame:(CGRect)frame
{
    // Color is used as placeholder in case of disabled IB_DESIGNABLE
    self.backgroundColor = [UIColor clearColor];
    
    // Get our view from storyboard.
    UIView *contentView = [[[NSBundle bundleForClass:self.class] loadNibNamed:NSStringFromClass(self.class) owner:self options:nil] firstObject];
    contentView.frame = frame;
    
    // Add it as child of current View.
    [self addSubview:contentView];
    
    // Used to handle return key.
    [_textUserId            setDelegate:self];
    [_textRegistrationCode  setDelegate:self];
    
    // QR Code button is by default hidden.
    [_buttonProvisionUsingQr setHidden:YES];
}

// MARK: - Public API

- (void)updateGUI:(BOOL)enabled token:(id<EMOathToken>)token;
{
    [_textUserId                setEnabled:enabled && !token];
    [_textRegistrationCode      setEnabled:enabled && !token];
    [_buttonProvision           setEnabled:enabled && !token];
    [_buttonProvisionUsingQr    setEnabled:enabled && !token];
    [_buttonRemoveToken         setEnabled:enabled && token];
    
    // Update token name
    [_textUserId setText:token ? token.name : @""];
    if (token) {
        [_textRegistrationCode setSecureTextEntry:NO];
        [_textRegistrationCode setText:@"--"];
    } else {
        [_textRegistrationCode setSecureTextEntry:YES];
        [_textRegistrationCode setText:@""];
    }
}

- (void)setQrCodeButtonVisible
{
    [_buttonProvisionUsingQr setHidden:NO];
}

// MARK: - UITextFieldDelegate

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    // Hide current keyboard.
    [textField resignFirstResponder];
    
    // Jump to next one.
    if ([textField isEqual:_textUserId]) {
        [_textRegistrationCode becomeFirstResponder];
    }
    
    // All actions are allowed
    return YES;
}

// MARK: - User Interface

- (IBAction)onButtonPressedProvision:(UIButton *)sender
{
    // Check user input.
    if (!_textUserId.text.length) {
        [_delegate displayMessageDialog:NSLocalizedString(@"STRING_PROVISION_MISSING_USER_ID", nil)];
        return;
    } else if (!_textRegistrationCode.text.length) {
        [_delegate displayMessageDialog:NSLocalizedString(@"STRING_PROVISION_MISSING_REG_CODE", nil)];
        return;
    }
    
    // Secure data should be handled in secure containers and wiped once they are not needed.
    id<EMSecureString> regCode = [[[EMCore sharedInstance] secureContainerFactory] secureStringFromString:_textRegistrationCode.text];
    
    // Notify controller.
    [_delegate onProvision:_textUserId.text withRegistrationCode:regCode];
}
- (IBAction)onButtonPressedRemoveToken:(UIButton *)sender
{
    [_delegate displayOnCancelDialog:NSLocalizedString(@"STRING_PROVISION_REMOVE_TOKEN_MSG", nil) completionHandler:^(BOOL result) {
        if (result) {
            [self.delegate onRemoveToken];
        }
    }];
}

- (IBAction)onButtonPressedProvisionUsingQr:(UIButton *)sender
{
    [_delegate onProvisionUsingQr];
}

@end
