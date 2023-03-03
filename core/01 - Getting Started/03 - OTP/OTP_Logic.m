/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "OTP_Logic.h"
#import "OTP_Config.h"

@implementation OTP_Value

@synthesize otp = _otp, lifespan = _lifespan;

+ (instancetype)valueWithOTP:(id<EMSecureString>)otp
                lastLifespan:(NSInteger)lastLifespan
                 maxLifespan:(NSInteger)maxLifespan
{
    return [[OTP_Value alloc] initWithOTP:otp lastLifespan:lastLifespan maxLifespan:maxLifespan];
}

- (id)initWithOTP:(id<EMSecureString>)otp
     lastLifespan:(NSInteger)lastLifespan
      maxLifespan:(NSInteger)maxLifespan
{
    if (self = [super init]) {
        _otp                = otp;
        _lifespan.current   = lastLifespan;
        _lifespan.max       = maxLifespan;
    }
    
    return self;
}

- (void)wipe
{
    if (_otp) {
        [_otp wipe];
        _otp = nil;
    }
}

@end

@implementation OTP_Logic

+ (OTP_Value *)generateOtp:(id<EMOathToken>)token
             withAuthInput:(id<EMAuthInput>)authInput
                     error:(NSError *__autoreleasing *)error
{
    NSError     *internalErr = nil;
    OTP_Value   *retValue    = nil;
    
    do {
        // Detect jailbreak status.
        // Objective C
        int result;
        int status = EMDetectorJailbreakStatus(&result);
        if (status == EM_DETECTOR_STATUS_SUCCESS) {
            if (result == EM_DETECTOR_RESULT_POSITIVE) {
                break;
            }
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
        id<EMSecureString> otp = [deviceOath totpWithAuthInput:authInput error:&internalErr];
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

@end
