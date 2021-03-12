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
#import "EMPrimitive.h"
#import "EMSecureString.h"

/** Represents the allowed input format of the data. */
typedef NS_ENUM(int, EMPrimitiveInputFormat)
{
    /** A decimal number with two fraction digits such as "123.45". Either '.' or ',' can be used a decimal separator. */
    EMPrimitiveInputFormatDecimalTwoFractionDigits,
    /** Ascii digit between '0' to '9' */
    EMPrimitiveInputFormatDigit,
    /** The allowed input is fixed to a set of predefined values */
    EMPrimitiveInputFormatFixed
};

/**
   A primitive for all primitives which accept input, either user entered
   or selected.
 */
@protocol EMInputPrimitive <EMPrimitive>

/**
   Returns the minimum allowed input characters for this input dialog, -1 if there is no minimum or not applicable.

   @return Minimum allowed input length.
 */
@property (assign, nonatomic, readonly) NSInteger minimumInputLength;

/**
   Returns the maximum allowed input characters for this input dialog, -1 if there is no maximum or not applicable.

   @return Maximum allowed input length.
 */
@property (assign, nonatomic, readonly) NSInteger maximumInputLength;

/**
   Returns the input format. see EMPrimitiveInputFormat

   @return The input format for this input dialog primitive.
 */
@property (assign, nonatomic, readonly) EMPrimitiveInputFormat inputFormat;

/**
   Check if the given input data is valid for this input dialog

   @param data The input data to check.
   @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
   @return `YES` if data valid, `NO` otherwise.
   @see assertInputData:
 */
- (BOOL)validateInputData:(id<EMSecureString>)data error:(NSError **)error;

/**
   Assert that the given input data is valid for this input dialog.

   @param data The input data to check.
   @exception DsDataFormatException If the data is not valid
   @see validateInputData:error:
 */
-(void)assertInputData:(id<EMSecureString>)data;

@end
