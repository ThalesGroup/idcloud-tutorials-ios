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
#import "EMSoftOathSettings.h"

/**
 * Protocol for changeable OATH settings.
 *
 * - Since: 2.2
 */
@protocol EMMutableSoftOathSettings <EMSoftOathSettings>

/**
 * The HOTP length. Allowed range is 6-10 digits.
 *
 * @exception NSInvalidArgumentException When hotpLength is not in allowed range.
 */
@property(assign, nonatomic) NSInteger hotpLength;

/**
 * The hash algorithm for HOTP.
 * HOTP only supports EMOathHashSHA1 and EMOathHashSHA256. See EMOathHashAlgorithm.
 *
 * @exception NSInvalidArgumentException When hash algorithm is not supported.
*/
@property(assign, nonatomic) EMOathHashAlgorithm hotpHashAlgorithm;

/**
 * The TOTP length. Allowed range is 6-10 digits.
 *
 * @exception NSInvalidArgumentException When hotpLength is not in allowed range.
 */
@property(assign, nonatomic) NSInteger totpLength;

/**
 * The hash algorithm for TOTP.
 */
@property(assign, nonatomic) EMOathHashAlgorithm totpHashAlgorithm;

/**
 * The T0 value for TOTP. Value to start counting the time steps.
 * Default: 0
 *
 * @exception NSInvalidArgumentException When totpStartTime is negative.
 */
@property(assign, nonatomic) int64_t totpStartTime;

/**
 * The time step size for TOTP.
 * Default: 30 seconds.
 */
@property(assign, nonatomic) NSInteger totpTimestepSize;

/**
 * The time step type for TOTP.
 */
@property(assign, nonatomic) EMOathTimestepType totpTimestepType;

/**
 * The OTP length for OCRA.
 * 0 for full length or any value in the range 4-10 digits.
 *
 * @exception NSInvalidArgumentException When ocraOtpLength is not in allowed range.
 */
@property(assign, nonatomic) NSInteger ocraOtpLength;

/**
 * The hash algorithm for OCRA.
 */
@property(assign, nonatomic) EMOathHashAlgorithm ocraHashAlgorithm;

/**
 * The T0 value for OCRA. Value to start counting the time steps.
 * Default: 0. Must not be negative.
 *
 * @exception NSInvalidArgumentException When ocraStartTime is negative.
 */
@property(assign, nonatomic) int64_t ocraStartTime;

/**
 * The time step type for OCRA.
 */
@property(assign, nonatomic, readonly) EMOathTimestepType ocraTimestepType;

/**
 * The time step size for OCRA. Must be larger than 0.
 */
@property(assign, nonatomic, readonly) NSInteger ocraTimestepSize;

/**
 * If the Counter is used in the OCRA computation
 */
@property(assign, nonatomic, getter = isOcraCounterUsed) BOOL ocraCounterUsed;

/**
 * The format of the Challenge Question field in the OCRA computation
 */
@property(assign, nonatomic) EMOcraChallengeQuestionFormat ocraChallengeQuestionFormat;

/**
 * The session length in the OCRA computation.
 * -1 to not use session in OCRA computation or any value in the range 1-512.
 * Default value is -1 (not used)
 */
@property(assign, nonatomic) NSInteger ocraSessionLength;

/**
 * The password hash algorithm in the OCRA computation
 */
@property(assign, nonatomic) EMOcraPasswordHashAlgorithm ocraPasswordHashAlgorithm;

/**
 * The maximum length of the challenge string regardless of the format (e.g. the number of nibbles in hexadecimal
 * format or the maximum number of digits in numerical format).
 * Any value in the range 4-64.
 */
@property(assign, nonatomic) NSInteger ocraMaximumChallengeQuestionLength;

/**
 * Sets the OCRA time settings.
 *
 * @param timestepType The time step type, set to `EMOathTimestepTypeNone` to not use it.
 * @param timestepSize The time step size, it is ignored if `timestepType` is `EMOathTimestepTypeNone`.
 * @param startTime The start time in seconds, it is ignored if `timestepType` is `EMOathTimestepTypeNone`.
 *
 * @exception NSInvalidArgumentException If one of the following conditions is true:
 * <ul>
 * <li> `timestepType` is not equal to `EMOathTimestepTypeNone` and `timestepSize` is less than or equal to zero.
 * <li> `timestepType` is not equal to `EMOathTimestepTypeNone` and `startTime` is less than zero.
 * <li> `timestepType` is equal to `EMOathTimestepTypeSeconds` and `timestepSize` is greater than 59.
 * <li> `timestepType` is equal to `EMOathTimestepTypeMinutes` and `timestepSize` is greater than 59.
 * <li> `timestepType` is equal to `EMOathTimestepTypeHours` and `timestepSize` is greater than 48.
 * </ul>
 */
-(void)setOcraTimeSettingsWithTimeStep:(EMOathTimestepType)timestepType
                          timestepSize:(NSInteger)timestepSize
                             startTime:(int64_t)startTime;

/**
 * Sets the OCRA Suite, all the relevant OCRA settings will be set accordingly.
 *
 * Notice the startTime cannot be configured by OCRA Suite. Call setOcraTimeSettingsWithTimeStep:timestepSize:startTime if startTime needs to be tweaked.
 *
 * @param ocrasuite The OCRA Suite.
 * - Since: 2.3
 */
-(void)setOcraSuite:(id<EMSecureString>)ocrasuite;

@end
