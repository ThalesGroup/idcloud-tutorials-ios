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

NS_ASSUME_NONNULL_BEGIN

/**
 Default value to start counting the time steps.
 */
static const int64_t DEFAULT_OATH_OCRA_START_TIME                               = 0LL;

/**
 Default OCRA Suite
 */
static NSString *DEFAULT_OATH_OCRA_SUITE                                        = @"OCRA-1:HOTP-SHA1-8:QN08-T30S";

/**
 OCRA based OTP settings.
 To use this object default settings could be done by directly initializing it.
 * - Since: 5.3
 */
@interface EMProtectorOcraSettings : NSObject

/**
 The T0 value for OCRA. Value to start counting the time steps.
 Default: 0
 */
@property(assign, nonatomic) int64_t startTime;

/**
 Sets the OCRA Suite, all the relevant OCRA settings will be set accordingly.
 Notice the startTime can not be configured by OCRA Suite. If startTime needs to be tweaked, `ocraStartTime` property could be set.
 */
@property(copy, nonatomic) NSString* ocraSuite;

@end

NS_ASSUME_NONNULL_END
