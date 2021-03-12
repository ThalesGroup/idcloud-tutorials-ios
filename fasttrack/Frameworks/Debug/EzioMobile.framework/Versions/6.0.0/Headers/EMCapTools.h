/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2016  -  GEMALTO DEVELOPMENT - R&D
 *
 * -----------------------------------------------------------------------------
 * GEMALTO MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF
 * THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, OR NON-INFRINGEMENT. GEMALTO SHALL NOT BE
 * LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
 * MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
 *
 * THIS SOFTWARE IS NOT DESIGNED OR INTENDED FOR USE OR RESALE AS ON-LINE
 * CONTROL EQUIPMENT IN HAZARDOUS ENVIRONMENTS REQUIRING FAIL-SAFE
 * PERFORMANCE, SUCH AS IN THE OPERATION OF NUCLEAR FACILITIES, AIRCRAFT
 * NAVIGATION OR COMMUNICATION SYSTEMS, AIR TRAFFIC CONTROL, DIRECT LIFE
 * SUPPORT MACHINES, OR WEAPONS SYSTEMS, IN WHICH THE FAILURE OF THE
 * SOFTWARE COULD LEAD DIRECTLY TO DEATH, PERSONAL INJURY, OR SEVERE
 * PHYSICAL OR ENVIRONMENTAL DAMAGE ("HIGH RISK ACTIVITIES"). GEMALTO
 * SPECIFICALLY DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTY OF FITNESS FOR
 * HIGH RISK ACTIVITIES.
 *
 * -----------------------------------------------------------------------------
 */


#import <Foundation/Foundation.h>
#import "EMSecureString.h"
#import "EMToken.h"

/**
 * Helper utility for CAP operation in generating OTP.
 */
@interface EMCapTools : NSObject

/**
 Prefixes an OTP value with a token sequence number, zero padded to the left.
 
 @warning This method should be used when token has been provisioned with provisioning protocol v1.
 @warning The token sequence number is not defined for OATH tokens. All OATH tokens will be assigned to the default value as 0xFF.
 @param otp OTP to prefix.
 @param token The token which generated the OTP. Only significant digits will be used.
 @param tokenVersionLength Number of digits to prefix, if needed the `token.tokenSequenceNumber` will be zero padded to the left. Maximum length is 3, cannot be 0.
 
 | tokenVersionLength | Prefix range |
 |-------------------:|-------------:|
 | 1                  | 1 - 9        |
 | 2                  | 01 - 99      |
 | 3                  | 001 - 255    |
 
 @return The OTP value prefixed.
 @exception NSInvalidArgumentException - when the tokens sequence number is invalid or the tokenVersionLength is less then the actual length.
 */
+ (id<EMSecureString>)prefixSequenceNumberToOtp:(id<EMSecureString>)otp token:(id<EMToken>)token tokenVersionLength:(int)tokenVersionLength;

/**
 Prefixes an OTP value with a token sequence number, zero padded to the left.
 
 @warning This method should be used when token has been provisioned with provisioning protocol v1.
 @param otp OTP to prefix.
 @param token The token which generated the OTP. Only significant digits will be used.
 @return The OTP value prefixed.
 @exception NSInvalidArgumentException - when token's sequence number is invalid.
 */
+ (id<EMSecureString>)prefixSequenceNumberToOtp:(id<EMSecureString>)otp token:(id<EMToken>)token;

/**
 Prefixes an OTP value with a token sequence number as hexadecimal digits.
 
 @warning This method should be used when token has been provisioned with provisioning protocol v2.
 @warning The token sequence number is not defined for OATH tokens. All OATH tokens will be assigned to the default value as 0xFF.
 @param otp OTP to prefix.
 @param token The token which generated the OTP. Only significant digits will be used.
 @return The OTP value prefixed.
 @exception NSInvalidArgumentException - when token's sequence number is invalid.
 */
+ (id<EMSecureString>)prefixSequenceNumberAsHexToOtp:(id<EMSecureString>)otp token:(id<EMToken>)token;

@end
