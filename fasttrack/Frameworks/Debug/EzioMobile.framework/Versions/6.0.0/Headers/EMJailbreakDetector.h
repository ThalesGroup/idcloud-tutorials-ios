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


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wstrict-prototypes"

///
extern NSString * EMJailbreakErrorDomain;


#pragma clang diagnostic pop


/**
   Error codes in EMJailbreakErrorDomain
  
   - Since: 2.3
 */
typedef NS_ENUM(NSInteger, EMJailbreakErrorCode)
{
    /** Returned if EomJailbreakPolicyFail is used and jailbreak detected */
    EMJailbreakPolicyError     = 1
};


/**
  Representation of the physical device's jailbreak status.
  
  - Since: 2.3
 */
typedef NS_ENUM(NSInteger, EMJailbreakStatus)
{
    /** The device is not jailbroken */
    EMJailbreakStatusNotJailbroken,
    /** The device is jailbroken */
    EMJailbreakStatusJailbroken
    
};


/**
  Gets the jailbreak status of the physical device.
  
  @return The jailbreak status.
  - Since: 2.3
 */
EMJailbreakStatus EMJailbreakDetectorGetJailbreakStatus(void) __attribute__((deprecated("This API is deprecated since 5.4. Use `EMDetectorJailbreakStatus` instead")));


