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
#import "EMSoftOathSettings.h"

/**
 * Protocol for DCV related settings.
 *
 * - Since: 4.1
 */
@protocol EMSoftDcvOathSettings <NSObject>

/**
 * Returns the length of an DCV.
 *
 * Default: 3
 */
@property(assign, nonatomic, readonly) NSInteger dcvLength;

/**
 * Returns the hash algorithm used in the HMAC computation for DCV.
 *
 * Default: `EMOathHashSHA1`. see EMOathHashAlgorithm.
 */
@property(assign, nonatomic, readonly) EMOathHashAlgorithm dcvHashAlgorithm;

/**
 * Returns the T0 start time used in the settings.
 *
 * Default: 0
 */
@property(assign, nonatomic, readonly) int64_t dcvStartTime;

/**
 * Returns the time step size used in the settings.
 *
 * Default: 20
 */
@property(assign, nonatomic, readonly) NSInteger dcvTimestepSize;


/**
 * Returns the time step type used in the settings.
 *
 * Default: Minutes
 */
@property(assign, nonatomic, readonly) EMOathTimestepType dcvTimestepType;


@end
