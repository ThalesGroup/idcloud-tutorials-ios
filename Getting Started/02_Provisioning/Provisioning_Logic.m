//  MIT License
//
//  Copyright (c) 2019 Thales DIS
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

// IMPORTANT: This source code is intended to serve training information purposes only. Please make sure to review our IdCloud documentation, including security guidelines.

#import "Provisioning_Logic.h"
#import "Provisioning_Config.h"

@implementation Provisioning_Logic

+ (void)provisionWithUserId:(NSString *)userId
           registrationCode:(id<EMSecureString>)regCode
          completionHandler:(void (^)(id<EMOathToken>, NSError *))completionHandler
{
    NSError                 *managerErr = nil;
    id<EMOathTokenManager>  oathManager = [[EMOathService serviceWithModule:[EMOtpModule otpModule]] tokenManager:&managerErr];
    
    // Failed to get oath manager. Notify handler and exit.
    if (managerErr)
    {
        completionHandler(nil, managerErr);
        return;
    }
    
    @try
    {
        // Prepare provisioning configuration based on app data.
        EMProvisioningConfiguration *config = [EMProvisioningConfiguration
                                               epsConfigurationWithURL:C_PROVISION_URL()
                                               rsaKeyId:C_RSA_KEY_ID()
                                               rsaExponent:C_RSA_KEY_EXPONENT()
                                               rsaModulus:C_RSA_KEY_MODULUS()
                                               registrationCode:regCode
                                               provisioningProtocol:EMMobileProvisioningProtocolVersion3
                                               optionalParameters:^(EMEpsConfigurationBuilder *builder) {
                                                   // We can waken TLS configuration for debug purposes ( forbidden in release mode ).
                                                   builder.tlsConfiguration = C_TLS_CONFIGURATION();
                                               }];
        
        // Provision token with given config.
        [oathManager createTokenWithName:userId
               provisioningConfiguration:config
                       completionHandler:^(id<EMOathToken> token, NSError *error) {
                           // Notify in UI thread.
                           if (completionHandler)
                           {
                               dispatch_async(dispatch_get_main_queue(), ^{
                                   completionHandler(token, error);
                               });
                           }
                       }];
    }
    @catch (NSException *exception)
    {
        completionHandler(nil, NSErrorFromNSException(exception));
    }
}

+ (id<EMOathToken>)token:(NSError *__autoreleasing *)error
{
    id<EMOathToken> retValue        = nil;
    NSError         *internalErr    = nil;

    do {
        // Try to get oath manager.
        id<EMOathTokenManager> oathManager = [[EMOathService serviceWithModule:[EMOtpModule otpModule]] tokenManager:&internalErr];
        BREAK_IF_NOT_NULL(internalErr);
        
        // Try to get list of stored tokens. There should be zero or one in this scope.
        NSSet<NSString*> *tokens = [oathManager tokenNames:&internalErr];
        BREAK_IF_NOT_NULL(internalErr);
        
        // Try to get stored token
        if (tokens.count)
            retValue = [oathManager tokenWithName:tokens.anyObject error:&internalErr];
    } while (false);
    
    // Something went wrong? Propagate error.
    if (internalErr && error)
        *error = internalErr;
    
    return retValue;
}

+ (BOOL)removeToken:(NSError **)error
{
    BOOL    retValue        = NO;
    NSError *internalErr    = nil;
    
    do {
        id<EMOathTokenManager> oathManager = [[EMOathService serviceWithModule:[EMOtpModule otpModule]] tokenManager:&internalErr];
        BREAK_IF_NOT_NULL(internalErr);

        id<EMToken> token = [Provisioning_Logic token:&internalErr];
        BREAK_IF_NOT_NULL(internalErr);

        retValue = [oathManager removeToken:token error:&internalErr];
    } while (NO);
    

    // Something went wrong? Propagate error.
    if (internalErr && error)
        *error = internalErr;
    
    return retValue;
}

@end
