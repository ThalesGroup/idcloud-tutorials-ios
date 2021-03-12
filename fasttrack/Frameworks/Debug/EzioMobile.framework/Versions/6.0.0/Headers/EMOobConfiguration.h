/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2015  -  GEMALTO DEVELOPMENT - R&D
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
#import "EMDeviceFingerprintSource.h"
#import "EMOobJailbreakPolicy.h"

@class EMDeviceFingerprintSource;
@class EMTlsConfiguration;

@protocol EMOobManager;

/**
 * Builder for building EMOobConfiguration object.
 *
 * - Since: 4.0
 */
@interface EMOobConfigurationBuilder : NSObject


/**
 * The device fingerprint source. Overrides the default when set. Should not be nil.
 *
 * - Since: 4.0
 */
@property (nonatomic, strong) EMDeviceFingerprintSource *deviceFingerprintSource;

/**
 * The TLS configuration. Overrides the default when set. Should not be nil.
 *
 * - Since: 4.0
 */
@property (nonatomic, strong) EMTlsConfiguration *tlsConfiguration;

/**
 * The OOB Jailbreak policy. Overrides the default when set. The default is EMOobJailbreakPolicyFail.
 *
 * - Since: 4.0
 */
@property (nonatomic, assign) EMOobJailbreakPolicy jailbreakPolicy;

@end


/**
 * OobConfiguration for OOB module. To be built by
 * EMOobConfigurationBuilder
 *
 * - Since: 4.0
 */
@interface EMOobConfiguration : EMModuleConfiguration

/**
 * Designated constructor.
 * Creates new configuration based on default parameters
 *
 * @param optionalParameters The block that allows to set optional parameters. May be nil. If optionalParameters is set, do not assign properties to nil, or exception will be raised.
 *
 * @return EMOobModule module object created using the configurations that has been created.
 *
 * - Since: 4.0
 */
+ (instancetype)configurationWithOptionalParameters:(void(^)(EMOobConfigurationBuilder *configurationBuilder))optionalParameters;

/**
 * The device fingerprint source.
 *
 * - Since: 4.0
 */
@property (nonatomic, readonly) EMDeviceFingerprintSource *deviceFingerprintSource;

/**
 * The TLS configuration.
 *
 * - Since: 4.0
 */
@property (nonatomic, readonly) EMTlsConfiguration *tlsConfiguration;

/**
 * The OOB Jailbreak policy.
 *
 * - Since: 4.0
 */
@property (nonatomic, readonly) EMOobJailbreakPolicy jailbreakPolicy;

@end
