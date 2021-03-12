/** -----------------------------------------------------------------------------
 
 Copyright (c) 2019  -  GEMALTO DEVELOPMENT - R&D
 
 -----------------------------------------------------------------------------
 GEMALTO MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF
 THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 PARTICULAR PURPOSE, OR NON-INFRINGEMENT. GEMALTO SHALL NOT BE
 LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
 MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
 
 THIS SOFTWARE IS NOT DESIGNED OR INTENDED FOR USE OR RESALE AS ON-LINE
 CONTROL EQUIPMENT IN HAZARDOUS ENVIRONMENTS REQUIRING FAIL-SAFE
 PERFORMANCE, SUCH AS IN THE OPERATION OF NUCLEAR FACILITIES, AIRCRAFT
 NAVIGATION OR COMMUNICATION SYSTEMS, AIR TRAFFIC CONTROL, DIRECT LIFE
 SUPPORT MACHINES, OR WEAPONS SYSTEMS, IN WHICH THE FAILURE OF THE
 SOFTWARE COULD LEAD DIRECTLY TO DEATH, PERSONAL INJURY, OR SEVERE
 PHYSICAL OR ENVIRONMENTAL DAMAGE ("HIGH RISK ACTIVITIES"). GEMALTO
 SPECIFICALLY DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTY OF FITNESS FOR
 HIGH RISK ACTIVITIES.
 
 -----------------------------------------------------------------------------
 */

#import <Foundation/Foundation.h>
#import "EMMobileMessageManager.h"
#import "EMFastTrackTlsConfiguration.h"
#import "EMFastTrackDeviceFingerprintSource.h"
#import "EMRegistrationResponse.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Mobile Messenger Generic Content Type in JSON
 */
extern NSString *MOBILE_MESSENGER_JSON_CONTENT_TYPE_GENERIC;

/**
 Mobile Messenger Transaction Verify Request Content Type in JSON
 */
extern NSString *MOBILE_MESSENGER_JSON_CONTENT_TYPE_TRANSACTION_VERIFY_REQUEST;

/**
 Mobile Messenger Transaction Verify Response Content Type in JSON
 */
extern NSString *MOBILE_MESSENGER_JSON_CONTENT_TYPE_TRANSACTION_VERIFY_RESPONSE;

/**
 Mobile Messenger Transaction Signing Request Content Type in JSON
 */
extern NSString *MOBILE_MESSENGER_JSON_CONTENT_TYPE_TRANSACTION_SIGNING_REQUEST;

/**
 Mobile Messenger Transaction Signing Response Content Type in JSON
 */
extern NSString *MOBILE_MESSENGER_JSON_CONTENT_TYPE_TRANSACTION_SIGNING_RESPONSE;

/**
 The mobile messenger policy of the Mobile Protector SDK when the physical device is
 detected as being jailbroken.
 * - Since: 5.3
 */
typedef NS_ENUM(NSInteger, EMMobileMessengerJailbreakPolicy)
{
    /**
     * No action is taken when calling a method in the Mobile SDK
     * even the physical device is jailbroken.
     */
    EMMobileMessengerJailbreakPolicyIgnore,
    
    /** A EMJailbreakError is returned via the error parameter when calling a method in the Mobile Protector SDK that detects if the physical device is jailbroken.
     */
    EMMobileMessengerJailbreakPolicyFail,
    
    /** A EMJailbreakError is returned via the error parameter and the client is silently unregistered when calling a method in the Mobile Protector SDK that detects if the physical device is jailbroken.
     */
    EMMobileMessengerJailbreakPolicyUnregister
};

/**
 * EMMobileMessenger configuration builder.
 * - Since: 5.3
 */
@interface EMMobileMessengerOptionalParameters : NSObject

/**
 * Gets/sets the policy for Jailbreak detection.
 */
@property (nonatomic, assign) EMMobileMessengerJailbreakPolicy jailbreakPolicy;

/**
 * Gets/sets the transport layer security configuration for the connection. This may be used for test environments where the security of the system is not a concern (e.g. using insecure HTTP connections). See EMTlsConfiguration
 * For default instance insecureConnectionAllowed is set to 'NO'
 * selfSignedCertAllowed is set to 'NO'
 * hostnameMismatchAllowed is set to 'NO'
 */
@property (nonatomic, strong) EMFastTrackTlsConfiguration *tlsConfiguration;

/**
 * Gets/sets device fingerprint source.
 */
@property (nonatomic, strong) EMFastTrackDeviceFingerprintSource *deviceFingerprintSource;

@end


/**
 * EMMobileMessenger represents the entry point to the SDK features related to messaging.
 * - Since: 5.3
 */
@interface EMMobileMessenger : NSObject

/**
 * Singleton instance of EMMobileMessenger
 *
 * @return The singleton EMMobileMessenger instance. This method requires EMMobileMessenger to be configured
 */
+ (nullable instancetype)sharedInstance;

/**
 * Perform the registration of the user to the OOBS.
 *
 * @param userId            The ID of the user who registers to the OOBS.
 * @param userAlias         Human readable alias for this client.
 * @param registrationCode  Registration is authorised by the registration code entered by the user via the application UI.
 * @param headers           The request parameter containing custom header.
 * @param completionHandler The block to invoke on the main thread upon completion which contains the response and error information if any.
 */
- (void)registerWithUserId:(NSString *)userId
                 userAlias:(NSString *)userAlias
          registrationCode:(NSString *)registrationCode
             customHeaders:(nullable NSDictionary<NSString *, NSString *> *)headers
         completionHandler:(void(^)(EMRegistrationResponse * _Nullable aResponse, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(register(userId:userAlias:registrationCode:customHeaders:completionHandler:));

/**
 * Performs the unregistration of the user to the OOBS.
 * @param headers           The request parameter containing custom header.
 * @param completionHandler The block to invoke on the main thread upon completion which contains the status and error information if any.
 */
- (void)unregisterWithCustomHeaders:(nullable NSDictionary<NSString *, NSString *> *)headers
                  completionHandler:(void(^)(BOOL success, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(unregister(customHeaders:completionHandler:));

/**
 * Performs the unregistration of the user to the OOBS.
 *
 * @param clientId          The ID of the user who unregister from the OOBS.
 * @param headers           The request parameter containing custom header.
 * @param completionHandler The block to invoke on the main thread upon completion which contains the status and error information if any.
 */
- (void)unregisterWithClientId:(NSString *)clientId
                 customHeaders:(nullable NSDictionary<NSString *, NSString *> *)headers
             completionHandler:(void(^)(BOOL success, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(unregister(clientId:customHeaders:completionHandler:));

/**
 * Sets/Clear the notification profile. SDK updates the notification profile on the OOB server on the first time.
 * In subsequent invocation to this API, SDK checks the value of the endPoint. Notification profile is updated if
 * the endPoint value is different from previous value. Otherwise SDK skips the server call.
 *
 * @param channel           The channel to use for the notification (SMS, push, email, etc.)
 * @param endPoint          Value associated with this channel.
 * @param headers           The request parameter containing custom header.
 * @param completionHandler The block to invoke on the main thread upon completion which contains the response and error information if any.
 */
- (void)refreshTokenWithChannel:(NSString *)channel
                       endPoint:(nullable NSString *)endPoint
                  customHeaders:(nullable NSDictionary<NSString *, NSString *> *)headers
              completionHandler:(void(^)(BOOL success, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(refreshToken(channel:endPoint:customHeaders:completionHandler:));

/**
 * Sets/Clear the notification profile. SDK updates the notification profile on the OOB server on the first time.
 * In subsequent invocation to this API, SDK checks the value of the endPoint. Notification profile is updated if
 * the endPoint value is different from previous value. Otherwise SDK skips the server call.
 *
 * @param clientId          The ID of the user who registered with the OOBS.
 * @param channel           The channel to use for the notification (SMS, push, email, etc.)
 * @param endPoint          Value associated with this channel.
 * @param headers           The request parameter containing custom header.
 * @param completionHandler The block to invoke on the main thread upon completion which contains the response and error information if any.
 */
- (void)refreshTokenWithClientId:(NSString *)clientId
                         channel:(NSString *)channel
                        endPoint:(nullable NSString *)endPoint
                   customHeaders:(nullable NSDictionary<NSString *, NSString *> *)headers
               completionHandler:(void(^)(BOOL success, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(refreshToken(clientId:channel:endPoint:customHeaders:completionHandler:));

/**
 * Retrieve the Set of names of existing clientIds in the database.
 *
 * @return The set of names of existing clientIds in the database.
 */
- (NSSet<NSString *> *)clientIds;

/**
 * Retrieve the Set of names of existing clientIds in the database.
 *
 * @param userId            The ID associated with the clientId.
 * @return The set of names of existing clientIds in the database.
 */
- (NSSet<NSString *> *)clientIdsForUserId:(NSString *)userId NS_SWIFT_NAME(clientIds(userId:));

/**
 * Returns the default OOB message manager.
 *
 * @param providerId        The ID of the provider used for message communication.
 * @param error             If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The OOB message manager.
 */
- (nullable EMMobileMessageManager *)defaultMessageManagerWithProviderId:(NSString*)providerId
                                                                   error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(defaultMessageManager(providerId:));

/**
 * Returns the OOB message manager.
 *
 * @param clientId          The ID associated with the clientId.
 * @param providerId        The ID of the provider used for message communication.
 * @param error             If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The OOB message manager.
 */
- (nullable EMMobileMessageManager *)messageManagerWithClientId:(NSString *)clientId
                                                     providerId:(NSString *)providerId
                                                          error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(messageManager(clientId:providerId:));

/**
 * If your client was registered using Old Mobile Protector SDK, call this method to insert your clientId
 * so you can use your existing data with the new APIs.
 *
 * @param clientId          The ID associated with the clientId.
 * @param userId            The ID associated with the clientId.
 * @param error             If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The migration status.
 */
- (BOOL)persistClientId:(NSString *)clientId
                 userId:(NSString *)userId
                  error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(persist(clientId:userId:));

@end

NS_ASSUME_NONNULL_END
