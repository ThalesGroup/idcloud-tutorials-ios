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
#import "EMTransactionVerifyResponse.h"
#import "EMMessageMeta.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Interface of a transaction verify request from the OOB server.
 * - Since: 5.3
 */
@interface EMTransactionVerifyRequest : EMIncomingMessage<EMMessageMeta>

/**
 * Gets the locale the message content is for.
 *
 * @return The locale.
 */
@property (nonatomic, copy, readonly) NSString *locale;

/**
 * Gets the content type of the generic message.
 *
 * @return The content type.
 */
@property (nonatomic, copy, readonly) NSString *contentType;

/**
 * Gets message content as a secure byte array.
 *
 * @return The content.
 */
@property (nonatomic, strong, readonly) NSData *content;

/**
 * Gets message content in form of string.
 *
 * @return The content.
 */
@property (nonatomic, strong, readonly) NSString *contentString;


/**
 * Gets message subject
 *
 * @return The subject.
 */
@property (nonatomic, copy, readonly) NSString *subject;


/**
 * Gets message content in specific encoding format.
 *
 * @param encoding          A string encoding.
 *
 * @return The content.
 */
- (NSString *)contentStringWithEncoding:(NSStringEncoding)encoding NS_SWIFT_NAME(contentString(encoding:));


/**
 * Creates an outgoing response for this transaction verification request message.
 *
 * @param aResponse         The response to provide to the transaction. See enum EMTransactionVerifyResponseValue.
 * @param aMeta             The metadata for the message.
 *
 * @return The outgoing message ready to be sent.
 */
- (EMTransactionVerifyResponse *)createWithResponse:(EMTransactionVerifyResponseValue)aResponse meta:(nullable NSDictionary<NSString *, NSString *> *)aMeta NS_SWIFT_NAME(create(response:meta:));


@end

NS_ASSUME_NONNULL_END
