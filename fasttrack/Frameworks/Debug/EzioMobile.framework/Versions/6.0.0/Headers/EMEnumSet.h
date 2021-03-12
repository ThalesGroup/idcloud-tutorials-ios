/** -----------------------------------------------------------------------------
 
        Copyright (c) 2015  -  GEMALTO DEVELOPMENT - R&D
 
     -----------------------------------------------------------------------------
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
  
    -----------------------------------------------------------------------------
 */

#import <Foundation/Foundation.h>

/**
 * An interface representing a collection of enum type data.
 */
@interface EMEnumSet : NSObject

/**
 * Create and Initialize an EnumSet object.
 *
 * @param set The CFMutableSet object containing all capabilities of a token.
 * - Since: 2.6
 */
-(void)createEnumSet:(CFMutableSetRef) set;

/**
 * Checks the existence of a specific item in the set.
 *
 * @param item The item to be checked.
 * @return `YES` if the EnumSet contains that item and otherwise `NO` will be returned.
 * - Since: 2.6
 */
- (BOOL)contains:(CFIndex) item;

/**
 * Counts the number of capabilities in the EnumSet.
 *
 * @return The number of items in the set.
 * - Since: 2.6
 */
- (CFIndex)count;

@end
