/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "OTP_Logic.h"

// Review: SNE add javadoc
@protocol OobMessageListener <NSObject>


/**
 <#Description#>

 @param caption <#caption description#>
 */
- (void)onOobLoadingShow:(NSString *)caption;


/**
 <#Description#>
 */
- (void)onOobLoadingHide;


/**
 <#Description#>

 @param message <#message description#>
 */
- (void)onOobDisplayMessage:(NSString *)message;


/**
 <#Description#>

 @param message <#message description#>
 @param serverChallenge <#serverChallenge description#>
 @param handler <#handler description#>
 */
- (void)onOobApproveMessage:(NSString *)message
        withServerChallenge:(id<EMSecureString>)serverChallenge
          completionHandler:(void (^)(OTP_Value *otp))handler;

@end

@interface OobMessaging_Logic : NSObject


/**
 <#Description#>

 @param listener <#listener description#>
 */
+ (void)setCurrenOobListener:(id<OobMessageListener>)listener;

/**
 <#Description#>
 
 @param notification <#userInfo description#>
 */
+ (void)processIncommingPush:(NSDictionary *)notification;




+ (void)fetchMessages;

/**
 <#Description#>

 @param token <#token description#>
 @param authInput <#authInput description#>
 @param serverChallenge <#serverChallenge description#>
 @param error <#error description#>
 @return <#return value description#>
 */
+ (OTP_Value *)generateOtp:(id<EMOathToken>)token
             withAuthInput:(id<EMAuthInput>)authInput
           serverChallenge:(id<EMSecureString>)serverChallenge
                     error:(NSError *__autoreleasing *)error;

@end
