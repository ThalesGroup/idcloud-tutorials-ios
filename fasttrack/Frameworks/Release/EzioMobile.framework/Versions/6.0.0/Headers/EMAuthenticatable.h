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
#import "EMAuthInput.h"

/**
 * Authenticatable protocol. Authenticatable refers to some asset which could
 * be authenticated with multi-authentication modes once configured.
 *
 * - Since: 3.2
 */
@protocol EMAuthenticatable <NSObject>

/**
 * Check if a mode has already been activated for this authenticatable.
 *
 * @param authMode the authentication mode to be check.
 * @return 'YES' if mode is active, 'NO' otherwise.
 *
 * - Since: 3.2
 */
- (BOOL)isAuthModeActive:(id<EMAuthMode>) authMode;

/**
 * Get the list of authentication modes that have been activated for this
 * authenticatable.
 *
 * @return list of activated modes.
 *
 * - Since: 3.2
 */
- (NSSet *)activatedModes;

/**
 * Activate an authentication mode.  An active authentication input is required to access protected data.
 * Currently, only supports using EMPinAuthMode to activate EMBioFingerprintAuthMode.
 * <p>
 * Prior to activate the mode, this method will check if it is well-configured on the platform.
 *
 * @param authMode The authentication mode to activate.
 * @param activatedAuthInput The authentication input for an activated authentication mode that gives access to protected data.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return 'YES' if mode has been activated, 'NO' otherwise.
 *
 * - Since: 3.2
 */
- (BOOL)activateAuthMode:(id<EMAuthMode>)authMode usingActivatedInput:(id<EMAuthInput>)activatedAuthInput error:(NSError **)error;

/**
 * Deactivate an authentication mode without user authentication.
 * <p>
 * Prior to deactivating the mode, this method will check if it is well-configured on the platform.
 *
 * @param authMode The authentication mode to be deactivated.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return 'YES' if mode has been deactivated, 'NO' otherwise.
 *
 * - Since: 3.2
 */
- (BOOL)deactivateAuthMode:(id<EMAuthMode>)authMode error:(NSError **)error;


/**
 * Check if multi authentication mode has been enabled. This function will
 * return true if the authenticatable has been migrated to support multi
 * auth modes. After migration, this function will return true even when
 * only one mode is activated.
 *
 * @return if multi authentication mode has been enabled.
 *
 * - Since: 3.2
 */
- (BOOL)isMultiAuthModeEnabled;

/**
 * Get the UUID of an Authenticatable object.
 *
 * @return String value of UUID.
 *
 * - Since: 4.0
 */
- (NSString *)uuid;

@end
