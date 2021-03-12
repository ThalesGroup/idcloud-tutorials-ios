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
#import "EMDsTransactionData.h"
#import "EMDsFormattingDevice.h"
#import "EMAuthInput.h"

/**
   A protocol defining a Dynamic Signature (DS) device using the
   Gemalto Proprietary Formatting (GPF) for generating OTPs.

   This works using the Gemalto VAS Authentication Server. For pure CAP
   authentication servers should use -[EMDsDevice capParametersWithChallenge:domain:dsCapMode:transactionData:] or -[EMDsDevice capParametersWithDomain:dsCapMode:transactionData:] instead.

 */
@protocol EMGpfDsDevice <NSObject>

/**
 Generates a code.
 
 Note that a code in practice is a CAP mode2 OTP with a prefixed
 sequence number formatting applied. Example: 010 543 203.
 Use +[EMToolBox formatOtpWithType:otp:] to format the token.
 
 @param authInput the authInput.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The code.
 
 @warning Depending of the EMAuthInput type you are using, you may have to use this function asynchronously, please @see EMAuthInput for more details
 
 - Since: 3.2
 */
- (id<EMSecureString>)codeWithAuthInput:(id<EMAuthInput>)authInput error:(NSError **)error;

/**
 Generates a dynamic signature.
 
 Note that a dynamic signature in practice is a CAP mode3 TDS OTP with
 prefixed sequence number and formatting applied. Example: 010 543 203.
 Use +[EMToolBox prefixSequenceNumberToOtp:token:tokenVersionLength:] to prefix the sequence number.
 Use +[EMToolBox formatOtpWithType:otp:] to format the token.
 
 @param authInput The authInput.
 @param challenge The challenge. The challenge can be `nil` in connected mode.
 @param domain The secure domain.
 @param transactionData The transaction data. The transaction data can be `nil`.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The signature.
 - Since: 3.2
 */
- (id<EMSecureString>)dynamicSignatureWithAuthInput:(id<EMAuthInput>)authInput challenge:(id<EMSecureString>) challenge domain:(EMDomainType)domain transactionData:(id<EMDsTransactionData>)transactionData error:(NSError **)error;

@end
