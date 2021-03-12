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

#import "EMMessage.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The incoming message types.
 * - Since: 5.3
 */
typedef NS_ENUM(NSUInteger, EMIncomingMessageType) {
    /**
     * Not supported.
     */
    EMIncomingMessageTypeUnsupported,

    /**
     * Received message is a Transaction Verification request.
     */
    EMIncomingMessageTypeTransactionVerifyRequest,

    /**
     * Received message is a Transaction Signing request.
     */
    EMIncomingMessageTypeTransactionSigningRequest,
    
    /**
     * Received message is a Generic one.
     */
    EMIncomingMessageTypeGeneric
};

/**
 * Interface of an incoming message from the OOB server.
 *
 * - Since: 5.3
 */
@interface EMIncomingMessage : NSObject<EMMessage>

/**
 * Gets the underlying incoming message type.
 *
 * @return The incoming message type.
 */
@property (nonatomic, assign, readonly) EMIncomingMessageType messageType;

/**
 * The server acknowledgment state of the message.
 *
 * @return `YES` if the server has requested an acknowledgment, `NO` otherwise.
 */
@property (nonatomic, assign, readonly) BOOL isAcknowledgmentRequested;

/**
 * Gets the message expiration date.
 *
 * @return The expiration date in NSTimeInterval.
 */
@property (nonatomic, assign, readonly) NSTimeInterval expirationDate;

@end

NS_ASSUME_NONNULL_END
