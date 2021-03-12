/** -----------------------------------------------------------------------------
 
 Copyright (c) 2019  -  GEMALTO DEVELOPMENT - R&D
 
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

NS_ASSUME_NONNULL_BEGIN

/**
 Default padding sequence used for the MAC data.
 */
static const unsigned char DEFAULT_CAP_MAC_PADDING[] = {
    0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

/**
 Default card risk management data object list.
 */
static const unsigned char DEFAULT_CAP_CDOL[] = {
    // Amount authorized
    0x9F, 0x02, 0x06, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    // Amount other
    0x9F, 0x03, 0x06, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    // Terminal country code
    0x9F, 0x1A, 0x02, 0x00, 0x00,
    // TVR
    0x95, 0x05, 0x80, 0x00, 0x00, 0x00,
    0x00,
    // Transaction currency code
    0x5F, 0x2A, 0x02, 0x00, 0x00,
    // Transaction date
    0x9A, 0x03, 0x00, 0x00, 0x00,
    // Transaction type
    0x9C, 0x01, 0x00,
    // UN
    0x9F, 0x37, 0x04, 0x00, 0x00, 0x00,
    0x00,
    // AIP
    0x82, 0x02, 0x10, 0x00,
    // ATC
    0x9F, 0x36, 0x02, 0x00, 0x00,
    // CVR
    0x9F, 0x52, 0x06, 0xA5, 0x00, 0x03,
    0x04, 0x00, 0x00
};

/** The IPB applies to the assembled Token Data, which consists of:
 Optionally,
 the PAN Sequence Number (PSN): 1 byte.
 The Cryptogram Information Data (CID): 1 byte.
 The Application Transaction Counter (ATC): 2 bytes.
 The Cryptogram: 8 bytes.
 The Issuer Application Data (IAD): 0-32 bytes.
 */
static const unsigned char DEFAULT_CAP_IPB[] = {
    // No PSN
    // CID
    0x00,
    // ATC
    0x00, 0xFF,
    // Cryptogram (AC)
    0xFF, 0xFF, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    // IAD
    0x00, // IAD-KDI
    0x00, // IAD-CVN
    0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, // IAD-CVR
    0x00, 0x00, // IAD-DAC
};

/**
 Default Issuer authentication flags.
 */
static const unsigned char DEFAULT_CAP_IAF =  0x80;

/**
 Default issuer application data.
 */
static const unsigned char DEFAULT_CAP_IAD[] = {
    0x06, 0x01, 0x0A, 0x03,
    0x04, 0x00, 0x00, 0x00,
    0x00, 0x00
};

/**
 Default cryptographic identifier.
 */
static const unsigned char DEFAULT_CAP_CID =  0x80;

/**
 A class for mutable CAP settings for soft tokens.
 To use this object default settings could be done by directly initializing it.
 * - Since: 5.3
 */
@interface EMProtectorCapSettings : NSObject

/**
 The padding sequence used for the MAC data.
 */
@property (copy, nonatomic) NSData * macPadding;

/**
 The card risk management data object list 1
 */
@property (copy, nonatomic) NSData * cdol;

/**
 The issuer proprietary bitmap
 */
@property (copy, nonatomic) NSData * ipb;

/**
 The Issuer authentication flags.
 
 The bits listed have the following meaning if set:
 <ul>
 <li>8 (most significant) - Either the amount or the amount and
 currency are used.</li>
 <li>7 - PSN is included.</li>
 <li>6 - Include only the amount (bit 8 must be set).</li>
 </ul>
 All other bits are reserved and must not be set.
 */
@property (assign, nonatomic) unsigned char iaf;

/**
 The issuer application data.
 */
@property (copy, nonatomic) NSData * iad;

/**
 The cryptographic identifier.
 */
@property (assign, nonatomic) unsigned char cid;

@end

NS_ASSUME_NONNULL_END
