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

#import <Foundation/Foundation.h>
#import "EMProtectorTokenDevice.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A class defining a device that generates CAP based OTPs.
 * - Since: 5.3
 */
@interface EMProtectorCapTokenDevice : EMProtectorTokenDevice

/**
 Creates a mode 1 OTP.
 
 The typical use case of this OTP is for purchasing items from a merchant.
 
 @param pin                                     The pin.
 @param challenge                        The merchant challenge: An unpredictable number of up to 8 hexadecimal digits.
 @param amount                               The amount of the transaction. This value should only contain digits and can not be `nil`, empty string is a valid input.
                            Minimum digit length is 0 and maximum is 12. The SDK takes the original value of the amount, there will be no truncate, rounding off or append. This feature should be done by the application.
 @param currencyCode                  The currency as an ISO 4217 currency code, for example "USD". for United States Dollar.
 @param error                                  If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return The mode 1 OTP.
 */
- (nullable NSString *)otpMode1WithPin:(NSString *)pin
                             challenge:(NSString *)challenge
                                amount:(nullable NSString *)amount
                          currencyCode:(nullable NSString *)currencyCode
                                 error:(NSError * _Nullable * _Nullable)error;

/**
 Creates a mode 1 OTP with AuthInput.
 
 The typical use case of this OTP is for purchasing items from a merchant.
 
 @param authInput                        The authInput.
 @param challenge                        The merchant challenge: An unpredictable number of up to 8 hexadecimal digits.
 @param amount                               The amount of the transaction. This value should only contain digits and can not be `nil`, empty string is a valid input.
 Minimum digit length is 0 and maximum is 12. The SDK takes the original value of the amount, there will be no truncate, rounding off or append. This feature should be done by the application.
 @param currencyCode                  The currency as an ISO 4217 currency code, for example "USD". for United States Dollar.
 @param error                                  If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return The mode 1 OTP.
 */
- (nullable NSString *)otpMode1WithAuthInput:(EMProtectorAuthInput *)authInput
                                   challenge:(NSString *)challenge
                                      amount:(nullable NSString *)amount
                                currencyCode:(nullable NSString *)currencyCode
                                       error:(NSError * _Nullable * _Nullable)error;


/**
 Creates a mode 2 OTP.
 
 The typical use case of this mode is for simple authentication.
 
 @param pin                                     The pin.
 @param error                                 If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return The mode 2 OTP.
 */
- (nullable NSString *)otpMode2WithPin:(NSString *)pin
                                 error:(NSError * _Nullable * _Nullable)error;

/**
 Creates a mode 2 OTP with AuthInput.
 
 The typical use case of this mode is for simple authentication.
 
 @param authInput                             The authInput.
 @param error                                 If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return The mode 2 OTP.
 */
- (nullable NSString *)otpMode2WithAuthInput:(EMProtectorAuthInput *)authInput
                                       error:(NSError * _Nullable * _Nullable)error;

/**
 Creates a mode 2 transaction data signature OTP.
 
 The typical use case of this mode is for signing a set of transaction data.
 One such example is to sign the destination bank account in a transaction.
 
 @param pin                                     The pin.
 @param dataToSign                      The data to sign.
                            Data should only contain digits, maximum 10 digit per data and maximum 10 data fields in the list.
                            Don't pass empty data, at least one non-empty data is required.
 @param error                                  If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return The mode 2 TDS OTP.
 */
- (nullable NSString *)otpMode2TdsWithPin:(NSString *)pin
                               dataToSign:(NSMutableArray *)dataToSign
                                    error:(NSError * _Nullable * _Nullable)error;

/**
 Creates a mode 2 transaction data signature OTP with authInput.
 
 The typical use case of this mode is for signing a set of transaction data.
 One such example is to sign the destination bank account in a transaction.
 
 @param authInput                       The authInput.
 @param dataToSign                      The data to sign.
 Data should only contain digits, maximum 10 digit per data and maximum 10 data fields in the list.
 Don't pass empty data, at least one non-empty data is required.
 @param error                                  If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return The mode 2 TDS OTP.
 */
- (nullable NSString *)otpMode2TdsWithAuthInput:(EMProtectorAuthInput *)authInput
                                     dataToSign:(NSMutableArray *)dataToSign
                                          error:(NSError * _Nullable * _Nullable)error;


/**
 Creates a Mode3 OTP.
 
 The typical use case of this mode is for challenge/response.
 One such example is to log into a bank's website.
 
 @param pin                                      The pin.
 @param challenge                         The login challenge: An unpredictable number of up to 8 hexadecimal digits.
 @param error                                  If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return The mode 3 OTP.
 
 */
- (nullable NSString *)otpMode3WithPin:(NSString *)pin
                             challenge:(NSString *)challenge
                                 error:(NSError * _Nullable * _Nullable)error;

/**
 Creates a Mode3 OTP with AuthInput.
 
 The typical use case of this mode is for challenge/response.
 One such example is to log into a bank's website.
 
 @param authInput                         The authInput.
 @param challenge                         The login challenge: An unpredictable number of up to 8 hexadecimal digits.
 @param error                             If an error occurs, upon return contains an `NSError` object that describes the problem.
 @return The mode 3 OTP.
 
 */
- (nullable NSString *)otpMode3WithAuthInput:(EMProtectorAuthInput *)authInput
                                   challenge:(NSString *)challenge
                                       error:(NSError * _Nullable * _Nullable)error;


/**
 Checks if amount is required for a mode 1 operation.

 @return `YES` if amount is required, `NO` otherwise.
 */
- (BOOL)isMode1AmountRequired;

/**
 Checks if currency is required for a mode 1 operation

 @return `YES` if amount is required, `NO` otherwise.
 */
- (BOOL)isMode1CurrencyRequired;

@end

NS_ASSUME_NONNULL_END
