/** ------------------------------------------------------------------------------------------------------
 
 Copyright (c) 2017  -  GEMALTO DEVELOPMENT - R&D
 
 --------------------------------------------------------------------------------------------------------
 GEMALTO MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF
 THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 PARTICULAR PURPOSE, OR NON-INFRINGEMENT. GEMALTO SHALL NOT BE
 LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
 MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
 
 THIS SOFTWARE IS NOT DESIGNED OR INTENDED FOR USE OR RESALE AS ON-LINE
 CONTROL EQUIPMENT IN HAZARDOUS ENVIRONMENTS REQUIRING FAIL-SAFE
 PERFORMANCE, SUCH AS IN THE OPERATION OF NUCLEAR FACILITIES, AIRCRAFT
 NAVIGATION OR COMMUNICATION SYSTEMS, AIR TRAFFIC CONTROL, DIRECT LIFE
 SUPPORT MACHINES, OR WEAPONS SYSTEMS, IN WHICH THE FAILURE OF THE
 SOFTWARE COULD LEAD DIRECTLY TO DEATH, PERSONAL INJURY, OR SEVERE
 PHYSICAL OR ENVIRONMENTAL DAMAGE ("HIGH RISK ACTIVITIES"). GEMALTO
 SPECIFICALLY DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTY OF FITNESS FOR
 HIGH RISK ACTIVITIES.
 
 ----------------------------------------------------------------------------------------------------------
 */

#import <Foundation/Foundation.h>
#import "EMMspFrame.h"
#import "EMMspData.h"
#import "EMMspRegistration.h"
#import "EMSecureByteArray.h"

/**
 *  Msp parser protocol
 *
 *  - Since: 4.5
 */
@protocol EMMspParser <NSObject>

/**
 *  Retrieving the Msp frame from data
 *
 *  @param data Secure Data containing a Msp frame to decode
 *
 *  @param nsError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in nil.
 *
 *  @return An object following the Msp frame protocol, nil if an error occurs.
 *
 *  - Since: 4.5
 */
- (id<EMMspFrame>)parse:(id<EMSecureByteArray>)data error:(NSError *__autoreleasing *)nsError;

/**
 *  Retrieving a Msp Data from data
 *
 *  @param frame target msp frame to parse
 *
 *  @param nsError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in nil.
 *
 *  @return An object following the Msp data protocol, nil if an error occurs.
 *
 *  - Since: 4.5
 */
- (id<EMMspData>)parseMspData:(id<EMMspFrame>)frame error:(NSError *__autoreleasing *)nsError;


@end
