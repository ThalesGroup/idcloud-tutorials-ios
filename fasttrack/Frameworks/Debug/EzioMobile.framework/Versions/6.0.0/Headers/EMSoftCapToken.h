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

#import <Foundation/Foundation.h>
#import "EMCapToken.h"

/**
   Pin error domain
 */
FOUNDATION_EXPORT NSString * const EMPinErrorDomain;

/**
   NSError codes for EMPinErrorDomain
 */
typedef NS_ENUM(NSInteger, EMPinErrorCode)
{
    /** The digits in the pin is a series (e.g. 2345) */
    EMPinNumericSeriesError     = 1,
    /** The pin has non digits characters (e.g. 23AF) */
    EMPinNonDigitsError         = 2,
    /** The pin is a palindrome (e.g. 12321) */
    EMPinPalindromeError        = 3,
    /** All digits in the pin is the same number (e.g. 2222) */
    EMPinSameDigitsError        = 4,
    /** The pin is too short */
    EMPinTooShortError          = 5,
    /** The new pin equals the old one */
    EMPinEqualsOldPinError      = 6,
    /**
     * The error was caused by an error in the EMPinRuleErrorDomain
     * To access the error, use the NSUnderlyingErrorKey key on the userInfo.
     *
     * - Since: 2.1
     */
    EMPinRuleErrorDomainError   = 7,
};

/**
   Soft CAP token.
 */
@protocol EMSoftCapToken <NSObject, EMCapToken>


@end
