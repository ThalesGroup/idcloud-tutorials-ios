/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "Provisioning_ViewController.h"
#import "Provisioning_Logic.h"

@interface Provisioning_ViewController()

/**
 All sample applications using provisioning ui should set this property so it can be handled automatically.
 */
@property (nonatomic, weak) IBOutlet ProvisionerView *provisionView;

@end

@implementation Provisioning_ViewController

// MARK: - Lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Set provisioner UI delegate.
    _provisionView.delegate     = self;
    
    // Update UI availability
    [self updateGUI];
}

// MARK: - Public API

- (void)setQrCodeButtonVisible
{
    [_provisionView setQrCodeButtonVisible];
}

// MARK: - Private helpers

- (id<EMOathToken>)updateGUI
{
    // Get stored token
    id<EMOathToken> token = [Provisioning_Logic token];
    
    // To make demo simple we will just disable / enable UI.
    [_provisionView updateGUI:![self loadingBarIsPresent] token:token];
    
    // Pass token to all subclasses.
    return token;
}

// MARK: - ProvisionerViewDelegate

- (void)onProvision:(NSString *)userId withRegistrationCode:(id<EMSecureString>)regCode
{
    // Display loading message before asynchronous provisioning
    [self loadingBarShow:NSLocalizedString(@"STRING_PROVISION_LOADING", nil) animated:YES];
    
    // Provision
    [Provisioning_Logic provisionWithUserId:userId
                           registrationCode:regCode
                          completionHandler:^(id<EMOathToken> _Nullable token, NSError * _Nullable error)
     {
         // Wipe registration code. Since it's not needed any
         [regCode wipe];
         
         // Async operation finished. We can hide loading.
         [self loadingBarHide:YES];
         
         if (token) {
             [self displayMessageDialog:NSLocalizedString(@"STRING_PROVISION_SUCCESS", nil)];
         } else if (error) {
             [self displayMessageDialogError:error];
         } else {
             [self displayMessageDialog:NSLocalizedString(@"STRING_PROVISION_ERROR_UNKNOWN", nil)];
         }
     }];
}

- (void)onProvisionUsingQr {
    // Qr code registration is explained in later tutorial.
}

- (void)onRemoveToken
{
    NSError *error = nil;
    if ([Provisioning_Logic removeToken:&error]) {
        [self updateGUI];
    }
    
    // Display any possible errors during token removal process.
    [self displayMessageDialogError:error];

}

@end
