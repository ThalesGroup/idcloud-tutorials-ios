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
#import "EMSecureString.h"
#import "EMAuthInput.h"

/**
 * An DCV OATH device complying with the Standard Gemalto DCV options.
 *
 * - Since: 4.1
 */
@protocol EMDcvOathDevice <NSObject>

/**
 * Gets a time based DCV value as defined by the Standard Gemalto DCV
 * options.
 *
 * @param authInput The authInput.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The DCV.
 * @warning Depending of the EMAuthInput type you are using, you may have to use this function asynchronously, please see EMAuthInput for more details
 * - Since: 4.1
 */
- (id<EMSecureString>)dcvWithAuthInput:(id<EMAuthInput>)authInput error:(NSError **)error;

/**
 * Returns lifespan of the last DCV computed by this device.
 *
 * @return lifespan
 *
 * <ul>
 * <li> If positive, the last DCV is still valid according to current time and device's
 * timestep settings. The returned value indicates the remaining seconds
 * before the DCV becomes obsolete.</li>
 * <li> If negative, the last DCV computed is obsolete. The absolute
 * value indicates the time elapsed since the OTP has become obsolete.</li>
 * </ul>
 * <ul>
 * <li> In case no DCV has been computed yet, the function returns NSIntegerMax.</li>
 * </ul>
 *
 * The following example illustrates the usage
 *
 *     // Create OATH DCV settings (see EMOathFactory)
 *    id<EMMutableSoftOathDcvSettings> oathDcvSettings = ...
 *
 *    // Set up OATH DCV settings (for example a 20 minutes timestep)
 *    [oathDcvSettings setDcvTimeSettingsWithTimeStep:EMOathTimestepTypeMinutes timestepSize:20 starTime:0];
 *
 *    // Create a OATH DCV device (see EMOathFactory)
 *    id<EMOathDcvDevice> device = ...
 *
 *    // Compute DCV with device (with pin EMSecureString)
 *    [device getDcv:pin];
 *
 *    // Each time selector [... lastDcvLifespan] is called, it returns the
 *    // remaining lifespan in seconds of the last time-based DCV. Lifespan is
 *    // computed with respect of device's settings (in this example it returns
 *    // the lifespan according the 20-minutes timestep)
 *
 * - Since: 4.1
 */
- (NSInteger)lastDcvLifespan;

@end
