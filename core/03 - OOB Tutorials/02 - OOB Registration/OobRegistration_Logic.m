/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "OobRegistration_Logic.h"
#import "OobRegistration_Config.h"

static NSString * const C_STORAGE               = @"STORAGE";
static NSString * const C_CLIENT_ID             = @"CLIENT_ID";
static NSString * const C_PUSH_TOKEN            = @"PUSH_TOKEN";
static NSString * const C_REGISTERED_PUSH_TOKEN = @"REGISTERED_PUSH_TOKEN";

// Review: SNE document private methods
@implementation OobRegistration_Logic

// MARK: - Public API

+ (void)registerToMsm:(NSString *)userId
              regCode:(id<EMSecureString>)regCode
    completionHandler:(OOBRegistrationHandler)handler
{
    NSError                         *error      = nil;
    
    // We can optionally register push token profiles in case we already have token from apple.
    NSString                        *pushToken  = [OobRegistration_Logic readPushToken];
    NSArray                         *profiles   = [OobRegistration_Logic pushProfileWithToken:pushToken];
    
    // Build registration request. Profiles might be nil at this point.
    id<EMOobManager>                manager     = [OobRegistration_Logic initializeOOBManager];
    id<EMOobRegistrationManager>    regManager  = [manager oobRegistrationManager];
    EMOobRegistrationRequest        *request    = [[EMOobRegistrationRequest alloc] initWithUserId:userId
                                                                                userAliasForClient:userId
                                                                                registrationMethod:EMOobRegistrationMethodRegistrationCode
                                                                             registrationParameter:regCode
                                                                          notificationProfileItems:profiles
                                                                                             error:&error];
    
    // Check if all parameters was valid and send request to server. Otherwise notify about error.
    if (!error) {
        [regManager registerWithRequest:request completionHandler:^(id<EMOobRegistrationResponse> aResponse, NSError *anError) {
            
            // We need instance of manager to exist during whole registration process.
            // Application will usually have one instance set in some class property, so this line would not be needed.
            (void)manager;
            
            BOOL success = aResponse && aResponse.resultCode == EMOobResultCodeSuccess;
            if (success) {
                [OobRegistration_Logic storeClientId:aResponse.clientId];
            }
            handler(success, anError);
        }];
    } else {
        handler(NO, error);
    }
}

+ (void)unregisterFromMsm:(OOBRegistrationHandler)handler
{
    NSString *clientId = [OobRegistration_Logic readClientId];
    if (clientId) {
        id<EMOobManager>                manager     = [OobRegistration_Logic initializeOOBManager];
        id<EMOobUnregistrationManager>  regManager  = [manager oobUnregistrationManagerWithClientId:clientId];
        
        [regManager unregisterWithCompletionHandler:^(id<EMOobResponse> aResponse, NSError *anError) {
            // We need instance of manager to exist during whole registration process.
            // Application will usually have one instance set in some class property, so this line would not be needed.
            (void)manager;
            
            BOOL success = aResponse && aResponse.resultCode == EMOobResultCodeSuccess;
            if (success) {
                [OobRegistration_Logic storeClientId:nil];
            }
            handler(success, anError);
        }];
    } else {
        // OOB Was not registered.
        handler(YES, nil);
    }
}

+ (void)updateNotificationProfileWithPushToken:(NSData *)pushToken {
    // Convert token to hex string, which is accepted by server.
    NSString *hexToken = [OobRegistration_Logic hexStringFromData:pushToken];
    
    // Store token and update notification profile if user is registered
    [OobRegistration_Logic storePushToken:hexToken];
    
    // Client id is nil mean, that user is not yet registered.
    NSString *clientId = [OobRegistration_Logic readClientId];
    if (!clientId) {
        return;
    }
    
    // Compare last registered token with current one.
    if ([hexToken isEqualToString:[OobRegistration_Logic readRegisteredPushToken]]) {
        return;
    }
    
    id<EMOobManager>                manager         = [OobRegistration_Logic initializeOOBManager];
    id<EMOobNotificationManager>    notifyManager   = [manager oobNotificationManagerWithClientId:clientId];
    NSArray                         *profiles       = [OobRegistration_Logic pushProfileWithToken:hexToken];
    
    [notifyManager setNotificationProfiles:profiles completionHandler:^(id<EMOobResponse> response, NSError *error) {
        BOOL success = !error && response && [response resultCode] == EMOobResultCodeSuccess;
        if (success) {
            [OobRegistration_Logic storeRegisteredPushToken:hexToken];
        }
    }];
}

// MARK: - Storage helper methods

+ (void)storeRegisteredPushToken:(NSString *)pushToken
{
    [OobRegistration_Logic writeValue:pushToken forKey:C_REGISTERED_PUSH_TOKEN];
}

+ (NSString *)readRegisteredPushToken
{
    return [OobRegistration_Logic readValueWithKey:C_REGISTERED_PUSH_TOKEN withDefault:nil];
}

+ (void)storePushToken:(NSString *)pushToken
{
    [OobRegistration_Logic writeValue:pushToken forKey:C_PUSH_TOKEN];
}

+ (NSString *)readPushToken
{
    return [OobRegistration_Logic readValueWithKey:C_PUSH_TOKEN withDefault:nil];
}

+ (void)storeClientId:(NSString *)clientId
{
    [OobRegistration_Logic writeValue:clientId forKey:C_CLIENT_ID];
}

+ (NSString *)readClientId
{
    return [OobRegistration_Logic readValueWithKey:C_CLIENT_ID withDefault:nil];
}

+ (id)readValueWithKey:(NSString *)key withDefault:(id)defaultValue
{
    id retValue = [[NSUserDefaults standardUserDefaults] valueForKey:C_CLIENT_ID];
    return retValue ? retValue : defaultValue;
}

+ (void)writeValue:(id)value forKey:(NSString *)key
{
    NSUserDefaults *manager = [NSUserDefaults standardUserDefaults];
    [manager setValue:value forKey:key];
    [manager synchronize];
    
}

// MARK: - Private Helpers

+ (NSArray *)pushProfileWithToken:(NSString *)pushToken {
    if (pushToken) {
        return @[[[EMOobNotificationProfile alloc] initWithChannel:CFG_OOB_CHANNEL() endPoint:pushToken]];
    } else {
        return nil;
    }
}

+ (NSString *)hexStringFromData:(NSData *)data
{
    static const char *hexTable = "0123456789ABCDEF";
    
    const NSUInteger byteLength = data.length;
    const NSUInteger charLength = byteLength * 2;
    char *const hexChars = malloc(charLength * sizeof(*hexChars));
    __block char *charPtr = hexChars;
    
    [data enumerateByteRangesUsingBlock:^(const void *bytes, NSRange byteRange, BOOL *stop) {
        const uint8_t *bytePtr = bytes;
        for (NSUInteger count = 0; count < byteRange.length; ++count) {
            const uint8_t byte = *bytePtr++;
            *charPtr++ = hexTable[(byte >> 4) & 0xF];
            *charPtr++ = hexTable[byte & 0xF];
        }
    }];
    
    return [[NSString alloc] initWithBytesNoCopy:hexChars length:charLength encoding:NSASCIIStringEncoding freeWhenDone:YES];
}

+ (id<EMOobManager>)initializeOOBManager
{    
    NSError *error;
    id<EMOobManager> retValue = [[EMOobModule oobModule] createOobManagerWithURL:CFG_OOB_URL()
                                                                          domain:CFG_OOB_DOMAIN()
                                                                   applicationId:CFG_OOB_APP_ID()
                                                                     rsaExponent:CFG_OOB_RSA_KEY_EXPONENT()
                                                                      rsaModulus:CFG_OOB_RSA_KEY_MODULUS()
                                                                           error:&error];
    
    // Something went wrong during init phase.
    // Probably wrong configuration, license etc..
    if (error) {
        @throw [NSException
                exceptionWithName:@"OOBManagerException"
                reason:error.localizedDescription
                userInfo:nil];
    }
    
    return retValue;
}

@end
