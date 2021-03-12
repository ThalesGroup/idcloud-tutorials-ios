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
#import "EMTokenManager.h"
#import "EMVicToken.h"
#import "EMTokenCapability.h"
#import "EMProvisioningConfiguration.h"
#import "EMDeviceFingerprintTokenPolicy.h"

/**
 * VIC Token Manager
 */
@protocol EMVicTokenManager <NSObject,EMTokenManager>

/**
 Returns an existing token with the given name.
 
 @param name The name of the token.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The token, `nil` if not found or if an error occurred.
 */
- (id<EMVicToken>)tokenWithName:(NSString *)name error:(NSError **)error;

/**
 Returns an existing token with the given name and fingerprint.
 
 @param name The name of the token.
 @param fingerprintCustomData The fingerprint custom data.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The token, `nil` if not found or if an error occurred.
 */
- (id<EMVicToken>)tokenWithName:(NSString *)name fingerprintCustomData:(NSData *)fingerprintCustomData error:(NSError **)error;

/**
 Starts the creation of a new token via the specified provisioning configuration. Before creating the token, integrator has to make sure there is no existing token with the same token name.
 
 @param name The token name.
 @param configuration The provisioning configuration.
 @param completionHandler mandatory block to be invoked when error occurs or when token creation is completed.
 
 */
- (void)createTokenWithName:(NSString *)name provisioningConfiguration:(EMProvisioningConfiguration *)configuration completionHandler:(void (^)(id<EMToken> token, NSError *error))completionHandler;

/**
 Starts the creation of a new token with the specified provisioning configuration and device fingerprint policy. Before creating the token, integrator has to make sure there is no existing token with the same token name.
 
 @param name The token name.
 @param configuration The provisioning configuration.
 @param deviceFingerprintTokenPolicy device fingerprint token policy
 @param completionHandler mandatory block to be invoked when error occurs or when token creation is completed.
 
 */
- (void)createTokenWithName:(NSString *)name provisioningConfiguration:(EMProvisioningConfiguration *)configuration deviceFingerprintTokenPolicy:(EMDeviceFingerprintTokenPolicy *)deviceFingerprintTokenPolicy completionHandler:(void (^)(id<EMToken> token, NSError *error))completionHandler;

@end
