/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2015  -  GEMALTO DEVELOPMENT - R&D
 *
 * -----------------------------------------------------------------------------
 * GEMALTO MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF
 * THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, OR NON-INFRINGEMENT. GEMALTO SHALL NOT BE
 * LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
 * MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
 *
 * THIS SOFTWARE IS NOT DESIGNED OR INTENDED FOR USE OR RESALE AS ON-LINE
 * CONTROL EQUIPMENT IN HAZARDOUS ENVIRONMENTS REQUIRING FAIL-SAFE
 * PERFORMANCE, SUCH AS IN THE OPERATION OF NUCLEAR FACILITIES, AIRCRAFT
 * NAVIGATION OR COMMUNICATION SYSTEMS, AIR TRAFFIC CONTROL, DIRECT LIFE
 * SUPPORT MACHINES, OR WEAPONS SYSTEMS, IN WHICH THE FAILURE OF THE
 * SOFTWARE COULD LEAD DIRECTLY TO DEATH, PERSONAL INJURY, OR SEVERE
 * PHYSICAL OR ENVIRONMENTAL DAMAGE ("HIGH RISK ACTIVITIES"). GEMALTO
 * SPECIFICALLY DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTY OF FITNESS FOR
 * HIGH RISK ACTIVITIES.
 *
 * -----------------------------------------------------------------------------
 */

#import <Foundation/Foundation.h>
#import "EMAuthMode.h"

/**
 * A protocol that represents authentication service.
 *
 * - Since: 3.2
 */
@protocol EMAuthService <NSObject>

/**
 * Get authentication mode reference corresponding to this service.
 *
 * @return current auth mode.
 *
 * - Since: 3.2
 */
- (id<EMAuthMode>)authMode;

/**
 * Indicates if the authentication mode is supported by the hardware.
 *
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return 'YES' if authentication is supported, 'NO' otherwise.
 *
 * - Since: 3.2
 */
- (BOOL)isSupported:(NSError **)error;

/**
 * Indicates if the authentication mode is configured and ready for use.  For example, a user may need to configure the OS to use a particular feature, such as TouchID, Face ID, before this authentication mode can be used.
 *
 * TouchID authentication mode is configured only if the following conditions met:
 * 1. At least one touch ID user is registered into the system
 * 2. Touch ID service is available. If the touch ID is temporarily locked out because there were too many failed Touch ID attempts, the function will return false and an error.
 *
 * Face ID authentication mode is configured only if the following conditions met:
 * 1. Face ID authentication service is initialized, and
 * 2. One user is enrolled.
 *
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return 'YES' if the platform is correctly configured to support the authentication mode; 'NO' otherwise.
 *
 * - Since: 3.2
 */
- (BOOL)isConfigured:(NSError **)error;

@end
