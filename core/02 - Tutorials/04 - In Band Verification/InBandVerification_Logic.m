/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "InBandVerification_Logic.h"
#import "InBandVerification_Config.h"

typedef void (^HTTPResponse)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error);

#define kXMLTemplateAuth @"<?xml version=\"1.0\" encoding=\"UTF-8\"?> \
<AuthenticationRequest> \
<UserID>%@</UserID> \
<OTP>%@</OTP> \
</AuthenticationRequest>"

// Review: SNE document private methods
@implementation InBandVerification_Logic

+ (void)verifyWithToken:(id<EMOathToken>)token
              authInput:(id<EMAuthInput>)authInput
      completionHandler:(GenericOtpHandler)completionHandler
{
    // Calculate OTP for given pin.
    NSError *internalErr = nil;
    OTP_Value *otpValue = [OTP_Logic generateOtp:token withAuthInput:authInput error:&internalErr];
    
    // If otp computation was succesfull, we can send validation request to server.
    if (!internalErr) {
        [InBandVerification_Logic verifyWithTokenName:token.name
                                         withOTPValue:otpValue
                                    completionHandler:completionHandler];
    } else {
        completionHandler(NO, internalErr.localizedDescription, otpValue.lifespan);
    }
    
    // We don't need otp any more. Wipe it.
    [otpValue wipe];
}

// MARK: - Private helpers

+ (void)verifyWithTokenName:(NSString *)tokenName
               withOTPValue:(OTP_Value *)otpValue
          completionHandler:(GenericOtpHandler)completionHandler
{
    NSString        *toHash     = [NSString stringWithFormat:@"%@:%@", CFG_BASICAUTH_USERNAME(), CFG_BASICAUTH_PASSWORD()];
    NSString        *hash       = [[toHash dataUsingEncoding:NSUTF8StringEncoding] base64EncodedStringWithOptions:0];
    NSString        *body       = [NSString stringWithFormat:kXMLTemplateAuth, tokenName, otpValue.otp.stringValue];
    NSDictionary    *headers    = @{@"Authorization" : [NSString stringWithFormat:@"Basic %@", hash]};
    
    // Post message and wait for results.
    [InBandVerification_Logic doPostMessage:CFG_URL_AUTH()
                                contentType:@"text/xml"
                                    headers:headers
                                       body:body
                           returnInUIThread:YES
                          completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error)
     {
         if (!error) {
             NSString *value = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
             completionHandler([value isEqualToString:@"Authentication succeeded"], value, otpValue.lifespan);
         } else {
             completionHandler(NO, error.localizedDescription, otpValue.lifespan);
         }
     }];
}

+ (void)doPostMessage:(NSString *)url
          contentType:(NSString *)contentType
              headers:(NSDictionary<NSString *, NSString *> *)headers
                 body:(NSString *)body
     returnInUIThread:(BOOL)returnInUIThread
    completionHandler:(HTTPResponse)completionHandler
{
    // Prepare HTTP post request.
    NSData                  *postData   = [body dataUsingEncoding:NSASCIIStringEncoding allowLossyConversion:YES];
    NSMutableURLRequest     *request    = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:url]];
    [request setHTTPMethod:@"POST"];
    [request setValue:[NSString stringWithFormat:@"%lu", (unsigned long)[postData length]] forHTTPHeaderField:@"Content-Length"];
    [request setValue:contentType forHTTPHeaderField:@"Content-Type"];
    for (NSString *loopKey in headers.allKeys) {
        [request setValue:headers[loopKey] forHTTPHeaderField:loopKey];
    }
    [request setHTTPBody:postData];
    
    // Make response return in UI thread if requested.
    HTTPResponse handler = returnInUIThread && completionHandler ? ^void(NSData *data, NSURLResponse *response, NSError *error)
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            completionHandler(data, response, error);
        });
    } : completionHandler;
    
    // Prepare session with predefined short timeout.
    NSURLSessionConfiguration *sessionConfig    = [NSURLSessionConfiguration defaultSessionConfiguration];
    sessionConfig.timeoutIntervalForRequest     = 15.0;
    sessionConfig.timeoutIntervalForResource    = 15.0;
    
    // Post request.
    [[[NSURLSession sessionWithConfiguration:sessionConfig] dataTaskWithRequest:request completionHandler:handler] resume];
}

@end
