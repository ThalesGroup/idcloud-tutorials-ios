
/** ----------------------------------------------------------------------------
 *
 *     Copyright (c)  2019  -  GEMALTO DEVELOPEMENT - R&D
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

#ifndef lib_EzioMobileFastTrack_h
#define lib_EzioMobileFastTrack_h

/* iOS Version Support */

#ifndef __IPHONE_11_0
    #define __IPHONE_11_0        110000
#endif

#define __EZIO_MINIMUM_IOS_VERSION_SUPPORT           __IPHONE_11_0

#ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
    #if __IPHONE_OS_VERSION_MIN_REQUIRED < __EZIO_MINIMUM_IOS_VERSION_SUPPORT
        #warning Ezio SDK supports Minimum iOS SDK 11.0.0. Set Deployment target to 11.0.
    #endif
#endif


#import <EzioMobileFastTrack/EMCapMobileProtector.h>
#import <EzioMobileFastTrack/EMFastTrack.h>
#import <EzioMobileFastTrack/EMFastTrackDeviceFingerprintSource.h>
#import <EzioMobileFastTrack/EMFastTrackErrorDomain.h>
#import <EzioMobileFastTrack/EMFastTrackTlsConfiguration.h>
#import <EzioMobileFastTrack/EMFetchMessageResponse.h>
#import <EzioMobileFastTrack/EMGenericIncomingMessage.h>
#import <EzioMobileFastTrack/EMGenericOutgoingMessage.h>
#import <EzioMobileFastTrack/EMIncomingMessage.h>
#import <EzioMobileFastTrack/EMMessage.h>
#import <EzioMobileFastTrack/EMMessageMeta.h>
#import <EzioMobileFastTrack/EMMessengerResponse.h>
#import <EzioMobileFastTrack/EMMobileMessageManager.h>
#import <EzioMobileFastTrack/EMMobileMessenger.h>
#import <EzioMobileFastTrack/EMMobileProtector.h>
#import <EzioMobileFastTrack/EMOathMobileProtector.h>
#import <EzioMobileFastTrack/EMOutgoingMessage.h>
#import <EzioMobileFastTrack/EMProtectorAuthInput.h>
#import <EzioMobileFastTrack/EMProtectorCapSettings.h>
#import <EzioMobileFastTrack/EMProtectorCapTokenDevice.h>
#import <EzioMobileFastTrack/EMProtectorDcvvSettings.h>
#import <EzioMobileFastTrack/EMProtectorHotpSettings.h>
#import <EzioMobileFastTrack/EMProtectorOathSettings.h>
#import <EzioMobileFastTrack/EMProtectorOathTokenDevice.h>
#import <EzioMobileFastTrack/EMProtectorOcraSettings.h>
#import <EzioMobileFastTrack/EMProtectorTokenDevice.h>
#import <EzioMobileFastTrack/EMProtectorTotpSettings.h>
#import <EzioMobileFastTrack/EMRegistrationResponse.h>
#import <EzioMobileFastTrack/EMSendMessageResponse.h>
#import <EzioMobileFastTrack/EMTransactionSignatureKey.h>
#import <EzioMobileFastTrack/EMTransactionSigningRequest.h>
#import <EzioMobileFastTrack/EMTransactionSigningResponse.h>
#import <EzioMobileFastTrack/EMTransactionVerifyRequest.h>
#import <EzioMobileFastTrack/EMTransactionVerifyResponse.h>
#import <EzioMobileFastTrack/SecureLog.h>
#import <EzioMobileFastTrack/SecureLogConfig.h>


#endif

