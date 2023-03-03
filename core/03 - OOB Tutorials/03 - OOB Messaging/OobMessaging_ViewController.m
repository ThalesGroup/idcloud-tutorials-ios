/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "OobMessaging_ViewController.h"
#import "OobMessaging_Logic.h"
#import "Provisioning_Logic.h"

@interface OobMessaging_ViewController()

@property (weak, nonatomic) IBOutlet UIButton *buttonFetchMessages;

@end

// Review: SNE document private methods
@implementation OobMessaging_ViewController

// MARK: - Life Cycle

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    [OobMessaging_Logic setCurrenOobListener:self];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
    [OobMessaging_Logic setCurrenOobListener:nil];
}

// MARK: - Override

- (id<EMOathToken>)updateGUI
{
    // All token related error is solved in previous chapter.
    id<EMOathToken> token = [super updateGUI];
    
    // To make demo simple we will just disable / enable UI.
    [_buttonFetchMessages setEnabled:![self loadingBarIsPresent] && token];
    
    return token;
}


// MARK: - OobMessageListener

- (void)onOobLoadingShow:(NSString *)caption
{
    [self loadingBarShow:caption animated:YES];
}

- (void)onOobLoadingHide
{
    [self loadingBarHide:YES];
}

- (void)onOobDisplayMessage:(NSString *)message
{
    [self displayMessageDialog:message];
}

- (void)onOobApproveMessage:(NSString *)message
        withServerChallenge:(id<EMSecureString>)serverChallenge
          completionHandler:(void (^)(OTP_Value *otp))handler
{
    // Prepare simple dialog with two actions.
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:NSLocalizedString(@"STRING_PUSH_APPROVE_QUESTION", nil)
                                                                   message:message
                                                            preferredStyle:UIAlertControllerStyleAlert];
    
    // First is for approving. In that case we need to calculate OTP.
    [alert addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"STRING_PUSH_APPROVE_QUESTION_APPROVE", nil)
                                              style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                                                  [self approveMessage:serverChallenge completionHandler:handler];
                                              }]];
    
    // Second is deny action. For such message we don't need to calculate OTP.
    [alert addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"STRING_PUSH_APPROVE_QUESTION_DENY", nil)
                                              style:UIAlertActionStyleDestructive handler:^(UIAlertAction * _Nonnull action) {
                                                  handler(nil);
                                              }]];
    
    // Display messagebox and lock thread to wait for response.
    [self presentViewController:alert animated:YES completion:nil];
}

// MARK: - User Interface

- (IBAction)onButtonPressedFetchMessages:(UIButton *)sender
{
    // Any incoming messages are handled through OobMessageListener as normal push notification.
    [OobMessaging_Logic fetchMessages];
}

// MARK: - Private Helpers

- (void)approveMessage:(id<EMSecureString>)serverChallenge
     completionHandler:(void (^)(OTP_Value *otp))handler
{
    // Get pin from user.
    [self userPinWithCompletionHandler:^(id<EMPinAuthInput> pin) {
        NSError     *internalErr    = nil;
        OTP_Value   *otpValue       = nil;
        
        // Server challenge is used for ocra calculation during transaction sign.
        // Without challenge it's authentication request.
        if (serverChallenge) {
            otpValue = [OobMessaging_Logic generateOtp:[Provisioning_Logic token]
                                         withAuthInput:pin
                                       serverChallenge:serverChallenge
                                                 error:&internalErr];
        } else {
            otpValue = [OTP_Logic generateOtp:[Provisioning_Logic token]
                                withAuthInput:pin
                                        error:&internalErr];
        }
        
        
        // We can return control to handler.
        // If there is some error present and OTPValue is nil, we still want to send response to server. In this case reject.
        handler(otpValue);
        
        // All secure containers should be wiped asap.
        [pin wipe];
        [otpValue wipe];
        
        // Display error if something went wrong.
        if (internalErr) {
            [self displayMessageDialogError:internalErr];
        }
    }];
}


@end

