/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2016  -  GEMALTO DEVELOPMENT - R&D
 *
 * -----------------------------------------------------------------------------
 * GEMALTO MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF
 * THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, OR NON-INFRINGEMENT. GEMALTO SHALL NOT BE
 * LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
 * MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
 *
 * THIS SOFTWARE IS NOT DESIGNED OR INTENDED FOR USE OR RESALE AS ON-LINE
 * CONTROL EQUIPMENT IN HAZARDOUS ENVIRONMENTS REQUIRING FAIL-SAFE
 * PERFORMANCE, SUCH AS IN THE OPERATION OF NUCLEAR FACILITIES, AIRCRAFT
 * NAVIGATION OR COMMUNICATION SYSTEMS, AIR TRAFFIC CONTROL, DIRECT LIFE
 * SUPPORT MACHINES, OR WEAPONS SYSTEMS, IN WHICH THE FAILURE OF THE
 * SOFTWARE COULD LEAD DIRECTLY TO DEATH, PERSONAL INJURY, OR SEVERE
 * PHYSICAL OR ENVIRONMENTAL DAMAGE ("HIGH RISK ACTIVITIES"). GEMALTO
 * SPECIFICALLY DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTY OF FITNESS FOR
 * HIGH RISK ACTIVITIES.
 *
 * -----------------------------------------------------------------------------
 */


#import <Foundation/Foundation.h>
#import "EMSecureString.h"
#import "EMSecureByteArray.h"
#import "EMPinAuthInput.h"
#import "EMTlsConfiguration.h"
#import "EMDskppTlsConfiguration.h"
#import "EMDskppProvisioningCallback.h"

/** The supported Provisioning protocols 
 */
typedef NS_ENUM(int, EMMobileProvisioningProtocol)
{
    /** Provisioning protocol version 1 */
    EMMobileProvisioningProtocolVersion1 = 1,
    /** Provisioning protocol version 2 */
    EMMobileProvisioningProtocolVersion2 = 2,
    /** Provisioning protocol version 3 */
    EMMobileProvisioningProtocolVersion3 = 3,
    /** Provisioning protocol version 5 */
    EMMobileProvisioningProtocolVersion5 = 5
};

/** The supported Dskpp Provisioning protocols 
 * - Since: 4.1
 */
typedef NS_ENUM(int, EMDskppProvisioningProtocol)
{
    /** Provisioning protocol version 3 */
    EMDskppProvisioningProtocolVersion1 = 4
};

/**
 * EPS Configuration Builder
 */
@interface EMEpsConfigurationBuilder : NSObject

/**
 * The HTTP Headers to be added in the HTTP request.
 */
@property NSDictionary *headers;

/**
 * Gets/Sets the transport layer security configuration for the connection. This may be used for test environments where the security of the system is not a concern (e.g. using insecure HTTP connections). See EMTlsConfiguration
 * For default instance insecureConnectionAllowed is set to 'NO'
 * selfSignedCertAllowed is set to 'NO'
 * hostnameMismatchAllowed is set to 'NO'
 */
@property EMTlsConfiguration *tlsConfiguration;

@end

/**
 * DSKPP Configuration Builder
 */
@interface EMDskppConfigurationBuilder : NSObject

/**
 * Gets/Sets the transport layer security configuration for the connection. This may be used for test environments where the security of the system is not a concern (e.g. using insecure HTTP connections). See EMDskppTlsConfiguration
 * For default instance insecureConnectionAllowed is set to 'NO'
 * selfSignedCertAllowed is set to 'NO'
 * hostnameMismatchAllowed is set to 'NO'
 *
 * - Since: 4.1
 */
@property EMDskppTlsConfiguration *tlsConfiguration;

/**
 * Set the application name.
 *
 * - Since: 4.1
 */
@property id<EMSecureString> applicationName;

/**
 * Set the application version.
 *
 * - Since: 4.1
 */
@property id<EMSecureString> applicationVersion;

/**
 * Set the parameter version of DSKPP provisioning. default '1'.
 *
 * - Since: 4.1
 */
@property id<EMSecureString> parametersVersion;

/**
 * Set capability. default '6'.
 *
 * - Since: 4.1
 */
@property id<EMSecureString> capability;

/**
 * Set the jailbreak status of the device. default value is 'NO'.
 *
 * - Since: 4.1
 */
@property BOOL jailbreakStatus;

/**
 * Set the security level. eg: "Soft" or "UICC". default to "Soft".
 *
 * - Since: 4.1
 */
@property id<EMSecureString> securityLevel;

/**
 * Set device friendly name. The name will be stored on the back-end server. default "iOS Device".
 *
 * - Since: 4.1
 */
@property id<EMSecureString> deviceFriendlyName;

/**
 * Set device form factor. default "iOS".
 *
 * - Since: 4.1
 */
@property id<EMSecureString> deviceFormFactor;

/**
 * Set OS type. default "iOS".
 *
 * - Since: 4.1
 */
@property id<EMSecureString> osType;

/**
 * Set OS version.
 *
 * - Since: 4.1
 */
@property id<EMSecureString> osVersion;

/**
 * Set if push is capable. default 'NO'.
 *
 * - Since: 4.1
 */
@property BOOL pushCapable;

/**
 * List of tags for sending to a server as DSKPP message <"mpdskpp:AppName","MobilePASS NG">.
 *
 * - Since: 4.1
 */
@property NSDictionary<NSString *, id<EMSecureString>> *listToSend;

/**
 * Set list of tags for parsing DSKPP message and return by responseCallback ex:
 * "mpdskpp:OOBSExtensionType","mpdskpp:PushExtensionType".
 *
 * - Since: 4.1
 */
@property NSArray *listToReceive;

@end

/**
 * Clear Text Secret Token Configuration Builder
 *
 * - Since: 4.1
 */
@interface EMClearTextSecretTokenConfigurationBuilder : NSObject

/**
 * If wipePinAndSecret is set to 'YES' then the pin  and secret is wipped after use. Default is set to 'YES'
 *
 *  - Since: 4.0
 */
@property BOOL wipePinAndSecret;

/**
 * Returns the User Token Identifier (UTI).
 *
 * The UTI is an unsigned value ranging from 0x00 to 0xFF (i.e. 0 to 255).
 * It is generated by the provisioning server and is part of the credential
 * pushed during provisioning. It is guaranteed that two tokens for the
 * same end-user (on authentication server) and from the same EPS domain
 * will never have the same UTI. See the Enrollment and Provisioning Server
 * documentation for domains configuration description.
 *
 * The UTI is defined only if the token has been created with Provisioning
 * Protocol V3.  When the token has been created with Provisioning Protocol
 * V1 or V2 the method returns -1.
 *
 * Default is set to '0x01'
 *
 * - Since: 4.0
 */
@property int userTokenId;

/**
 * Gets the token sequence number that distinguishes this token among others
 * the users has.
 *
 * The token sequence number is defined only for CAP tokens and is an
 * unsigned value ranging from 0x00 to 0x63 (i.e. 0 to 99). For OATH
 * tokens, the method always return 0xFF (i.e. 255).
 *
 * Default is set to '0xFF'
 *
 * - Since: 4.0
 */
@property int tokenSequenceNumber;

/**
 * The provisioning protocol to use when decoding the credentials.
 *
 * Default is set to 'EMProvisioningProtocolVersion3'
 *
 * - Since: 4.0
 */
@property EMMobileProvisioningProtocol provisioningProtocol;

@end


/**
 * The provisioning configuration
 */
@interface EMProvisioningConfiguration : NSObject

/**
 * Wipes internal state of secure container objects.
 */
- (void)wipe;


/**
 * Creates EMProvisioningConfiguration. This instance is used to create a token from a legacy 1.x credential blob.
 * @param codeGeneratorData Code Generation Data blob created by previous Mobile Protector SDK.
 * @param deviceUniqueData Device Unique Data that the codeGeneratorData is protected under. Provide `nil` if no such data.
 * @param simCardUniqueData SIM Card Unique Data that the codeGeneratorData is protected under. Provide `nil` if no such data.
 * @param provisioningProtocol The provisioning protocol to use when decoding the credentials.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. error will belong to the `EMLegacyTokenErrorDomain` and contain a `EMLegacyTokenErrorCode`. If you are not interested in possible errors, you may pass in `NULL`.
 * @return EMProvisioningConfiguration instance.
 *
 * - Since: 4.0
 */
+ (EMProvisioningConfiguration *)legacyTokenConfigurationWithCodeGeneratorData:(id<EMSecureByteArray>)codeGeneratorData
                                                              deviceUniqueData:(id<EMSecureByteArray>)deviceUniqueData
                                                             simCardUniqueData:(id<EMSecureByteArray>)simCardUniqueData
                                                          provisioningProtocol:(EMMobileProvisioningProtocol)provisioningProtocol
                                                                         error:(NSError **)error;

/**
 * Creates EMProvisioningConfiguration. This instance is used for creation of clear text secret token import.
 * @param pin The pin to be used for wrapping the secret. The value stored in this array will be wiped by the constructor if 'wipePinAndSecret' is set to 'YES'.
 * @param secret The clear text secret seed or key to be provisioned in the SDK. The value stored in this array will be wiped by the constructor if in optionalParameters'wipePinAndSecret' is set to 'YES'.
 * @param optionalParameters Block where optional parameters set. See the EMClearTextSecretTokenConfigurationBuilder class for more details about the parameters and there optiona values.
 * @return EMProvisioningConfiguration instance.
 *
 * - Since: 4.0
 */
+ (EMProvisioningConfiguration *)clearTextSeedImportConfigurationWithPin:(id<EMPinAuthInput>)pin
                                                                  secret:(id<EMSecureByteArray>)secret
                                                      optionalParameters:(void(^)(EMClearTextSecretTokenConfigurationBuilder *))optionalParameters;

/**
 * Creates offline EMProvisioningConfiguration.
 * @param sessionKey key to decrypt the provisioning response
 * @param hmacKey key to authenticate the provisioning response.
 * @param provisioningResponse the provisioning response from EPS
 * @param provisioningProtocol The provisioning protocol to use when decoding the credentials. 
 * @warning: Must be version 3.
 * @return EMProvisioningConfiguration instance.
 * - Since: 4.0
 */
+ (EMProvisioningConfiguration *)offlineTokenConfigurationWithSessionKey:(id<EMSecureByteArray>)sessionKey
                                                             withHmacKey:(id<EMSecureByteArray>)hmacKey
                                                    provisioningResponse:(id<EMSecureByteArray>)provisioningResponse
                                                    provisioningProtocol:(EMMobileProvisioningProtocol)provisioningProtocol;

/**
 * Creates offline EMProvisioningConfiguration.
 * @param sessionKey key to decrypt the provisioning response
 * @param provisioningResponse the provisioning response from EPS
 * @param provisioningProtocol The provisioning protocol to use when decoding the credentials. Must be version 2 or lower.
 * @return EMProvisioningConfiguration instance.
 * - Since: 4.0
 */
+ (EMProvisioningConfiguration *)offlineTokenConfigurationWithSessionKey:(id<EMSecureByteArray>)sessionKey
                                                    provisioningResponse:(id<EMSecureByteArray>)provisioningResponse
                                                    provisioningProtocol:(EMMobileProvisioningProtocol)provisioningProtocol;

/**
 * Creates EMProvisioningConfiguration. This instance to modify Eps configuration.
 * @warning This API does not support Mobile Provisioning Protocol version 5
 * @param url The URL of the Enrollment API endpoint, e.g:
 *
 * - http(s)://&lt;host&gt;:&lt;port&gt;/EnrolmentServlet/GetAppCredentials for EPS 1.x
 * - http(s)://&lt;host&gt;:&lt;port&gt;/provisioner/api/provisioning/pp for EPS 2.x
 *
 * @param rsaKeyId Identifier for the EPS server's public RSA key.
 * @param rsaExponent The RSA exponent of the EPS public key (on provisioning protocol level, not transport level).
 * @param rsaModulus The RSA modulus of the EPS public key (on provisioning protocol level, not transport level).
 * @param registrationCode The registration code. Minimum registration code length is 2, and maximum registration code length is 14.
 * @param provisioningProtocol The provisioning protocol to use when decoding the credentials.
 * @param optionalParameters Block where optional parameters set. See the EMEpsConfigurationBuilder class for more details about the parameters and there optional values.
 * @return EMProvisioningConfiguration instance.
 *
 * - Since: 4.0
 */
+ (EMProvisioningConfiguration *)epsConfigurationWithURL:(NSURL *)url
                                                rsaKeyId:(NSString *)rsaKeyId
                                             rsaExponent:(NSData *)rsaExponent
                                              rsaModulus:(NSData *)rsaModulus
                                        registrationCode:(id <EMSecureString>)registrationCode
                                    provisioningProtocol:(EMMobileProvisioningProtocol)provisioningProtocol
                                      optionalParameters:(void(^)(EMEpsConfigurationBuilder *))optionalParameters;

/**
 * Creates EMProvisioningConfiguration. This instance to modify Eps configuration.
 * Use this API for Mobile Provisioning Protocol version 5
 * @param url The URL of the Enrollment API endpoint, e.g:
 *
 * - http(s)://&lt;host&gt;:&lt;port&gt;/EnrolmentServlet/GetAppCredentials for EPS 1.x
 * - http(s)://&lt;host&gt;:&lt;port&gt;/provisioner/api/provisioning/pp for EPS 2.x
 * - http(s)://&lt;host&gt;:&lt;port&gt;/provisioner/domains/DomainName/provision for EPS 3.x with PPv5
 *
 * @param domain for EPS. This domain can only be use when EMMobileProvisioningProtocol set to `EMMobileProvisioningProtocolVersion5` and above as well as when EPS that is being use is version 3 and above. Otherwise, this domain can be put `nil` or empty.
 * @param rsaKeyId Identifier for the EPS server's public RSA key.
 * @param rsaExponent The RSA exponent of the EPS public key (on provisioning protocol level, not transport level).
 * @param rsaModulus The RSA modulus of the EPS public key (on provisioning protocol level, not transport level).
 * @param registrationCode The registration code. Minimum registration code length is 2, and maximum registration code length is 14.
 * @param provisioningProtocol The provisioning protocol to use when decoding the credentials.
 * @param optionalParameters Block where optional parameters set. See the EMEpsConfigurationBuilder class for more details about the parameters and there optional values.
 * @return EMProvisioningConfiguration instance.
 *
 * - Since: 5.0
 */
+ (EMProvisioningConfiguration *)epsConfigurationWithURL:(NSURL *)url
                                                  domain:(NSString *)domain
                                                rsaKeyId:(NSString *)rsaKeyId
                                             rsaExponent:(NSData *)rsaExponent
                                              rsaModulus:(NSData *)rsaModulus
                                        registrationCode:(id <EMSecureString>)registrationCode
                                    provisioningProtocol:(EMMobileProvisioningProtocol)provisioningProtocol
                                      optionalParameters:(void(^)(EMEpsConfigurationBuilder *))optionalParameters;

/**
 * Creates EMProvisioningConfiguration. This configuration is used for DSKPP provisioning.
 * @param url The URL of the Enrollment API endpoint.
 * @param uid User identifier for DSKPP provisioning.
 * @param password Password for DSKPP provisioning.
 * @param dskppCallback The callback to be called during stages of DKSPP provisioning. 
 *      All the callbacks will be invoked in the main thread.
 * @param provisioningProtocol The provisioning protocol to use when decoding the credentials.
 * @param shouldWipe If YES, user identifier and password will be wiped upon completion.
 * @param optionalParameters Block where optional parameters set. See the EMDskppConfigurationBuilder class for more details about the parameters and there optiona values.
 * @return EMProvisioningConfiguration instance.
 *
 * - Since: 4.1
 */
+ (EMProvisioningConfiguration *)dskppConfigurationWithUrl:(NSURL *)url
                                                       uid:(id<EMSecureString>)uid
                                                  password:(id<EMSecureString>)password
                                             dskppCallback:(EMDskppProvisioningCallback *)dskppCallback
                                      provisioningProtocol:(EMDskppProvisioningProtocol)provisioningProtocol
                               shouldWipeUserIdAndPassword:(BOOL)shouldWipe
                                        optionalParameters:(void(^)(EMDskppConfigurationBuilder *))optionalParameters;

/**
 * Creates EMProvisioningConfiguration. This configuration is used for DSKPP provisioning.
 * @param base64 The base64 string for DKSPP provisioning. Contains url uid, and password.
 * @param dskppCallback The callback to be called during stages of DKSPP provisioning.
 *      All the callbacks will be invoked in the main thread.
 * @param provisioningProtocol The provisioning protocol to use when decoding the credentials.
 * @param shouldWipe If YES, base64 string will be wiped upon completion.
 * @param optionalParameters Block where optional parameters set. See the EMDskppConfigurationBuilder class for more details about the parameters and there optiona values.
 * @return EMProvisioningConfiguration instance.
 *
 * - Since: 4.1
 */
+ (EMProvisioningConfiguration *)dskppConfigurationWithBase64:(id<EMSecureString>)base64
                                                dskppCallback:(EMDskppProvisioningCallback *)dskppCallback
                                         provisioningProtocol:(EMDskppProvisioningProtocol)provisioningProtocol
                                         shouldWipeBase64Data:(BOOL)shouldWipe
                                           optionalParameters:(void(^)(EMDskppConfigurationBuilder *))optionalParameters;

@end
