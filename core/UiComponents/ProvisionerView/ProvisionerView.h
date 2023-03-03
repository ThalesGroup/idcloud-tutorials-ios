/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

// Review: SNE add javadoc
@protocol ProvisionerViewDelegate <NSObject>


/**
 User triggered provision process.

 @param userId User identifier.
 @param regCode Registration code.
 */
- (void)onProvision:(NSString *)userId withRegistrationCode:(id<EMSecureString>)regCode;

/**
 * User triggered provision process using Qr Code Reader.
 */
- (void)onProvisionUsingQr;

/**
 Triggered when user decided to remove token.
 */
- (void)onRemoveToken;

@end


/**
 Helper to autoresize view without stackview.
 */
@interface UIButtonAutoSize : UIButton

@end

IB_DESIGNABLE
@interface ProvisionerView : UIView

@property (weak, nonatomic) id<MainViewProtocol, ProvisionerViewDelegate> delegate;

/**
 Update provisioning view with current status.

 @param enabled Enable / Disable UI.
 @param token Provisioned token.
 */
- (void)updateGUI:(BOOL)enabled token:(id<EMOathToken>)token;

/**
 Display "Provision using Qr code" button.
 */
- (void)setQrCodeButtonVisible;


@end
