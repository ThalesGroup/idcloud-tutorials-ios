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

/** Supported hash algorithms for HMAC computation */
typedef NS_ENUM(NSInteger, EMOathHashAlgorithm)
{
    /** SHA1 */
    EMOathHashSHA1,
    /** SHA256 */
    EMOathHashSHA256,
    /** SHA512 */
    EMOathHashSHA512,
};

/** Supported Hash algorithm for Ocra password field. choose EMOcraPasswordNone if not used */
typedef NS_ENUM(NSInteger, EMOcraPasswordHashAlgorithm)
{
    /** Not used */
    EMOcraPasswordNone,
    /** SHA1 */
    EMOcraPasswordSHA1,
    /** SHA256 */
    EMOcraPasswordSHA256,
    /** SHA512 */
    EMOcraPasswordSHA512,
};

/** Supported types of Time step. Choose EMTotpTimestepTypeNone if not used. */
typedef NS_ENUM(NSInteger, EMOathTimestepType)
{
    /** Timestep is not used */
    EMOathTimestepTypeNone,
    /** Seconds */
    EMOathTimestepTypeSeconds,
    /** Minutes */
    EMOathTimestepTypeMinutes,
    /** Hours */
    EMOathTimestepTypeHours,
};

/** Supported challenge question formats for Ocra */
typedef NS_ENUM(NSInteger, EMOcraChallengeQuestionFormat)
{
    /** Alphanumeric */
    EMOcraChallengeQuestionFormatAlphanumeric,
    /** Numeric */
    EMOcraChallengeQuestionFormatNumeric,
    /** Hexadecimal */
    EMOcraChallengeQuestionFormatHexadecimal,
};

/**
 * Protocol for OATH related settings.
 *
 * - Since: 2.2
 */
@protocol EMSoftOathSettings <NSObject>

/**
 * Returns the length of an HOTP.
 *
 * Default: 8
 */
@property(assign, nonatomic, readonly) NSInteger hotpLength;

/**
 * Returns the hash algorithm used in the HMAC computation for HOTP.
 *
 * Default: `EMOathHashSHA1`. see EMOathHashAlgorithm.
 */
@property(assign, nonatomic, readonly) EMOathHashAlgorithm hotpHashAlgorithm;

/**
 * Returns the length of an TOTP.
 *
 * Default: 8
 */
@property(assign, nonatomic, readonly) NSInteger totpLength;

/**
 * Returns the hash algorithm used in the HMAC computation for TOTP.
 *
 * Default: `EMOathHashSHA1`. see EMOathHashAlgorithm.
 */
@property(assign, nonatomic, readonly) EMOathHashAlgorithm totpHashAlgorithm;

/**
 * Returns the T0 start time used in the settings.
 *
 * Default: 0
 */
@property(assign, nonatomic, readonly) int64_t totpStartTime;

/**
 * Returns the time step size used in the settings.
 *
 * Default: 30
 */
@property(assign, nonatomic, readonly) NSInteger totpTimestepSize;

/**
 * Returns the time step type for TOTP.
 *
 * Default: Seconds
 */
@property(assign, nonatomic, readonly) EMOathTimestepType totpTimestepType;

/**
 * Returns the length of an OCRA OTP.
 *
 * Default: 8
 */
@property(assign, nonatomic, readonly) NSInteger ocraOtpLength;

/**
 * Returns the hash algorithm used in the HMAC computation.
 * <p>
 * Default: `EMOathHashSHA1`. See EMOathHashAlgorithm.
 */
@property(assign, nonatomic, readonly) EMOathHashAlgorithm ocraHashAlgorithm;

/**
 * Returns the T0 start time used in the settings.
 * <p>
 * Default: 0
 */
@property(assign, nonatomic, readonly) int64_t ocraStartTime;

/**
 * Returns the time step type used in the settings.
 *
 * Default: `EMTotpTimestepTypeSeconds`. See EMOathTimestepType.
 */
@property(assign, nonatomic, readonly) EMOathTimestepType ocraTimestepType;

/**
 * Returns the time step size used in the settings.
 *
 * Default: 30
 */
@property(assign, nonatomic, readonly) NSInteger ocraTimestepSize;

/**
 * Returns `YES` if Counter is used, `NO` otherwise.
 *
 * Default: `NO`
 */
@property(assign, nonatomic, readonly, getter = isOcraCounterUsed) BOOL ocraCounterUsed;

/**
 * Returns the format of the Challenge Question field.
 *
 * Default: `EMOcraChallengeQuestionFormatNumeric`. See EMOcraChallengeQuestionFormat.
 */
@property(assign, nonatomic, readonly) EMOcraChallengeQuestionFormat ocraChallengeQuestionFormat;

/**
 * Returns the session length, -1 if not used.
 *
 * Default: -1
 */
@property(assign, nonatomic, readonly) NSInteger ocraSessionLength;

/**
 * Returns the used password hash algorithm.
 *
 * Default: `EMOcraPasswordNone`. See EMOcraPasswordHashAlgorithm.
 */
@property(assign, nonatomic, readonly) EMOcraPasswordHashAlgorithm ocraPasswordHashAlgorithm;

/**
 * Returns the maximum length of Challenge Question.
 *
 * Default: 8
 */
@property(assign, nonatomic, readonly) NSInteger ocraMaximumChallengeQuestionLength;

/**
 * Returns the OCRA suite for the OCRA settings.
 *
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * Default OCRA-1:HOTP-SHA1-8:QN08-T30S
 */
- (id<EMSecureString>)getOcraSuite:(NSError**)error;

@end
