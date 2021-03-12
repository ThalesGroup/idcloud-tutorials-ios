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
 * A protocol representing a secure container object in memory.
 */
@protocol EMSecureContainer <NSObject, NSCopying>

/**
 * Wipes internal state of a secure container object.
 */
-(void)wipe;

/**
 * Returns a copy of the secure container object.
 *
 * @return The copy of the secure container object.
 */
- (id)copy;

/**
 * Compares the receiver to the other secure container object.
 * 
 * @param anotherData The object to be compared.
 * @return `YES` if two objects are equivalent, `NO` otherwise.
 */
- (BOOL)isEqual:(id) anotherData;

/**
 * Calculates the hash code of this secure container object.
 * @return The hash code.
 */
- (NSUInteger)hash;

@end

