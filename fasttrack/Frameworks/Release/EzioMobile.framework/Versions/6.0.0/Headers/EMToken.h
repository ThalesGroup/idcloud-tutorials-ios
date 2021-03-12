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

#import "EMAuthenticatable.h"
#import "EMAuthMode.h"
#import "EMPinAuthInput.h"

/**
 * The EMToken protocol represents user's credentials known as <b>tokens</b>.
 */
@protocol EMToken <NSObject, EMAuthenticatable>

/**
 * Gets the name of the token. The name of the token was defined when the
 * token was created.
 *
 * @return The name of the token.
 */
@property (copy, nonatomic, readonly) NSString *name;

/**
 * Returns `YES` if the token's credentials are software based
 * (i.e. the credentials are not stored inside a special hardware chip).
 *
 * @return `YES` if this is a soft token, `NO` otherwise
 */
@property (nonatomic, readonly, getter = isSoft) BOOL soft;

/**
 * Gets the token sequence number that distinguishes this token among others
 * the users has.
 *
 * The token sequence number is defined only for CAP tokens and is an
 * unsigned value ranging from 0x00 to 0x63 (i.e. 0 to 99). For OATH
 * tokens, the method always return 0xFF (i.e. 255).
 *
 * @return The token sequence number.
 */
@property (nonatomic, readonly) NSInteger tokenSequenceNumber;

/**
 * Returns the User Token Identifier (UTI).
 *
 * The UTI is an unsigned value ranging from 0x00 to 0xFF (i.e. 0 to 255).
 * It is generated by the provisioning server and is part of the credential
 * pushed during provisioning. It is guaranteed that two tokens for the
 * same end-user (on authentication server) and from the same EPS domain
 * will never have the same UTI. See the Enrollment and Provisioning Server
 * documentation for domains configuration description.
 *
 * The UTI is defined only if the token has been created with Provisioning
 * Protocol V3 or V5. When the token has been created with Provisioning Protocol
 * V1 or V2 the method returns -1.
 *
 *
 * - Since: 2.2
 * @return The user token id, -1 if none.
 */
@property (nonatomic, readonly) NSInteger userTokenId;

/**
 * Performs a change PIN using a PIN authentication mode. If the EMTokenCapability of the token is
 * `EMTokenCapabilityDUAL_SEED` then this operation changes the PIN
 * for both keys regardless of which key is currently selected. See EMTokenCapability.
 * <p>
 *
 * @param oldPin Current Pin value.
 * @param newPin New Pin value.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * object containing the error information.  Possible errors are:
 * - EMPinRuleErrorDomain when the new PIN does not comply with the configured
 * PIN rules.
 * @return `YES` if the pin was changed, `NO` if an error occurred.
 * - Since: 3.2
 */
- (BOOL)changePinWithAuthInput:(id<EMPinAuthInput>)oldPin newPin:(id<EMPinAuthInput>)newPin error:(NSError **)error;

/**
 * Performs upgrade token migration to support multi authentication mode. The migration is supposed to be performed from SDK version 2.3.0 or newer.
 * @warning 1. It's mandatory to perform token migration on a previously created token but also on new token before any token operation.
 * 2. Pin value parsed here needs to be correct one, otherwise the token will no longer be valid.
 *
 * @param pin Current Pin value.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in 'NULL'.
 * object containing the error information. Possible errors are:
 * - EZIO_MOBILE_ERROR_DOMAIN_MULTI_AUTH_MODE , when upgrade lowplatformcoupling token to multi-auth mode which is not supported.
 * - EMTokenMigrationErrorDomain , when token already migrated to support multi auth modes.
 * @return 'YES' if the token migration was succeeded. 'NO' if an error occurred.
 * - Since: 3.2
 */
- (BOOL)upgradeToMultiAuthMode:(id<EMPinAuthInput>)pin error:(NSError **)error;

@end