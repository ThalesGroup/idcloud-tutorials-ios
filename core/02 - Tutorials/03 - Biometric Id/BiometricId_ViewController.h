/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "QRCodeBasic_ViewController.h"

// Review: SNE add javadoc
@interface BiometricId_ViewController : QRCodeBasic_ViewController

/**
 Enable selected auth mode for given token.

 @param token Token to where auth mode should be enabled.
 @param mode Auth mode we want to enable.
 */
- (void)enableAuthMode:(id<EMOathToken>)token authMode:(id<EMAuthMode>)mode;

/**
 Disable selected auth mode for given token.
 
 @param token Token to where auth mode should be disabled.
 @param mode Auth mode we want to disable.
 */
- (void)disableAuthMode:(id<EMOathToken>)token authMode:(id<EMAuthMode>)mode;


/**
 Method to generate OTP and display result on screen using Touch Id.
 */
- (void)generateAndDisplayOtp_TouchId;


/**
 Method to generate OTP and display result on screen using Face Id.
 */
- (void)generateAndDisplayOtp_FaceId;


@end

