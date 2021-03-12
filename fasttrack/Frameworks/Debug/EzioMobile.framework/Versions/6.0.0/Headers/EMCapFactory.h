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

#import <Foundation/Foundation.h>
#import "EMCapToken.h"
#import "EMCapDevice.h"
#import "EMSoftCapSettings.h"
#import "EMMutableSoftCapSettings.h"
#import "EMCapDevice.h"
#import "EMSoftCapToken.h"

/**
  A factory for creating objects that produce or affect CAP (or its relatives)
  OTPs.
 */
@interface EMCapFactory : NSObject

///////////////////////////////////////////////////////////////////////////////////////
/// Create CAP device
///////////////////////////////////////////////////////////////////////////////////////

/**
 Creates a Hardware or Software CAP device for the given CAP token.

 If the token is soft, i.e `[EMToken isSoft]` is `YES`,
 the default CAP settings are used, otherwise the device
 settings are used.

 @warning Currently Mobile Protector SDK library only supports Software
 CAP device.
 
 @param token The CAP token.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The CAP device.
 - Since: 4.0
 */
- (id<EMCapDevice>)createCapDeviceWithToken:(id<EMCapToken>)token error:(NSError **)error;

/**
 Returns a mutable copy of the default CAP settings used for soft tokens.
 
 @return Mutable CAP settings based on the default cap settings.
 - Since: 4.0
 */
- (id<EMMutableSoftCapSettings>)mutableSoftCapSettings;

/**
 Creates a Software CAP device for the given token using the given settings.
 
 This method may only be used for soft tokens, i.e `[EMToken isSoft]` is `YES`.
 
 @param token The CAP token.
 @param settings The CAP settings.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The cap device.
 - Since: 4.0
 */
- (id<EMCapDevice>)createSoftCapDeviceWithToken:(id<EMSoftCapToken>)token settings:(id<EMSoftCapSettings>)settings error:(NSError **)error;

@end
