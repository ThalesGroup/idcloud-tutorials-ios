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

/**
 * This manager provides functionality to manage the client's notification profiles. A
 * notification profile is represented as an EMOobNotificationProfile object.
 * It is a tuple which contains a channel (SMS, Push, email, etc.)
 * and an end point attached to that channel (for example an email address for
 * the case of an email channel).
 *
 * - Since: 3.0
 *
 */

#import <Foundation/Foundation.h>

#import "EMOobResponse.h"
#import "EMOobNotificationProfilesResponse.h"
#import "EMOobRequestParameter.h"

/**
 * The manager that provides functionality to manage a user notification profile. A notification profile is a list of
 * EMOobNotificationProfile objects. Each notification profile contains a channel (SMS, Push, email,
 * etc.) and an end point attached to that channel (for example an email address for the case of an email channel).
 *
 * - Since: 3.0
 *
 */
@protocol EMOobNotificationManager <NSObject>

/**
 * Retrieves the list of notification profiles from the server.
 *
 * This method is long-running and should not be executed on the UI thread.
 *
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * 
 * - Since: 3.0
 *
 * @return The list of notification profiles associated with the current client.
 */
- (id<EMOobNotificationProfilesResponse>)notificationProfiles:(NSError **)anError;

/**
 * Retrieves the list of notification profiles from the server.
 *
 * This method is long-running and should not be executed on the UI thread.
 *
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * - Since: 4.7
 *
 * @return The list of notification profiles associated with the current client.
 */
- (id<EMOobNotificationProfilesResponse>)notificationProfilesWithRequestParameter:(EMOobRequestParameter*)aParam error:(NSError **)anError;

/**
 * Sets or updates the list of notification profiles of the current client. If
 * the list has already been set, it will be replaced by this new list.
 *
 * This method is long running and should not be executed on the UI thread.
 *
 * @param aNotificationProfiles A list of one or more notification profile to set as the new notification profile.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * 
 * - Since: 3.0
 * 
 * @return The result of the request.
 */
- (id<EMOobResponse>)setNotificationProfiles:(NSArray *)aNotificationProfiles error:(NSError **)anError;

/**
 * Sets or updates the list of notification profiles of the current client. If
 * the list has already been set, it will be replaced by this new list.
 *
 * This method is long running and should not be executed on the UI thread.
 *
 * @param aNotificationProfiles A list of one or more notification profile to set as the new notification profile.
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * - Since: 4.7
 *
 * @return The result of the request.
 */
- (id<EMOobResponse>)setNotificationProfiles:(NSArray *)aNotificationProfiles requestParameter:(EMOobRequestParameter*)aParam error:(NSError **)anError;

/**
 * Clears (removes all) the current client notification profiles. This
 * will leave the client with no notification profile.
 *
 * This method is long-running and should not be executed on the UI thread.
 *
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * - Since: 3.0
 *
 * @return The response of the request.
 */
- (id<EMOobResponse>)clearNotificationProfiles:(NSError **)anError;

/**
 * Clears (removes all) the current client notification profiles. This
 * will leave the client with no notification profile.
 *
 * This method is long-running and should not be executed on the UI thread.
 *
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * - Since: 4.7
 *
 * @return The response of the request.
 */
- (id<EMOobResponse>)clearNotificationProfilesWithRequestParameter:(EMOobRequestParameter*)aParam error:(NSError **)anError;

/**
 * Retrieves the list of notification profiles from the server.
 *
 * @warning This method is executed asynchronously
 *
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 * - Since: 3.0
 */
- (void)notificationProfilesWithCompletionHandler:(void (^)(id<EMOobNotificationProfilesResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Retrieves the list of notification profiles from the server.
 *
 * @warning This method is executed asynchronously
 *
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 * - Since: 4.7
 */
- (void)notificationProfilesWithRequestParameter:(EMOobRequestParameter*)aParam completionHandler:(void (^)(id<EMOobNotificationProfilesResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Sets or updates the list of notification profiles of the current client. If
 * the list has already been set, it will be replaced by this new list.
 *
 * @warning This method is executed asynchronously
 *
 * @param aNotificationProfiles A list of one ore more notification profiles to set.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 3.0
 */
- (void)setNotificationProfiles:(NSArray *)aNotificationProfiles
              completionHandler:(void (^)(id<EMOobResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Sets or updates the list of notification profiles of the current client. If
 * the list has already been set, it will be replaced by this new list.
 *
 * @warning This method is executed asynchronously
 *
 * @param aNotificationProfiles A list of one ore more notification profiles to set.
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 4.7
 */
- (void)setNotificationProfiles:(NSArray *)aNotificationProfiles requestParameter:(EMOobRequestParameter*)aParam
              completionHandler:(void (^)(id<EMOobResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Clears (removes all) the current client notification profiles. This
 * will leave the client with no notification profile.
 *
 * @warning This method is executed asynchronously
 *
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 3.0
 */
- (void)clearNotificationProfilesWithCompletionHandler:(void (^)(id<EMOobResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Clears (removes all) the current client notification profiles. This
 * will leave the client with no notification profile.
 *
 * @warning This method is executed asynchronously
 *
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 4.7
 */
- (void)clearNotificationProfilesWithRequestParameter:(EMOobRequestParameter*)aParam completionHandler:(void (^)(id<EMOobResponse> aResponse, NSError *anError))aCompletionHandler;

@end
