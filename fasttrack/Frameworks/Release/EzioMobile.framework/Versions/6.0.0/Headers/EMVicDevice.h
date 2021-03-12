/** -----------------------------------------------------------------------------
 
        Copyright (c) 2014  -  GEMALTO DEVELOPMENT - R&D
 
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
#import "EMAuthInput.h"

/**
   A protocol defining a device that verifies VIC codes.
 */
@protocol EMVicDevice <NSObject>

/**
   Checks if Verify Issuer Code is blocked
   (verifyIssuerCode:pin:)
   @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 
   @return `YES` if verify issuer code is blocked, `NO` otherwise.
 */
- (BOOL)isVerifyBlocked:(NSError **)error;

/**
   Checks if Verify Issuer Code is the last attempt
   (verifyIssuerCode:pin:)
   @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 
   @return `YES` if verify issuer code is the last attempt. `NO` otherwise.
 */
- (BOOL)isVerifyLastAttempt:(NSError **)error;

/**
 Verify the code given by the caller to authenticate him
 
 @param vic The code to be verified.
 @param authInput The authInput.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return `YES` if verification succeeded, `NO` otherwise.`
 @warning Depending of the EMAuthInput type you are using, you may have to use this function asynchronously, please @see EMAuthInput for more details
 - Since: 3.2
 */
- (BOOL)verifyIssuerCode:(id<EMSecureString>)vic authInput:(id<EMAuthInput>)authInput error:(NSError **)error;

@end
