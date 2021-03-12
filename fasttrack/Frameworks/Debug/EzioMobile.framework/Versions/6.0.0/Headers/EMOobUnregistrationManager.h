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

#import "EMOobRegistrationRequest.h"
#import "EMOobResponse.h"
#import "EMOobRequestParameter.h"

/**
 * Interface for unregistering the user from the OOBS.
 *
 * - Since: 3.0
 */
@protocol EMOobUnregistrationManager

/**
 * Performs the unregistration of the user from the OOBS: The synchronous variant.
 *
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The unregistration response object.
 *
 * - Since: 3.0
 */
- (id<EMOobResponse>)unregisterWithError:(NSError **)anError;

/**
 * Performs the unregistration of the user from the OOBS: The synchronous variant.
 *
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 * @return The unregistration response object.
 *
 * - Since: 4.7
 */
- (id<EMOobResponse>)unregisterWithRequestParameter:(EMOobRequestParameter*)aParam error:(NSError **)anError;

/**
 * Performs the unregistration of the user to the OOBS
 *
 * @warning This method is executed asynchronously
 *
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 3.0
 */
- (void)unregisterWithCompletionHandler:(void (^)(id<EMOobResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Performs the unregistration of the user to the OOBS
 *
 * @warning This method is executed asynchronously
 *
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 4.7
 */
- (void)unregisterWithRequestParameter:(EMOobRequestParameter*)aParam completionHandler:(void (^)(id<EMOobResponse> aResponse, NSError *anError))aCompletionHandler;

@end
