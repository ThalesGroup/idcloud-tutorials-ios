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
#import "EMSecureContainerFactory.h"

/**
 * Builder for building EMOobRequestParameter object.
 *
 * - Since: 4.7
 */
@interface EMOobRequestParameterBuilder : NSObject

/**
 * The additional customized HTTP headers.
 *
 * - Since: 4.7
 */
@property (nonatomic, strong) NSDictionary<NSString *, id<EMSecureString>> *customHeaders;

@end

/**
 * EMOobRequestParameter class for configuration of additional parameters of OOB request. For 4.7, only customized HTTP headers can be added for each request. To be built by EMOobRequestParameterBuilder.
 *
 * - Since: 4.7
 */
@interface EMOobRequestParameter : NSObject

/**
 * Designated constructor.
 * Creates a new EMOobRequestParameter object.
 *
 * @param optionalParameters The block that allows to set optional parameters. May be nil.
 *
 * @return EMOobRequestParameter object created containing the optional parameters.
 *
 * - Since: 4.7
 */
+ (instancetype)configurationWithOptionalParameters:(void(^)(EMOobRequestParameterBuilder *paramBuilder))optionalParameters;

/**
 * The additional customized HTTP headers.
 *
 * - Since: 4.7
 */
@property (nonatomic, readonly) NSDictionary<NSString *, id<EMSecureString>> *customHeaders;

@end
