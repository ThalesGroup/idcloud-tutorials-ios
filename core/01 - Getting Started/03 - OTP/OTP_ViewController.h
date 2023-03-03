/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "Provisioning_ViewController.h"
#import "ResultView.h"

@interface OTP_ViewController : Provisioning_ViewController


/**
 Display message using ResultView with given lifespan count down.

 @param message Text to be displayed.
 @param lifespan Text validity time in seconds.
 */
- (void)displayMessageResult:(NSString *)message lifespan:(Lifespan)lifespan;

/**
 Method to generate OTP and display result on screen using any generic auth input.

 @param token Token to be used for OTP generation.
 @param authInput Any supported authinput. Pin, Touch, Face etc...
 */
- (void)generateAndDisplayOtp:(id<EMOathToken>)token authInput:(id<EMAuthInput>)authInput;

/**
 Method to generate OTP and display result on screen using Pin.
 */
- (void)generateAndDisplayOtp_PinInput;

/**
 Asynchronous method to get user PIN using secure keypad.
 
 @param completionHandler Asynchronous handler triggered once user confirm entered pin.
 */
- (void)userPinWithCompletionHandler:(AuthPinHandler)completionHandler;

@end

