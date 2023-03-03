/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

// Register those notifications to NSNotificationCenter in case you want to track some state changes.
// By default it's tracked by SDKStateView component.
extern NSString * const C_NOTIFICATION_ID_LOG_STATE_CHANGED;

// Review: SNE Add javadoc
@interface AdvancedSetup_Logic : NSObject

/**
 Initialise all Mobile Protector SDK component.
 */
+ (void)setup;

/**
 Used for demonstration cases to keep track about SDK states. No log's should be stored in production environment.

 @return Current SDK Logs.
 */
+ (NSString *)log;

/**
 Append log message to the current stack and notify handlers about that change.

 @param log Message to be logged.
 */
+ (void)logMessage:(NSString *)log;


/**
 Log error using logMessage if given object is not nil.

 @param error Error to be logged.
 */
+ (void)logError:(NSError *)error;


@end
