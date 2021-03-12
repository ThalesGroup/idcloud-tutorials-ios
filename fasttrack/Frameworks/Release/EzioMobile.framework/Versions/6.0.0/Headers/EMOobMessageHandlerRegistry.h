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

/**
 * Registery of EMOobMessageHandler. Manages the registration/un-registration of EMOobMessageHandler. Incoming message and outgoing message will be parsed by registered message handlers identified by its MIME type.
 *
 * If no message handler is registered to handle a message, it will be handled internally by the SDK as a generic message.
 *
 * - Since: 4.0
 */
@interface EMOobMessageHandlerRegistry : NSObject

/**
 * Get the registry of EMOobMessageHandler.
 *
 * @return registry instance.
 *
 * - Since: 4.0
 */
+ (instancetype)sharedInstance;


/**
 * Check if a handler for given MIME type has been registered.
 *
 * @param mimeType MIME type of a message.
 *
 * @return if registered.
 *
 * - Since: 4.0
 */
- (BOOL)isRegistered:(NSString *)mimeType;

/**
 * Register a message handler. It accepts both outgoing & incoming message handler.
 *
 * @warning The following message type has been used internally by the SDK. Avoid using any of them.
 * <ul>
 * <li>"message/vnd.gemalto.ezio.oob.ErrorReport_1.0+json"</li>
 * <li>"message/vnd.gemalto.ezio.oob.VerifyTransaction_1.0+json"</li>
 * <li>"message/vnd.gemalto.ezio.oob.VerifyTransactionResponse_1.0+json"</li>
 * <li>"message/vnd.gemalto.ezio.oob.UserMessage_1.0+json"</li>
 * </ul>
 *
 * @param mimeType MIME type of a message.
 * @param oobMessageHandler implementation of EMOobMessageHandler.
 *
 * - Since: 4.0
 */
- (void)registerMIMEType:(NSString *)mimeType withOobMessageHandler:(id<EMOobMessageHandler>)oobMessageHandler;

/**
 * Unregister a message handler. Once unregistered, message with given MIME type will be parsed internally by the SDK as generic message.
 *
 * @warning The following message type has been used internally by the SDK. Avoid removing any of them.
 * <ul>
 * <li>"message/vnd.gemalto.ezio.oob.ErrorReport_1.0+json"</li>
 * <li>"message/vnd.gemalto.ezio.oob.VerifyTransaction_1.0+json"</li>
 * <li>"message/vnd.gemalto.ezio.oob.VerifyTransactionResponse_1.0+json"</li>
 * <li>"message/vnd.gemalto.ezio.oob.UserMessage_1.0+json"</li>
 * </ul>
 *
 * @param mimeType MIME type of a message.
 *
 * - Since: 4.0
 */
- (void)unregisterMIMEType:(NSString *)mimeType;

/**
 * Get a message handler of given MIME type.
 *
 * @param mimeType MIME type of a message.
 *
 * @return Implementation of EMOobMessageHandler.
 *
 * - Since: 4.0
 */
- (id<EMOobMessageHandler>)oobMessageHandlerWithMIMEType:(NSString *)mimeType;

@end
