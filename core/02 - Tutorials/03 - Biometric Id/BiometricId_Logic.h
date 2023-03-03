/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

typedef struct
{
    // Whever is System Touch ID supported by device and SDK
    BOOL isTouchSupported;
    // Whever is System Face ID supported by device and SDK
    BOOL isFaceSupported;
    
    // Whever is System Touch ID supported and enabled
    BOOL isTouchEnabled;
    // Whever is System Face ID supported and enabled
    BOOL isFaceEnabled;
}TokenStatus;


/**
 Generic auth input handler used for biometric identification.

 @param authInput Face/Touch etc.. auth input.
 @param error Error description in case of not succesfull operation.
 */
typedef void (^AuthInputHandler)(id<EMAuthInput> authInput, NSError *error);

// Review: SNE add javadoc
@interface BiometricId_Logic : NSObject

/**
 Return token status summary with all biometric status details.

 @return Current status.
 */
+ (TokenStatus)tokenStatus;

/**
 Return user Touch Id auth input or error description for given token.

 @param token Token you want to use for authentication.
 @param completionHandler Auth / Error completion halnder.
 */
+ (void)userTouchId:(id<EMOathToken>)token completionHandler:(AuthInputHandler)completionHandler;

/**
 Return user Face Id auth input or error description for given token.

 @param token Token you want to use for authentication.
 @param completionHandler Auth / Error completion halnder.
 */
+ (void)userFaceId:(id<EMOathToken>)token completionHandler:(AuthInputHandler)completionHandler;


@end
