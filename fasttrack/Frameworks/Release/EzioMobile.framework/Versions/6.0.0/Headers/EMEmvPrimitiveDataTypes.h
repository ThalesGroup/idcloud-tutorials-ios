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
 * Bool class providing method to create EMVQR primitive data type that represent BOOL values.
 *
 * - Since: 5.0
 */
@protocol EMEmvBool <NSObject>

/**
 creates an instance which conform to this protocol

 @param aValue Bool value
 @return instancetype
 */
+ (instancetype)boolWithValue:(BOOL)aValue;

/**
 The boolean data type has only two possible values: @{code YES} and @{code NO}.
 */
@property (nonatomic, assign) BOOL value;

@end

/**
 * Byte class providing method to create EMVQR primitive data type that represent unsigned integer values.
 */
@protocol EMEmvByte <NSObject>

/**
 creates an instance which conform to this protocol

 @param aValue Byte value
 @return instancetype
 */
+ (instancetype)byteWithValue:(Byte)aValue;

/**
 An 8-bit unsigned integer value type. It has a minimum value of 0 and a maximum value of 255.
 */
@property (nonatomic, assign) Byte value;

@end
