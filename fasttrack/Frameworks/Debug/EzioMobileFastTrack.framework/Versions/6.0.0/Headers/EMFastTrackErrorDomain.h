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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wstrict-prototypes"

NS_ASSUME_NONNULL_BEGIN

/**
 FastTrack Error Domain
 */
extern NSErrorDomain EMFastTrackErrorDomain;

/**
 List of error code for FastTrack
 * - Since: 5.3
 */
typedef NS_ERROR_ENUM(EMFastTrackErrorDomain, EMFastTrackErrorCode)
{
    
#pragma mark Generic Error
    /**
     * This error occurs when the caller passed an invalid argument (e.g. null or empty string) into a function
    */
    EMFastTrackErrorCodeInvalidArgument                       = -100,
    
    /**
     * Internal Failure, most likely due to storage
     */
    EMFastTrackErrorCodeInternalFailure                       = -101,
    
    /**
     * Device Fingerprint failure, most likely due to invalid configuration on CustomData
     */
    EMFastTrackErrorCodeDeviceFingerprint                     = -102,
    
    /**
     * Device Fingerprint update failure, e.g. token not found, invalid configuration on CustomData
     * - Since: 5.4.0
     */
    EMFastTrackErrorCodeUpdateDeviceFingerprintFailure        = -103,
    
    /**
     * Device Fingerprint update failure, if new device fingerprint is identical.
     * - Since: 5.4.0
     */
    EMFastTrackErrorCodeUpdateDeviceFingerprintIdentical      = -104,

#pragma mark OTP Error
    
    /**
     * Failed in provision Token
     */
    EMFastTrackErrorCodeOtpProvisionFailure                   = -200,
    
    /**
     * Failed in generating OTP
     */
    EMFastTrackErrorCodeOtpGenerationFailure                  = -201,

    /**
     * Violation of Pin Rule on changePin operation
     */
    EMFastTrackErrorCodePinRuleViolation                      = -202,
    
    /**
     * OTP Settings not found.
     * If OTP has been provisioned previously using IDP Mobile SDK, please invoke any of the following functions:
     * @see <code>-[EMCapMobileProtector persistSettingsWithTokenDeviceName:capSettings:error:]</code>
     * @see <code>-[EMOathMobileProtector persistSettingsWithTokenDeviceName:totpSettings:error:]</code>
     * @see <code>-[EMOathMobileProtector persistSettingsWithTokenDeviceName:hotpSettings:error:]</code>
     * @see <code>-[EMOathMobileProtector persistSettingsWithTokenDeviceName:ocraSettings:error:]</code>
     * @see <code>-[EMOathMobileProtector persistSettingsWithTokenDeviceName:dcvvSettings:error:]</code>
     */
    EMFastTrackErrorCodeOtpSettingsNotFound                   = -203,
    
#pragma mark System Biometric
    
    /** SystemBiometric is not supported by the device.*/
    /** Authentication could not start, because biometric is not available on the device.*/
    /** Authentication could not start, because biometric has no enrolled fingers/face.*/
    EMFastTrackErrorCodeSystemBiometricNotSupported           = -301,
    
    /**SystemBiometric is not enrolled on the device. If BioFingerprint/face is supported, the application
     * should prompt the user to enroll fingerprint/face from device->Settings.*/
    EMFastTrackErrorCodeSystemBiometricNotConfigured          = -302,
    
    /** SystemBiometric mode has not been activated for the tokenDevice.*/
    EMFastTrackErrorCodeSystemBiometricNotActivated           = -303,
    
    /** Authentication attempt fails. The application integrator can prompt user to try again.*/
    EMFastTrackErrorCodeSystemBiometricAuthenticationFaied    = -304,
    
    /** Authentication was not successful, because there were too many failed Touch ID attempts and
    Touch ID is now locked. Passcode is required to unlock Touch ID, e.g. evaluating
    LAPolicyDeviceOwnerAuthenticationWithBiometrics will ask for passcode as a prerequisite.*/
    EMFastTrackErrorCodeSystemBiometricAuthenticationBlocked  = -305,
    
    /** Authentication was canceled by application/user/system/user callback*/
    EMFastTrackErrorCodeSystemBiometricCancelled              = -306,
    
    /** Authentication was canceled, because the user tapped the fallback button (Enter Password).*/
    EMFastTrackErrorCodeSystemBiometricCancelledUserFallback   = -307,
    
#pragma mark Mobile Messenger

    /**
     * Mobile messenger - Invalid registration code
     */
    EMFastTrackErrorCodeInvalidRegistrationCode               = -400,
    
    /**
     * Mobile messenger - Invalid request parameter
     */
    EMFastTrackErrorCodeInvalidRequestParameter               = -401,

    /**
     * Mobile messenger - network failure
     */
    EMFastTrackErrorCodeNetworkFailure                        = -402,

    /**
     * Mobile messenger - Invalid operation
     */
    EMFastTrackErrorCodeInvalidOperation                      = -403,

    /**
     * Mobile messenger - Invalid message state
     */
    EMFastTrackErrorCodeInvalidMessageState                   = -404,
    

#pragma mark Mobile Messenger Transaction Signing parsing MSP
    
    /**
     * Mobile messenger failure on fetch TransactionSigningRequest message. Occours when then signing content is not
     * correctly formatted.
     */
    EMFastTrackErrorCodeTransactionInvalidData                = -500,
    
    /**
     * Mobile messenger failure on fetch TransactionSigningRequest message. Occur when the signing content is not
     * signed with the correct key, or publicKey provided by the application is incorrect.
     */
    EMFastTrackErrorCodeTransactionInvalidSignature           = -501,
    
    /**
     * Mobile messenger failure on fetch TransactionSigningRequest message. Occurs when then signing content is not
     * obfuscated with the correct key, or the obfuscation key provided by the application is incorrect.
     */
    EMFastTrackErrorCodeTransactionDeobfuscationFailure       = -502
};

/**
 Token management error domain.
 */
extern NSString *FASTTRACK_ERROR_DOMAIN_TOKEN_MANAGEMENT;

/**
 OTP generation error domain.
 */
extern NSString *FASTTRACK_ERROR_DOMAIN_OTP_GENERATION;

/**
 Change PIN error domain.
 */
extern NSString *FASTTRACK_ERROR_DOMAIN_CHANGE_PIN;

/**
 Mobile messenger error domain.
 */
extern NSString *FASTTRACK_ERROR_DOMAIN_MOBILE_MESSENGER;

/**
 Biometric error domain.
 */
extern NSString *FASTTRACK_ERROR_DOMAIN_BIOMETRIC;

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop
