/** -----------------------------------------------------------------------------
 
 Copyright (c) 2016  -  GEMALTO DEVELOPMENT - R&D
 
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
#import "EMSoftDcvOathSettings.h"

/**
 * Protocol for changeable DCV settings.
 *
 * - Since: 4.1
 */
@protocol EMMutableSoftDcvOathSettings <EMSoftDcvOathSettings>

/**
 * The DCV length. Allowed range is 3-4 digits.
 *
 * @exception NSInvalidArgumentException When dcvLength is not in allowed range.
 */
@property(assign, nonatomic) NSInteger dcvLength;

/**
 * The hash algorithm for DCV. See EMOathHashAlgorithm.
 *
 * @exception NSInvalidArgumentException When hash algorithm is not supported.
 */
@property(assign, nonatomic) EMOathHashAlgorithm dcvHashAlgorithm;

/**
 * The T0 value for DCV. Value to start counting the time steps.
 * Default: 0
 *
 * @exception NSInvalidArgumentException When dcvStartTime is negative.
 */
@property(assign, nonatomic) int64_t dcvStartTime;

/**
 * The time step size for DCV.
 * Default: 20
 */
@property(assign, nonatomic, readonly) NSInteger dcvTimestepSize;

/**
 * The time step type for DCV.
 * Default: Minutes.
*/
@property(assign, nonatomic, readonly) EMOathTimestepType dcvTimestepType;

/**
 *
 * Sets the DCV time settings.
 *
 * @param timestepType The time step type, set to `EMOathTimestepTypeNone` to not use it.
 * @param timestepSize The time step size, it is ignored if `timestepType` is `EMOathTimestepTypeNone`.
 *
 * @exception NSInvalidArgumentException If one of the following conditions is true:
 * <ul>
 * <li> `timestepType` is not equal to `EMOathTimestepTypeNone` and `timestepSize` is less than or equal to zero.
 * <li> `timestepType` is not equal to `EMOathTimestepTypeNone` and `startTime` is less than zero.
 * <li> `timestepType` is equal to `EMOathTimestepTypeSeconds` and `timestepSize` is greater than 59.
 * <li> `timestepType` is equal to `EMOathTimestepTypeMinutes` and `timestepSize` is greater than 59.
 * <li> `timestepType` is equal to `EMOathTimestepTypeHours` and `timestepSize` is greater than 48.
 * </ul>
 * 
 */
-(void)setDcvTimeSettingsWithTimestepSize:(NSInteger)timestepSize
                             timestepType:(EMOathTimestepType)timestepType;

@end
