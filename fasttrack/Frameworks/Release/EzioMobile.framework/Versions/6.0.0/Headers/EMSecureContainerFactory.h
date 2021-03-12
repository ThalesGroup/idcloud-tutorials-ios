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
#import "EMSecureString.h"
#import "EMSecureByteArray.h"

/**
 * Secure Container Factory
 */
@protocol EMSecureContainerFactory <NSObject>

/**
 * Create a secure string object from a String.
 *
 * @param string The string to securely store. The string will be converted to NSUTF8StringEncoding when stored in the 'secure data' object. String can't be null
 *
 *  @return A 'secure data' object that securely stores the data.
 *  @exception NSException When string is nil or if string encoding is not NSUTF8StringEncoding.
 */
- (id <EMSecureString>)secureStringFromString:(NSString *)string;

/**
 *  Create a secure string object from a String using a specific character set.
 *  <p>
 *  <b>Warning:</b> This method does not guarantee that the given string and the given encoding is compatible.
 *
 *  @param string The string to securely store. String can't be null
 *  @param encoding The string will be converted to this encoding when stored in the 'secure data' object. It could be any NSStringEncoding, etc.
 *
 *  @return A 'secure data' object that securely stores the data.
 *  @exception NSException When string is nil or if string encoding is not the one provided in encoding.
 */
- (id <EMSecureString>)secureStringFromString:(NSString *)string encoding:(NSStringEncoding)encoding;

/**
 * Create a secure string object from a NSData.
 *
 * @param data Data to securely store.
 * @param wipeSource If 'true', then the 'data' will be erased if the method returns successfully. Otherwise the input will not be modified.
 *
 * @return A 'secure data' object that securely stores the data.
 */
- (id <EMSecureString>)secureStringFromData:(NSData *)data wipeSource:(BOOL)wipeSource;

/**
 * Creates the secure byte array object.
 *
 * @param data Data to store to the output object.
 * @param wipeSource Pass `true` to wipe the original data.
 * @return The secure byte array object.
 */
- (id <EMSecureByteArray>)secureByteArrayWithData:(NSData *)data wipeSource:(BOOL)wipeSource;

@end
