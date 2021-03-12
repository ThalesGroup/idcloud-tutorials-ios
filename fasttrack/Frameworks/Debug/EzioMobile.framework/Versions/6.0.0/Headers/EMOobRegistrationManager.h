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

#import "EMOobRegistrationResponse.h"
#import "EMOobRegistrationRequest.h"
#import "EMOobRequestParameter.h"

/**
 * Interface for registering the user to the OOBS.
 * 
 * - Since: 3.0
 */
@protocol EMOobRegistrationManager

/**
 * Performs the registration of the user to the OOBS: The synchronous variant.
 *
 * @param aRequest The request object carrying all the data required by the OOBS in order to register the user to it.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return The registration response object.
 *
 * - Since: 3.0
 */
- (id<EMOobRegistrationResponse>)registerWithRequest:(EMOobRegistrationRequest *)aRequest error:(NSError **)anError;

/**
 * Performs the registration of the user to the OOBS: The synchronous variant.
 *
 * @param aRequest The request object carrying all the data required by the OOBS in order to register the user to it.
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param anError If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 *
 * @return The registration response object.
 *
 * - Since: 4.7
 */
- (id<EMOobRegistrationResponse>)registerWithRequest:(EMOobRegistrationRequest *)aRequest requestParameter:(EMOobRequestParameter*)aParam error:(NSError **)anError;

/**
 * Performs the registration of the user to the OOBS: The asynchronous variant.
 *
 * @warning This method is executed asynchronously
 *
 * @param aRequest The request object carrying all the data required by the OOBS in order to register the user to it.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 3.0
 */

- (void)registerWithRequest:(EMOobRegistrationRequest *)aRequest
          completionHandler:(void (^)(id<EMOobRegistrationResponse> aResponse, NSError *anError))aCompletionHandler;

/**
 * Performs the registration of the user to the OOBS: The asynchronous variant.
 *
 * @warning This method is executed asynchronously
 *
 * @param aRequest The request object carrying all the data required by the OOBS in order to register the user to it.
 * @param aParam The request parameter object carrying the additional parameters, i.e. custom HTTP headers.
 * @param aCompletionHandler The block to invoke on the main thread upon completion which contains
 * the response and error information if any.
 *
 * - Since: 4.7
 */
- (void)registerWithRequest:(EMOobRegistrationRequest *)aRequest requestParameter:(EMOobRequestParameter*)aParam
          completionHandler:(void (^)(id<EMOobRegistrationResponse> aResponse, NSError *anError))aCompletionHandler;

@end
