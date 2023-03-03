/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#include "OTP_Logic.h"

// Review: SNE add javadoc
@interface InBandVerification_Logic : NSObject

/**
 Verify token validity against tutorial webpage.

 @param token Token to be verified.
 @param authInput Selected authentication input.
 @param completionHandler Completion handler triggered in UI thread once operation is done.
 */
+ (void)verifyWithToken:(id<EMOathToken>)token
              authInput:(id<EMAuthInput>)authInput
      completionHandler:(GenericOtpHandler)completionHandler;

@end
