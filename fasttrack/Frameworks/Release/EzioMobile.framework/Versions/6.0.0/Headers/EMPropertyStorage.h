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

/**
 * <p>
 * PropertyStorage represents a storage which can be used to store data in the
 * form of key-value pair. It provides protections on the stored property.
 * PropertyStorage seals the property with a password which is managed by the
 * PasswordManager, as well as the configured device fingerprint.
 * </p>
 * <p>
 * <b>NOTE:</b> Since the password is managed by the password manager, login is
 * required before using the storage. Default password is supported by Ezio SDK
 * but it is strongly recommended to use a customized password for the
 * SecureStorage.
 * </p>
 *
 * - Since: 3.1
 *
 */
@protocol EMSecureByteArray;

/**
 * Interface of the secure storage object. See EMSecureStorageManager to query secure storage objects.
 *
 * **Note:**<br />
 * Before calling any method of EMPropertyStorage, make sure you have already logged in to password manager first. See EMPasswordManager.
 *
 * - Since: 3.1
 */
@protocol EMPropertyStorage <NSObject>

/**
 *
 * Opens a storage. This has to be called before retrieving or updating the data in the storage.
 *
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return `YES` if opening succeeds, `NO` otherwise.
 *
 * - Since: 3.1
 */
- (BOOL)open:(NSError **)anError;

/**
 *
 * Closes a storage.
 *
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return `YES` if closing succeeds, `NO` otherwise.
 *
 * - Since: 3.1
 */
- (BOOL)close:(NSError **)anError;


/**
 * Checks if the storage is open.
 *
 * @return `YES` if open, `NO` otherwise.
 *
 * - Since: 3.1
 */
- (BOOL)isOpen;

/**
 * Gets the set of keys for all the data stored in the storage.
 *
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return Set of keys in the secure storage; an empty set if contains no key-value; `nil` if an error occurs.
 *
 * - Since: 3.1
 */
- (NSSet *)allKeys:(NSError **)anError;

/**
 * Check if an entry with the given key exist in the storage.
 *
 * @param key the identifier of a property.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return `YES` if property exists, `NO` if not exist or some error occurred.
 *
 * - Since: 3.1
 */
- (BOOL)hasPropertyWithKey:(NSData *)key error:(NSError **)anError;

/**
 * Sets a property into the storage.
 *
 * @param key The key. Should not be `nil`.
 * @param property The property value. Should not be `nil`.
 * @param wipeValue If `YES` immediately wipes the property value after calling the method.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return `YES` if stored successfully, `NO` otherwise.
 *
 * - Since: 3.1
 */
- (BOOL)setProperty:(id<EMSecureByteArray>)property forKey:(NSData *)key wipeValue:(BOOL)wipeValue error:(NSError **)anError;

/**
 * Gets property from the storage.
 *
 * @param key The key. Should not be `nil`.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The property if found, `nil` if not found or if an error occurs.
 *
 * - Since: 3.1
 */
- (id<EMSecureByteArray>)propertyForKey:(NSData *)key error:(NSError **)anError;

/**
 * Removes a property with given key.
 *
 * @param key The key. Should not be `nil`.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return `YES` if deleted successfully, `NO` otherwise.
 *
 * - Since: 3.1
 */
- (BOOL)removePropertyForKey:(NSData *)key error:(NSError **)anError;

/**
 *
 * Removes all the properties from the storage. Results in empty storage but the storage table still exists.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return `YES` if deleted successfully, `NO` otherwise.
 *
 * - Since: 3.1
 */
- (BOOL)removeAllProperties:(NSError **)anError;


@end
