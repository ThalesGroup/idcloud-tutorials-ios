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

#import "EMMobileProtector.h"
#import "EMProtectorOathTokenDevice.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A class that manages the token devices.
 This class could be use to do Token Device management such as creating the token through provisioning process also getting and removing it.
 * - Since: 5.3
 */
@interface EMOathMobileProtector : EMMobileProtector

/**
 Singleton instance of `EMOathMobileProtector`
 
 @return The singleton `EMOathMobileProtector` instance. This method requires `EMOathMobileProtector` to be created on `EMFastTrack`.
 */
+ (nullable instancetype)sharedInstance;

/**
 Retrieve the Set of names of existing `EMProtectorOathTokenDevice` from the database.
 
 @param error                If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return The set of names of existing TokenDevices. Could return empty if there's no token device in the database.
 */
- (nullable NSSet<NSString*> *)tokenDeviceNamesWithError:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(tokenDeviceNames());

/**
 Retrieve the `EMProtectorOathTokenDevice` with given name.
 
 @param tokenDeviceName       The token device name.
 @param fingerprintCustomData  The fingerprint custom data. This data is mandatory if the `EMFastTrackDeviceFingerprintSource customData` is set on `EMProvisionerOptionalParameters` during provisioning.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return The `EMProtectorOathTokenDevice` object
 */
- (nullable EMProtectorOathTokenDevice *)tokenDeviceWithName:(NSString *)tokenDeviceName
                                       fingerprintCustomData:(nullable NSData *)fingerprintCustomData
                                                       error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(tokenDevice(name:fingerprintCustomData:));


/**
 Retrieve the `EMProtectorOathTokenDevice` with user token ID.
 
 @param userTokenID           The userTokenID
 @param fingerprintCustomData  The fingerprint custom data. This data is mandatory if the `EMFastTrackDeviceFingerprintSource customData` is set on `EMProvisionerOptionalParameters` during provisioning.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return The `EMProtectorOathTokenDevice` object
 */
- (nullable EMProtectorOathTokenDevice *)tokenDeviceWithUserTokenID:(int)userTokenID
                                              fingerprintCustomData:(nullable NSData *)fingerprintCustomData
                                                              error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(tokenDevice(userTokenID:fingerprintCustomData:));

/**
 Remove `EMProtectorOathTokenDevice` from the database with given name.
 
 @param tokenDeviceName       The token name.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return `YES` if the succeeded. Otherwise `NO`
 */
- (BOOL)removeTokenDeviceWithName:(NSString *)tokenDeviceName
                            error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(removeTokenDevice(name:));

/**
 Starts the creation of a `EMProtectorOathTokenDevice` for Time-based OTP.
 If there's a token device that has the same name in the database, the provisioning process will stop and an error will be return.
 
 @param tokenDeviceName       The token device name.
 @param registrationCode      The registration code. For Protocol Version 3, minimum registration code length is 2, and maximum registration code length is 14. For Protocol Version 5, minimum registration code length is 6, and maximum registration code length is 32.
 @param totpSettings          The Time-based OTP settings that should be the same as the policy on the authentication server. This settings are persisted and will be used later by OTP generation.
 @param optionalParameters    The optional parameters, @see `EMProvisionerOptionalParameters`
 @param completionHandler     A callback from provisioning that contains `EMProtectorOathTokenDevice` if there's no error also a provisioning extensions that was set by the bank during enrollment process.
 */
- (void)provisionWithTokenDeviceName:(NSString *)tokenDeviceName
                    registrationCode:(NSString *)registrationCode
                        totpSettings:(EMProtectorTotpSettings *)totpSettings
                  optionalParameters:(nullable void(^)(EMProvisionerOptionalParameters *))optionalParameters
                   completionHandler:(void(^)(EMProtectorOathTokenDevice * _Nullable tokenDevice, NSDictionary * _Nullable extensions, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(provision(tokenDeviceName:registrationCode:totpSettings:optionalParameters:completionHandler:));

/**
 Starts the creation of a `EMProtectorOathTokenDevice` for Event-based OTP.
 If there's a token device that has the same name in the database, the provisioning process will stop and an error will be return.
 
 @param tokenDeviceName       The token device name.
 @param registrationCode      The registration code. For Protocol Version 3, minimum registration code length is 2, and maximum registration code length is 14. For Protocol Version 5, minimum registration code length is 6, and maximum registration code length is 32.
 @param hotpSettings          The Event-based OTP settings that should be the same as the policy on the authentication server. This settings are persisted and will be used later by OTP generation.
 @param optionalParameters    The optional parameters, @see `EMProvisionerOptionalParameters`
 @param completionHandler     A callback from provisioning that contains `EMProtectorOathTokenDevice` if there's no error also a provisioning extensions that was set by the bank during enrollment process.
 */
- (void)provisionWithTokenDeviceName:(NSString *)tokenDeviceName
                    registrationCode:(NSString *)registrationCode
                        hotpSettings:(EMProtectorHotpSettings *)hotpSettings
                  optionalParameters:(nullable void(^)(EMProvisionerOptionalParameters *))optionalParameters
                   completionHandler:(void(^)(EMProtectorOathTokenDevice * _Nullable tokenDevice, NSDictionary * _Nullable extensions, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(provision(tokenDeviceName:registrationCode:hotpSettings:optionalParameters:completionHandler:));

/**
 Starts the creation of a `EMProtectorOathTokenDevice` for OCRA OTP.
 If there's a token device that has the same name in the database, the provisioning process will stop and an error will be return.
 
 @param tokenDeviceName       The token device name.
 @param registrationCode      The registration code. For Protocol Version 3, minimum registration code length is 2, and maximum registration code length is 14. For Protocol Version 5, minimum registration code length is 6, and maximum registration code length is 32.
 @param ocraSettings          The OCRA OTP settings that should be the same as the policy on the authentication server. This settings are persisted and will be used later by OTP generation.
 @param optionalParameters    The optional parameters, @see `EMProvisionerOptionalParameters`
 @param completionHandler     A callback from provisioning that contains `EMProtectorOathTokenDevice` if there's no error also a provisioning extensions that was set by the bank during enrollment process.
 */
- (void)provisionWithTokenDeviceName:(NSString *)tokenDeviceName
                    registrationCode:(NSString *)registrationCode
                        ocraSettings:(EMProtectorOcraSettings *)ocraSettings
                  optionalParameters:(nullable void(^)(EMProvisionerOptionalParameters *))optionalParameters
                   completionHandler:(void(^)(EMProtectorOathTokenDevice * _Nullable tokenDevice, NSDictionary * _Nullable extensions, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(provision(tokenDeviceName:registrationCode:ocraSettings:optionalParameters:completionHandler:));

/**
 Starts the creation of a `EMProtectorOathTokenDevice` for DCVV OTP.
 If there's a token device that has the same name in the database, the provisioning process will stop and an error will be return.
 
 @param tokenDeviceName       The token device name.
 @param registrationCode      The registration code. For Protocol Version 3, minimum registration code length is 2, and maximum registration code length is 14. For Protocol Version 5, minimum registration code length is 6, and maximum registration code length is 32.
 @param dcvvSettings          The Time-based OTP settings that should be the same as the policy on the authentication server. This settings are persisted and will be used later by OTP generation.
 @param optionalParameters    The optional parameters, @see `EMProvisionerOptionalParameters`
 @param completionHandler     A callback from provisioning that contains `EMProtectorOathTokenDevice` if there's no error also a provisioning extensions that was set by the bank during enrollment process.
 */
- (void)provisionWithTokenDeviceName:(NSString *)tokenDeviceName
                    registrationCode:(NSString *)registrationCode
                        dcvvSettings:(EMProtectorDcvvSettings *)dcvvSettings
                  optionalParameters:(nullable void(^)(EMProvisionerOptionalParameters *))optionalParameters
                   completionHandler:(void(^)(EMProtectorOathTokenDevice * _Nullable tokenDevice, NSDictionary * _Nullable extensions, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(provision(tokenDeviceName:registrationCode:dcvvSettings:optionalParameters:completionHandler:));

/**
 Store the previously used `OathSettings` into a storage so it can be use later during otp generation.
 Only useful when upgrading from previous version of Mobile Protector SDK.
 
 @param tokenDeviceName       The token device name.
 @param totpSettings          The Time-based OTP settings that should be the same as the policy on the authentication server. This settings are persisted and will be used later by OTP generation.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return `YES` if the succeeded. Otherwise `NO`
 */
- (BOOL)persistSettingsWithTokenDeviceName:(NSString *)tokenDeviceName
                              totpSettings:(EMProtectorTotpSettings *)totpSettings
                                     error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(persistSettings(tokenDeviceName:totpSettings:)) __attribute__((deprecated("This API is deprecated since 6.0. Use 'tokenDeviceWithName:fingerprintCustomData:totpSettings:error' or 'tokenDeviceWithUserTokenID:fingerprintCustomData:totpSettings:error' instead.")));

/**
 Store the previously used `OathSettings` into a storage so it can be use later during otp generation.
 Only useful when upgrading from previous version of Mobile Protector SDK.
 
 @param tokenDeviceName       The token device name.
 @param hotpSettings          The Event-based OTP settings that should be the same as the policy on the authentication server. This settings are persisted and will be used later by OTP generation.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return `YES` if the succeeded. Otherwise `NO`
 */
- (BOOL)persistSettingsWithTokenDeviceName:(NSString *)tokenDeviceName
                              hotpSettings:(EMProtectorHotpSettings *)hotpSettings
                                     error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(persistSettings(tokenDeviceName:hotpSettings:)) __attribute__((deprecated("This API is deprecated since 6.0. Use 'tokenDeviceWithName:fingerprintCustomData:hotpSettings:error' or 'tokenDeviceWithUserTokenID:fingerprintCustomData:hotpSettings:error' instead.")));

/**
 Store the previously used `OathSettings` into a storage so it can be use later during otp generation.
 Only useful when upgrading from previous version of Mobile Protector SDK.
 
 @param tokenDeviceName       The token device name.
 @param ocraSettings          The OCRA OTP settings that should be the same as the policy on the authentication server. This settings are persisted and will be used later by OTP generation.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return `YES` if the succeeded. Otherwise `NO`
 */
- (BOOL)persistSettingsWithTokenDeviceName:(NSString *)tokenDeviceName
                              ocraSettings:(EMProtectorOcraSettings *)ocraSettings
                                     error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(persistSettings(tokenDeviceName:ocraSettings:)) __attribute__((deprecated("This API is deprecated since 6.0. Use 'tokenDeviceWithName:fingerprintCustomData:ocraSettings:error' or 'tokenDeviceWithUserTokenID:fingerprintCustomData:ocraSettings:error' instead.")));

/**
 Store the previously used `OathSettings` into a storage so it can be use later during otp generation.
 Only useful when upgrading from previous version of Mobile Protector SDK.
 
 @param tokenDeviceName       The token device name.
 @param dcvvSettings          The Time-based OTP settings that should be the same as the policy on the authentication server. This settings are persisted and will be used later by OTP generation.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return `YES` if the succeeded. Otherwise `NO`
 */
- (BOOL)persistSettingsWithTokenDeviceName:(NSString *)tokenDeviceName
                              dcvvSettings:(EMProtectorDcvvSettings *)dcvvSettings
                                     error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(persistSettings(tokenDeviceName:dcvvSettings:)) __attribute__((deprecated("This API is deprecated since 6.0. Use 'tokenDeviceWithName:fingerprintCustomData:dcvvSettings:error' or 'tokenDeviceWithUserTokenID:fingerprintCustomData:dcvvSettings:error' instead.")));

/**
 Retrieve the `EMProtectorOathTokenDevice` with given name and settings.
 @param tokenDeviceName       The token device name.
 @param fingerprintCustomData  The fingerprint custom data. This data is mandatory if the `EMFastTrackDeviceFingerprintSource customData` is set on `EMProvisionerOptionalParameters` during provisioning.
 @param dcvvSettings          The Time-based OTP settings that should be the same as the policy on the authentication server.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return The `EMProtectorOathTokenDevice` object
 - Since: 6.0
 */
- (nullable EMProtectorOathTokenDevice *)tokenDeviceWithName:(NSString *)tokenDeviceName
                                       fingerprintCustomData:(nullable NSData *)fingerprintCustomData
                                                dcvvSettings:(EMProtectorDcvvSettings *)dcvvSettings
                                                       error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(tokenDevice(name:fingerprintCustomData:dcvvSettings:));

/**
 Retrieve the `EMProtectorOathTokenDevice` with user token ID and settings.
 @param userTokenID           The userTokenID
 @param fingerprintCustomData  The fingerprint custom data. This data is mandatory if the `EMFastTrackDeviceFingerprintSource customData` is set on `EMProvisionerOptionalParameters` during provisioning.
 @param dcvvSettings          The Time-based OTP settings that should be the same as the policy on the authentication server.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return The `EMProtectorOathTokenDevice` object
 - Since: 6.0
 */
- (nullable EMProtectorOathTokenDevice *)tokenDeviceWithUserTokenID:(int)userTokenID
                                              fingerprintCustomData:(nullable NSData *)fingerprintCustomData
                                                       dcvvSettings:(EMProtectorDcvvSettings *)dcvvSettings
                                                              error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(tokenDevice(userTokenID:fingerprintCustomData:dcvvSettings:));

/**
 Retrieve the `EMProtectorOathTokenDevice` with given name and settings.
 @param tokenDeviceName       The token device name.
 @param fingerprintCustomData  The fingerprint custom data. This data is mandatory if the `EMFastTrackDeviceFingerprintSource customData` is set on `EMProvisionerOptionalParameters` during provisioning.
 @param hotpSettings          The Event-based OTP settings that should be the same as the policy on the authentication server.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return The `EMProtectorOathTokenDevice` object
 - Since: 6.0
 */
- (nullable EMProtectorOathTokenDevice *)tokenDeviceWithName:(NSString *)tokenDeviceName
                                       fingerprintCustomData:(nullable NSData *)fingerprintCustomData
                                                hotpSettings:(EMProtectorHotpSettings *)hotpSettings
                                                       error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(tokenDevice(name:fingerprintCustomData:hotpSettings:));

/**
 Retrieve the `EMProtectorOathTokenDevice` with user token ID and settings.
 @param userTokenID           The userTokenID
 @param fingerprintCustomData  The fingerprint custom data. This data is mandatory if the `EMFastTrackDeviceFingerprintSource customData` is set on `EMProvisionerOptionalParameters` during provisioning.
 @param hotpSettings          The Event-based OTP settings that should be the same as the policy on the authentication server.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return The `EMProtectorOathTokenDevice` object
 - Since: 6.0
 */
- (nullable EMProtectorOathTokenDevice *)tokenDeviceWithUserTokenID:(int)userTokenID
                                              fingerprintCustomData:(nullable NSData *)fingerprintCustomData
                                                       hotpSettings:(EMProtectorHotpSettings *)hotpSettings
                                                              error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(tokenDevice(userTokenID:fingerprintCustomData:hotpSettings:));


/**
 Retrieve the `EMProtectorOathTokenDevice` with given name and settings.
 @param tokenDeviceName       The token device name.
 @param fingerprintCustomData  The fingerprint custom data. This data is mandatory if the `EMFastTrackDeviceFingerprintSource customData` is set on `EMProvisionerOptionalParameters` during provisioning.
 @param totpSettings          The Time-based OTP settings that should be the same as the policy on the authentication server.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return The `EMProtectorOathTokenDevice` object
 - Since: 6.0
 */
- (nullable EMProtectorOathTokenDevice *)tokenDeviceWithName:(NSString *)tokenDeviceName
                                       fingerprintCustomData:(nullable NSData *)fingerprintCustomData
                                                totpSettings:(EMProtectorTotpSettings *)totpSettings
                                                       error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(tokenDevice(name:fingerprintCustomData:totpSettings:));

/**
 Retrieve the `EMProtectorOathTokenDevice` with user token ID and settings.
 @param userTokenID           The userTokenID
 @param fingerprintCustomData  The fingerprint custom data. This data is mandatory if the `EMFastTrackDeviceFingerprintSource customData` is set on `EMProvisionerOptionalParameters` during provisioning.
 @param totpSettings          The Time-based OTP settings that should be the same as the policy on the authentication server.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return The `EMProtectorOathTokenDevice` object
 - Since: 6.0
 */
- (nullable EMProtectorOathTokenDevice *)tokenDeviceWithUserTokenID:(int)userTokenID
                                              fingerprintCustomData:(nullable NSData *)fingerprintCustomData
                                                       totpSettings:(EMProtectorTotpSettings *)totpSettings
                                                              error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(tokenDevice(userTokenID:fingerprintCustomData:totpSettings:));


/**
 Retrieve the `EMProtectorOathTokenDevice` with given name and settings.
 @param tokenDeviceName       The token device name.
 @param fingerprintCustomData  The fingerprint custom data. This data is mandatory if the `EMFastTrackDeviceFingerprintSource customData` is set on `EMProvisionerOptionalParameters` during provisioning.
 @param ocraSettings          The OCRA OTP settings that should be the same as the policy on the authentication server.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return The `EMProtectorOathTokenDevice` object
 - Since: 6.0
 */
- (nullable EMProtectorOathTokenDevice *)tokenDeviceWithName:(NSString *)tokenDeviceName
                                       fingerprintCustomData:(nullable NSData *)fingerprintCustomData
                                                ocraSettings:(EMProtectorOcraSettings *)ocraSettings
                                                       error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(tokenDevice(name:fingerprintCustomData:ocraSettings:));

/**
 Retrieve the `EMProtectorOathTokenDevice` with user token ID and settings.
 @param userTokenID           The userTokenID
 @param fingerprintCustomData  The fingerprint custom data. This data is mandatory if the `EMFastTrackDeviceFingerprintSource customData` is set on `EMProvisionerOptionalParameters` during provisioning.
 @param ocraSettings          The OCRA OTP settings that should be the same as the policy on the authentication server.
 @param error                 If an error occurs, upon return contains an `NSError` object that describes the problem
 @return The `EMProtectorOathTokenDevice` object
 - Since: 6.0
 */
- (nullable EMProtectorOathTokenDevice *)tokenDeviceWithUserTokenID:(int)userTokenID
                                              fingerprintCustomData:(nullable NSData *)fingerprintCustomData
                                                       ocraSettings:(EMProtectorOcraSettings *)ocraSettings
                                                              error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(tokenDevice(userTokenID:fingerprintCustomData:ocraSettings:));



@end

NS_ASSUME_NONNULL_END
