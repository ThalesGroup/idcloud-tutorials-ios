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

/** The supported check digit algorithms for challenge. */
typedef NS_ENUM(NSInteger, EMVerifyType) {
    /** Use Verhoeff check digit algorithm */
    EMVerifyTypeVerhoeff
};

/**
 * DS Formatting Tools
 */
@interface EMDsFormattingTools : NSObject

/**
 Gets the Dynamic Signature template ID encoded by the challenge.
 
 @param challenge The challenge of the transaction, must not be `nil`.
 
 @return The template ID indicating the list of input to request from the user for Dynamic Signature.
 */
+ (NSInteger)getDynamicSignatureTemplateIdWithChallenge:(id<EMSecureString>)challenge;

/**
 Checks validity of a challenge against a checksum mode.
 
 @param type Checksum algorithm to use, See EMVerifyType define list of supported modes.
 @param challenge The challenge of the transaction, must not be `nil`.
 @return `YES` if the checksum is correct, `NO` otherwise
 */
+ (BOOL)checkDigitWithType:(EMVerifyType)type challenge:(id<EMSecureString>)challenge;

@end
