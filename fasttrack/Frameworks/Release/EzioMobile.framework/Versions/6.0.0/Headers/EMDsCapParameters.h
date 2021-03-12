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
#import "EMSecureString.h"

/** The supported modes for DS CAP. */
typedef NS_ENUM(NSInteger, EMDsCapMode)
{
    /** Cap mode 2 Tds */
    EMDsCapMode2Tds
};


/**
   Represents a DS mapping to standard CAP parameters such that verification may be done using Gemalto DSIP and any standard CAP authentication server.
 */
@interface EMDsCapParameters : NSObject

///////////////////////////////////////////////////////////////////////////////////////
/// Create DsCapParameter object 
///////////////////////////////////////////////////////////////////////////////////////

/**
   Creates a CAP verification parameter object.

   @param capMode The CAP mode to use.
   @param challenge The merchant challenge.
   @param amount The amount.
   @param currencyCode The currency code of the transaction.
   @param dataToSign The data to sign.

   @return A CAP verification parameter object.
 */
- (id)initWithCapMode:(EMDsCapMode)capMode challenge:(id<EMSecureString>)challenge amount:(id<EMSecureString>)amount currencyCode:(NSString *)currencyCode dataToSign:(NSArray *)dataToSign;


///////////////////////////////////////////////////////////////////////////////////////
/// Properties 
///////////////////////////////////////////////////////////////////////////////////////

/**
   Returns the DS CAP mode. See enum EMDsCapMode.

   @return The DS CAP mode.
 */
@property (assign, nonatomic, readonly) EMDsCapMode capMode;

/**
   Returns the challenge.

   @return The challenge.
 */
@property (strong, nonatomic, readonly) id<EMSecureString> challenge;

/**
   Returns the amount.

   @return The amount.
 */
@property (strong, nonatomic, readonly) id<EMSecureString> amount;

/**
   Returns the currency code.

   @return The currency code.
 */
@property (strong, nonatomic, readonly) NSString *currencyCode;

/**
   Returns an array of data to be signed. Each item in the array is an instance
   of EMSecureString.

   @return The signing data.
 */
@property (strong, nonatomic, readonly) NSArray *dataToSign;



@end
