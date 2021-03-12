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
#import "EMOobOutgoingMessage.h"
#import "EMOobMessageMeta.h"


/**
 * Current supported error message codes.
 * - Since: 3.0
 */
typedef NS_ENUM(NSUInteger, EMOobErrorMessageCode){
    /**
     * Error code: Unsupported locale.
     */
    EMOobErrorMessageCodeUnsupportedLocale = 1000,
    
    /**
     * Error code: Unsupported content type.
     */
    EMOobErrorMessageCodeUnsupportedContentType = 1001,
    
    /**
     * Error code: Corrupted content.
     */
    EMOobErrorMessageCodeCorruptedContent = 1002,
    
    /**
     * Error code: Unknown "TO" (recipient).
     */
    EMOobErrorMessageCodeUnknownRecipient = 1003,
    
    /**
     * Baseline for the application specific error codes. I.e. the custom error codes should be 10000, 10001, ...
     */
    EMOobErrorMessageCodeCustomBase = 10000
};


/**
 * This object allows the client to send some error information to the server.
 *
 * - Since: 3.0
 */
@protocol EMOobErrorMessage <EMOobOutgoingMessage, EMOobMessageMeta>

/**
 * Gets the error code.
 *
 * @return The error code.
 *
 * - Since: 3.0
 */
@property (nonatomic, assign, readonly) int errorCode;

/**
 * Gets the error description.
 *
 * @return The error description.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSString *errorDescription;

/**
 * Gets the error stack trace.
 *
 * @return The error stack trace.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSString *errorStackTrace;

/**
 * Gets the external reference.
 *
 * @return The external reference.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSString *externalRef;

/**
 * Gets the meta data
 *
 * @return The meta data.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSDictionary *meta;

@end
