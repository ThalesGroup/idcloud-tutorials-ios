/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "OTP_Logic.h"

// Review: SNE add javadoc
@interface TransactionSign_Logic : NSObject

+ (OTP_Value *)generateOtp:(id<EMOathToken>)token
             withAuthInput:(id<EMAuthInput>)authInput
                    amount:(NSString *)amount
               beneficiary:(NSString *)beneficiary
                     error:(NSError *__autoreleasing *)error;

@end
