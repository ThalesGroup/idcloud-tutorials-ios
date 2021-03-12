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
#import "EMSecureString.h"

/**
 * The enum class to describe the completeness of a MSP field.
 *
 * - Since: 4.5
 */
typedef NS_ENUM(NSInteger, FieldCompleteness){
    /**
     *  Indicates that the field data contains incompletes byte
     */
    INCOMPLETE,
    /**
     *  Indicates that the field data is complete
     */
    COMPLETE
};

/**
 *  Msp Field class
 *
 *  The class represents the MSP field which describes the field information such as field
 *  completeness. This class also is a helper class to work with UI components for the partial
 *  input from end users.
 *
 *  - Since: 4.5
 */
@interface EMMspField : NSObject

/**
 *  The associated Msp data value of the field
 *
 *  - Since: 4.5
 */
@property (strong, nonatomic) id<EMSecureString> value;

/**
 *  Retrieves the missing bytes of a Msp field data, if any
 *
 *  @return Return a NSDictionary representing the missing bytes fo the Msp field. Keys are NSNumber representing the position of the missing bytes and values are NSData containing the missing byte value
 *
 *  - Since: 4.5
 */
- (NSDictionary*)missingBytes;

/**
 *  Retrieves the missing bytes of a Msp field data, if any
 *
 *  @return Return a NSDictionary representing the visible bytes fo the Msp field. Keys are NSNumber representing the position of the visible bytes and values are NSData containing the visible byte value
 *
 *  - Since: 4.5
 */
- (NSDictionary*)visibleBytes;

/**
 *  Retrieves the state for completeness of the Msp field
 *
 *  @return One of the FieldCompleteness constant
 *
 *  - Since: 4.5
 */
- (FieldCompleteness)isComplete;

/**
 *  Updates the missing bytes with a NSDictionary of new values
 *
 *  @param missingBytes NSDictionary representing the bytes which will replace the missing ones. Key are NSNumber representing location of the byte, values are NSData containing the byte to use for replacement.
 *
 *  @return An int representing the success of the operation. 1 means it was successfull, 0 means it failed
 *
 *  - Since: 4.5
 */
- (int)updateMissingBytes:(NSDictionary*)missingBytes;


@end
