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
#import "EMMspBaseAlgorithm.h"
#import "EMSecureString.h"

/**
 *  A basic object protocol to retrieve the common public parameters of a decoded MspData Object
 *
 *  - Since: 4.5
 */
@protocol EMMspData <NSObject>

/**
 *  Retrieve the base algorithm of the associated MspData object
 *
 *  @return a EMMspBaseAlgorithm representing the base algorithm of the associated MspData object
 *
 *  - Since: 4.5
 */
- (EMMspBaseAlgorithm)baseAlgo;

/**
 *  Retrieve the mode of the associated MspData object
 *
 *  @return a int representing the mode of the associated MspData object
 *
 *  - Since: 4.5
 */
- (int)mode;

/**
 *  Retrieve the userTokenId of the associated MspData object
 *
 *  @return a int representing the user token ID of the associated MspData object
 *
 *  - Since: 4.5
 */
- (int)userTokenId;

/**
 *  Retrieve the externalId of the associated MspData object
 *
 *  @return a SecureString representing the external ID of the associated MspData object
 *
 *  - Since: 4.5
 */
- (id<EMSecureString>)externalId;

/**
 *  Retrieve the time of the associated MspData object
 *
 *  @return a uint64_t variable representing the time of the associated MspData object
 *
 *  - Since: 4.5
 */
- (uint64_t)time;

@end
