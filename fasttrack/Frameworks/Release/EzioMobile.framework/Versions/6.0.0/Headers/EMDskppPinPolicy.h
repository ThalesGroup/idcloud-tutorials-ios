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

#import "EMPinPolicy.h"
#include "em_auth_pin_enums.h"

/**
 * Pubic Pin Type enum.
 * - Since: 4.1
 */
typedef NS_ENUM(NSUInteger, EMDskppPinType) {
    /**
     * User pin type.
     */
    EMDskppPinTypeUserPin = EMPinTypeUserPin,
    
    /**
     * Server pin type.
     */
    EMDskppPinTypeServerPin = EMPinTypeServerPin,
    
    /**
     * No pin type.
     */
    EMDskppPinTypeNoPin = EMPinTypeNoPin,
    
    /**
     * Unknown pin type.
     */
    EMDskppPinTypeUnknown = EMPinTypeUnknown
};

/**
 * Public Pin complexity enum.
 * - Since: 4.1
 */
typedef NS_ENUM(NSUInteger, EMDskppPinComplexity) {
    /**
     * Pin complexity numberic.
     */
    EMDskppPinComplexityNumeric = EMPinComplexityNumeric,
    
    /**
     * Pin complexity alpha numeric.
     */
    EMDskppPinComplexityAlphaNumeric = EMPinComplexityAlphaNumeric,
    
    /**
     * Pin complexity strong alpha numeric.
     */
    EMDskppPinComplexityStrongAlphaNumeric = EMPinComplexityStrongAlphaNumeric,
    
    /**
     * Pin complexity complex alpha numberic.
     */
    EMDskppPinComplexityComplexAlphaNumeric = EMPinComplexityComplexAlphaNumeric,
    
    /**
     * Pin complexity unknown.
     */
    EMDskppPinComplexityUnknown = EMPinComplexityUnknown
};

/**
 * The PIN policy object
 * - Since: 4.1
 */
@interface EMDskppPinPolicy: NSObject<EMPinPolicy>

/**
 * The Pin Type
 * - Since: 4.1
 */
@property (nonatomic, assign) EMPinType pinType;

/**
 * The Complexity of the pin/pass code
 * - Since: 4.1
 */
@property (nonatomic, assign) EMPinComplexity pinComplexity;

/**
 * The Minimum Passcode Length
 * - Since: 4.1
 */
@property (nonatomic, assign) int minLength;

/**
 * The Maximum Passcode Length
 * - Since: 4.1
 */
@property (nonatomic, assign) int maxLength;

@end
