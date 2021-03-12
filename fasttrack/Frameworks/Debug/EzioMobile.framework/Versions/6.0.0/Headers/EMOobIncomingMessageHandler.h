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
#import "EMOobMessageHandler.h"
#import "EMOobIncomingMessage.h"

/**
 * Incoming message handler interface.
 *
 * - Since: 4.0
 */
@protocol EMOobIncomingMessageHandler <EMOobMessageHandler>

@required

/**
 * Parse incoming message from byte array into EMOobIncomingMessage object.
 *
 * @param mimeType MIME type of a message.
 * @param content content of the message in byte array.
 * @param error NSError object to for error during message parsing.
 *
 * return deserialized message object.
 * - Since: 4.0
 */
- (id<EMOobIncomingMessage>)deserializeWithMIMEType:(NSString *)mimeType withContent:(NSData *)content withError:(NSError **)error;

@end
