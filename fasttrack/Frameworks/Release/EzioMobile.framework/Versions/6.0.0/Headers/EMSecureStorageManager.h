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

#import "EMCore.h"
#import "EMPropertyStorage.h"

/**
 * The Secure Storage Manager is a high level interface that allows to manage Property Storage objects for storing sensitive data.
 *
 * - Since: 3.1
 */
@protocol EMSecureStorageManager <NSObject>

/**
 * Gets Property Storage with the given identifier, creates it if it does not exist.
 *
 * @param identifier Should not be `nil`.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The property storage.
 *
 * - Since: 3.1
 */
- (id<EMPropertyStorage>)propertyStorageWithIdentifier:(NSString *)identifier
                                                 error:(NSError **)anError;

/**
 * Check if the property storage of given identifier exists.
 * @param identifier Should not be `nil`.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return `YES` if the property storage exists otherwise returns `NO`.
 *
 * - Since: 3.1
 */
- (BOOL)hasPropertyStorageWithIdentifier:(NSString *)identifier
                                   error:(NSError **)anError;


/**
 * Destroys a storage and all data in the storage will be wiped.
 * @param identifier Should not be `nil`.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return `YES` if destroyed successfully, `NO` otherwise.
 *
 * - Since: 3.1
 */
- (BOOL)destroyPropertyStorageWithIdentifier:(NSString *)identifier error:(NSError **)anError;

@end
