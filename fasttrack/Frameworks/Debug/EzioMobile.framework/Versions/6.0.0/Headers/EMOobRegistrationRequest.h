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

/**
 * Registration methods.
 *
 * - Since: 3.0
 */
typedef NS_ENUM(NSUInteger, EMOobRegistrationMethod){
    /**
     * Registration is authorised by the registration code entered by the user via the application UI.
     * The registration parameter in this case is the registration code entered by the end-user via the application
     * UI.
     */
    EMOobRegistrationMethodRegistrationCode
};

/**
 * OOB registration request object.
 *
 * - Since: 3.0
 */
@interface EMOobRegistrationRequest : NSObject

/**
 * Returns registration operation.
 * 
 * - Since: 3.0
 */
@property (nonatomic, assign, readonly) EMOobRegistrationMethod registrationMethod;

/**
 * Returns the value of the registration code.
 * 
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) id<EMSecureString> registrationParameter;

/**
 * Returns the user ID of the user who registers to the OOBS.
 * 
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSString *userId;

/**
 * Returns the alias of the user who performs the registration.
 * 
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSString *userAliasForClient;

/**
 * Returns The list of notification profile.
 * 
 * - Since: 3.0
 */
@property (nonatomic, copy, readonly) NSArray *notificationProfileItems;

/**
 * Constructs the OOB registration request object: Variant w/o any notification endpoints set.
 *
 * @param aUserId The ID of the user who registers to the OOBS.
 * @param aUserAliasForClient The alias of the user who performs th registration.
 * @param aRegistrationMethod The registration method to be used for the registration to the OOBS.
 * @param aRegistrationParameter The registration parameter. Its meaning depends on the value of the registration method - see previous parameter.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * - Since: 3.0
 */
- (id)initWithUserId:(NSString *)aUserId
  userAliasForClient:(NSString *)aUserAliasForClient
  registrationMethod:(EMOobRegistrationMethod)aRegistrationMethod
registrationParameter:(id<EMSecureString>)aRegistrationParameter
               error:(NSError **)anError;

/**
 * Constructs the OOB registration request object: Variant with the notification endpoints set.
 *
 * @param aUserId The ID of the user who registers to the OOBS.
 * @param aUserAliasForClient The alias of the user who performs th registration.
 * @param aNotificationProfileItems The notification endpoints to initially add to the currently being registered user.
 * @param aRegistrationMethod The registration method to be used for the registration to the OOBS.
 * @param aRegistrationParameter The registration parameter. Its meaning depends on the value of the registration method - see previous parameter.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * - Since: 3.0
 */
- (id)initWithUserId:(NSString *)aUserId
           userAliasForClient:(NSString *)aUserAliasForClient
  registrationMethod:(EMOobRegistrationMethod)aRegistrationMethod
registrationParameter:(id<EMSecureString>)aRegistrationParameter
notificationProfileItems:(NSArray *)aNotificationProfileItems
               error:(NSError **)anError;

/**
 *
 * Used by the SDK to wipe any sensitive data managed by this object when it is no longer needed.
 *
 * - Since: 3.0
 */
- (void)wipe;

@end
