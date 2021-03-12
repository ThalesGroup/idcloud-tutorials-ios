/** -----------------------------------------------------------------------------
 
        Copyright (c) 2014  -  GEMALTO DEVELOPMENT - R&D
 
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

/**
   Pin error domain
 */

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wstrict-prototypes"

///
extern NSString * EMPinRuleErrorDomain;

#pragma clang diagnostic pop
/**
   NSError codes for EMPinRuleErrorDomain
 */
typedef NS_ENUM(NSInteger, EMPinRuleErrorCode)
{
    /** The pin contains non-numeric characters */
    EMNonNumericPinRuleError = 1,
    /** The digits in the pin are a series (e.g. 2345) */
    EMPinRuleSeriesError     = 2,
    /** The pin is a palindrome (e.g. 12321) */
    EMPinRulePalindromeError = 3,
    /** The old PIN and the new PIN are not allowed to be equal */
    EMPinRuleIdenticalError  = 4,
    /** The pin is too short or too long */
    EMPinRuleLengthError     = 5,
    /** The pin is uniform */
    EMPinRuleUniformError    = 6,
    /** The pin contains non-alphabetic characters */
    EMNonAlphabeticPinRuleError = 7,
    /** The pin must not be changed */
    EMPinMustNotBeChangedError = 8
};

/**
 * A protocol that represents a rule to apply to a PIN.  If the rule is found
 *  to be broken, then the PIN will not be accepted.
 *
 *  Applicable to tokens that can change their PIN.
 *
 *  - Since: 2.1
 */
@protocol EMPinRule <NSObject>

@end
