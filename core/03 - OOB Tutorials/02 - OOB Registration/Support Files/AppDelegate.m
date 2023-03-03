/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "AppDelegate.h"
#import "OOBSetup_Logic.h"
#import "OobRegistration_Logic.h"

@interface AppDelegate(OOB) <UNUserNotificationCenterDelegate>
@end

@implementation AppDelegate

// MARK: - Life Cycle

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [OOBSetup_Logic setup];
    
    // Register for notifications
    if (@available(iOS 10.0, *))
    {
        UNUserNotificationCenter *notifyCenter = [UNUserNotificationCenter currentNotificationCenter];
        [notifyCenter requestAuthorizationWithOptions: UNAuthorizationOptionAlert | UNAuthorizationOptionBadge | UNAuthorizationOptionSound completionHandler:^(BOOL granted, NSError * _Nullable error) {
            if (granted)
            {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [application registerForRemoteNotifications];
                });
            }
        }];
    }
    else
    {
        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeAlert | UIUserNotificationTypeBadge | UIUserNotificationTypeSound) categories:nil];
        [application registerUserNotificationSettings:settings];
        [application registerForRemoteNotifications];
    }
    
    return YES;
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    // Logic layer will update profile if needed.
    [OobRegistration_Logic updateNotificationProfileWithPushToken:deviceToken];
}

@end
