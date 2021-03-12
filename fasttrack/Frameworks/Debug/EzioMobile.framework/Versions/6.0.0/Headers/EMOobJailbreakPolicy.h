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
 * The OOB behavior policy of the Mobile Protector SDK when the physical device is
 * detected as being rooted.
 * 
 * - Since: 4.0
 */
typedef NS_ENUM(NSInteger, EMOobJailbreakPolicy)
{
    /**
     * No action is taken when calling any OOB related API of Mobile Protector SDK
     * even the physical device is jailbroken.
     */
    EMOobJailbreakPolicyIgnore,
    /**
     * A RootPolicyException is thrown when calling a method in the
     * Mobile Protector SDK that detects if the physical device is jailbroken.
     * <b>Notice!</b> This is the default jailbroken policy.
     */
    EMOobJailbreakPolicyFail,
    /**
     * A RootPolicyException is thrown and client is silently
     * unregistered when calling a method in the Mobile Protector SDK that detects if
     * the physical device is jailbroken.
     */
    EMOobJailbreakPolicyUnregister
};

/**
 * Returns the current OOB behavior policy when the device is detected as
 * jailbroken.
 *
 * @return The current policy.
 * - Since: 4.0
 */
EMOobJailbreakPolicy EMOobJailbreakPolicyGetPolicy(void);

/**
 * Sets the OOB behavior policy when the device is detected as jailbroken.
 *
 * @param anOobJailbreakPolicy The new policy.
 * - Since: 4.0
 */
void EMOobJailbreakPolicySetPolicy(EMOobJailbreakPolicy anOobJailbreakPolicy);

