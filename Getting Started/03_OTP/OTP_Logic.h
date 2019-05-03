//  MIT License
//
//  Copyright (c) 2019 Thales DIS
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

// IMPORTANT: This source code is intended to serve training information purposes only. Please make sure to review our IdCloud documentation, including security guidelines.


@interface OTP_Logic : NSObject


/**
 Method to generate One Time Password based on generic auth input.

 @param token Token from which we want to generate OTP.
 @param authInput Generic auth input object like Pin, FaceId etc..
 @param error Error description.
 @return One time password encapsulated in secure string.
 */
+ (id<EMSecureString>)generateOtp:(id<EMOathToken>)token
                    withAuthInput:(id<EMAuthInput>)authInput
                            error:(NSError **)error;


/**
 Asynchronous method to get user PIN using secure keypad.

 @param parent Parent navigation view controller where pinpad should be displayd.
 @param completionHandler Asynchronous handler triggered once user confirm entered pin.
 */
+ (void)getUserPin:(UINavigationController *)parent
 completionHandler:(EMSecureInputUiOnFinish)completionHandler;

@end
