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
