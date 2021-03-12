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

#import "EMEmvDataObject.h"
#import "EMEmvOptional.h"

/**
 * Implementation of template data object type as defined by EMV specification.
 * Template data object contains an inner structure of other templates or primitive data objects which could be
 * retrieved by `-[EMEmvTemplate dataObject:]` method.
 *
 * - Since: 5.0
 */
@protocol EMEmvTemplate <EMEmvDataObject>

/**
 * Provides an unmodifiable list of data objects within a range of given IDs.
 *
 * @param anIdMinInclusive Minimum ID value (inclusive) for data objects to be provided.
 * @param anIdMaxInclusive Maximum ID value (inclusive) for data objects to be provided.
 * @return an unmodifiable list of data objects within a range of given IDs.
 */
- (NSArray<id<EMEmvDataObject>> *)dataObjectsWithinIdRange:(NSInteger)anIdMinInclusive idMaxInclusive:(NSInteger)anIdMaxInclusive;

/**
 *
 * @param anId ID of the data object to be retrieved from the inner list of data objects.
 * @return inner `EMEmvDataObject` with specified ID or null if not found.
 */
- (id<EMEmvDataObject>)dataObject:(Byte)anId;

@end

