/** -----------------------------------------------------------------------------
 
        Copyright (c) 2013  -  GEMALTO DEVELOPMENT - R&D
 
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
#import "EMInputPrimitive.h"
#import "EMTextPrimitive.h"
#import "EMSecureString.h"
#import "EMMessageDialogPrimitive.h"

/**
   Holder class for a primitive with an associate value.
 */
@interface EMPrimitiveValue : NSObject

///////////////////////////////////////////////////////////////////////////////////////
/** Create PrimitiveValue object */
///////////////////////////////////////////////////////////////////////////////////////

/**
   Creates a new holder with a primitive value.

   @param primitive The primitive.
   @param value The value.
   @return Initialized new instance of EMPrimitiveValue.
 */
- (id)initWithInputPrimitive:(id<EMInputPrimitive>)primitive value:(id<EMSecureString>)value;

/**
   Creates a new holder with a text primitive value.

   @param primitive The text primitive.
   @param value The value.
   @return Initialized new instance of EMPrimitiveValue.
   - Since: 2.1.0
 */
- (id)initWithTextPrimitive:(id<EMTextPrimitive>)primitive value:(id<EMSecureString>)value;


/**
   Creates a new holder without a value.

   @param messagePrimitive The primitive.
   @return Initialized new instance of EMPrimitiveValue.
 */
- (id)initWithMessagePrimitive:(id<EMMessageDialogPrimitive>)messagePrimitive;


///////////////////////////////////////////////////////////////////////////////////////
/** Properties  */
///////////////////////////////////////////////////////////////////////////////////////

/**
   The primitive.

   @return The primitive.
 */
@property (strong, nonatomic, readonly) id<EMPrimitive> primitive;

/**
   The value of the primitive.

   @return The value, `nil` if these is no associated value.
 */
@property (strong, nonatomic, readonly) id<EMSecureString> value;

@end
