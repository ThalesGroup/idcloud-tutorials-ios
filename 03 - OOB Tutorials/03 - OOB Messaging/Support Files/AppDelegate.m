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

#import "AppDelegate.h"
#import "OOBSetup_Logic.h"
#import "OobRegistration_Logic.h"
#import "OobMessaging_Logic.h"

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
        notifyCenter.delegate = self;
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

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    // Pre iOS 10 notification.
    [OobMessaging_Logic processIncommingPush:userInfo];
}


// MARK: - UNUserNotificationCenterDelegate

- (void)userNotificationCenter:(UNUserNotificationCenter *)center
       willPresentNotification:(UNNotification *)notification
         withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler API_AVAILABLE(ios(10.0))
{
    // Since iOS 10 notification.
    [OobMessaging_Logic processIncommingPush:notification.request.content.userInfo];
    completionHandler(0);
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center
didReceiveNotificationResponse:(UNNotificationResponse *)response
         withCompletionHandler:(void(^)(void))completionHandler API_AVAILABLE(ios(10.0))
{
    // Since iOS 10 notification.
    [OobMessaging_Logic processIncommingPush:response.notification.request.content.userInfo];
    completionHandler();
}

@end
