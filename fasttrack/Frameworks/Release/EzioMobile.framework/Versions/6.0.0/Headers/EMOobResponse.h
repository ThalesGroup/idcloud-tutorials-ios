/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2015  -  GEMALTO DEVELOPMENT - R&D
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

/**
 * OOB result codes.
 *
 * - Since: 3.0
 */
typedef NS_ENUM(NSUInteger, EMOobResultCode){
    /**
     * Result code succeeded
     *
     * - Since: 3.0
     */
    EMOobResultCodeSuccess,
    
    /**
     * Result code failed
     *
     * - Since: 3.0
     */
    EMOobResultCodeFail
};

//Placeholder until we do #16611: Design Messages/Responses object Model

/**
 * Defines the user data keys specific for the OOB subsystem.
 *
 * - Since: 3.0
 */
@protocol EMOobResponse <NSObject>

/**
 * Retrieves the result of the registration operation.
 *
 * @return The result of the registration operation, see EMOobResultCode.
 *
 * - Since: 3.0
 */
@property (nonatomic, assign, readonly) EMOobResultCode resultCode;

/**
 * Retrieves the message accompanying the result as retrieved from the OOBS.
 *
 * @return The result text, never `nil`.
 *
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSString *resultMessage;

@end
