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

/**
 Cap modes
 */

///
static const int EM_MSP_CAP_MODE1 = 0;
///
static const int EM_MSP_CAP_MODE2 = 1;
///
static const int EM_MSP_CAP_MODE2_TDS = 2;
///
static const int EM_MSP_CAP_MODE3 = 3;

/**
 *  Protocol allowing to retrieve all the public fields and data from a cap data
 *
 *  - Since: 4.5
 */
@protocol EMMspCapData <EMMspData>

/**
 *  Return the corresponding cap challenge
 *
 *  @return A cap challenge msp field of the associated cap data
 *
 *  - Since: 4.5
 */
- (EMMspField*)capChallenge;

/**
 *  Return the corresponding cap amount
 *
 *  @return A cap amount msp field of the associated cap data
 *
 *  - Since: 4.5
 */
- (EMMspField*)capAmount;

/**
 *  Return the corresponding cap currency
 *
 *  @return A cap currency msp field of the associated cap data
 *
 *  - Since: 4.5
 */
- (EMMspField*)capCurrency;

/**
 *  Return list fo the msp fields representing the cap data
 *
 *  @return A list of msp fields of the associated cap data
 *
 *  - Since: 4.5
 */
- (NSArray *)capData;

@end
