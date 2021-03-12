/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2016  -  GEMALTO DEVELOPMENT - R&D
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
#import "EMTokenManager.h"
#import "EMDeviceFingerprintTokenPolicy.h"

/**
 * OtpModule class which is the entry-point for OTP features.
 *
 * - Since: 4.0
 */
@interface EMOtpModule : NSObject

/**
 * Create OtpModule object.
 *
 * @return Otp Module.
 * - Since: 4.0
 */
+ (EMOtpModule *)otpModule;

/**
 To apply the new device fingerprint policy to the token.
 This API will change (add or remove) the device token policy 'EMDeviceFingerprintTokenPolicy' properties, such as:
 <ul>
 <li>The mode 'failIfInvalid'</li>
 <li>The custom fingerprint data </li>
 <li>The fingerprint source type 'EMDeviceFingerprintSource' </li>
 </ul>
 @param tokenName The token name
 @param oldCustomData The old custom fingerprint data (if any)
 NOTE: The application manages the custom fingerprint data value so that it uses the proper value while retrieving the token, for example, by calling [capTokenManager tokenWithName:fingerprintCustomData:error:];
 @param newDeviceFingerprintTokenPolicy The new device fingerprint token policy.
 NOTE: The application has to retrieve the token object again to update the changes, for example, by calling [capTokenManager tokenWithName:fingerprintCustomData:error:];
 @param error If an error occurs while updating the token, upon return contains an NSError object that describes the problem. Update may fail due to:
 <ol>
 <li>If the new DeviceFingerprintTokenPolicy and old policy are identical.</li>
 <li>If the provided 'oldCustomData' does not match with the one while creating the token</li>
 <li>If there is no token present with the specified token name.</li>
 </ol>

 @return YES if the migration is successful else returns NO
 */

- (BOOL)updateDeviceFingerprintTokenPolicyWithTokenName:(NSString *)tokenName
                                          oldCustomData:(NSData * _Nullable)oldCustomData
                        newDeviceFingerprintTokenPolicy:(EMDeviceFingerprintTokenPolicy *)newDeviceFingerprintTokenPolicy
                                                  error:(NSError **)error;

@end
