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
typedef NS_ENUM(int, EMPrimitiveTextFormat)
{
    /** Input is restricted to ISO8859-15 */
    EMPrimitiveTextFormatIso8859_15,
    /** Input has no restriction */
    EMPrimitiveTextFormatBinary
};

/**
   A primitive for all primitives which accept text for connected DS mode.
   
   - Since: 2.1
 */
@protocol EMTextPrimitive <EMPrimitive>

/**
   Returns the minimum allowed input characters for this primitive, -1 if there is no minimum or not applicable.

   @return Minimum allowed input length.
 */
@property (assign, nonatomic, readonly) NSInteger minimumInputLength;

/**
   Returns the maximum allowed input characters for this primitive, -1 if there is no maximum or not applicable.

   @return Maximum allowed input length.
 */
@property (assign, nonatomic, readonly) NSInteger maximumInputLength;

/**
   Returns the data format. See EMPrimitiveTextFormat

   @return The data format for this primitive.
 */
@property (assign, nonatomic, readonly) EMPrimitiveTextFormat textFormat;

/**
   Check if the given input data is valid for this primitive

   @param data The input data to check.
   @return `YES` if data valid, `NO` otherwise.
   @see [EMTextPrimitive assertInputData:]
 */
- (BOOL)validateInputData:(id<EMSecureString>)data;

/**
   Assert that the given input data is valid for this primitive.

   @param data The input data to check.
   @exception DsDataFormatException If the data is not valid
   @see [EMTextPrimitive validateInputData:]
 */
-(void)assertInputData:(id<EMSecureString>)data;

@end
