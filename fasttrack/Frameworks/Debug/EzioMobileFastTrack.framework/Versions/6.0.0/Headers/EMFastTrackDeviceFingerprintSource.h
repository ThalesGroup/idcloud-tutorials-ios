/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2019  -  GEMALTO DEVELOPPEMENT - R&D
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

NS_ASSUME_NONNULL_BEGIN

/** The defined anti-cloning types.
 * - Since: 5.3
 Seals the user's credentials. A factory reset/initialization of the device will make the credentials unusable.<br>Requirements: None
 @warning: If `EMFastTrackDeviceFingerprintTypeSoft` or `EMFastTrackDeviceFingerprintTypeHardwareKey` is used, user can not use the restored data after doing a factory reset
 and re-initializing to the same device.
 */
typedef NS_ENUM(NSUInteger, EMFastTrackDeviceFingerprintType) {

    /**
     Device fingerprint soft.
     */
    EMFastTrackDeviceFingerprintTypeSoft = 0x04,
    
    /**
     Device fingerprint hardware key.
     - Since: 5.4
     */
    EMFastTrackDeviceFingerprintTypeHardwareKey = 0x10
};

/**
 This class is used to create device fingerprint source settings.
 * - Since: 5.3
 */
@interface EMFastTrackDeviceFingerprintSource : NSObject

/**
 List for anti-cloning sources to use.
 */
@property (nonatomic, copy, readonly, nullable) NSSet *deviceFingerprintType;

/**
 Application custom fingerprint data to integrate into anti-cloning.
 */
@property (nonatomic, strong, readonly, nullable) NSData *customData;

/**
 Gets the default device fingerprint source `EMFastTrackDeviceFingerprintTypeSoft`. See `EMFastTrackDeviceFingerprintType`.
 */
+ (instancetype)defaultDeviceFingerprintSource NS_SWIFT_NAME(defaultDeviceFingerprintSource());

/**
 Initializes a new device fingerprint source.
 
 @param aDft Set of sources to use, see `EMFastTrackDeviceFingerprintType`.
 
 @return An instance of EMDeviceFingerprintSource.
 */
- (id)initWithDeviceFingerprintType:(NSSet *)aDft;

/**
 Initializes a new device fingerprint source with some application's custom data.
 @param aCustomData Application's custom data.
 
 @return An instance of EMDeviceFingerprintSource.
 */
- (id)initWithCustomData:(NSData *)aCustomData;

/**
 Initializes a new device fingerprint source with some application's custom data.
 @param aCustomData Application's custom data.
 @param aDft Set of sources to use, see EMFastTrackDeviceFingerprintType.
 
 @return An instance of EMDeviceFingerprintSource.
 */
- (id)initWithCustomData:(NSData *)aCustomData deviceFingerprintType:(NSSet *)aDft;

/**
 Checks if the provided device fingerprint type is activated.
 @param aDeviceFingerprintType The source to be verified.
 
 @return `YES` if source is active, `NO` otherwise.
 */
- (BOOL)isActive:(EMFastTrackDeviceFingerprintType)aDeviceFingerprintType;

/**
 Checks if the current device supports hardware-based key (Secure Enclave) for device fingerprint source `EMFastTrackDeviceFingerprintTypeHardwareKey`

 @return `YES` if device supports, `NO` otherwise.

 - Since: 5.4
 */
+ (BOOL)isHardwareKeySupported;

@end

NS_ASSUME_NONNULL_END
