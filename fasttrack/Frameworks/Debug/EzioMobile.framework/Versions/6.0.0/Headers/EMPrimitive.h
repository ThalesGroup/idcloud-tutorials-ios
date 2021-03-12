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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wstrict-prototypes"

///
extern NSString * EMDsDataFormatException;
///
extern NSString * EMDsDataFormatErrorDomain;

#pragma clang diagnostic pop

///
FOUNDATION_EXPORT NSInteger const EMDsDataFormatErrorCodeGeneral;

/** The defined types of primitives */
typedef NS_ENUM(int, EMPrimitiveType)
{
    // Input primitive types:
    /** Input Dialog Grouped */
    EMPrimitiveTypeIDG,
    /** Decimal Input Dialog */
    EMPrimitiveTypeDID,
    /** Input Dialog */
    EMPrimitiveTypeID,
    /** Selection Dialog */
    EMPrimitiveTypeSD,
    /** Numeric Input Dialog */
    EMPrimitiveTypeNID,
    
    // Context primitive types:
    /** Message Dialog */
    EMPrimitiveTypeMD,
    /** Information Message Dialog */
    EMPrimitiveTypeIMD,
    
    // Connected only primitive types:
    /** Free text */
    EMPrimitiveTypeE0,
    /** Hidden text */
    EMPrimitiveTypeE1
};

/**
   A protocol representing a DS primitive.
 */
@protocol EMPrimitive <NSObject>

/**
   Returns the tag for this primitive, the value is unsigned and ranges
   from 0x0000 to 0xFFFF. see `EMPrimitiveTags` in EMPrimitiveTags.h
 
   @return The tag value of this primitive.
 */
@property (assign, nonatomic, readonly) NSInteger tag;

/**
   Returns the type of the primitive, see EMPrimitiveType.
 
   @return The type of this primitive.
 */
@property (assign, nonatomic, readonly) EMPrimitiveType primitiveType;

/**
   Returns a textual description of this primitive, this is mainly intended for debug purposes.
 
   @return The textual description.
 */
- (NSString *)description;

@end
