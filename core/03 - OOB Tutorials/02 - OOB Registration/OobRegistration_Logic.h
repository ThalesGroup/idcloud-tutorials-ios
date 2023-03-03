/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

typedef void (^OOBRegistrationHandler)(BOOL success, NSError *error);

// Review: SNE add javadoc
@interface OobRegistration_Logic : NSObject


/**
 <#Description#>

 @param userId <#userId description#>
 @param regCode <#regCode description#>
 @param handler <#handler description#>
 */
+ (void)registerToMsm:(NSString *)userId
              regCode:(id<EMSecureString>)regCode
    completionHandler:(OOBRegistrationHandler)handler;


/**
 <#Description#>

 @param handler <#handler description#>
 */
+ (void)unregisterFromMsm:(OOBRegistrationHandler)handler;

/**
 <#Description#>

 @param pushToken <#pushToken description#>
 */
+ (void)updateNotificationProfileWithPushToken:(NSData *)pushToken;

/**
 <#Description#>

 @return <#return value description#>
 */
+ (NSString *)readClientId;


/**
 <#Description#>

 @return <#return value description#>
 */
+ (id<EMOobManager>)initializeOOBManager;

@end
