/* -----------------------------------------------------------------------------
 *
 *     Copyright (c)  2015  -  GEMALTO DEVELOPMENT - R&D
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
#import "EMOobMessage.h"

/**
 * Current supported outgoing message types.
 *
 * - Since: 3.0
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wstrict-prototypes"

///
extern NSString * EMOobOutgoingMessageTypeError;
///
extern NSString * EMOobOutgoingMessageTypeUserMessage;
///
extern NSString * EMOobOutgoingMessageTypeTransactionVerify;
///
extern NSString * EMOobOutgoingMessageTypeTransactionSigning;
///
extern NSString * EMOobOutgoingMessageTypeGeneric;

#pragma clang diagnostic pop

/**
 * Interface to an outgoing message to the OOB server.
 *
 * - Since: 3.0
 */
@protocol EMOobOutgoingMessage <EMOobMessage>

@required
/**
 * Gets the underlying outgoing message type.
 *
 * @return The outgoing message type.
 *
 * - Since: 3.0
 */
@property (nonatomic, readonly) NSString * messageType;

/**
 * Sets the message identifier.
 *
 * @param aMessageId Identifier of the message to send. Must not be `nil`.
 *
 * - Since: 3.0
 */
- (void)setMessageId:(NSString *)aMessageId __attribute__((deprecated));

/**
 * Sets the provider identifier.
 *
 * @param aProviderId Identifier of the provider. Must not be `nil`.
 *
 * - Since: 3.0
 */
- (void)setProviderId:(NSString *)aProviderId __attribute__((deprecated));

@end
