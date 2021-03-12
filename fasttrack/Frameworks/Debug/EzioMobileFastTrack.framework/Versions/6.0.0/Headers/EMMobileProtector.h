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
#import "EMProtectorTotpSettings.h"
#import "EMProtectorHotpSettings.h"
#import "EMProtectorDcvvSettings.h"
#import "EMProtectorOcraSettings.h"
#import "EMProtectorCapSettings.h"
#import "EMFastTrackTlsConfiguration.h"
#import "EMFastTrackDeviceFingerprintSource.h"
#import <EzioMobile/EzioMobile.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The enum Otp type.
 *
 * - Since: 5.3
 */
typedef NS_ENUM(NSUInteger, EMOtpType) {
    /**
     * Oath totp otp type.
     */
    EMOtpTypeOathTotp,
    /**
     * Oath hotp otp type.
     */
    EMOtpTypeOathHotp,
    /**
     * Oath dcvv otp type.
     */
    EMOtpTypeOathDcvv,
    /**
     * Oath ocra otp type.
     */
    EMOtpTypeOathOcra,
    /**
     * Cap otp type.
     */
    EMOtpTypeCap
};
/**
 * Supported Provisioning Protocol
 * - Since: 5.3
 */
typedef NS_ENUM(int, EMFastTrackProvisioningProtocol)
{
//    /** Provisioning protocol version 1 */
//    EMFastTrackProvisioningProtocolVersion1 = 1,
//    /** Provisioning protocol version 2 */
//    EMFastTrackProvisioningProtocolVersion2 = 2,
    /** Provisioning protocol version 3 */
    EMFastTrackProvisioningProtocolVersion3 = 3,
    /** Provisioning protocol version 5 */
    EMFastTrackProvisioningProtocolVersion5 = 5
};

/**
 The token policy of the Mobile Protector SDK when the physical device is
 detected as being jailbroken.
 * - Since: 5.3
 */
typedef NS_ENUM(NSInteger, EMMobileProtectorTokenJailbreakPolicy)
{
    /**
     * No action is taken when calling any token operation related method of Mobile Protector SDK
     * even the physical device is jailbroken.
     */
    EMMobileProtectorTokenJailbreakPolicyIgnore,
    
    /** A EMJailbreakError is returned via the error parameter when calling a method in the Mobile Protector SDK that detects if the physical device is jailbroken.
     */
    EMMobileProtectorTokenJailbreakPolicyFail,
    
    /** A EMJailbreakError is returned via the error parameter and the associated token is silently removed when calling a method in the Mobile Protector SDK that detects if the physical device is jailbroken.
     */
    EMMobileProtectorTokenJailbreakPolicyRemoveToken,
    
    /** A EMJailbreakErrorDomain is returned via the error parameter and all tokens are silently
     removed when calling a method in the Mobile Protector SDK that detects if the physical device is jailbroken.
     */
    EMMobileProtectorTokenJailbreakPolicyRemoveAllTokens
    
};


/**
 * The System Biometric type.
 *
 * - Since: 5.3
 */
typedef NS_ENUM(NSUInteger, EMSystemBiometricType) {
    /**
     * Not enrolled or Not Supported
     */
    EMSystemBiometricTypeNotSupport,
    /**
     * System bio fingerprint
     */
    EMSystemBiometricTypeFingerprint,
    /**
     * System Face
     */
    EMSystemBiometricTypeFace
};


/**
 * EMMobileProtector configuration builder.
 * - Since: 5.3
 */
@interface EMMobileProtectorOptionalParameters : NSObject

/**
 * Gets/Sets the policy for Jailbreak detection.
 */
@property (nonatomic, assign) EMMobileProtectorTokenJailbreakPolicy tokenJailbreakPolicy;

@end

/**
 * EMMobileProtector provisioning configuration builder.
 * - Since: 5.3
 */
@interface EMProvisionerOptionalParameters : NSObject

/**
 * The deviceFingerprintSource configuration used to seal the Token data.
 */
@property (nonatomic, strong) EMFastTrackDeviceFingerprintSource *deviceFingerprintSource;

/**
 * The HTTP Headers to be added in the HTTP request.
 */
@property (nonatomic) NSDictionary *customHeaders;

/**
 tlsConguration
 */
@property (nonatomic, strong) EMFastTrackTlsConfiguration *tlsConfiguration;

@end

/**
 * EMMobileProtector represents the entry point to the SDK features related to One-Time-Password computation.
 * - Since: 5.3
 */
@interface EMMobileProtector : NSObject

/**
 * Check System Biometric type
 *
 * @return type of system biometric
 */
- (EMSystemBiometricType)systemBiometricType;

/**
 * Check if System Biometric mode is supported by the device.
 *
 * @return `YES` if the system biometric mode is supported. Otherwise `NO`.
 */
- (BOOL)isSystemBiometricModeSupported;

/**
 * Check if System Biometric has been configured on the device. To use the feature, user has to have device lock screen setup and enrolled at least 1 fingerprint/face.
 *
 * @return `YES` if the system biometric mode is configured. Otherwise `NO`.
 */
- (BOOL)isSystemBiometricModeConfigured;

/**
 Update the old device fingerprint source to new one.
 This API will help to change (add or remove) the TokenDevice properties, such as:
 <ul>
 <li>The custom fingerprint data </li>
 <li>The fingerprint source type 'EMFastTrackDeviceFingerprintSource' </li>
 </ul>
 @param tokenDeviceName             The token device name.
 @param oldFingerprintCustomData  The old fingerprint custom data. This data is mandatory if the `EMFastTrackDeviceFingerprintSource customData` is set on `EMProvisionerOptionalParameters` during provisioning.
 NOTE: The application manages the custom fingerprint data value so that it uses the proper value while retrieving the token, for example, by calling - [EMProtectorCapTokenDevice tokenDeviceWithName:fingerprintCustomData:error]
 @param newDeviceFingerprintSource The new device fingerprint source.
 NOTE: The application has to retrieve the token device object again to update the changes, for example, by calling [EMProtectorCapTokenDevice tokenDeviceWithName:fingerprintCustomData:error]
 @param error                                    If an error occurs, upon return contains an `NSError` object that describes the problem
 @return `YES` if the operation is succeeded. Otherwise `NO`.
 
 - Since: 5.4
 */
- (BOOL)updateDeviceFingerprintSourceWithTokenDeviceName:(NSString *)tokenDeviceName
                                oldFingerprintCustomData:(nullable NSData *)oldFingerprintCustomData
                              newDeviceFingerprintSource:(EMFastTrackDeviceFingerprintSource *)newDeviceFingerprintSource
                                                   error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(updateDeviceFingerprintSource(tokenDeviceName:oldFingerprintCustomData:newDeviceFingerprintSource:));

@end

NS_ASSUME_NONNULL_END
