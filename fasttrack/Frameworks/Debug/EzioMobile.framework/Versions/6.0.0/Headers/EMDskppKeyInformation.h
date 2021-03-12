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


@protocol EMSecureString;


/**
 * This class contains the information of the key that was provisioned.
 * - Since: 4.1
 */
@interface EMDskppKeyInformation: NSObject

/**
 * The key algorithm.
 * - Since: 4.1
 */
@property (nonatomic) id<EMSecureString> keyAlgorithm;

/**
 * The key container Id.
 * - Since: 4.1
 */
@property (nonatomic) id<EMSecureString> keyContainerId;

/**
 * The key container version.
 * - Since: 4.1
 */
@property (nonatomic) id<EMSecureString> keyContainerVersion;

/**
 * The key usage.
 * - Since: 4.1
 */
@property (nonatomic) id<EMSecureString> keyUsage;

/**
 * The manufacturer.
 * - Since: 4.1
 */
@property (nonatomic) id<EMSecureString> manufacturer;

/**
 * The token serial number.
 * - Since: 4.1
 */
@property (nonatomic) id<EMSecureString> tokenSerialNumber;

/**
 * The token version.
 * - Since: 4.1
 */
@property (nonatomic) id<EMSecureString> version;

@end
