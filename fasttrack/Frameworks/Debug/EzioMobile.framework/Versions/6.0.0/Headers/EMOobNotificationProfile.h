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

/**
 * This object represent one notification end point. A notification end point
 * is a mean by which a user can be notify by the Out of Band Server.
 *
 * Each notification profile contains a channel (SMS, Push, email, etc.) and an end point
 * attached to that channel (for example an email address for the case of an email channel).
 *
 * Each channel are dependent on the deployment environment and are completely
 * customizable by the application. Thus, no processing will be done on the channel
 * and value strings; they will be used "as-is".
 *
 * - Since: 3.0
 *
 */

@interface EMOobNotificationProfile : NSObject

/**
 * Returns the channel associated with this notification profile.
 * 
 * - Since: 3.0
 *
 * @return The channel associated with this notification profile.
 */
@property (nonatomic, copy, readonly) NSString *channel;

/**
 * Returns the value of the end point associated with this channel.
 *
 * since 3.0
 *
 * @return The value of the end point associated with this channel.
 */
@property (nonatomic, copy, readonly) NSString *endPoint;

/**
 * The constructor. Once build the object is immutable.
 *
 * @param aChannel The channel to use for the notification (SMS, push, email, etc.).This value must not be `nil`.
 * @param anEndPoint  An endPoint string.
 *
 * - Since: 3.0
 * 
 * @exception NSInvalidArgumentException If aChannel or anEndPoints is `nil`.
 */
- (id)initWithChannel:(NSString *)aChannel
             endPoint:(NSString *)anEndPoint;

@end