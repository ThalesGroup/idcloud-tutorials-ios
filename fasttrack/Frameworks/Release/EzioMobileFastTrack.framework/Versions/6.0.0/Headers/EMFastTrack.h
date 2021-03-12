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
#import "EMCapMobileProtector.h"
#import "EMOathMobileProtector.h"
#import "EMMobileMessenger.h"
#import "EMTransactionSignatureKey.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A FastTrack optional parameters that is set on `EMFastTrack configureWithOptionalParameters:`
 * - Since: 5.3
 */
@interface EMFastTrackOptionalParameters : NSObject

/**
 The activation code. This value is use to unlock Secure Messenger, VIC Token or Secure PinPad feature.
 This value could be retrieved from Gemalto representative.
 The value is in Hex string format.
 */
@property (nonatomic, strong, nullable) NSString *activationCode;

/**
 If this value is set, the token will tied with the device where the application installed.
 */
@property (nonatomic, assign) BOOL deviceBinding;

/**
 A custom password to set. This password is used to protect Secure Messenger or Secure Storage data.
 If not set then a `default` password will be use.
 */
@property (nonatomic, strong, nullable) NSString *password;

/**
 MSP Obfuscation Keys
 */

@property (nonatomic, strong, nullable) NSArray *obfuscationKeys;

/**
 MSP Signature Keys
 */
@property (nonatomic, strong, nullable) NSArray<EMTransactionSignatureKey *> *signatureKeys;

/**
 Add share group Identifier
 */
@property (nonatomic, strong, nullable) NSString *groupIdentifier;


@end

/**
 FastTrack is the entry-point of the Mobile Protector and Mobile Secure Messenger. FastTrack takes
 the configurations needed for different modules and provides shared SDK functionality.
 * - Since: 5.3
 */
@interface EMFastTrack : NSObject

/**
 Get `EMFastTrack` instance.
 This function can be called after calling `EMFastTrack configureWithOptionalParameters:param1` otherwise will throw `NSInternalInconsistencyException`.

 @return `EMFastTrack` instance.
 */
+ (nullable instancetype)sharedInstance;

/**
 * Configure the secure log. Pass config = nil if you want to disable the logging.
 * This functions should be called before configuring the IDPFastTrack SDK and can only be called once.
 * @param config consist of  public key and setting of SecureLog
 * @return id<SecureLog> the instance of SecureLog - use to interact with SecureLog feature.
 * Throw NSGenericException if the function is called more than once.
 * - Since: 6.0
*/
+ (nullable id<SecureLog>)configureSecureLog:(nullable SecureLogConfig*)config NS_SWIFT_NAME(configureSecureLog(config:));

/**
 Configure the FastTrack.

 @param optionalParameters      The optional parameters, @see `EMFastTrackOptionalParameters`.
 @return Return an instance of `EMFastTrack`.
 */
+ (instancetype)configureWithOptionalParameters:(nullable void(^)(EMFastTrackOptionalParameters *))optionalParameters NS_SWIFT_NAME(configure(optionalParameters:));

/**
 Representation of the physical device's jailbreak status
 @return `YES` if the device is jailbroken otherwise `NO`
 */
+ (BOOL)isJailbroken;

/**
 * Get the state if FastTrack has been configured previously.
 * @return true if it has been configured, false otherwise
 */
+ (BOOL)isConfigured;

/**
 Construct an `EMOathMobileProtector` object.

 @param url                     The URL of the provisioning API endpoint, e.g: for EPS 2.x: `http(s)://<eps-url>:<eps-port>/provisioner/api/provisioning/pp` and for EPS 3.x: `http(s)://<eps-url>:<eps-port>/provisioner/provision`
 @param domain                  The eps domain for provisioning.
 @param provisioningProtocol    A mobile provisioning protocol.
 @param rsaKeyId                Identifier for the EPS server's public RSA key. The value can be nil for EPS 3.x and above and EMFastTrackProvisioningProtocol is version 5.
 @param rsaExponent             The RSA exponent of the EPS public key (on provisioning protocol level, not transport level).
 @param rsaModulus              The RSA modulus of the EPS public key (on provisioning protocol level, not transport level).
 @param optionalParameters      An optional parameters to be set, @see `EMFastTrackOptionalParameters`.
 @return                        Return an instance of `EMOathMobileProtector`.
 */
- (EMOathMobileProtector *)oathMobileProtectorWithUrl:(NSURL *)url
                                               domain:(nullable NSString *)domain
                                 provisioningProtocol:(EMFastTrackProvisioningProtocol)provisioningProtocol
                                             rsaKeyId:(NSString *)rsaKeyId
                                          rsaExponent:(NSData *)rsaExponent
                                           rsaModulus:(NSData *)rsaModulus
                                   optionalParameters:(nullable void(^)(EMMobileProtectorOptionalParameters *))optionalParameters NS_SWIFT_NAME(oathMobileProtector(url:domain:provisioningProtocol:rsaKeyId:rsaExponent:rsaModulus:optionalParameters:));

/**
 Construct an `EMCapMobileProtector` object.
 
 @param url                     The URL of the provisioning API endpoint, e.g: for EPS 2.x: `http(s)://<eps-url>:<eps-port>/provisioner/api/provisioning/pp` and for EPS 3.x: `http(s)://<eps-url>:<eps-port>/provisioner/provision`
 @param domain                  The eps domain for provisioning.
 @param provisioningProtocol    A mobile provisioning protocol.
 @param rsaKeyId                Identifier for the EPS server's public RSA key. The value can be nil for EPS 3.x and above and EMFastTrackProvisioningProtocol is version 5.
 @param rsaExponent             The RSA exponent of the EPS public key (on provisioning protocol level, not transport level).
 @param rsaModulus              The RSA modulus of the EPS public key (on provisioning protocol level, not transport level).
 @param optionalParameters      An optional parameters to be set, @see `EMFastTrackOptionalParameters`.
 @return                        Return an instance of `EMCapMobileProtector`.
 */
- (EMCapMobileProtector *)capMobileProtectorWithUrl:(NSURL *)url
                                             domain:(nullable NSString *)domain
                               provisioningProtocol:(EMFastTrackProvisioningProtocol)provisioningProtocol
                                           rsaKeyId:(NSString *)rsaKeyId
                                        rsaExponent:(NSData *)rsaExponent
                                         rsaModulus:(NSData *)rsaModulus
                                 optionalParameters:(nullable void(^)(EMMobileProtectorOptionalParameters *))optionalParameters  NS_SWIFT_NAME(capMobileProtector(url:domain:provisioningProtocol:rsaKeyId:rsaExponent:rsaModulus:optionalParameters:));

/**
 Construct an `EMMobileMessenger` object.

 @param url                     The URL of the OOB server.
 @param domain                  The domain to use for requests to the OOB server. It must be compliant with server configuration on back-end side.
 @param applicationId           The application identifier use to communicate with the OOB server.
 @param rsaExponent             The RSA public exponent to use to communicate with the OOB server.
 @param rsaModulus              The RSA modules to use to communicate with the OOB server.
 @param optionalParameters      An optional parameters to be set, @see `EMMobileMessengerOptionalParameters`.
 @param error                   If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return                        Return an instance of `EMMobileMessenger` or `nil`.
 */
- (nullable EMMobileMessenger *)mobileMessengerWithUrl:(NSURL *)url
                                                domain:(NSString *)domain
                                         applicationId:(NSString *)applicationId
                                           rsaExponent:(NSData *)rsaExponent
                                            rsaModulus:(NSData *)rsaModulus
                                    optionalParameters:(nullable void(^)(EMMobileMessengerOptionalParameters *))optionalParameters
                                                 error:(NSError * _Nullable * _Nullable)error
NS_SWIFT_NAME(mobileMessenger(url:domain:applicationId:rsaExponent:rsaModulus:optionalParameters:));

/**
 * The version of the SDK.
 *
 * @return Version of the SDK.
 */
+ (NSString *)version;


+ (void)performMigrationWithAlertMessage:(NSString *)message completion:(void(^)(BOOL success, NSError *error))completion;

+ (void)dumpKeychain;
@end

NS_ASSUME_NONNULL_END
