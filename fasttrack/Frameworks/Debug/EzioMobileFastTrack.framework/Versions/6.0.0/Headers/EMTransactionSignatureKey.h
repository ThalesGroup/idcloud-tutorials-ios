/** -----------------------------------------------------------------------------
 
 Copyright (c) 2019  -  GEMALTO DEVELOPMENT - R&D
 
 -----------------------------------------------------------------------------
 GEMALTO MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF
 THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 PARTICULAR PURPOSE, OR NON-INFRINGEMENT. GEMALTO SHALL NOT BE
 LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
 MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
 
 THIS SOFTWARE IS NOT DESIGNED OR INTENDED FOR USE OR RESALE AS ON-LINE
 CONTROL EQUIPMENT IN HAZARDOUS ENVIRONMENTS REQUIRING FAIL-SAFE
 PERFORMANCE, SUCH AS IN THE OPERATION OF NUCLEAR FACILITIES, AIRCRAFT
 NAVIGATION OR COMMUNICATION SYSTEMS, AIR TRAFFIC CONTROL, DIRECT LIFE
 SUPPORT MACHINES, OR WEAPONS SYSTEMS, IN WHICH THE FAILURE OF THE
 SOFTWARE COULD LEAD DIRECTLY TO DEATH, PERSONAL INJURY, OR SEVERE
 PHYSICAL OR ENVIRONMENTAL DAMAGE ("HIGH RISK ACTIVITIES"). GEMALTO
 SPECIFICALLY DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTY OF FITNESS FOR
 HIGH RISK ACTIVITIES.
 
 -----------------------------------------------------------------------------
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The Signature Key module.
 *
 * - Since: 5.3
 */
@interface EMTransactionSignatureKey : NSObject

/**
 * The public key.
 */
@property (nonatomic, strong, readonly) NSData *Y;

/**
 * Signature key - P
 */
@property (nonatomic, strong, readonly) NSData *P;

/**
 * Signature key - Q
 */
@property (nonatomic, strong, readonly) NSData *Q;

/**
 * Signature key - G.
 */
@property (nonatomic, strong, readonly) NSData *G;

/**
 *  Initialize a Signature Key with the public key, p value, q value and g value
 *
 *  @param y the public key
 *  @param p the p value
 *  @param q the q value
 *  @param g the g value
 *
 *  @return A newly initialized signature key
 */
- (instancetype)initWithY:(NSData *)y p: (NSData *)p q:(NSData *)q g:(NSData *)g NS_SWIFT_NAME(init(y:p:q:g:));

/**
 *  Initialize a Signature Key with the public key pem
 *
 *  @param publicKeyPem the public key in pem format
 *
 *  @return A newly initialized signature key
 */
- (instancetype)initWithPublicKeyPem:(NSString *)publicKeyPem NS_SWIFT_NAME(init(publicKeyPem:));

@end

NS_ASSUME_NONNULL_END
