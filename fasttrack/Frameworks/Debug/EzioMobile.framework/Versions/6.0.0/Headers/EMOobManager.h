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

#import "EMOobConfiguration.h"
#import "EMOobRegistrationManager.h"
#import "EMOobUnregistrationManager.h"
#import "EMOobNotificationManager.h"
#import "EMOobMessageManager.h"

/**
 * OOB Manager
 *
 * - Since: 3.0
 */
@protocol EMOobManager<NSObject>


/**
 * Returns the OOB registration manager object.
 *
 * @return The OOB registration manager object.
 *
 * - Since: 3.0
 */
- (id<EMOobRegistrationManager>)oobRegistrationManager;

/**
 * Returns the OOB unregistration manager object.
 *
 * @param aClientId The client ID of the client to unregister. Must not be `nil`.
 *
 * @return The OOB unregistration manager object.
 *
 * - Since: 3.0
 */
- (id<EMOobUnregistrationManager>)oobUnregistrationManagerWithClientId:(NSString *)aClientId;

/**
 * Returns the OOB notification profile manager, which can be used to add/remove/set the notification profile details of the user.
 *
 * @param aClientId The ID of the client whose profile to be managed. Must not be `nil`.
 * @return the EMOobNotificationManager object attached to the provided clientId.
 *
 * - Since: 3.0
 */
- (id<EMOobNotificationManager>)oobNotificationManagerWithClientId:(NSString *)aClientId;

/**
 * Returns the OOB message manager.
 *
 * @param aClientId The ID of the client whose message exchanges to be managed. Must not be `nil`.
 * @param aProviderId The provider identifier. Must not be `nil`.
 *
 * @return The message manager object attached to the provided client ID.
 *
 * - Since: 3.0
 */
- (id<EMOobMessageManager>)oobMessageManagerWithClientId:(NSString *)aClientId providerId:(NSString *)aProviderId;

@end
