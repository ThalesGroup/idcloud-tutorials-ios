/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2015  -  GEMALTO DEVELOPMENT - R&D
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
#import "EMAuthMode.h"
#import "EMBioFingerprintAuthService.h"
#import "EMBioFingerprintAuthInput.h"
#import "EMAuthenticatable.h"

/**
 * The biometric fingerprint authentication container.
 *
 * @warning For security, do not subclass this interface.
 * - Since: 3.2
 */
__attribute__((deprecated("This API is deprecated since 4.6, it is replaced with `EMSystemBioFingerprintContainer`")))
@interface EMBioFingerprintContainer : NSObject


/**
 * Designated constructor.
 * Returns the EMBioFingerprintContainer object created using the EMBioFingerprintAuthService
 * <p>
 * @param service the instance of EMBioFingerprintAuthService
 * @return instance of this class
 * - Since: 4.0
 */
+ (instancetype)containerWithBioFingerprintAuthService:(EMBioFingerprintAuthService *)service;


/**
 * Authenticate user by Touch ID, returns an EMBioFingerprintAuthInput object upon success, that can be used to generate OTPs.
 * <p>
 * @param authenticatable the target authenticatable item (e.g. CapToken)
 * @param localizedMessage the message that will be displayed on Touch ID
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return instance of this class
 * - Since: 4.0
 */
- (id<EMBioFingerprintAuthInput>)authenticateUser:(id<EMAuthenticatable>)authenticatable withMessage:(NSString *)localizedMessage error:(NSError **)error;

/**
 * Authenticate user by Touch ID with PIN fallback feature. By using this API, the application could customize the action upon error cases. The completion handler will return an EMBioFingerprintAuthInput object upon success, that can be used to generate OTPs.
 * <p>
 * @warning PIN fallback feature only works on iOS9.0+. [error code] will contains EM_STATUS_AUTHENTICATION_USER_FALLBACK_IS_NOT_SUPPORTED if the application run it on unsupported OS.
 * @param authenticatable the target authenticatable item (e.g. CapToken)
 * @param localizedMessage the message that will be displayed on Touch ID
 * @param fallbackTitle the fallback title. If set to empty string, the button will be hidden.
 * @param completionHandler completion handler to be called with the result once it's completed. [error code] will contain EM_STATUS_AUTHENTICATION_CANCELED_USER_FALLBACK if user tapped the fallback button.
 * - Since: 4.1
 */
- (void)authenticateUser:(id<EMAuthenticatable>)authenticatable withMessage:(NSString *)localizedMessage fallbackTitle:(NSString *)fallbackTitle completionHandler:(void (^)(id<EMBioFingerprintAuthInput> bioFpAuthInput, NSError *error))completionHandler;

/**
 * Authenticate user by Touch ID with PIN fallback feature. By using this API, the application could customize the action upon error cases. The completion handler will return an EMBioFingerprintAuthInput object and Touch ID evaluatedPolicyDomainState upon success. The EMBioFingerprintAuthInput object can be used to generate OTPs.
 * <p>
 *
 * @warning PIN fallback feature only works on iOS9.0+. [error code] will contains EM_STATUS_AUTHENTICATION_USER_FALLBACK_IS_NOT_SUPPORTED if the application run it on unsupported OS.
 * @param authenticatable the target authenticatable item (e.g. CapToken)
 * @param localizedMessage the message that will be displayed on Touch ID
 * @param fallbackTitle the fallback title. If set to empty string, the button will be hidden.
 * @param completionHandler completion handler to be called with the result once it's completed. Touch ID evaluatedPolicyDomainState data will be returned upon success. [error code] will contain EM_STATUS_AUTHENTICATION_CANCELED_USER_FALLBACK if user tapped the fallback button.
 * - Since: 4.1.1
 */
- (void)authenticateUserV2:(id<EMAuthenticatable>)authenticatable withMessage:(NSString *)localizedMessage fallbackTitle:(NSString *)fallbackTitle completionHandler:(void (^)(id<EMBioFingerprintAuthInput> bioFpAuthInput, NSData *evaluatedPolicyDomainState, NSError *error))completionHandler;

/**
 * Cancel biometric fingerprint authentication prompt.
 * <p>
 *
 * - Since: 5.0
 */
- (void) cancelAuthentication;
@end
