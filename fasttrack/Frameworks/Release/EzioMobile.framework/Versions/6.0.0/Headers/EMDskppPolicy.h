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
#import "EMTokenPolicy.h"

/*
 * Token modes:
 */
/** Token mode : Event Based Token */
extern int const EMDskppTokenModeEventSync;
/** Token mode : Time Based Token */
extern int const EMDskppTokenModeTimeSync;
/** Token mode : Challenge Response Token */
extern int const EMDskppTokenModeOcraChallengeResponse;

/**
 * OTP Complexity:
 */
/** OTP Complexity : Decimal */
extern int const EMDskppOtpComplexityDecimal;
/** OTP Complexity : Hexadecimal */
extern int const EMDskppOtpComplexityHexadecimal;
/** OTP Complexity : Base32 */
extern int const EMDskppOtpComplexityBase32;
/** OTP Complexity : Base64 */
extern int const EMDskppOtpComplexityBase64;

/**
 * Policy status:
 */
/** Policy status: Off */
extern int const EMDskppPolicyStatusOff;
/** Policy status: On */
extern int const EMDskppPolicyStatusOn;

/**
 * Policy traits
 * - Since: 4.1
 */
typedef NS_ENUM(NSInteger, EMDskppPolicyParamType) {
    /** Undefined policy mode */
    EMDskppPolicyParamTypeUndefined               = 0,
    
    /** Token mode - EMDskppTokenModeEventSync - Event synchronous, EMDskppTokenModeTimeSync - time synchronous, EMDskppTokenModeOcraChallengeResponse - challenge response (OCRA) */
    EMDskppPolicyParamTypeMode,
    
    /** Time Interval for Time Based Token (in seconds) */
    EMDskppPolicyParamTypeTimeInterval,
    
    /** Challenge length */
    EMDskppPolicyParamTypeChallengeLength,
    
    /** Pin length*/
    EMDskppPolicyParamTypePinLength,
    
    /** PIN verification failures before token should be erased */
    EMDskppPolicyParamTypeMaxAttacks,
    
    /** This parameter specifies the count of correct PIN entries after which the PIN is changed. */
    EMDskppPolicyParamTypePinUseChanges,
    
    /** Attack Delay (in seconds) */
    EMDskppPolicyParamTypeAttackDelay,
    
    /** Secure Mode  0: Off,  1: On */
    EMDskppPolicyParamTypeSecureMode,
    
    /** Pass Code length */
    EMDskppPolicyParamTypePasscodeLength,
    
    /** Time interval to suspend generation of the next OTP (in seconds). */
    EMDskppPolicyParamTypeOtpProtectiveSuspend,
    
    /** Policy level*/
    EMDskppPolicyParamTypePolicyLevel,
    
    /** Transaction Signing    0: Off. 1: On */
    EMDskppPolicyParamTypeTransactionSign,
    
    /** 0: Off (Do not allow trivial PIN), 1: On (Allow trivial PIN) */
    EMDskppPolicyParamTypeTrivialPinAllowed,
    
    /** 0: Off (Do not allow numeric only PIN), 1: On (Allow numeric only PIN) */
    EMDskppPolicyParamTypeNumericOnlyPinAllowed,
    
    /** 0: Off (No PIN Verification during Login to token (failure during OTP usage))
     *  1: On (Pin Verification failure during Token login) */
    EMDskppPolicyParamTypePinVerificationActive,
    
    /** OTP Complexity - 0: Decimal, 1: Hexadecimal, 2: Base32, 3: Base64 */
    EMDskppPolicyParamTypeOtpComplexity,
    
    /** PIN Caching - 0: Off, 1: On */
    EMDskppPolicyParamTypePinCaching
};

/**
 * DskppPolicyProtocol represents the policy for DSKPP.
 *
 * - Since: 4.7
 */
@protocol EMDskppPolicyProtocol

@optional
/**
 * Gets member value by type.
 *
 * @param param Name as EMPolicyParamType enumeration.
 *
 * @return value as integer.
 * - Since: 4.1
 */
-(int)valueForParam:(EMDskppPolicyParamType)param;

@end

/**
 * Provide an abstract class to return the features as defined by the server.
 * - Since: 4.1
 */
@interface EMDskppPolicy : NSObject <EMDskppPolicyProtocol>

@end
