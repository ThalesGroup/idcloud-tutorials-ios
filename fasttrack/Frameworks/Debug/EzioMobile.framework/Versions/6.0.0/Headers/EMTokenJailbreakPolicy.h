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

/**
 The token policy of the Mobile Protector SDK when the physical device is
 detected as being jailbroken.
 
 - Since: 4.0
 */
typedef NS_ENUM(NSInteger, EMTokenJailbreakPolicy)
{
    /**
     * No action is taken when calling any token operation related method of Mobile Protector SDK
     * even the physical device is jailbroken.
     */
    EMTokenJailbreakPolicyIgnore,
    
    /** A EMJailbreakError is returned via the error parameter when calling a method in the Mobile Protector SDK that detects if the physical device is jailbroken.
     */
    EMTokenJailbreakPolicyFail,
    
    /** A EMJailbreakError is returned via the error parameter and the associated token is silently removed when calling a method in the Mobile Protector SDK that detects if the physical device is jailbroken.
     */
    EMTokenJailbreakPolicyRemoveToken,
    
    /** A EMJailbreakErrorDomain is returned via the error parameter and all tokens are silently
     removed when calling a method in the Mobile Protector SDK that detects if the physical device is jailbroken.
     */
    EMTokenJailbreakPolicyRemoveAllTokens
    
};

/**
 Returns the current token behavior policy when the device is detected as
 jailbroken.
 
 @return The current policy.
 - Since: 4.0
 */
EMTokenJailbreakPolicy EMTokenJailbreakPolicyGetPolicy(void);


/**
 Sets the token behavior policy when the device is detected as jailbroken.
 
 @param aTokenJailbreakPolicy The new policy.
 - Since: 4.0
 */
void EMTokenJailbreakPolicySetPolicy(EMTokenJailbreakPolicy aTokenJailbreakPolicy);

