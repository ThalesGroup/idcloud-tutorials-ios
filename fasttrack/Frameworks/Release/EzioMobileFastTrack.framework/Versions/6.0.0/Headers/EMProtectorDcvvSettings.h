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
 Default DCVV length
 */
static const NSInteger DEFAULT_OATH_DCVV_TRUNCATION                             = 3;

/**
 Default hash algorithm for DCVV.
 */
static const EMFastTrackOathHashAlgorithm DEFAULT_OATH_DCVV_HASH_ALGORITHM    = EMFastTrackOathHashAlgorithmSHA1;

/**
 Default time step type for DCVV.
 */
static const EMFastTrackOathTimestepType DEFAULT_OATH_DCVV_TIMESTEP_TYPE      = EMFastTrackOathTimestepTypeMinutes;

/**
 Default time step size for DCVV.
 */
static const NSInteger DEFAULT_OATH_DCVV_TIMESTEP_SIZE                          = 20;

/**
 Default value to start counting the time steps.
 */
static const int64_t DEFAULT_OATH_DCVV_START_TIME                               = 0LL;

/**
 Time-based OTP settings.
 To use this object default settings could be done by directly initializing it.
 * - Since: 5.3
 */
@interface EMProtectorDcvvSettings : NSObject

/**
 The DCVV length. Allowed range is 3 or 4 digits.
 @exception NSInvalidArgumentException When the length is not in allowed range.
 */
@property(assign, nonatomic) NSInteger length;

/**
 The hash algorithm for DCVV.
 */
@property(assign, nonatomic) EMFastTrackOathHashAlgorithm hashAlgorithm;

/**
 The T0 value for DCVV. Value to start counting the time steps.
 Default: 0
 @exception NSInvalidArgumentException When the negative value is given.
 */
@property(assign, nonatomic) int64_t startTime;

/**
 The time step size for DCVV.
 Default: 20 minutes.
 */
@property(assign, nonatomic) NSInteger timestepSize;

/**
 The time step type for DCVV.
 */
@property(assign, nonatomic) EMFastTrackOathTimestepType timestepType;

@end

NS_ASSUME_NONNULL_END
