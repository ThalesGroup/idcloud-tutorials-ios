/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

@interface OTP_Value : NSObject

@property (nonatomic, strong, readonly) id<EMSecureString>  otp;
@property (nonatomic, assign, readonly) Lifespan            lifespan;


/**
 Constructor

 @param otp OTP Value
 @param lastLifespan Last OTP value life span since calculation.
 @param maxLifespan Maximum OTP value life span.
 @return New instance of OTP Value.
 */
+ (instancetype)valueWithOTP:(id<EMSecureString>)otp
                lastLifespan:(NSInteger)lastLifespan
                 maxLifespan:(NSInteger)maxLifespan;

/**
 Wipe all sensitive data.
 */
- (void)wipe;

@end

@interface OTP_Logic : NSObject

/**
 Method to generate One Time Password based on generic auth input.
 
 @param token Token from which we want to generate OTP.
 @param authInput Generic auth input object like Pin, FaceId etc..
 @param error Error description.
 @return One time password encapsulated in OTP_Value object.
 */
+ (OTP_Value *)generateOtp:(id<EMOathToken>)token
             withAuthInput:(id<EMAuthInput>)authInput
                     error:(NSError **)error;


@end
