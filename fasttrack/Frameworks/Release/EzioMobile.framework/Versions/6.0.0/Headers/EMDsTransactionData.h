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
#import "EMTemplate.h"
#import "EMPrimitiveValue.h"
#import "EMInputPrimitive.h"
#import "EMTextPrimitive.h"
#import "EMMessageDialogPrimitive.h"

@protocol EMTemplate;

/**
   A protocol representing a DS Transaction Data.
 */
@protocol EMDsTransactionData <NSObject>

/**
   Returns the template that is associated with this transaction data.

   @return The template that this transaction data is associated with.
 */
@property (strong, nonatomic, readonly) id<EMTemplate> template;

/**
   Returns the list of primitive values added in the transaction data.

   @return The list of added primitive values in this transaction data; if none, returns an empty list.
 */
@property (strong, nonatomic, readonly) NSArray *entries;

/**
   Adds the given primitive value holder to the transaction data.

   @param primitiveValue The primitive value holder.
   @return This transaction data (for method chaining).
 */
- (id<EMDsTransactionData>)addPrimitiveValue:(EMPrimitiveValue *)primitiveValue;

/**
   Adds a input primitive to the transaction data.

   @param inputPrimitive The input primitive.
   @param value The value for the primitive.
   @return This transaction data (for method chaining).
 */
- (id<EMDsTransactionData>)addInputPrimitive:(id<EMInputPrimitive>)inputPrimitive value:(id<EMSecureString>)value;

/**
   Adds a text primitive to the transaction data.

   @param textPrimitive The text primitive.
   @param value The value for the primitive.
   @return This transaction data (for method chaining).
   - Since: 2.1
 */
- (id<EMDsTransactionData>)addTextPrimitive:(id<EMTextPrimitive>)textPrimitive value:(id<EMSecureString>)value;

/**
   Adds a message primitive to the transaction data.
   <p>

   @param messagePrimitive The message primitive.
   @return This transaction data (for method chaining).
 */
- (id<EMDsTransactionData>)addMessagePrimitive:(id<EMMessageDialogPrimitive>)messagePrimitive;




@end


