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
#import "EMCapToken.h"
#import "EMSecureByteArray.h"
#import "EMTokenManager.h"
#import "EMTokenCapability.h"
#import "EMProvisioningConfiguration.h"
#import "EMDeviceFingerprintTokenPolicy.h"

/**
 * CAP Token Manager
 */
@protocol EMCapTokenManager <NSObject,EMTokenManager>

/**
 Returns an existing token with the given name.
 
 @param name The name of the token.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The token, `nil` if not found or if an error occurred.
 */
- (id<EMCapToken>)tokenWithName:(NSString *)name error:(NSError **)error;

/**
 Returns an existing token with the given name and fingerprint.
 
 @param name The name of the token.
 @param fingerprintCustomData The fingerprint custom data.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The token, `nil` if not found or if an error occurred.
 */
- (id<EMCapToken>)tokenWithName:(NSString *)name fingerprintCustomData:(NSData *)fingerprintCustomData error:(NSError **)error;

/**
 Returns an existing token with the given UTI (user token id).
 
 @param uti The UTI of the token.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The token, `nil` if not found or if an error occurred.
 - Since: 4.5
 */
- (id<EMCapToken>)tokenWithUti:(long)uti error:(NSError **)error;

/**
 Returns an existing token with the given UTI (user token id) and fingerprint.
 
 @param uti The UTI of the token.
 @param fingerprintCustomData The fingerprint custom data.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The token, `nil` if not found or if an error occurred.
 - Since: 4.5
 */
- (id<EMCapToken>)tokenWithUti:(long)uti fingerprintCustomData:(NSData *)fingerprintCustomData error:(NSError **)error;

/**
 Starts the creation of a new token with the specified token name and the provisioning configuration. Before creating the token, integrator has to make sure there is no existing token with the same token name.
 
 @param name The token name.
 @param configuration The provisioning configuration.
 @param completionHandler mandatory block to be invoked when error occurs or when token creation is completed.
 */
- (void)createTokenWithName:(NSString *)name provisioningConfiguration:(EMProvisioningConfiguration *)configuration completionHandler:(void (^)(id<EMCapToken> token, NSError *error))completionHandler;

/**
 Starts the creation of a new token with the specified token name, provisioning configuration, and device fingerprint policy. Before creating the token, integrator has to make sure there is no existing token with the same token name. This API does not support Mobile Provisioning Protocol version 5.
 
 @param name The token name.
 @param configuration The provisioning configuration.
 @param deviceFingerprintTokenPolicy device fingerprint token policy
 @param completionHandler mandatory block to be invoked when error occurs or when token creation is completed.
 */
- (void)createTokenWithName:(NSString *)name provisioningConfiguration:(EMProvisioningConfiguration *)configuration deviceFingerprintTokenPolicy:(EMDeviceFingerprintTokenPolicy *)deviceFingerprintTokenPolicy completionHandler:(void (^)(id<EMCapToken> token, NSError *error))completionHandler;

/**
 Starts the creation of a new token with the specified token name, provisioning configuration, and device fingerprint policy. Before creating the token, integrator has to make sure there is no existing token with the same token name. This API support Mobile Provisioning Protocol version 5 which will allows extensions to provide additional information set by the server, if any.
 
 @param name The token name.
 @param configuration The provisioning configuration.
 @param deviceFingerprintTokenPolicy device fingerprint token policy
 @param completionHandler mandatory block to be invoked when error occurs or when token creation is completed. Specific for Mobile Provisioning Protocol version 5, this handler will contains extensions information for any string extension of "client.app.*"

 - Since: 5.0
 */
- (void)createTokenWithName:(NSString *)name provisioningConfiguration:(EMProvisioningConfiguration *)configuration deviceFingerprintTokenPolicy:(EMDeviceFingerprintTokenPolicy *)deviceFingerprintTokenPolicy extendedCompletionHandler:(void (^)(id<EMCapToken> token, NSDictionary *extensions, NSError *error))completionHandler;

/**
 * To Creates a LowPlatformCoupling Token which is not affected by the changes in DeviceFingerprint.
 * <warn>A LowPlatformCoupling Token only permits PIN mode. [token upgradeToMultiAuthMode:input error:error] call is not allowed. <warn/>
 *
 * @param name The token name.
 * @param configuration The provisioning configuration.
 * @param completionHandler mandatory block to be invoked when error occurs or when token creation is completed. Specific for Mobile Provisioning Protocol version 5, this handler will contains extensions information for any string extension of "client.app.*"
 *
 * - Since: 5.2.0
 */
- (void)createLowPlatformCouplingToken:(NSString *)name provisioningConfiguration:(EMProvisioningConfiguration *)configuration extendedCompletionHandler:(void (^)(id<EMCapToken> token, NSDictionary *extensions, NSError *error))completionHandler;

@end
