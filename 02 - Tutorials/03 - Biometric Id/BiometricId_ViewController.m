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

#import "BiometricId_ViewController.h"
#import "BiometricId_Logic.h"
#import "AdvancedSetup_Logic.h"
#import "Provisioning_Logic.h"

@interface BiometricId_ViewController()

@property (weak, nonatomic) IBOutlet UIButton *buttonOTPPin;
@property (weak, nonatomic) IBOutlet UIButton *buttonOTPTouchId;
@property (weak, nonatomic) IBOutlet UIButton *buttonOTPFaceId;
@property (weak, nonatomic) IBOutlet UIButton *buttonOTPProtectorFaceId;
@property (weak, nonatomic) IBOutlet UIButton *buttonOTPProtectorFaceIdEnroll;

@property (weak, nonatomic) IBOutlet UISwitch *switchOTPTouchID;
@property (weak, nonatomic) IBOutlet UISwitch *switchOTPFaceId;
@property (weak, nonatomic) IBOutlet UISwitch *switchOTPProtectorFaceId;

@end

// Review: SNE document private methods
@implementation BiometricId_ViewController

// MARK: - Life cycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Register notifications
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(onFaceStateChanged:)
                                                 name:C_NOTIFICATION_ID_FACE_STATE_CHANGED
                                               object:nil];
}

- (void)dealloc
{
    // Unregister all notifications.
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

// MARK: - Helpers

- (id<EMOathToken>)updateGUI
{
    // Check all auth mode states so we can enable / disable proper buttons.
    id<EMOathToken>         token   = [super updateGUI];
    TokenStatus             status  = [BiometricId_Logic tokenStatus];
    ProtectorFaceIdState    state   = [AdvancedSetup_Logic state];
    BOOL                    enabled = ![self loadingBarIsPresent];
    
    _buttonOTPPin.enabled                   = enabled && token != nil;
    _buttonOTPTouchId.enabled               = enabled && status.isTouchEnabled;
    _switchOTPTouchID.enabled               = enabled && status.isTouchSupported;
    _switchOTPTouchID.on                    = status.isTouchEnabled;
    _buttonOTPFaceId.enabled                = enabled && status.isFaceEnabled;
    _switchOTPFaceId.enabled                = enabled && status.isFaceSupported;
    _switchOTPFaceId.on                     = status.isFaceEnabled;
#if USE_FACE_ID
    _buttonOTPProtectorFaceIdEnroll.enabled = enabled && (state == ProtectorFaceIdStateInited || state == ProtectorFaceIdStateReadyToUse);
    if (state == ProtectorFaceIdStateInited) {
        [_buttonOTPProtectorFaceIdEnroll setTitle:NSLocalizedString(@"STRING_PROTECTOR_FACE_ID_ENROLL", nil) forState:UIControlStateNormal];
    } else {
        [_buttonOTPProtectorFaceIdEnroll setTitle:NSLocalizedString(@"STRING_PROTECTOR_FACE_ID_UNENROLL", nil) forState:UIControlStateNormal];
    }
#else
    _buttonOTPProtectorFaceIdEnroll.enabled = NO;
#endif
    _buttonOTPProtectorFaceId.enabled       = enabled && (state == ProtectorFaceIdStateReadyToUse) && status.isProtectorFaceEnabled;
    _switchOTPProtectorFaceId.enabled       = enabled && (state == ProtectorFaceIdStateReadyToUse) && status.isProtectorFaceSupported;
    _switchOTPProtectorFaceId.on            = status.isProtectorFaceEnabled;
    

    
    return token;
}

- (void)enableMultiauth:(id<EMOathToken>)token withCompletionHandler:(AuthPinHandler)handler
{
    // Check whenever multiauthmode is already enabled.
    __block BOOL isEnabled = [token isMultiAuthModeEnabled];
    
    // In both cases we will need auth pin, becuase it's used for
    // multiauth upgrade as well as enabling specific authmodes.
    [self userPinWithCompletionHandler:^(id<EMPinAuthInput> pin) {
        // If multiauth is not enabled, we will try to upgrade it.
        NSError *error = nil;
        if (!isEnabled) {
            isEnabled = [token upgradeToMultiAuthMode:pin error:&error];
        }
        
        // Display whenever something went wrong and relaod GUI.
        [self displayMessageDialogError:error];
        [self updateGUI];
        
        // Notify handler
        handler(pin);
        
        // Pin is not needed any more.
        [pin wipe];
    }];
}

- (void)enroll
{
#if USE_FACE_ID
    [EMFaceManager enrollWithPresentingViewController:self timeout:60 completion:^(EMFaceManagerProcessStatus code) {
        
        // Display possible errors.
        if (code == EMFaceManagerProcessStatusFail) {
            [self displayMessageDialog:[[EMFaceManager sharedInstance] faceStatusError]];
        }
        
        // Notify others.
        [AdvancedSetup_Logic updateProtectorFaceIdStatus];
        
    }];
#endif
}

-(void)unenroll
{
#if USE_FACE_ID
    [EMFaceManager unenrollWithCompletion:^(EMFaceManagerProcessStatus code) {
        // Display possible errors.
        if (code == EMFaceManagerProcessStatusFail) {
            [self displayMessageDialog:[[EMFaceManager sharedInstance] faceStatusError]];
        }
        
        // Notify others.
        [AdvancedSetup_Logic updateProtectorFaceIdStatus];
    }];
#endif
}

- (void)enableOrDisableAuthMode:(UISwitch *)sender enabled:(BOOL)enabled service:(id<EMAuthService>)authService
{
    // Toggle button back, because cancel operation is not handled and succes will reload UI.
    [sender setOn:!sender.on];
 
    id<EMOathToken> token = [Provisioning_Logic token];
    
    if (enabled) {
        [self disableAuthMode:token authMode:[authService authMode]];
    } else {
        [self enableAuthMode:token authMode:[authService authMode]];
    }
}

- (AuthInputHandler)handleBiometricId:(id<EMOathToken>)token
{
    return ^(id<EMAuthInput> authInput, NSError *error) {
        if (authInput) {
            [self generateAndDisplayOtp:token authInput:authInput];
        } else if ([error code] == EM_STATUS_AUTHENTICATION_CANCELED_USER_FALLBACK) {
            [self generateAndDisplayOtp_PinInput];
        } else {
            [self displayMessageDialogError:error];
        }
    };
}

// MARK: - Public API

- (void)enableAuthMode:(id<EMOathToken>)token authMode:(id<EMAuthMode>)mode
{
    // This should not happen due GUI lock, but it's good practice to check anyway.
    if ([token isAuthModeActive:mode]) {
        [self updateGUI];
        return;
    }
    
    // We must enable multiauth mode before activating any specific one.
    // Since we need pin for both of those operations this metod will ask for it and return one directly.
    [self enableMultiauth:token withCompletionHandler:^(id<EMPinAuthInput> pin)
     {
         // Try to activate selected mode.
         NSError *error = nil;
         [token activateAuthMode:mode usingActivatedInput:pin error:&error];;
         
         // Some errors are not critical and we don't want to display them.
         // Check whenever operation was successful by checking mode state.
         if (error && ![token isAuthModeActive:mode]) {
             [self displayMessageDialogError:error];
         } else {
             [self updateGUI];
         }
     }];
}

- (void)disableAuthMode:(id<EMOathToken>)token authMode:(id<EMAuthMode>)mode
{
    // This should not happen due GUI lock, but it's good practice to check anyway.
    if (![token isAuthModeActive:mode]) {
        [self updateGUI];
        return;
    }
    
    NSError *error = nil;
    [token deactivateAuthMode:mode error:&error];
    
    // Some errors are not critical and we don't want to display them.
    // Check whenever operation was successful by checking mode state.
    if (error && [token isAuthModeActive:mode]) {
        [self displayMessageDialogError:error];
    } else {
        [self updateGUI];
    }
}

- (void)generateAndDisplayOtp_TouchId
{
    // Trigger system authentication
    id<EMOathToken> token = [Provisioning_Logic token];
    [BiometricId_Logic userTouchId:token completionHandler:[self handleBiometricId:token]];
}

- (void)generateAndDisplayOtp_FaceId
{
    // Trigger system authentication
    id<EMOathToken> token = [Provisioning_Logic token];
    [BiometricId_Logic userFaceId:token completionHandler:[self handleBiometricId:token]];
}

- (void)generateAndDisplayOtp_MobileProtectorFaceId
{
#if USE_FACE_ID
    // Trigger authentication
    id<EMOathToken> token = [Provisioning_Logic token];
    [EMFaceManager verifyWithPresentingViewController:self
                                      authenticatable:token
                                              timeout:30000
                                           completion:^(EMFaceManagerProcessStatus code, id<EMFaceAuthInput> authInput)
     {
         // Call in UI thread. New sdk is already doing that, but we want to support all versions.
         dispatch_async(dispatch_get_main_queue(), ^{
             // Display possible errors.
             if (code == EMFaceManagerProcessStatusFail) {
                 [self displayMessageDialog:[[EMFaceManager sharedInstance] faceStatusError]];
             } else if (authInput) {
                 [self generateAndDisplayOtp:token authInput:authInput];
             }
         });
     }];
#endif
}

// MARK: - NSNotificationCenter

- (void)onFaceStateChanged:(NSNotification *) notification
{
    [self updateGUI];
}

// MARK: - User Interface

- (IBAction)onButtonPressedOTPPin:(UIButton *)sender
{
    [self generateAndDisplayOtp_PinInput];
}

- (IBAction)onButtonPressedOTPTouchId:(UIButton *)sender
{
    [self generateAndDisplayOtp_TouchId];
}

- (IBAction)onButtonPressedOTPFaceId:(UIButton *)sender
{
    [self generateAndDisplayOtp_FaceId];
}

- (IBAction)onButtonPressedOTPProtectorFaceId:(UIButton *)sender
{
    [self generateAndDisplayOtp_MobileProtectorFaceId];
}

- (IBAction)onSwitchToggledOTPTouchId:(UISwitch *)sender
{
    // Toggle auth mode
    [self enableOrDisableAuthMode:sender
                          enabled:[BiometricId_Logic tokenStatus].isTouchEnabled
                          service:[EMSystemBioFingerprintAuthService serviceWithModule:[EMAuthModule authModule]]];
}

- (IBAction)onSwitchToggledOTPFaceId:(UISwitch *)sender
{
    // Toggle auth mode
    [self enableOrDisableAuthMode:sender
                          enabled:[BiometricId_Logic tokenStatus].isFaceEnabled
                         service:[EMSystemFaceAuthService serviceWithModule:[EMAuthModule authModule]]];
}

- (IBAction)onSwitchToggledOTPProtectorFaceId:(UISwitch *)sender
{
    // Toggle auth mode
    [self enableOrDisableAuthMode:sender
                          enabled:[BiometricId_Logic tokenStatus].isProtectorFaceEnabled
                          service:[EMFaceAuthService serviceWithModule:[EMAuthModule authModule]]];
}

- (IBAction)onButtonPressedOTPProtectorFaceIdEnroll:(UIButton *)sender
{
    // Do proper action based on current state.
    if ([AdvancedSetup_Logic state] == ProtectorFaceIdStateInited) {
        [self enroll];
    } else {
        // Ask user before un-enrolling.
        [self displayOnCancelDialog:NSLocalizedString(@"STRING_BIOMETRIC_UNENROLL_FACE_MSG", nil) completionHandler:^(BOOL result) {
            if (result) {
                [self unenroll];
            }
        }];
    }
}

@end
