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
#import "EMMspField.h"

// Moved from external to internal as we don't support it in 4.5

/**
 *  Protocol allowing to retrieve all the public fields and data from a Gpfds data
 */
@protocol EMMspGpfdsData <NSObject>

/**
 *  Return the corresponding Gpfds data ds domain
 *
 *  @return A integer corresponding to the ds domain of the associated cap data
 */
- (int)dsDomain;

/**
 *  Return the corresponding Gpfds data ds input challenge
 *
 *  @return A ds input challenge msp field of the associated cap data
 */
- (EMMspField*)dsInputChallenge;

/**
 *  Return list of the msp fields corresponding to the ds primitives MSP Field
 *
 *  @return A list of ds primitive field of the associated Gpfds data
 */
- (NSArray *)dsPrimitives;

@end
