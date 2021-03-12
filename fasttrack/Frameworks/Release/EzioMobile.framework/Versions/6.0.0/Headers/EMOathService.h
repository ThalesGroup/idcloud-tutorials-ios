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
#import "EMOtpModule.h"
#import "EMOathTokenManager.h"
#import "EMOathFactory.h"

/**
 * OathService is the entry-point for Oath features.
 * 
 * - Since: 4.0
 */
@interface EMOathService : NSObject

/**
 * Designated constructor.
 * Returns the EMOathService object created using the EMOtpModule
 *
 * @param module an instance of EMOtpModule
 * @return EMOathService module instance.
 *
 * - Since: 4.0
 */
+ (instancetype)serviceWithModule:(EMOtpModule *)module;

/**
 * Returns Factory for creating OATH settings and OATH devices.
 *
 * @return EMCapFactory object.
 *
 * - Since: 4.0
 */
- (EMOathFactory *)oathFactory;

/**
 * Returns object which confirms to EMOathTokenManager protocol for OATH tokens.
 * Note an error could return if database file is not decrypted in time, please try again.
 *
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return object which confirms to EMCapTokenManager protocol.
 * - Since: 4.0
 */
- (id <EMOathTokenManager>)tokenManager:(NSError **)error;

@end
