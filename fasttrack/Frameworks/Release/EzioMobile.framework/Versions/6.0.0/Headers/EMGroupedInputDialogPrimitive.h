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
#import "EMInputDialogPrimitive.h"

/**
   A protocol representing a grouped input dialog (IDG) primitive.
   <p>
   This is an extension of the EMInputDialogPrimitive which visually partitions the input into groups. e.g. 1234 5678.
   <p>
   This primitive has type `EMPrimitiveTypeIDG`.
   <p>
   The allowed input format is `EMPrimitiveInputFormatDigit`.
 */
@protocol EMGroupedInputDialogPrimitive <EMInputDialogPrimitive>

@end
