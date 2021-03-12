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

/**
   A protocol representing the CAP settings for soft tokens.
 */
@protocol EMSoftCapSettings <NSObject>

/**
   Returns the padding sequence used for the MAC data.
 
   Default: 0x8000000000000000
 */
@property (copy, nonatomic, readonly) NSData * macPadding;

/**
 Returns the card risk management data object list 1
 
 Default (hex):
 
     Amount authorized
     0x9F, 0x02, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     
     Amount other
     0x9F, 0x03, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     
     Terminal country code
     0x9F, 0x1A, 0x02, 0x00, 0x00,
     
     TVR
     0x95, 0x05, 0x80, 0x00, 0x00, 0x00, 0x00,
     
     Transaction currency code
     0x5F, 0x2A, 0x02, 0x00, 0x00,
     
     Transaction date
     0x9A, 0x03, 0x00, 0x00, 0x00,
     
     Transaction type
     0x9C, 0x01, 0x00,
     
     UN
     0x9F, 0x37, 0x04, 0x00, 0x00, 0x00, 0x00,
     
     AIP
     0x82, 0x02, 0x10, 0x00,
     
     ATC
     0x9F, 0x36, 0x02, 0x00, 0x00,
     
     CVR
     0x9F, 0x52, 0x06, 0xA5, 0x00, 0x03, 0x04, 0x00, 0x00
 
 */
@property (copy, nonatomic, readonly) NSData * cdol;

/**
 Returns the issuer proprietary bitmap
 
 Default (hex):
 
     No PSN
     
     CID
     0x00,
     
     ATC
     0x00, 0xFF,
     
     Cryptogram (AC)
     0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     
     IAD
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 
 */
@property (copy, nonatomic, readonly) NSData * ipb;

/**
   Returns the issuer authentication flags.
 
   Default: 0x80
 */
@property (assign, nonatomic, readonly) unsigned char iaf;

/**
   Returns the issuer application data.
 
   Default: 0x06010A03040000000000
 */
@property (copy, nonatomic, readonly) NSData * iad;

/**
   Returns the cryptographic identifier.
 
   Default: 0x80
 */
@property (assign, nonatomic, readonly) unsigned char cid;

@end
