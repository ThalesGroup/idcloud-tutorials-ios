/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "QRCodeBasic_ViewController.h"
#import "QRCodeReaderVC.h"
#import "QRCodeBasic_Logic.h"
#import "Provisioning_Logic.h"

// Review: SNE document private methods
@interface QRCodeBasic_ViewController () <QRCodeReaderDelegate>

@end

@implementation QRCodeBasic_ViewController

// MARK: - Life Cycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Add QR Code provision button since this module.
    [self setQrCodeButtonVisible];
}

// MARK: - ProvisionerViewDelegate

- (void)onProvisionUsingQr
{
    // Display QR code reader and wait for delegate response onQRCodeProvided.
    [self.navigationController pushViewController:[QRCodeReaderVC readerWithDelegate:self customTag:0] animated:YES];
}

// MARK: - QRCodeReaderDelegate

- (void)onQRCodeProvided:(QRCodeReaderVC *)sender qrCode:(NSString *)qrCode
{
    // Parse provided QR data to get user id and registration code.
    [QRCodeBasic_Logic parseQRCode:qrCode completionHandler:^(BOOL successful, NSString *userId, id<EMSecureString> regCode, NSError *error) {
        // QR Data was succesfully parsed. Continue with provision process as usual.
        if (successful) {
            [self onProvision:userId withRegistrationCode:regCode];
        } else {
            [self displayMessageDialogError:error];
        }
    }];
}

@end
