/* -----------------------------------------------------------------------------
 *
 *     Copyright (c)  2017  -  GEMALTO DEVELOPMENT - R&D
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
 * ------------------------------------------------------------------------------
 */

#import <Foundation/Foundation.h>
#import "EMOobIncomingMessage.h"
#import "EMOobTransactionSigningResponse.h"
#import "EMSecureString.h"
#import "EMOobMessageMeta.h"

/**
 * Interface of a transaction signing request from the OOB server.
 *
 * - Since: 4.4
 */
@protocol EMOobTransactionSigningRequest <EMOobIncomingMessage, EMOobMessageMeta>

/**
 * Gets the locale the message is designed for.
 *
 * @return The locale.
 *
 * - Since: 4.4
 */
@property (nonatomic, copy, readonly) NSString *locale;


/**
 * Gets MSP frame as a secure string. It is hex encoded.
 *
 * @return The MSP frame.
 *
 * - Since: 4.4
 */
@property (nonatomic, strong, readonly) id<EMSecureByteArray> mspFrame;


/**
 * Gets message subject
 *
 * @return The subject.
 *
 * - Since: 4.4
 */
@property (nonatomic, copy, readonly) id<EMSecureString> subject;


/**
 * Creates an outgoing response for this transaction signing request message.
 *
 * @param aResponse The response to provide to the transaction. See enum EMOobTransactionSigningResponseValue.
 * @param otp The OTP to send over to OOB server. Can be `nil`only if user denied the transaction.
 * @param aMeta The metadata for the message. Can be `nil`.
 *
 * @return The outgoing message ready to be sent.
 *
 * - Since: 4.4
 */
- (id<EMOobTransactionSigningResponse>)createWithResponse:(EMOobTransactionSigningResponseValue)aResponse otp:(id<EMSecureString>)otp meta:(NSDictionary *)aMeta;


@end
