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
#import "EMOutgoingMessage.h"
#import "EMIncomingMessage.h"
#import "EMFetchMessageResponse.h"
#import "EMSendMessageResponse.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The manager provides way to create outgoing messages for the server
 * and send/fetch messages to/from the server.
 * - Since: 5.3
 */
@interface EMMobileMessageManager : NSObject

/**
 * Fetch a message from the server.
 * This method fetches the first message from server queue.
 *
 * @param timeout           Maximum time in second to wait for an incoming message.
 * @param headers           The request parameter containing custom header.
 * @param completionHandler The block to invoke on the main thread upon completion which contains the response and error information if any.
 */
- (void)fetchMessageWithTimeout:(NSTimeInterval)timeout
                  customHeaders:(nullable NSDictionary<NSString *, NSString *> *)headers
              completionHandler:(void(^)(EMFetchMessageResponse * _Nullable aResponse, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(fetchMessage(timeout:customHeaders:completionHandler:));

/**
 * Fetch a message from the server.
 * This method fetches the first message from server queue.
 *
 * @param messageId         Identifier of the message to fetch.
 * @param headers           The request parameter containing custom header.
 * @param completionHandler The block to invoke on the main thread upon completion which contains the response and error information if any.
 */
- (void)fetchMessageWithMessageId:(NSString *)messageId
                    customHeaders:(nullable NSDictionary<NSString *, NSString *> *)headers
                completionHandler:(void(^)(EMFetchMessageResponse * _Nullable aResponse, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(fetchMessage(messageId:customHeaders:completionHandler:));

/**
 * Sends a message acknowledgment to the server.
 *
 * @param incomingMessage   The incoming message to acknowledge.
 * @param headers           The request parameter containing custom header.
 * @param completionHandler The block to invoke on the main thread upon completion which contains the response and error information if any.
 */
- (void)acknowledgeMessage:(EMIncomingMessage *)incomingMessage
             customHeaders:(nullable NSDictionary<NSString *, NSString *> *)headers
         completionHandler:(void(^)(BOOL success, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(acknowledge(message:customHeaders:completionHandler:));

/**
 * Sends a message to the server.
 *
 * @param outgoingMessage   The message to send.
 * @param headers           The request parameter containing custom header.
 * @param completionHandler The block to invoke on the main thread upon completion which contains the response and error information if any.
 */
- (void)sendMessage:(EMOutgoingMessage *)outgoingMessage
      customHeaders:(nullable NSDictionary<NSString *, NSString *> *)headers
  completionHandler:(void(^)(EMSendMessageResponse * _Nullable aResponse, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(send(message:customHeaders:completionHandler:));

/**
 * Creates a generic message that can be sent to the OOB server.
 *
 * @param contentType      Message content-type.
 * @param content          Message content.
 * @return The generic message ready to be sent.
 */
- (EMOutgoingMessage *)createGenericOutgoingMessageWithContentType:(NSString *)contentType
                                                           content:(NSData *)content NS_SWIFT_NAME(createGenericOutgoingMessage(contentType:content:));

@end

NS_ASSUME_NONNULL_END
