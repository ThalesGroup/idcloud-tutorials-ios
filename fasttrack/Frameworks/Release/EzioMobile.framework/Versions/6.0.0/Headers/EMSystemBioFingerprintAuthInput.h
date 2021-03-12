/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2017  -  GEMALTO DEVELOPMENT - R&D
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
#import "EMAuthInput.h"
#import "EMSystemBioFingerprintAuthService.h"

/**
 * A protocol that represents authentication input which carries the information from user.
 * <p>
 *
 * @warning As biometric fingerprint methods may request user to present its fingerprint through the TouchId UI,
 * it is recommended that developer avoid to call these methods on the main thread, to limit the risk of blocking
 * or freezing the handset. Developer should use the biometric fingerprint methods on a separate thread, as
 * describe in the example below
 *
 *   // dispatch a new thread to deactivate non silently
 *   dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
 *
 *      [token deactivateAuthModeWithInput:bioFpAuthInput error:&error];
 *
 *      //some logic
 *
 *      //update UI
 *      dispatch_async(dispatch_get_main_queue (), ^{
 *      …
 *      }
 *   }
 *
 * @warning In iOS8, two calls in a row of biometric methods; using the TouchID UI to authenticate the user,
 * will not work. The second call will return an error code without presenting the TouchID UI to the user.
 * So application should respect this constraint, and for example, not try to compute two OTP consecutively.
 * However, if it is really needed, developers can add a sleep instruction (of 1 second or more) between the
 * two biometric calls to make it work.
 *
 * - Since: 4.6
 */
@protocol EMSystemBioFingerprintAuthInput<EMAuthInput>

@end

