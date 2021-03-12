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

#import "EMModule.h"
#import "EMPasswordManager.h"
#import "EMSecureContainerFactory.h"
#import "EMModuleConfiguration.h"

@protocol SecureLog;
@class SecureLogConfig;
/**
 * EMCore is the entry-point of the SDK Core. EMCore takes the configurations
 * needed for different modules and provides shared SDK functionalities.
 *
 * - Since: 4.0
 */
@interface  EMCore : NSObject

/**
 * Singleton instance of EMCore
 *
 * @return The singleton EMCore instance. This method requires Core to be configured before.
 * - Since: 4.0
 */
+ (instancetype)sharedInstance;

/**
 * Configure the secure log. Pass config = nil if you want to disable the logging.
 * This functions should be called before configuring the EZIOMobile SDK and can only be called once.
 * @param config consist of  public key and setting of SecureLog
 * @return id<SecureLog> the instance of SecureLog - use to interact with SecureLog feature.
 * Throw NSGenericException if the function is called more than once.
 * - Since: 6.0
*/
+ (id<SecureLog>)configureSecureLog:(SecureLogConfig*)config;

/**
 * Configures the core with module configurations. It is the entry point of the SDK. 
 * All other features should not be used without invoking this method.
 * Configuration can only be called once.
 *
 * @param configurations The set of module configurations.
 * - Since: 4.0
 */
+ (instancetype)configureWithConfigurations:(NSSet *)configurations;

/**
 * Configures the core with module configurations. It is the entry point of the SDK.
 * All other features should not be used without invoking this method.
 * Configuration can only be called once.
 *
 * @param configurations The set of module configurations.
 * @param useDeviceSourceBinding device binding to enable or disable DEVICE fingerprint source. Enabling this flag is equivalent to including 'DEVICE' in the Device Fingerprint Source configuration in 2.X.
 * - Since: 4.4
 */
+ (instancetype)configureWithConfigurations:(NSSet *)configurations useDeviceSourceBinding:(BOOL)useDeviceSourceBinding;

/**
 * Configures the core with module configurations. It is the entry point of the SDK.
 * All other features should not be used without invoking this method.
 * Configuration can only be called once.
 *
 * @param configurations The set of module configurations.
 * @param useDeviceSourceBinding device binding to enable or disable DEVICE fingerprint source. Enabling this flag is equivalent to including 'DEVICE' in the Device Fingerprint Source configuration in 2.X.
 * @param groupIdentifier The app group id, to allow group access to the files.
 * - Since: 4.7
 */
+ (instancetype)configureWithConfigurations:(NSSet *)configurations useDeviceSourceBinding:(BOOL)useDeviceSourceBinding groupIdentifier:(NSString *)groupIdentifier;

/**
 * Configures the core with module configurations. It is the entry point of the SDK.
 * All other features should not be used without invoking this method.
 * Configuration can only be called once.
 *
 * @param activationCode The activation code.
 * @param configurations The set of EMModuleConfiguration module configurations.
 * @exception NSException if core is already configured
 * - Since: 4.0
 */
+ (instancetype)configureWithActivationCode:(NSData *)activationCode configurations:(NSSet *)configurations;

/**
 * Configures the core with module configurations. It is the entry point of the SDK.
 * All other features should not be used without invoking this method.
 * Configuration can only be called once.
 *
 * @param activationCode The activation code.
 * @param configurations The set of EMModuleConfiguration module configurations.
 * @param useDeviceSourceBinding device binding to enable or disable DEVICE fingerprint source. Enabling this flag is equivalent to including 'DEVICE' in the Device Fingerprint Source configuration in 2.X.
 * @exception NSException if core is already configured
 * - Since: 4.4
 */
+ (instancetype)configureWithActivationCode:(NSData *)activationCode configurations:(NSSet *)configurations useDeviceSourceBinding:(BOOL)useDeviceSourceBinding;

/**
 * Configures the core with module configurations. It is the entry point of the SDK.
 * All other features should not be used without invoking this method.
 * Configuration can only be called once.
 *
 * @param activationCode The activation code.
 * @param configurations The set of EMModuleConfiguration module configurations.
 * @param useDeviceSourceBinding device binding to enable or disable DEVICE fingerprint source. Enabling this flag is equivalent to including 'DEVICE' in the Device Fingerprint Source configuration in 2.X.
 * @param groupIdentifier The app group id, to allow group access to the files.
 * @exception NSException if core is already configured
 * - Since: 4.7
 */
+ (instancetype)configureWithActivationCode:(NSData *)activationCode configurations:(NSSet *)configurations useDeviceSourceBinding:(BOOL)useDeviceSourceBinding groupIdentifier:(NSString *)groupIdentifier;

/**
 * Tells if the core has been configured or not
 *
 * @return YES if configured, NO otherwise.
 * - Since: 4.0
 */
+ (BOOL)isConfigured;

/**
 * Tells if device source binding is enabled or not
 *
 * @return YES if enabled, NO otherwise.
 * - Since: 4.4
 */
+ (BOOL)isDeviceSourceBindingEnabled;

/**
 * The version of the core.
 *
 * @return Version of the core.
 * - Since: 4.0
 */
+ (NSString *)version;

/**
 * Get passwordManager EMPasswordManager. which is used to unlock secrets used by different
 * modules.
 *
 * @return The password manager.
 * - Since: 4.0
 */
- (id <EMPasswordManager>)passwordManager;

/**
 * Get factory object for creating SecureContainer objects.
 *
 * @return Secure container factory.
 * - Since: 4.0
 */
- (id <EMSecureContainerFactory>)secureContainerFactory;

/**
 * Update Configuration.
 * This will replace existing one (if any) and add new one (if it does not exist previously).
 * However, it will not delete existing one if configs parameter does not contains some of existing one
 * @param configurations list of configuration parameters. It does not need to contains all existing configurations
 *
 * - Since: 5.3.0
 */
+ (void)updateConfigurations:(NSSet *)configurations;


////////////////////////////////////////////////////
// Allows migration of Keychain Items and Files
// This is especially useful, if the SDK is being used across multiple apps
// where a common Keychain Access Group and App Groups are specified so they
// can share keychain data and application files.
//
// - Since: 4.7
////////////////////////////////////////////////////

/**
Whether the SDK has pending migration
This is TRUE any of the following conditions are met:
1. App Bundle Version Update
2. Ezio SDK Upgrade
3. Change in Keychain Access Group
4. Change in Device Binding Parameter

 @return YES if there are pending items to migrate, NO otherwise

 - Since: 4.7
 */
- (BOOL)hasPendingMigration;

/**
 * Performs the migration
 * @warning Performed asynchronously
 *
 * Note: During migration, if TouchID/FaceID has been used before, TouchID/FaceID alert is prompted for authentication.
 * It is recommended that before calling this API, you have already notified the end user that authentication is
 * about to be done to continue with the migration.
 *
 * @param message The prompt message for TouchID/FaceID
 * @param completion The migration completion handler. Returns the status of migration and error if any.
 *
 * - Since: 4.7
 */
- (void)performMigrationWithAlertMessage:(NSString *)message completion:(void(^)(BOOL success, NSError *error))completion;

/**
 * Sets whether to ignore the pending migration or not.
 * @warning This is called only once. After this, hasPendingMigration will return to NO.
 *
 * @param ignore Whether to ignore or not.
 * - Since: 4.7
 */
- (void)ignoreMigration:(BOOL)ignore;

+ (void)dumpKeychain;

@end
