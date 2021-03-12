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
#import "EMGpfDsDevice.h"
#import "EMSoftGpfDsSettings.h"
#import "EMCapToken.h"
#import "EMSoftCapToken.h"
#import "EMMutableSoftGpfDsSettings.h"

/**
 * GPF DS Factory
 */
@interface EMGpfDsFactory : NSObject

/**
 Returns the default DS CAP settings used for soft tokens.
 
 @return The default DS CAP settings.
 */
- (id<EMSoftGpfDsSettings>)defaultSoftGpfDsSettings;

/**
 Returns a mutable copy of the default GPF DS settings used for soft tokens.
 
 @return Mutable CAP settings based on the default cap settings returned from [EMCapFactory defaultSoftGpfDsSettings].
 */
- (id<EMMutableSoftGpfDsSettings>)mutableSoftGpfDsSettings;

/**
 Creates a Hardware or Software Gemalto Proprietary Framework (GPF)
 Dynamic Signature (DS) device.
 If the token is soft, i.e `[EMToken isSoft]` is `YES`,
 the default GPF DS settings are used otherwise
 the device settings are used.
 @warning Currently Mobile Protector SDK library only supports Software
 GPF DS device.
 @param token The CAP token.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The Gpf DS device.
 */
- (id<EMGpfDsDevice>)createGpfDsDeviceWithToken:(id<EMCapToken>)token error:(NSError **)error;


/**
 Creates a Software Gemalto Proprietary Framework (GPF)
 Dynamic Signature (DS) device using the given settings.
 
 This method may only be used for soft tokens, i.e `[EMToken isSoft]` is `YES`.
 
 @param softCapToken The soft CAP token.
 @param settings The GPF DS settings.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The Gpf DS device.
 */
- (id<EMGpfDsDevice>)createSoftGpfDsDeviceWithToken:(id<EMSoftCapToken>)softCapToken settings:(id<EMSoftGpfDsSettings>)settings error:(NSError **)error;


@end
