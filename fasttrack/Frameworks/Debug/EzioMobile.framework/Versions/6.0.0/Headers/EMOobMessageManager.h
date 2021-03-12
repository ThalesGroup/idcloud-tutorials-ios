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
#import "EMSecureString.h"
#import "EMOobUserToProviderMessage.h"
#import "EMOobIncomingMessage.h"
#import "EMOobUserMessageAttachment.h"
#import "EMOobGenericOutgoingMessage.h"
#import "EMOobErrorMessage.h"
#import "EMOobOutgoingMessage.h"
#import "EMOobIncomingMessage.h"
#import "EMOobResponse.h"
#import "EMOobMessageResponse.h"
#import "EMOobFetchMessageResponse.h"
#import "EMOobRequestParameter.h"

/**
 * This manager provides a way to create outgoing messages for the server
 * and; fetch messages from or send messages to the server.
 *
 * - Since: 3.0
 */
@protocol EMOobMessageManager <NSObject>

/**
 * Creates an outgoing user-to-provider message.
 *
 * @param aLocale Locale to use to handle messages.
 * @param aCreateTime Message creation time. If `nil` the default system time is used.
 * @param aSubject Message subject.
 * @param aFrom Message originator. Can be `nil`.
 * @param aTo Message recipient.
 * @param aReplyTo Message recipient to use in case a response is send by the server. Can be `nil`.
 * @param aThreadId Message thread identifier.
 * @param aContentType Message content-type.
 * @param aContent Message content.
 * @param anAttachments Array of attachments to the message. Can be `nil`.
 * @param aMeta Meta data for the message. Can be `nil`.
 *
 * @return The user-to-provider message to be sent.
 *
 * - Since: 3.0
 */
- (id<EMOobUserToProviderMessage>)createUserToProviderMessageWithLocale:(NSString *)aLocale
                                                             createTime:(NSTimeInterval)aCreateTime
                                                                subject:(id<EMSecureString>)aSubject
                                                                   from:(NSString *)aFrom
                                                                     to:(NSString *)aTo
                                                                replyTo:(NSString *)aReplyTo
                                                               threadId:(NSString *)aThreadId
                                                            contentType:(NSString *)aContentType
                                                                content:(id<EMSecureByteArray>)aContent
                                                            attachments:(NSArray *)anAttachments
                                                                   meta:(NSDictionary *)aMeta;

/**
 * Creates a user message attachment.
 *
 * @param aSubject Message subject.
 * @param aContentType Message content-type.
 * @param aContent Message content.
 * @param aMeta Meta data for the message. Can be `nil`.
 *
 * @return The user message attachment to be sent.
 *
 * - Since: 3.0
 */
- (id<EMOobUserMessageAttachment>)createUserMessageAttachmentWithSubject:(id<EMSecureString>)aSubject
                                                             contentType:(NSString *)aContentType
                                                                 content:(id<EMSecureByteArray>)aContent
                                                                    meta:(NSDictionary *)aMeta;

/**
 * Creates a generic message.
 *
 * @param aContentType Message content-type.
 * @param aContent Message content.
 *
 * @return The generic outgoing message to be sent.
 *
 * - Since: 3.0
 */
- (id<EMOobGenericOutgoingMessage>)createGenericOutgoingMessageWithContentType:(NSString *)aContentType
                                                                       content:(id<EMSecureByteArray>)aContent;

/**
 * Creates an error message to be sent as a response.
 *
 * @param anErrorCode Error code.
 * @param anErrorDescription Error description.
 * @param anErrorStackTrace Error stack trace. Can be `nil`.
 * @param anExternalRef Any external reference. Can be `nil`.
 * @param aMeta Meta data for the message. Can be `nil`.
 *
 * @return The error message to be sent.
 *
 * - Since: 3.0
 */
- (id<EMOobErrorMessage>)createOobErrorWithErrorCode:(int)anErrorCode
                                    errorDescription:(NSString *)anErrorDescription
                                     errorStackTrace:(NSString *)anErrorStackTrace
                                         externalRef:(NSString *)anExternalRef
                                                meta:(NSDictionary *)aMeta;

/**
 * Creates an error message to be sent as a response.
 *
 * @param anErrorCode Error code.
 * @param anErrorDescription Error description.
 * @param anException NSException object. Can be `nil`.
 * @param anExternalRef Any external reference. Can be `nil`.
 * @param aMeta Meta data for the message. Can be `nil`.
 *
 * @return The error message to be sent.
 *
 * - Since: 3.0
 */
- (id<EMOobErrorMessage>)createOobErrorWithErrorCode:(int)anErrorCode
                                    errorDescription:(NSString *)anErrorDescription
                                           exception:(NSException *)anException
                                         externalRef:(NSString *)anExternalRef
                                                meta:(NSDictionary *)aMeta;


/**
 * Fetches a message from the server.
 * This method retrieves the first message from server queue.
 *
 * @warning This method blocks the calling thread potentially for a very long time (like
 * tens of seconds or even more, depending on the quality of the mobile network connection).
 *
 * @param aTimeout Maximum time in seconds to wait for an incoming message.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return The incoming message response if any.
 *
 * - Since: 3.0
 */
- (id<EMOobFetchMessageResponse>)fetchWithTimeout:(NSInteger)aTimeout error:(NSError **)anError;

/**
 * Fetches a message from the server.
 * This method retrieves the first message from server queue.
 *
 * @warning This method blocks the calling thread potentially for a very long time (like
 * tens of seconds or even more, depending on the quality of the mobile network connection).
 *
 * @param aTimeout Maximum time in seconds to wait for an incoming message.
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return The incoming message response if any.
 *
 * - Since: 4.7
 */
- (id<EMOobFetchMessageResponse>)fetchWithTimeout:(NSInteger)aTimeout requestParameter:(EMOobRequestParameter*)aParam error:(NSError **)anError;

/**
 * Fetches a message from the server.
 * This method retrieves the first message from server queue.
 *
 * @warning This method is executed asynchronously
 *
 * @param aTimeout Maximum time in seconds to wait for an incoming message.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains 
 * the response and error information if any.
 *
 * - Since: 3.0
 */
- (void)fetchWithTimeout:(int)aTimeout
       completionHandler:(void (^)(id<EMOobFetchMessageResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Fetches a message from the server.
 * This method retrieves the first message from server queue.
 *
 * @warning This method is executed asynchronously
 *
 * @param aTimeout Maximum time in seconds to wait for an incoming message.
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 4.7
 */
- (void)fetchWithTimeout:(int)aTimeout requestParameter:(EMOobRequestParameter*)aParam
       completionHandler:(void (^)(id<EMOobFetchMessageResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Fetches a message from the server.
 * This method retrieves a message with a specific identifier.
 *
 * @warning This method blocks the calling thread potentially for a very long time (like
 * tens of seconds or even more, depending on the quality of the mobile network connection).
 *
 * @param aMessageId Identifier of the message to fetch.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return The incoming message response if any.
 *
 * - Since: 3.0
 */
- (id<EMOobFetchMessageResponse>)fetchWithMessageId:(NSString *)aMessageId error:(NSError **)anError;

/**
 * Fetches a message from the server.
 * This method retrieves a message with a specific identifier.
 *
 * @warning This method blocks the calling thread potentially for a very long time (like
 * tens of seconds or even more, depending on the quality of the mobile network connection).
 *
 * @param aMessageId Identifier of the message to fetch.
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return The incoming message response if any.
 *
 * - Since: 4.7
 */
- (id<EMOobFetchMessageResponse>)fetchWithMessageId:(NSString *)aMessageId requestParameter:(EMOobRequestParameter*)aParam error:(NSError **)anError;

/**
 * Fetches a message from the server.
 * This method retrieves a message with a specific identifier.
 *
 * @warning This method is executed asynchronously
 *
 * @param aMessageId Identifier of the message to fetch.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 3.0
 */
- (void)fetchWithMessageId:(NSString *)aMessageId
         completionHandler:(void (^)(id<EMOobFetchMessageResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Fetches a message from the server.
 * This method retrieves a message with a specific identifier.
 *
 * @warning This method is executed asynchronously
 *
 * @param aMessageId Identifier of the message to fetch.
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 4.7
 */
- (void)fetchWithMessageId:(NSString *)aMessageId requestParameter:(EMOobRequestParameter*)aParam
         completionHandler:(void (^)(id<EMOobFetchMessageResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Sends a message to the server
 *
 * @warning This method blocks the calling thread potentially for a very long time (like
 * tens of seconds or even more, depending on the quality of the mobile network connection).
 *
 * @param aMessage The object that will be use to post the result to the UI thread.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return Result of the request.
 *
 * - Since: 3.0
 */
- (id<EMOobMessageResponse>)sendWithMessage:(id<EMOobOutgoingMessage>)aMessage error:(NSError **)anError;

/**
 * Sends a message to the server
 *
 * @warning This method blocks the calling thread potentially for a very long time (like
 * tens of seconds or even more, depending on the quality of the mobile network connection).
 *
 * @param aMessage The object that will be use to post the result to the UI thread.
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return Result of the request.
 *
 * - Since: 4.7
 */
- (id<EMOobMessageResponse>)sendWithMessage:(id<EMOobOutgoingMessage>)aMessage requestParameter:(EMOobRequestParameter*)aParam error:(NSError **)anError;

/**
 * Sends a message to the server.
 *
 * @warning This method is executed asynchronously
 *
 * @param aMessage The message to send.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 3.0
 */

- (void)sendWithMessage:(id<EMOobOutgoingMessage>)aMessage
      completionHandler:(void (^)(id<EMOobMessageResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Sends a message to the server.
 *
 * @warning This method is executed asynchronously
 *
 * @param aMessage The message to send.
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 4.7
 */
- (void)sendWithMessage:(id<EMOobOutgoingMessage>)aMessage requestParameter:(EMOobRequestParameter*)aParam
      completionHandler:(void (^)(id<EMOobMessageResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Sends a message acknowledgment to the server
 *
 * @warning This method blocks the calling thread potentially for a very long time (like
 * tens of seconds or even more, depending on the quality of the mobile network connection).
 *
 * @param aMessage The incoming message to acknowledge.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return Result of the request.
 *
 * - Since: 3.0
 */
- (id<EMOobResponse>)acknowledgeWithMessage:(id<EMOobIncomingMessage>)aMessage error:(NSError **)anError;

/**
 * Sends a message acknowledgment to the server
 *
 * @warning This method blocks the calling thread potentially for a very long time (like
 * tens of seconds or even more, depending on the quality of the mobile network connection).
 *
 * @param aMessage The incoming message to acknowledge.
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return Result of the request.
 *
 * - Since: 4.7
 */
- (id<EMOobResponse>)acknowledgeWithMessage:(id<EMOobIncomingMessage>)aMessage requestParameter:(EMOobRequestParameter*)aParam error:(NSError **)anError;

/**
 * Sends a message acknowledgment to the server.
 *
 * @warning This method is executed asynchronously
 *
 * @param aMessage The incoming message to acknowledge.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 3.0
 */
- (void)acknowledgeWithMessage:(id<EMOobIncomingMessage>)aMessage
             completionHandler:(void (^)(id<EMOobResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Sends a message acknowledgment to the server.
 *
 * @warning This method is executed asynchronously
 *
 * @param aMessage The incoming message to acknowledge.
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 4.7
 */
- (void)acknowledgeWithMessage:(id<EMOobIncomingMessage>)aMessage requestParameter:(EMOobRequestParameter*)aParam
             completionHandler:(void (^)(id<EMOobResponse> aResponse, NSError *anError))aCompletionHandler;

@end
