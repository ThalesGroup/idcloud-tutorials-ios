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
#import "EMEmvFactory.h"
#import "EMEmvModule.h"

/**
 * Service class providing factory for creating decoder.
 *
 * - Since: 5.0
 */
@interface EMEmvService : NSObject

/**
 * Creates `EMEmvService` object.
 *
 * @param module an instance of `EMEmvModule`. Use `+[EMEmvModule createModule]` to obtain one.
 * @return Instance of `EMEmvService`.
 */
+ (nonnull EMEmvService*) createServiceWithModule: (nonnull EMEmvModule*)module;

/**
 * Creates `EMEmvFactory` object.
 *
 * @return Instance of `EMEmvFactory`.
 */
-(nonnull id<EMEmvFactory>) createFactory;

/**
 * Init method not available, please use createServiceWithModule to create object.
 */
- (nonnull id)init NS_UNAVAILABLE;

/**
 * New method not available, please use createServiceWithModule to create object.
 */
+ (nonnull id)new NS_UNAVAILABLE;

@end
