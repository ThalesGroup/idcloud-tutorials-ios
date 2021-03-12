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
#import "EMProtectorOathSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Default TOTP length.
 */
static const NSInteger DEFAULT_OATH_TOTP_TRUNCATION                             = 8;

/**
 Default hash algorithm for TOTP.
 */
static const EMFastTrackOathHashAlgorithm DEFAULT_OATH_TOTP_HASH_ALGORITHM    = EMFastTrackOathHashAlgorithmSHA1;

/**
 Default time step type for TOTP.
 */
static const EMFastTrackOathTimestepType DEFAULT_OATH_TOTP_TIMESTEP_TYPE      = EMFastTrackOathTimestepTypeSeconds;

/**
 Default time step size for TOTP.
 */
static const NSInteger DEFAULT_OATH_TOTP_TIMESTEP_SIZE                          = 30;

/**
 Default value to start counting the time steps.
 */
static const int64_t DEFAULT_OATH_TOTP_START_TIME                               = 0LL;

/**
 A time-based TOTP settings.
 To use this object default settings could be done by directly initializing it.
 * - Since: 5.3
 */
@interface EMProtectorTotpSettings : NSObject

/**
 The TOTP length. Allowed range is 6-10 digits.
 @exception NSInvalidArgumentException When the length is not in allowed range.
 */
@property(assign, nonatomic) NSInteger length;

/**
 The hash algorithm for TOTP.
 */
@property(assign, nonatomic) EMFastTrackOathHashAlgorithm hashAlgorithm;

/**
 The T0 value for TOTP. Value to start counting the time steps.
 Default: 0
 @exception NSInvalidArgumentException When the negative value is given.
 */
@property(assign, nonatomic) int64_t startTime;

/**
 The time step size for TOTP.
 Default: 30 seconds.
 */
@property(assign, nonatomic) NSInteger timestepSize;

/**
 The time step type for TOTP.
 */
@property(assign, nonatomic) EMFastTrackOathTimestepType timestepType;

@end

NS_ASSUME_NONNULL_END
