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
#import "EMMspData.h"
#import "EMMspField.h"

///
static const int EM_MSP_OATH_HOTP = 0;
///
static const int EM_MSP_OATH_TOTP = 1;
///
static const int EM_MSP_OATH_OCRA = 2;


/**
 *  Protocol allowing to retrieve all the public fields and data from a Oath data
 *
 *  - Since: 4.5
 */
@protocol EMMspOathData <EMMspData>

/**
 *  Return the corresponding Oath Ocra server challenge
 *
 *  @return A Msp field containing the Server challenge of the associated Oath data
 *
 *  - Since: 4.5
 */
- (EMMspField*)ocraServerChallenge;

/**
 *  Return the corresponding Oath Ocra client challenge
 *
 *  @return A Msp field containing the Client challenge of the associated Oath data
 *
 *  - Since: 4.5
 */
- (EMMspField*)ocraClientChallenge;

/**
 *  Return the corresponding Oath Ocra password hash
 *
 *  @return A Msp field containing the password hash of the associated Oath data
 *
 *  - Since: 4.5
 */
- (EMMspField*)ocraPasswordHash;

/**
 *  Return the corresponding Oath Ocra Session
 *
 *  @return A Msp field containing the Ocra session of the associated Oath data
 *
 *  - Since: 4.5
 */
- (EMMspField*)ocraSession;




@end
