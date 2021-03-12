/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2015 -  GEMALTO DEVELOPMENT - R&D
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
#import "EMDeviceFingerprintSource.h"

/**
 * This class is used to create device fingerprint source settings that are applied to a token when it is built.
 */
@interface EMDeviceFingerprintTokenPolicy : NSObject

/**
 * Specifies if fingerprint data is checked before using them.
 */
@property (nonatomic, readonly) BOOL failIfInvalid;

/**
 * List for device fingerprint source to use.
 */
@property (nonatomic, copy, readonly) EMDeviceFingerprintSource *deviceFingerprintSource;


/**
 * Default device fingerprint token policy source settings, with check enabled.
 *
 * @return An instance of EMDeviceFingerprintTokenPolicy.
 */
+ (id)defaultDeviceFingerprintTokenPolicy;

/**
 * Build a new device fingerprint token policy.
 * @warning If `aFailIfInvalid` is set to `YES`, it still remains a probability of 1/2^16 that wrong device fingerprint data will not be detected.
 *
 * @param aDeviceFingerprintSource Device fingerprint source to collect.
 * @param aFailIfInvalid Specify if anti-cloning data must be checked before instantiating the token. If `YES`, when a token is retrieved the token manager verifies if the anti-cloning matches a digest of the expected anti-cloning. If it does not match then an exception is thrown.
 *
 * @return An instance of EMDeviceFingerprintTokenPolicy.
 */
- (id)initWithDeviceFingerprintSource:(EMDeviceFingerprintSource *)aDeviceFingerprintSource failIfInvalid:(BOOL)aFailIfInvalid;

@end
