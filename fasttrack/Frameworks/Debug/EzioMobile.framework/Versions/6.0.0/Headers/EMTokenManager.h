/** -----------------------------------------------------------------------------
 
        Copyright (c) 2015  -  GEMALTO DEVELOPMENT - R&D
 
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
#import "EMToken.h"

/**
 * TokenManager error domain
 */
FOUNDATION_EXPORT NSString * const EMTokenManagerErrorDomain;

/**
 * NSError codes for EMTokenManagerErrorCode
 */
typedef NS_ENUM(NSInteger, EMTokenManagerErrorCode)
{
    /** The name is already used by an existing token. */
    EMNameAlreadyExistsTokenManagerError = 1,
};

/**
 * Token Builder
 */
@protocol EMTokenBuilder;

/**
 * The manager to create and retrieve tokens.
 */
@protocol EMTokenManager <NSObject>

/**
 * Returns the names of available tokens. An empty set is returned if no token
 * is found.
 *
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The available token names as a set of NSString.
 */
- (NSSet<NSString*> *)tokenNames:(NSError **)error;

/**
 * Removes an existing token.
 *
 * @param name The token name.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return `YES` if it existed and was removed, otherwise `NO`.
 */
- (BOOL)removeTokenWithName:(NSString *)name error:(NSError **)error;

/**
 * Removes an existing token.
 *
 * @param token The token to remove
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return `YES` if it existed and was removed, otherwise `NO`.
 */
- (BOOL)removeToken:(id<EMToken>)token error:(NSError **)error;

@end
