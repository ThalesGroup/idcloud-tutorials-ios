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
#import "EMFastTrackDeviceFingerprintSource.h"
#import "EMMobileProtector.h"
#import "EMProtectorAuthInput.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The interface Token Device.
 * - Since: 5.3
 */
@interface EMProtectorTokenDevice: NSObject

/**
 * Performs a change PIN on current TokenDevice with NSString Inputs.
 * <p>
 *
 * @param oldPin            Current Pin value.
 * @param newPin            New Pin value.
 * @param error              If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * object containing the error information.  Possible errors are:
 * - EMPinRuleErrorDomain when the new PIN does not comply with the configured
 * PIN rules.
 * @return `YES` if the operation is succeeded. Otherwise `NO`.
 */
- (BOOL)changePinWithOldPin:(NSString *)oldPin
                     newPin:(NSString *)newPin
                      error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(changePin(oldPin:newPin:));


/**
 * Performs a change PIN on current TokenDevice with EMProtectorAuthInput .
 * <p>
 *
 * @param oldPinAuthInput            Current Pin value.
 * @param newPinAuthInput            New Pin value.
 * @param error              If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * object containing the error information.  Possible errors are:
 * - EMPinRuleErrorDomain when the new PIN does not comply with the configured
 * PIN rules.
 * Throw run time exception if the wrap EMProtectorAuthInput is not from EMPinAuthInput
 * @return `YES` if the operation is succeeded. Otherwise `NO`.
 * - Since: 6.0
 */
- (BOOL)changePinWithOldPinAuthInput:(EMProtectorAuthInput *)oldPinAuthInput
                     newPinAuthInput:(EMProtectorAuthInput *)newPinAuthInput
                               error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(changePin(oldPinAuthInput:newPinAuthInput:));

/**
 Return a type of OTP. This value is based on the OTP settings that was configured during provisioning.
 
 @return `EMOtpType` enum value
 */
- (EMOtpType)otpType;

/**
 * Check if System Biometric mode is activated.
 *
 * @return `YES` if Biometric mode is activated. Otherwise `NO`.
 */
- (BOOL)isSystemBiometricModeActivated;

/**
 * Activate System Biometric mode with PIN String.
 *
 * @param pin                 Current pin value.
 * @param error             If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in 'NULL'.
 * @return 'YES' if mode has been activated. Otherwise `NO`.
 */
- (BOOL)activateSystemBiometricModeWithPin:(NSString *)pin
                                     error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(activateSystemBiometricMode(pin:));

/**
 * Activate System Biometric mode pin Auth Input.
 *
 * @param pinAuthInput                 Current pin Auth Input.
 * @param error             If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in 'NULL'.
 * @return 'YES' if mode has been activated. Otherwise `NO`.
 - Since: 6.0
 */
- (BOOL)activateSystemBiometricModeWithAuthInput:(EMProtectorAuthInput *)pinAuthInput
                                           error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(activateSystemBiometricMode(pinAuthInput:));

/**
 * Deactivate system Biometric mode.
 *
 * @param error             If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in 'NULL'.
 * @return 'YES' if mode has been deactivated. Otherwise `NO`.
 */
- (BOOL)deactivateSystemBiometricModeWithError:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(deactivateSystemBiometricMode());

/**
 * Authenticate with system Biometric
 *
 * @param message                the message that will be displayed on Touch ID
 * @param fallbackTitle          the fallback title. If set to empty string, the button will be hidden.
 * @param completionHandler      completion handler to be called with the result once it's completed. Touch ID evaluatedPolicyDomainState data will be returned upon success. [error code] will contain EM_STATUS_AUTHENTICATION_CANCELED_USER_FALLBACK if user tapped the fallback button.
 */
- (void)authenticateWithMessage:(nullable NSString *)message
                  fallbackTitle:(nullable NSString *)fallbackTitle
              completionHandler:(nullable void(^)(EMProtectorAuthInput * _Nullable, NSData*_Nullable, NSError*_Nullable))completionHandler NS_SWIFT_NAME(authenticateWithMessage(localizedMessage:fallbackTitle:completionHandler:));


@end

NS_ASSUME_NONNULL_END
