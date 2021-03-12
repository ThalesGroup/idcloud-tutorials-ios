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
#import "EMOobOutgoingMessage.h"
#import "EMOobMessageMeta.h"

/**
 * Supported transaction signing responses values
 *
 * - Since: 4.4
 */
typedef NS_ENUM(NSUInteger, EMOobTransactionSigningResponseValue){
    
    /**
     * Transaction signing value as ACCEPTED
     *
     * - Since: 4.4
     */
    EMOobTransactionSigningResponseValueAccepted,
    
    /**
     * Transaction signing value as REJECTED
     *
     * - Since: 4.4
     */
    EMOobTransactionSigningResponseValueRejected
};


/**
 * Interface of a transaction signing response for the OOB server.
 *
 * - Since: 4.4
 */
@protocol EMOobTransactionSigningResponse <EMOobOutgoingMessage, EMOobMessageMeta>

/**
 * Gets the response value. See enum EMOobTransactionSigningResponseValue.
 *
 * @return The response.
 *
 * - Since: 4.4
 */
@property (nonatomic, assign, readonly) EMOobTransactionSigningResponseValue response;



@end
