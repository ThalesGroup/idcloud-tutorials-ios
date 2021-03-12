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
#import "EMProtectorOathSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Default HOTP length.
 */
static const NSInteger DEFAULT_OATH_HOTP_TRUNCATION                             = 8;

/**
 Default hash algorithm for HOTP.
 */
static const EMFastTrackOathHashAlgorithm DEFAULT_OATH_HOTP_HASH_ALGORITHM    = EMFastTrackOathHashAlgorithmSHA1;

/**
 Event-base OTP settings.
 To use this object default settings could be done by directly initializing it.
 * - Since: 5.3
 */
@interface EMProtectorHotpSettings : NSObject

/**
 The HOTP length. Allowed range is 6-10 digits.
 @exception NSInvalidArgumentException When hotpLength is not in allowed range.
 */
@property(assign, nonatomic) NSInteger length;

/**
 The hash algorithm for HOTP.
 HOTP only supports EMFastTrackOathHashAlgorithmSHA1 and EMOathHashSHA256. See EMFastTrackOathHashAlgorithm.
 @exception NSInvalidArgumentException When hash algorithm is not supported.
 */
@property(assign, nonatomic) EMFastTrackOathHashAlgorithm hashAlgorithm;

@end

NS_ASSUME_NONNULL_END
