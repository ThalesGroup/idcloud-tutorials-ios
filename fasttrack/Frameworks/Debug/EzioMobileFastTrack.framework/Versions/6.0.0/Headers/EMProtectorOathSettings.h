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

NS_ASSUME_NONNULL_BEGIN

/**
 OATH Minimum Truncation value
 */
static const NSInteger MOBILE_PROTECTOR_OATH_MINIMUM_TRUNCATION = 6;

/**
 OATH Maximum Truncation value
 */
static const NSInteger MOBILE_PROTECTOR_OATH_MAXIMUM_TRUNCATION = 10;

/**
 OATH DCVV Minimum Truncation value
 */
static const NSInteger MOBILE_PROTECTOR_OATH_DCVV_MINIMUM_TRUNCATION = 3;

/**
 OATH DCVV Maximum Truncation value
 */
static const NSInteger MOBILE_PROTECTOR_OATH_DCVV_MAXIMUM_TRUNCATION = 4;

/**
 Supported hash algorithms for HMAC computation
 * - Since: 5.3
 */
typedef NS_ENUM(NSInteger, EMFastTrackOathHashAlgorithm)
{
    /** SHA1 */
    EMFastTrackOathHashAlgorithmSHA1,
    /** SHA256 */
    EMFastTrackOathHashAlgorithmSHA256,
    /** SHA512 */
    EMFastTrackOathHashAlgorithmSHA512,
};

/**
 Supported types of Time step. Choose `EMFastTrackOathTimestepTypeNone` if not used.
 * - Since: 5.3
 */
typedef NS_ENUM(NSInteger, EMFastTrackOathTimestepType)
{
    /** Timestep is not used */
    EMFastTrackOathTimestepTypeNone,
    /** Seconds */
    EMFastTrackOathTimestepTypeSeconds,
    /** Minutes */
    EMFastTrackOathTimestepTypeMinutes,
    /** Hours */
    EMFastTrackOathTimestepTypeHours,
};

NS_ASSUME_NONNULL_END
