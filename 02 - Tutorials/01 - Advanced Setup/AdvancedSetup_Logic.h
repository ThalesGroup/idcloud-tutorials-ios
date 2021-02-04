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
