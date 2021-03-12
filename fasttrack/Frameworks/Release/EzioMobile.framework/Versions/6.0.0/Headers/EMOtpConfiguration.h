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
#import "EMModuleConfiguration.h"
#import "EMModule.h"
#import "EMTokenJailbreakPolicy.h"

/**
 * OTP Configuration
 *
 * - Since: 4.0
 */
@interface EMOtpConfiguration : EMModuleConfiguration

/**
 * Designated constructor where:
 *      default configuration for pin validation rules (all available);
 *      and EMTokenJailbreakPolicy EMTokenJailbreakPolicyFail
 *
 * @return EMOtpConfiguration module instance.
 *
 * - Since: 4.0
 */
+ (instancetype)defaultConfiguration;

/**
 * Designated constructor where:
 *      default configuration for pin validation rules (all available);
 *
 * @param jailbreakPolicy EMTokenJailbreakPolicy to set.
 * @return EMOtpConfiguration module instance.
 *
 * - Since: 4.0
 */
+ (instancetype)configurationWithJailbreakPolicy:(EMTokenJailbreakPolicy)jailbreakPolicy;

@end
