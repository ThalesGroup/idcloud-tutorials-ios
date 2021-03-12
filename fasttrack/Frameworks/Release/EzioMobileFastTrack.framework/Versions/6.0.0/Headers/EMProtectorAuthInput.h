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
#import <EzioMobile/EzioMobile.h>
#import "EMProtectorAuthInput.h"
#import "EMFastTrackTlsConfiguration.h"
#import "EMFastTrackDeviceFingerprintSource.h"
#import "EMRegistrationResponse.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Authenticated Input that can be used for OTP generation. It is obtained after successful
 * authentication through BioFingerprint/Face
 * - Since: 5.3
 */
@interface EMProtectorAuthInput : NSObject

/**
 * Wipes out the sensitive data from memory
 * content.
 */
- (void)wipe;

/**
 *  Init Fast Track EMProtectorAuthInput from CoreAPI EMAuthInput object to use in Fast Track API
 *  @param authInput The object that conform to EMAuthInput protocol - especially EMPinAuthInput
 *  @return The  EMProtectorAuthInput object
 *  - Since: 6.0
*/
- (instancetype)initWithAuthInput:(id<EMAuthInput>)authInput;


@end

NS_ASSUME_NONNULL_END
