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
#import "EMOobIncomingMessage.h"

/**
 * Interface to an object that contains a generic message received from the
 * OOB server.
 *
 * - Since: 3.0
 */
@protocol EMOobGenericIncomingMessage <EMOobIncomingMessage>

/**
 * Get the content type of the generic message.
 *
 * @return The content type.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSString *contentType;

/**
 * Gets the content of the generic message.
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
 * Gets message content in form of secure string in specific encoding format.
 *
 * @param encoding A string encoding.
 *
 * @return The content.
 *
 * - Since: 3.0
 */
- (id<EMSecureString>)contentStringWithEncoding:(NSStringEncoding)encoding;

@end
