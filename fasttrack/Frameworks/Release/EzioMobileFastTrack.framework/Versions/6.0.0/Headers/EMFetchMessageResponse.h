/* -----------------------------------------------------------------------------
 *
 *     Copyright (c)  2019  -  GEMALTO DEVELOPMENT - R&D
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
#import "EMIncomingMessage.h"
#import "EMGenericIncomingMessage.h"
#import "EMTransactionVerifyRequest.h"
#import "EMTransactionSigningRequest.h"
#import "EMMessengerResponse.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Fetch message response.
 * - Since: 5.3
 */
@interface EMFetchMessageResponse : NSObject<EMMessengerResponse>

/**
 * Check whether there is any incoming message.
 *
 * @return `YES` if any incoming message. Otherwise `NO`.
 */
@property (nonatomic, assign, readonly) BOOL hasIncomingMessage;

/**
 * Gets the underlying incoming message type.
 *
 * @return The incoming message type.
 */
@property (nonatomic, assign, readonly) EMIncomingMessageType messageType;

/**
 * Gets the generic incoming message from the response.
 *
 * @return The generic message.
 */
@property (nonatomic, strong, readonly, nullable) EMGenericIncomingMessage *genericIncomingMessage;

/**
 * Get the Transaction verification request message from the response.
 *
 * @return The transaction verification request.
 */
@property (nonatomic, strong, readonly, nullable) EMTransactionVerifyRequest *transactionVerifyRequest;

/**
 * Get the Transaction signing request message from the response.
 *
 * @return The transaction signing request.
 */
@property (nonatomic, strong, readonly, nullable) EMTransactionSigningRequest *transactionSigningRequest;

@end

NS_ASSUME_NONNULL_END
