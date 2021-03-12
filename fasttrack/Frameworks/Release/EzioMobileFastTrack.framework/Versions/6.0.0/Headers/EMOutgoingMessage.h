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
 * The outgoing message types.
 * - Since: 5.3
 */
typedef NS_ENUM(NSUInteger, EMOutgoingMessageType) {
    /**
     * Message to send is a Transaction Verification response.
     */
    EMOutgoingMessageTypeTransactionVerifyResponse,
    
    /**
     * Message to send is a Transaction Signing response.
     */
    EMOutgoingMessageTypeTransactionSigningResponse,
    
    /**
     * Message to send is a Generic one.
     */
    EMOutgoingMessageTypeGeneric
};

/**
 * Interface to an outgoing message to the OOB server.
 * - Since: 5.3
 */
@interface EMOutgoingMessage : NSObject<EMMessage>

/**
 * Gets the underlying message type.
 *
 * @return The message type.
 */
@property (nonatomic, assign, readonly) EMOutgoingMessageType messageType;

@end

NS_ASSUME_NONNULL_END
