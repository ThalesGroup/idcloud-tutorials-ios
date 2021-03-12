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
#import "EMOobIncomingMessage.h"
#import "EMOobUserToProviderMessage.h"
#import "EMSecureString.h"
#import "EMOobMessageMeta.h"

/**
 * Interface of an incoming user message from the server.
 *
 * - Since: 3.0
 */
@protocol EMOobProviderToUserMessage <EMOobIncomingMessage, EMOobMessageMeta>

/**
 * Gets the locale the message content is for.
 *
 * @return The locale.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSString *locale;

/**
 * Gets the content type of the generic message.
 *
 * @return The content type.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSString *contentType;

/**
 * Gets message content as secure byte array.
 *
 * @return The content.
 *
 * - Since: 3.0
 */
@property (nonatomic, strong, readonly) id<EMSecureByteArray> content;

/**
 * Gets message content in form of secure string.
 *
 * @return The content.
 *
 * - Since: 3.0
 */
@property (nonatomic, strong, readonly) id<EMSecureString> contentString;

/**
 * Gets message subject
 *
 * @return The subject.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) id<EMSecureString> subject;

/**
 * Gets the message creation date.
 *
 * @return The creation date.
 *
 * - Since: 3.0
 */
@property (nonatomic, assign, readonly) NSTimeInterval createTime;

/**
 * Gets the message originator.
 *
 * @return The originator.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSString *from;

/**
 * Gets the message recipient.
 *
 * @return The recipient.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSString *to;

/**
 * Gets the recipient to use for a response.
 *
 * @return The response's recipient.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSString *replyTo;

/**
 * Gets the message thread identifier.
 *
 * @return The thread identifier.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSString *threadId;

/**
 * Gets messages attachments.
 *
 * @return The attachments.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSArray *attachments;


/**
 * Gets message content in form of secure string in specific encoding format.
 *
 * @param encoding A string encoding.
 *
 * @return The content.
 *
 * - Since: 3.0
 */
- (id<EMSecureString>)contentStringWithEncoding:(NSStringEncoding)encoding;

/**
 * Create an outgoing response for the current message.
 *
 * The recipient field (`to`) of the created message is set to the value of the
 * response recipient (`replyTo`) of the incoming message.
 *
 * The response thread identifier field (`threadId`) is set to the same value
 * than the incoming message.
 *
 * @param aLocale Locale to use to handle messages.
 * @param aCreateTime Message creation time. If `nil` the default system time is used.
 * @param aSubject Message subject.
 * @param aFrom Message originator. Can be `nil`.
 * @param aContentType Message content-type.
 * @param aContent Message content.
 * @param anAttachments Array of attachments to the message. Can be `nil`.
 * @param aMeta Meta data for the message. Can be `nil`.
 *
 * @return The outgoing message ready to be sent.
 *
 * - Since: 3.0
 */
- (id<EMOobUserToProviderMessage>)createResponseWithLocale:(NSString *)aLocale
                                                createTime:(NSTimeInterval)aCreateTime
                                                   subject:(id<EMSecureString>)aSubject
                                                      from:(NSString *)aFrom
                                               contentType:(NSString *)aContentType
                                                   content:(id<EMSecureByteArray>)aContent
                                               attachments:(NSArray *)anAttachments
                                                      meta:(NSDictionary *)aMeta;


@end
