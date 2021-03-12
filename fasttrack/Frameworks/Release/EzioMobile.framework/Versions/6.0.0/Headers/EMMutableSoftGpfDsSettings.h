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
#import "EMMutableSoftCapSettings.h"
#import "EMSoftGpfDsSettings.h"

/**
   A protocol for mutable GPF DS settings for soft tokens
 */
@protocol EMMutableSoftGpfDsSettings <EMMutableSoftCapSettings, EMSoftGpfDsSettings>

/**
   Sets the minimum length of an OTP.
  
   The length of an OTP is guaranteed to be at least
   `length` digits long (left padded with zeros).
  
   @see [EMSoftGpfDsSettings minimumOtpLength].
 */
@property (assign, nonatomic) NSInteger minimumOtpLength;

@end
