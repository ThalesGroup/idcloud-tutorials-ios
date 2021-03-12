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
