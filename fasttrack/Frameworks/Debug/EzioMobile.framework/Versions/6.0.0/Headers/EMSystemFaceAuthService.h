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
#import "EMAuthService.h"
#import "EMAuthModule.h"

/**
 * Native FaceID Authentication Service
 *
 * - Since: 4.6
 */
@interface EMSystemFaceAuthService : NSObject<EMAuthService>

/**
 * Designated constructor.
 * Returns the EMSystemFaceAuthService object created using the EMAuthModule
 *
 * @param module an instance of EMAuthModule
 * @return EMSystemFaceAuthService instance.
 *
 * - Since: 4.6
 */
+ (instancetype)serviceWithModule:(EMAuthModule *)module;

/**
 * Sets the fallback block to override whether or not an unidentified device supports native face auth service or not.
 *
 * For a device whose biometric authentication is not configured, or when the user has
 * denied access to this biometric mode, the System API does not provide what biometric type
 * is available on the device, hence the SDK will not be able to know whether
 * the device sports TouchID or FaceID.
 *
 * For devices released after 2017 (i.e. > iPhone X), such scenario by default assumes
 * that it will support native FaceID. However this may not be entirely accurate
 * because some devices may support only TouchID but not FaceID.
 *
 * In this case, this API provides for the application to override this behaviour by
 * implementing the `IsSupportedFallback` block and determine the hardware support
 * based on MachineID: For details on the available machine ids refer to:
 * https://en.wikipedia.org/wiki/List_of_iOS_devices under "Hardware strings" value.
 *
 *
 * The following example illustrates the usage.
 *````
 *      [EMSystemFaceAuthService setIsSupportedFallback:^BOOL(NSString *machineID) {
 *          if ([machineID isEqualToString:@"iPhone11,3"]) {        //Hypothetical future iPhone 11
 *              return YES;
 *          }else if(([machineID isEqualToString:@"iPhone11,6"])){  //Hypothetical future iPhone 11
 *              return YES;
 *          }else{
 *              return NO;
 *          }
 *      } error:&error];
 *
 *````
 * @note the fallback block will only be invoked when the biometric is not configured and that the device machine id is not recognized.
 * @param machineID The machine id string.
 * - Since: 4.6
 */

typedef BOOL(^IsSupportedFallback)(NSString *machineID);

/**
 * Sets the fallback block
 *
 * @param fallback The fallback block
 *
 * - Since: 4.6
 */
+ (void)setIsSupportedFallback:(IsSupportedFallback)fallback;

/**
 * Returns the fallback block to override whether or not an unidentified device
 * supports SystemFaceAuth service or not.
 *
 * - Since: 4.6
 */
+ (IsSupportedFallback)getIsSupportedFallback;

@end
