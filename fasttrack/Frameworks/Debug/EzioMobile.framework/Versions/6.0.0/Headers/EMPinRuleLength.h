/** -----------------------------------------------------------------------------
 
        Copyright (c) 2013  -  GEMALTO DEVELOPMENT - R&D
 
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

#import "EMPinRule.h"

/**
 * A PIN rule that requires a PIN's length to be within a specific range.
 * - Since: 2.1
 */
@interface EMPinRuleLength : NSObject<EMPinRule>

/**
 * The default PIN minimum length.
 *
 * @return Min length.
 */
+ (NSInteger)defaultMinimumLength;

/**
 * The default PIN maximum length.
 *
 * @return Max length.
 */
+ (NSInteger)defaultMaximumLength;

/**
 * Returns the minimum length of a PIN.
 */
@property (assign, nonatomic, readonly) NSInteger minimumLength;
/**
 * Returns the maximum length of a PIN.
 */
@property (assign, nonatomic, readonly) NSInteger maximumLength;

/**
 * Constructs a default rule whose minimum and maximum length are
 * EMPinRuleLength#defaultMinimumLength and EMPinRuleLength#defaultMaximumLength.
 *
 * @return New PinRule
 */
- (instancetype)init;

/**
 * Constructs a customized rule.
 *
 * @param min The minimum length of a PIN.
 * @param max The maximum length of a PIN.
 *
 * @return New PinRule
 */
- (instancetype)initWithMinimumLength:(NSInteger)min maximumLength:(NSInteger)max NS_DESIGNATED_INITIALIZER;

@end
