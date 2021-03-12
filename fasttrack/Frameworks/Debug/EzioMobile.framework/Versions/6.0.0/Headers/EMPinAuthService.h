/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2015  -  GEMALTO DEVELOPMENT - R&D
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
#import "EMAuthService.h"
#import "EMPinAuthInput.h"
#import "EMAuthModule.h"
#import "EMPinAuthMode.h"

/**
 * Provides services for authentication with PIN.
 *
 * - Since: 4.0
 */
@interface EMPinAuthService : NSObject<EMAuthService>

/**
 * Default PinValidationRules for 'changePinWithAuthInput' operation.
 *
 * @return The default pin validation rule set which contains All of rules as follow:
 *
 * - EMPinRuleIdentical
 * - EMPinRuleLength
 * - EMPinRulePalindrome
 * - EMPinRuleSeries
 * - EMPinRuleUniform
 *
 * - Since: 4.0
 */
+ (NSArray *)defaultPinValidationRules;

/**
 * Designated constructor.
 * Returns the EMPinAuthService object created using the EMAuthModule
 *
 * @param module an instance of EMAuthModule
 * @return EMPinAuthService module instance.
 *
 * - Since: 4.0
 */
+ (instancetype)serviceWithModule:(EMAuthModule *)module;

/**
 * Creates an `EMPinAuthInput` from from a string.
 *
 * @param str The string to securely store. The string will be converted to UTF-8 when stored in the EMPinAuthInput object.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return An `EMPinAuthInput` object that securely stores the data.
 * - Since: 4.0
 */
- (id<EMPinAuthInput>)createAuthInputWithString:(NSString *)str error:(NSError **)error;

/**
 * Creates an `EMPinAuthInput` from a string using a specific string encoding.
 * <p>
 * @warning This method does not guarantee that the given string and
 * the given character set are compatible.
 *
 * @param str The string to securely store.
 * @param encoding The string will be converted to this encoding when stored in the EMPinAuthInput object.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return An EMPinAuthInput object that securely stores the data.
 * - Since: 4.0
 */
- (id<EMPinAuthInput>)createAuthInputWithString:(NSString *)str encoding:(NSStringEncoding)encoding error:(NSError **)error;

/**
 * Creates an `EMPinAuthInput` from data.
 *
 * @param data The data to securely store.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return An EMPinAuthInput object that securely stores the data.
 * - Since: 4.0
 */
- (id<EMPinAuthInput>)createAuthInputWithData:(NSData *)data error:(NSError **)error;

/**
 * Creates an `EMPinAuthInput` from data.
 *
 * @param data The data to securely store.
 * @param wipeSource If `YES`, then the `data` will be erased if the method returns successfully. Otherwise the input will not be modified.
 * @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return An EMPinAuthInput object that securely stores the data.
 * - Since: 4.0
 */
- (id<EMPinAuthInput>)createAuthInputWithMutableData:(NSMutableData *)data wipeSource:(BOOL)wipeSource error:(NSError **)error;

/**
 * Gets an EMPinAuthMode.
 * - Since: 4.0
 */
- (id<EMPinAuthMode>)authMode;

/**
 * Set PinRules. This will be applied globally.
 * @param pinRules array of pin rules. See subclasses of EMPinRule.
 *
 * - EMPinRuleIdentical
 * - EMPinRuleLength
 * - EMPinRulePalindrome
 * - EMPinRuleSeries
 * - EMPinRuleUniform
 *
 * - Since: 4.0
 */
+ (void)setPinValidationRules:(NSArray*)pinRules;

@end

