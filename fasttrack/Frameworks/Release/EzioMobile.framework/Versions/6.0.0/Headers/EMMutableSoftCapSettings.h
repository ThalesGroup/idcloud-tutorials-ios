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
#import "EMSoftCapSettings.h"

#pragma clang diagnostic ignored "-Wobjc-property-synthesis"

/**
   A protocol for mutable CAP settings for soft tokens.
 */
@protocol EMMutableSoftCapSettings <NSObject, EMSoftCapSettings>

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
