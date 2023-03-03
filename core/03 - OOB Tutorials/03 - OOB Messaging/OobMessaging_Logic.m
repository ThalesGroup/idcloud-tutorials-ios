/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "OobMessaging_Logic.h"
#import "OobMessaging_Config.h"
#import "OobRegistration_Logic.h"
#import "OTP_Config.h"

// Message type we want to handle. Contain message id to fetch and origin client id.
#define kPushMessageType                @"com.gemalto.msm"
#define kPushMessageClientId            @"clientId"
#define kPushMessageMessageId           @"messageId"

static id<OobMessageListener> sOobListener = nil;

// Review: SNE document private methods
@implementation OobMessaging_Logic

// MARK: - Public API

+ (void)setCurrenOobListener:(id<OobMessageListener>)listener
{
    sOobListener = listener;
}

+ (void)processIncommingPush:(NSDictionary *)notification
{
    // React on message type com.gemalto.msm with supported view controller on screen.
    // This is just to simplify sample app scenario. Real application should handle all notification all the time.
    if (!sOobListener || !notification || !(notification = notification[kPushMessageType]))
        return;
    
    // Get client and message id out of it.
    NSString *msgClientId   = notification[kPushMessageClientId];
    NSString *msgMessageId  = notification[kPushMessageMessageId];
    NSString *locClientId   = [OobRegistration_Logic readClientId];
    
    // Find related token / client id on local. React only on current one.
    if (![msgClientId isEqualToString:locClientId])
        return;
    
    // Prepare manager with current client and provider id.
    id<EMOobManager>        manager             = [OobRegistration_Logic initializeOOBManager];
    id<EMOobMessageManager> oobMessageManager   = [manager oobMessageManagerWithClientId:locClientId
                                                                              providerId:CFG_OOB_PROVIDER_ID()];
    
    // Display loading bar to indicate message downloading.
    [sOobListener onOobLoadingShow:NSLocalizedString(@"LOADING_MESSAGE_INCOMMING_MESSAGE", nil)];
    
    // Download message content.
    // Some messages might already be prefetched so we don't have to download them.
    // For simplicity we will download all of them.
    [oobMessageManager fetchWithMessageId:msgMessageId completionHandler:^(id<EMOobFetchMessageResponse> response, NSError *error) {
        [OobMessaging_Logic processFetchResponse:oobMessageManager response:response error:error];
    }];
}

+ (void)fetchMessages
{
    // Fetching make sense only with registered listener.
    assert(sOobListener);
    if (!sOobListener)
        return;
    
    NSString *locClientId   = [OobRegistration_Logic readClientId];

    // Prepare manager with current client and provider id.
    id<EMOobManager>        manager             = [OobRegistration_Logic initializeOOBManager];
    id<EMOobMessageManager> oobMessageManager   = [manager oobMessageManagerWithClientId:locClientId
                                                                              providerId:CFG_OOB_PROVIDER_ID()];
    
    // Display loading bar to indicate message downloading.
    [sOobListener onOobLoadingShow:NSLocalizedString(@"STRING_FETCH_LOADING", nil)];
    
    // Try to fetch any possible messages on server.
    [oobMessageManager fetchWithTimeout:30 completionHandler:^(id<EMOobFetchMessageResponse> aResponse, NSError *anError) {
        [OobMessaging_Logic processFetchResponse:oobMessageManager response:aResponse error:anError];
    }];
    
}

+ (OTP_Value *)generateOtp:(id<EMOathToken>)token
             withAuthInput:(id<EMAuthInput>)authInput
           serverChallenge:(id<EMSecureString>)serverChallenge
                     error:(NSError *__autoreleasing *)error
{
    NSError     *internalErr = nil;
    OTP_Value   *retValue    = nil;
    
    do {
        // Detect jailbreak status.
        if (EMJailbreakDetectorGetJailbreakStatus() != EMJailbreakStatusNotJailbroken) {
            break;
        }
        
        // Get oath factory and prepare oath settings.
        EMOathFactory *factory = [[EMOathService serviceWithModule:[EMOtpModule otpModule]] oathFactory];
        id<EMMutableSoftOathSettings> oathSettings = [factory mutableSoftOathSettings];
        [oathSettings setOcraSuite:CFG_OCRA_SUITE()];
        
        // Create device based on specific ocra suite.
        id<EMOathDevice> deviceOath = [factory createSoftOathDeviceWithToken:(id<EMSoftOathToken>)token
                                                                    settings:oathSettings
                                                                       error:&internalErr];
        BREAK_IF_NOT_NULL(internalErr);
        
        // Calculate OTP.
        id<EMSecureString> otp = [deviceOath ocraOtpWithAuthInput:authInput
                                          serverChallengeQuestion:serverChallenge
                                          clientChallengeQuestion:nil
                                                     passwordHash:nil
                                                          session:nil
                                                            error:&internalErr];
        BREAK_IF_NOT_NULL(internalErr);
        
        // Return OTP value together with lifespan so UI can display time when password is valid.
        retValue = [OTP_Value valueWithOTP:otp
                              lastLifespan:deviceOath.lastOtpLifespan
                               maxLifespan:oathSettings.totpTimestepSize];
    } while (NO);
    
    // Something went wrong? Propagate error.
    if (internalErr && error) {
        *error = internalErr;
    }
    
    return retValue;
}

// MARK: - Message handlers

+ (void)processFetchResponse:(id<EMOobMessageManager>)manager response:(id<EMOobFetchMessageResponse>)response error:(NSError *)error
{
    // Downloading is done, we can hide dialog.
    [sOobListener onOobLoadingHide];
    
    // Check response code and either proccess incomming message or display error.
    if (response.resultCode == EMOobResultCodeSuccess && response.oobIncomingMessage) {
        [self processIncommingMessage:manager message:response.oobIncomingMessage];
    } else if (error) {
        [sOobListener onOobDisplayMessage:error.localizedDescription];
    }

}

+ (BOOL)processIncommingMessage:(id<EMOobMessageManager>)oobMessageManager
                        message:(id<EMOobIncomingMessage>)message
{
    BOOL retValue = NO;
    
    if ([message.messageType isEqualToString:EMOobIncomingMessageTypeTransactionSigning]) {
        // Sign request.
        retValue = [OobMessaging_Logic processTransactionSigningRequest:oobMessageManager request:(id <EMOobTransactionSigningRequest>)message];
    } else if ([message.messageType isEqualToString:EMOobIncomingMessageTypeTransactionVerify]) {
        // Verify request
        retValue = [OobMessaging_Logic processTransactionVerifyRequest:oobMessageManager request:(id <EMOobTransactionVerifyRequest>)message];
    }
    
    return retValue;
}

+ (BOOL)processTransactionSigningRequest:(id<EMOobMessageManager>)oobMessageManager
                                 request:(id<EMOobTransactionSigningRequest>)request

{
    NSError         *internalError  = nil;
    id<EMMspParser> parser          = [[[EMMspService serviceWithModule:[EMMspModule mspModule]] mspFactory] createMspParser];
    
    // Get message subject key and fill in all values.
    NSString *subject = NSLocalizedString(request.subject.stringValue, nil);
    for (NSString *key in request.meta.allKeys)
    {
        NSString *placeholder = [NSString stringWithFormat:@"%%%@", key];
        subject = [subject stringByReplacingOccurrencesOfString:placeholder withString:request.meta[key]];
    }
    
    // Try to parse frame.
    do {
        id<EMMspFrame>  frame   = [parser parse:request.mspFrame error:&internalError];
        BREAK_IF_NOT_NULL(internalError);
        
        id<EMMspData>   data    = [parser parseMspData:frame error:&internalError];
        BREAK_IF_NOT_NULL(internalError);
        
        // For purpouse of this sample app we will support only OATH.
        if (data.baseAlgo != EM_MSP_BASE_ALGO_OATH) {
            break; // Skip unsupported frames.
        }
        
        // Display dialog to get user reaction. For approve we need also OTP to be calculated.
        [sOobListener onOobApproveMessage:subject
                      withServerChallenge:((id <EMMspOathData>)data).ocraServerChallenge.value
                        completionHandler:^(OTP_Value *otpValue)
         {
             // Display loading bar to indicate message sending.
             [sOobListener onOobLoadingShow:NSLocalizedString(@"STRING_SEND_LOADING", nil)];
             
             // If we get OTP it mean, that user did approved request.
             id<EMOobTransactionSigningResponse> responseToSend = [request createWithResponse:otpValue ? EMOobTransactionSigningResponseValueAccepted : EMOobTransactionSigningResponseValueRejected
                                                                                          otp:[otpValue.otp copy] // Send copy, this instance will get wiped!
                                                                                         meta:nil];
             
             // Send message and wait display result.
             [oobMessageManager sendWithMessage:responseToSend
                              completionHandler:^(id<EMOobMessageResponse> response, NSError *error)
              {
                  // Hide loading indicator in all cases, because sending is done.
                  [sOobListener onOobLoadingHide];
                  
                  if (response && !error) {
                      [sOobListener onOobDisplayMessage:NSLocalizedString(@"STRING_SEND_SUCCESS", nil)];
                  } else if (error) {
                      [sOobListener onOobDisplayMessage:error.localizedDescription];
                  }
              }];
         }];
    } while (NO);
    
    // Display possible parsing issue.
    if (internalError)
    {
        [sOobListener onOobLoadingHide];
        [sOobListener onOobDisplayMessage:internalError.localizedDescription];
    }
    
    return YES;
}

+ (BOOL)processTransactionVerifyRequest:(id<EMOobMessageManager>)oobMessageManager
                                request:(id<EMOobTransactionVerifyRequest>)request

{
    // Empty sample method
    return NO;
}

@end
