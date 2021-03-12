/** -----------------------------------------------------------------------------
 
 Copyright (c) 2019  -  GEMALTO DEVELOPMENT - R&D
 
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

#import "EMMobileProtector.h"
#import "EMProtectorTokenDevice.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A class defining a device that generates OATH based OTPs.
 * - Since: 5.3
 */
@interface EMProtectorOathTokenDevice : EMProtectorTokenDevice

/**
 Get OTP with PIN.

 @param pin                                               The pin.
 @param error                                             If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return The OTP.
 */
- (nullable NSString *)otpWithPin:(NSString *)pin
                            error:(NSError * _Nullable * _Nullable )error NS_SWIFT_NAME(otp(pin:));

/**
 Get OTP with AuthInput.
 
 @param authInput                                         The protectorAuthInput.
 @param error                                             If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return The OTP.
 */
- (nullable NSString *)otpWithAuthInput:(EMProtectorAuthInput *)authInput
                                  error:(NSError * _Nullable * _Nullable )error NS_SWIFT_NAME(otp(authInput:));

/**
 Get the OCRA with PIN and given parameters.
 
 @param pin                                                 The pin.
 @param serverChallengeQuestion     The server challenge question.
 @param clientChallengeQuestion     The client challenge question.
 @param passwordHash                              The hash value of password.
 @param session                                         The session data.
 @param error                                              If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return The OCRA OTP.
 */
- (nullable NSString *)ocraWithPin:(NSString *)pin
           serverChallengeQuestion:(NSString *)serverChallengeQuestion
           clientChallengeQuestion:(nullable NSString *)clientChallengeQuestion
                      passwordHash:(nullable NSData *)passwordHash
                           session:(nullable NSString *)session
                             error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(ocra(pin:serverChallengeQuestion:clientChallengeQuestion:passwordHash:session:));

/**
 Get the OCRA with AuthInput and given parameters.
 
 @param authInput                   The authInput.
 @param serverChallengeQuestion     The server challenge question.
 @param clientChallengeQuestion     The client challenge question.
 @param passwordHash                              The hash value of password.
 @param session                                         The session data.
 @param error                                              If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return The OCRA OTP.
 */
- (nullable NSString *)ocraWithAuthInput:(EMProtectorAuthInput *)authInput
                 serverChallengeQuestion:(NSString *)serverChallengeQuestion
                 clientChallengeQuestion:(nullable NSString *)clientChallengeQuestion
                            passwordHash:(nullable NSData *)passwordHash
                                 session:(nullable NSString *)session
                                   error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(ocra(authInput:serverChallengeQuestion:clientChallengeQuestion:passwordHash:session:));

/**
 Gets password hash value according the algorithm defined on OCRA settings.

 @param password                       The password.
 @param error                              If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return passwordHash               The hash value of the password.
 */
- (nullable NSData *)ocraPasswordHash:(NSString *)password
                                error:(NSError * _Nullable * _Nullable)error;
/**
 Returns lifespan of the last OTP computed by this token device for time-based OTP.
 In case last OTP computed is event-based, or no OTP has been computed yet, the function returns 'NSIntegerMax'.
 Each time this function is called, it returns the remaining lifespan in seconds of the last time-based OTP.
 Lifespan is computed with respect of device's settings.
 @return lifespan                           If positive, the last OTP is still valid according current time and token device. If negative,the last OTP computed is obsolete, it indicates the time elapsed since the OTP has become obsolete
*/
- (NSInteger)lastOtpLifeSpan;

@end

NS_ASSUME_NONNULL_END
