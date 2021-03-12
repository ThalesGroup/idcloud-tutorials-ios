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
#import "EMToken.h"


/** The supported scramble modes for OTPs. */
typedef NS_ENUM(NSInteger, EMScrambleType)  {
    /** VAS compatible scrambling method. */
    EMScrambleTypeVas
};

/** The supported formatting modes for Otps. */
typedef NS_ENUM(NSInteger, EMFormatType)  {
    /** CAP formatting rules */
    EMFormatTypeCap
};

/**
 * The EMOtpTools class for utility functions like OTP scrambling and formatting functions.
 * It was originally called EMToolBox.
 *
 * - Since: 4.0
 */
@interface EMOtpTools : NSObject

/**
 * Computes a scrambled OTP from original OTP.
 *
 * @param type Specifies the type of scrambling function, See EMScrambleType define list of supported modes.
 * @param otp Original OTP. Length must greater or equal to 5, lower than 18 and only digits are accepted.
 *
 * @return The scrambled OTP.
 */
+ (id<EMSecureString>)scrambleOtpWithType:(EMScrambleType)type otp:(id<EMSecureString>)otp;

/**
 * Formats the OTP with according provided mode.
 *
 * @param type Specifies the type of formatting function, See EMFormatType define list of supported modes.
 * @param otp Original OTP.
 *
 * if mode is EMFormatTypeCap
 *
 * | Token length |Formatted Token|
 * |-------------:|---------------|
 * |   1          |  X            |
 * |   2          |  XX           |
 * |   3          |  XXX          |
 * |   4          |  XXXX         |
 * |   5          |  XX XXX       |
 * |   6          |  XXX XXX      |
 * |   7          |  XXX XXXX     |
 * |   8          |  XXXX XXXX    |
 * |   9          |  XXX XXX XXX  |
 * |  10          |  XX XXXX XXXX |
 * |  11          |  XXXXXXXXXXX  |
 * |  12          |  XXXXXXXXXXXX |
 * | >12          |  no change    |
 *
 * @return The formatted OTP.
 */
+ (id<EMSecureString>)formatOtpWithType:(EMFormatType)type otp:(id<EMSecureString>)otp;

/**
 * Gets the UTC time in milliseconds.
 *
 * @return The UTC time.
 */
+(unsigned long long)UTC;

/**
 * left pad an OTP with Zero if needed.
 *
 * @param otp OTP to pad.
 * @param minLength The minimum length of the padded OTP. If minLength is lower than the OTP length, no padding is added and a copy of OTP is returned (so original one can be wiped).
 * @return The OTP value left-padded.
 * - Since: 2.4
 */
+ (id<EMSecureString>)padOtpWithZero:(id<EMSecureString>)otp minLength:(int)minLength;

@end
