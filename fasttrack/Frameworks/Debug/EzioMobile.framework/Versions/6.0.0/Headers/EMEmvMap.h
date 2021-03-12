/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2018  -  GEMALTO DEVELOPMENT - R&D
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
 * EMEmvMap.
 *
 * - Since: 5.0
 */
@interface EMEmvMap<__covariant ObjectType> : NSMutableDictionary <NSNumber *, ObjectType>

/**
 * Add object with key to map. Only if not exists already.
 *
 * @param anObject Object you want to add to map.
 * @param aKey Unique key.
 *
 * @return YES if operation was successful.
 */
- (BOOL)addObject:(ObjectType)anObject withKey:(NSInteger)aKey;

/**
 * Get object for given key.
 *
 * @param aKey Unique key.
 *
 * @return Object or nil if key does not exits.
 */
- (ObjectType)objectWithKey:(NSInteger)aKey;

/**
 * Get subset of map for selected Id range.
 *
 * @param aMin Bottom limit of id.
 * @param aMax Top limit of id.
 *
 * @return Subset for given range.
 */
- (EMEmvMap *)subMap:(NSInteger)aMin max:(NSInteger)aMax;

@end
