/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2018  -  GEMALTO DEVELOPMENT - R&D
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
 * Enum type containing the possible handling when detecting hooking.
 *
 * - Since: 4.7
 */
typedef enum EMHookingDetectionPolicy {
    /**
     * Fail on hook detected (throws an exception).
     */
    EMHookingDetectionPolicyFail = 0,
    
    /**
     * Ignore on hook detected. Will preceed as normal.
     */
    EMHookingDetectionPolicyIgnore = 1
} EMHookingDetectionPolicy;

/**
 * Typedef for the function pointer to get the hooking detection callback
 *
 * @return the status of the operation
 *
 * - Since: 4.7
 */
typedef EMHookingDetectionPolicy(*EMHookingDetectionListener)(void);

/**
 * Set hooking detection listener to receive callbacks when protected methods in SDK are detected as hooked.
 * If this function is not called, SDK will not protect any methods.
 * @warning *Important:* that it is required to call this before [EMCore configureWithConfigurations] since detection is included
 * during the core configuration call.
 *
 * @param listener HookingDetection callback
 * @throw raise:NSInvalidArgumentException if listener is nil.
 *
 * - Since: 4.7
 */
void EMHookingDetectionSetListener(EMHookingDetectionListener listener);

/**
 * Remove hooking detection listener.
 *
 * It is recommended to call this API when the implementation is no longer in use. eg.
 * When the ViewController is killed application must remove the listener to avoid leaks.
 * And to add back the listener when the ViewController is created.
 *
 * @warning By using this option, it potentially opens one attack point.
 *
 * - Since: 4.7
 */
void EMHookingDetectionClearListener(void);


