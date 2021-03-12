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
#import "EMOobErrorMessage.h"

/**
 * Current supported incoming message types.
 *
 * - Since: 3.0
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wstrict-prototypes"

///
extern NSString * EMOobIncomingMessageTypeUserMessage;
///
extern NSString * EMOobIncomingMessageTypeTransactionVerify;
///
extern NSString * EMOobIncomingMessageTypeGeneric;
///
extern NSString * EMOobIncomingMessageTypeTransactionSigning;

#pragma clang diagnostic pop

/**
 * Interface of an incoming message from the OOB server.
 *
 * - Since: 3.0
 */
@protocol EMOobIncomingMessage <EMOobMessage>

@required
/**
 * Gets the underlying incoming message type.
 *
 * @return The incoming message type.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy) NSString * messageType;

/**
 * The server acknowledgment state of the message.
 *
 * @return `YES` if the server has requested an acknowledgment, `NO` otherwise.
 *
 * - Since: 3.0
 */
@property (nonatomic, assign, readonly) BOOL isAcknowledgmentRequested;

/**
 * Gets the message expiration date.
 *
 * @return The expiration date in NSTimeInterval.
 *
 * - Since: 3.0
 */
@property (nonatomic, assign, readonly) NSTimeInterval expirationDate;

/**
 * Creates an outgoing error response for the current message.
 *
 * @param anErrorCode Error code.
 * @param anErrorDescription Error description.
 * @param anException Exception object. Can be `nil`.
 * @param anExternalRef Any external reference. Can be `nil`.
 * @param aMeta Meta data for the message. Can be `nil`.
 *
 * @return The error message ready to be sent.
 *
 * - Since: 3.0
 */
- (id<EMOobErrorMessage>)createOobError:(int)anErrorCode
                       errorDescription:(NSString *)anErrorDescription
                              exception:(NSException *)anException
                            externalRef:(NSString *)anExternalRef
                                   meta:(NSDictionary *)aMeta;

/**
 * Creates an outgoing error response for the current message.
 *
 * @param anErrorCode Error code.
 * @param anErrorDescription Error description.
 * @param anErrorStackTrace Error stack trace. Can be `nil`.
 * @param anExternalRef Any external reference. Can be `nil`.
 * @param aMeta Meta data for the message. Can be `nil`.
 *
 * @return The error message ready to be sent.
 *
 * - Since: 3.0
 */
- (id<EMOobErrorMessage>)createOobError:(int)anErrorCode
                       errorDescription:(NSString *)anErrorDescription
                        errorStackTrace:(NSString *)anErrorStackTrace
                            externalRef:(NSString *)anExternalRef
                                   meta:(NSDictionary *)aMeta;


@end
