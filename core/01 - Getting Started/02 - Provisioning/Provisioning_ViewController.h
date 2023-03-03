/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "Setup_ViewController.h"
#import "ProvisionerView.h"

@interface Provisioning_ViewController : Setup_ViewController <ProvisionerViewDelegate>

/**
 Display "Provision using Qr code" button.
 */
- (void)setQrCodeButtonVisible;

@end

