/** -----------------------------------------------------------------------------
 
 Copyright (c) 2013  -  GEMALTO DEVELOPMENT - R&D
 
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
#import "EMSecureString.h"
#import "EMAuthInput.h"

/**
 * A protocol defining a device that generates OATH based OTPs.
 *
 * - Since: 2.2
 */
@protocol EMOathDevice <NSObject>

/**
 * Gets an event based OTP (HOTP).
 *
 * @param authInput The authInput.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @exception NSInternalInconsistencyException When the associated token has the `EMTokenCapabilityDUAL_SEED` capability since only time based algorithms are supported for this capability. See EMTokenCapability
 * @return The OTP.
 *
 * @warning Depending of the EMAuthInput type you are using, you may have to use this function asynchronously, please @see EMAuthInput for more details
 * - Since: 3.2
 */
- (id<EMSecureString>)hotpWithAuthInput:(id<EMAuthInput>)authInput error:(NSError **)error;

/**
 * Gets a time based OTP (TOTP).
 *
 * @param authInput The authInput.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The OTP.
 * @warning Depending of the EMAuthInput type you are using, you may have to use this function asynchronously, please @see EMAuthInput for more details
 * - Since: 3.2
 */
- (id<EMSecureString>)totpWithAuthInput:(id<EMAuthInput>)authInput error:(NSError **)error;

/**
 * Gets an OCRA OTP.
 *
 * @param authInput The authInput.
 * @param serverChallengeQuestion The server question. mandatory field, cannot be `nil`.
 * @param clientChallengeQuestion The client question, `nil` if not used.
 * @param passwordHash The hash value of password, `nil` if not used. If used, length must be compliant with hash algorithm defined in OCRA device settings.
 * @param session The session data, `nil` if not used.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The OTP.
 *
 * @exception NSInvalidArgumentException When the serverChallengeQuestion or the
 * `clientChallengeQuestion` is longer than the value returned by
 * [EMSoftOathSettings ocraMaximumChallengeQuestionLength].
 * @exception NSInvalidArgumentException When the passwordHash is `nil` but the
 * value returned by [EMSoftOathSettings ocraPasswordHashAlgorithm]
 * is not NONE or when the passwordHash length is not compliant with the
 * value returned by [EMSoftOathSettings ocraPasswordHashAlgorithm].
 * @exception NSInvalidArgumentException When the session is not `nil` but the
 * value returned by [EMSoftOathSettings ocraSessionLength]
 * is `-1` or vice versa.
 * @exception NSInvalidArgumentException When the session's byte length is
 * longer than the value returned by [EMSoftOathSettings ocraSessionLength].
 * @exception NSInvalidArgumentException When the session cannot be decoded using
 * UTF-8.
 * @exception NSInvalidArgumentException When the token's key length is not
 * compatible with the OCRA hash algorithm (see
 * [EMSoftOathSettings ocraHashAlgorithm]).
 * @exception NSInternalInconsistencyException When the associated token has the
 * `EMTokenCapabilityDUAL_SEED` capability and the OCRA suite is event based since
 * only time based algorithms are supported for this capability. See EMTokenCapability.
 * @warning Depending of the EMAuthInput type you are using, you may have to use this function asynchronously, please @see EMAuthInput for more details
 * - Since: 3.2
 */
- (id<EMSecureString>)ocraOtpWithAuthInput:(id<EMAuthInput>)authInput serverChallengeQuestion:(id<EMSecureByteArray>)serverChallengeQuestion clientChallengeQuestion:(id<EMSecureByteArray>)clientChallengeQuestion passwordHash:(id<EMSecureByteArray>)passwordHash session:(id<EMSecureByteArray>)session error:(NSError **)error;

/**
 * Gets password hash value according the algorithm defined by device settings.
 *
 * @param password The password, can be `nil`.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return passwordHash
 *
 *<ul>
 * <li> The hash value of the password.</li>
 * <li> 'nil' if password is 'nil' or hash algorithm
 * for OCRA password is set to 'EMOcraPasswordNone' by the
 * device settings</li>
 * </ul>
 */
- (id<EMSecureString>)ocraPasswordHash:(id<EMSecureString>)password error:(NSError**)error;

/**
 * Returns lifespan of the last OTP computed by this device.
 *
 * The following example illustrates the usage.
 *
 *     // Create OATH settings
 *     id<EMMutableSoftOathSettings> oathSettings = ...
 *
 *     // Set up OATH time-based settings (for example a 30 seconds timestep)
 *     [oathSettings setTotpTimestepSize:30];
 *
 *     // Create a OATH device
 *     id<EMOathDevice> device = ...
 *
 *     // Compute a time-based OTP with device (with pin EMSecureString)
 *     [device getTotpWithPin:pin];
 *
 *     // Each time selector [... lastOtpLifespan] is called, it returns the
 *     // remaining lifespan in seconds of the last time-based OTP. Lifespan is
 *     // computed with respect of device's settings (in this example it returns
 *     // the lifespan according the 30-seconds timestep).
 *     NSInteger lifespan = [device lastOtpLifespan];
 *
 * @return lifespan
 *
 * <ul>
 * <li> In case last OTP computed with this device is time-based
 * <ul>
 * <li> If positive, the last OTP is still valid according current time and device's
 * timestep settings. The returned value indicates the remaining seconds
 * before the OTP becomes obsolete.</li>
 * <li> If negative, the last OTP computed is obsolete. The absolute
 * value indicates the time elapsed since the OTP has become obsolete.</li>
 * </ul>
 * </li>
 * <li> In case last OTP computed with this device is event-based, or no OTP has
 * been computed yet, the function returns 'NSIntegerMax'</li>
 * </ul>
 *
 * - Since: 2.3
 */
- (NSInteger)lastOtpLifespan;

@end
