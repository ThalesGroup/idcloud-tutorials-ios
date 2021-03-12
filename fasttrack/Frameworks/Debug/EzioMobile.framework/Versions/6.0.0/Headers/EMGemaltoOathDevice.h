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
 * An OATH device complying with the Standard Gemalto OATH options.
 *
 * - Since: 2.2
 */
@protocol EMGemaltoOathDevice <NSObject>


/**
 * Gets an event based OTP (HOTP) as defined by the Gemalto OATH eBanking options.
 *
 * @param authInput The authInput.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @exception NSInternalInconsistencyException When the associated token has the `EMTokenCapabilityDUAL_SEED` capability since only time based algorithms are supported for this capability. See EMTokenCapability.
 * @return The OTP.
 *
 * @warning Depending of the EMAuthInput type you are using, you may have to use this function asynchronously, please @see EMAuthInput for more details
 *
 * - Since: 3.2
 */
- (id<EMSecureString>)hotpWithAuthInput:(id<EMAuthInput>)authInput error:(NSError **)error;

/**
 * Gets a time based OTP (TOTP) as defined by the Gemalto OATH eBanking options.
 *
 * @param authInput The authInput.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The OTP.
 *
 * @warning Depending of the EMAuthInput type you are using, you may have to use this function asynchronously, please @see EMAuthInput for more details
 *
 * - Since: 3.2
 */
- (id<EMSecureString>)totpWithAuthInput:(id<EMAuthInput>)authInput error:(NSError **)error;

/**
 * Creates an event based OCRA C/R as defined by the Gemalto OATH eBanking options.
 *
 * @param authInput The authInput.
 * @param challengeQuestion The challenge question.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @exception NSInternalInconsistencyException when the associated token has the `EMTokenCapabilityDUAL_SEED` capability since only time based algorithms are supported for this capability. See EMTokenCapability.
 * @return The OTP.
 *
 * @warning Depending of the EMAuthInput type you are using, you may have to use this function asynchronously, please @see EMAuthInput for more details
 *
 * - Since: 3.2
 */
- (id<EMSecureString>)ocraEventChallengeResponseWithAuthInput:(id<EMAuthInput>)authInput challengeQuestion:(id<EMSecureString>)challengeQuestion error:(NSError **)error;

/**
 * Creates a time based OCRA C/R as defined by the Gemalto OATH eBanking options.
 *
 * @param authInput The authInput.
 * @param challengeQuestion The challenge question.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The OTP.
 *
 * @warning Depending of the EMAuthInput type you are using, you may have to use this function asynchronously, please @see EMAuthInput for more details
 *
 * - Since: 3.2
 */
- (id<EMSecureString>)ocraTimeChallengeResponseWithAuthInput:(id<EMAuthInput>)authInput challengeQuestion:(id<EMSecureString>)challengeQuestion error:(NSError **)error;

/**
 * Creates an event based OCRA signature as defined by the Gemalto OATH eBanking options.
 *
 * @param authInput The authInput.
 * @param dataToSign The data to sign (as an array of EMSecureString instances). `dataToSign` must not contain a '~' (0x7E) byte value.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @exception NSInternalInconsistencyException when the associated token has the `EMTokenCapabilityDUAL_SEED` capability since only time based algorithms are supported for this capability. See EMTokenCapability.
 * @return The OTP.
 *
 * @warning Depending of the EMAuthInput type you are using, you may have to use this function asynchronously, please @see EMAuthInput for more details
 *
 * - Since: 3.2
 */
- (id<EMSecureString>)ocraEventSignatureWithAuthInput:(id<EMAuthInput>)authInput dataToSign:(NSArray *)dataToSign error:(NSError **)error;

/**
 * Creates a time based OCRA signature as defined by the Gemalto OATH eBanking options.
 *
 * @param authInput The authInput.
 * @param dataToSign The data to sign (as an array of EMSecureString instances). `dataToSign` must not contain a '~' (0x7E) byte value.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The OTP.
 *
 * @warning Depending of the EMAuthInput type you are using, you may have to use this function asynchronously, please @see EMAuthInput for more details
 *
 * - Since: 3.2
 */
- (id<EMSecureString>)ocraTimeSignatureWithAuthInput:(id<EMAuthInput>)authInput dataToSign:(NSArray *)dataToSign error:(NSError **)error;

/**
 * Return lifespan of the last OTP computed by this device.
 *
 * @return lifespan
 *
 * <ul>
 * <li> In case last OTP computed with this device is time-based
 * <ul>
 * <li> If positive, the last OTP is still valid according current time and device's
 * timestep settings. The returned value indicates the remaining seconds
 * before the OTP becomes obsolete.
 * <li> If negative, the last OTP computed is obsolete. The absolute
 * value indicates the time elapsed since the OTP has become obsolete.
 * </ul>
 * </li>
 * <li> In case last OTP computed with this device is event-based, or no OTP has
 * been computed yet, the function returns NSIntegerMax.
 * </ul>
 *
 * - Since: 2.3
 *
 * The following example illustrates the usage.
 *
 *      // Create OATH settings (see EMOathFactory)
 *     id<EMMutableSoftGemaltoOathSettings> oathSettings = ...
 *
 *     // Create a OATH device (see EMOathFactory)
 *     id<EMGemaltoOathDevice> device = ...
 *
 *     // Compute a time-based OTP with device (with pin and challengeQuestion EMSecureString)
 *     [device ocraTimeChallengeResponseWithPin:pin challengeQuestion:challengeQuestion];
 *
 *     // Each time selector [... lastOtpLifespan] is called, it returns the
 *     // remaining lifespan in seconds of the last time-based OTP. Lifespan is
 *     // computed with respect of device's settings (in this example it returns
 *     // the lifespan according to Gemalto device fixed settings, i.e. 30-seconds timestep).
 *     NSInteger lifespan = [device lastOtpLifespan];
 */
- (NSInteger)lastOtpLifespan;

@end
