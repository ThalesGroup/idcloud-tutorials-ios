/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "TransactionSign_Logic.h"
#import "OTP_Config.h"
#import <CommonCrypto/CommonDigest.h>

@interface KeyValue : NSObject

@property (nonatomic, readonly, copy) NSString *key;
@property (nonatomic, readonly, copy) NSString *value;

/// Simple constructor object constructor.
/// @param key Desired key.
/// @param value Desired value.
+ (instancetype _Nonnull)create:(NSString *)key value:(NSString *)value;

/// Return "key:value" string in UTF8 format.
- (NSData *)keyValueUTF8;

@end

@implementation KeyValue

+ (instancetype)create:(NSString *)key value:(NSString *)value {
    return [[KeyValue alloc] initWithKey:key value:value];
}

- (id)initWithKey:(NSString *)key value:(NSString *)value {
    if (self = [super init]) {
        _key    = [key copy];
        _value  = [value copy];
    }
    
    return self;
}

- (NSData * _Nonnull)keyValueUTF8 {
    NSString *keyValue = [NSString stringWithFormat:@"%@:%@", _key, _value];
    return [keyValue dataUsingEncoding:NSUTF8StringEncoding];
}

@end

@implementation TransactionSign_Logic

// MARK: Public API

+ (OTP_Value *)generateOtp:(id<EMOathToken>)token
             withAuthInput:(id<EMAuthInput>)authInput
                    amount:(NSString *)amount
               beneficiary:(NSString *)beneficiary
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
                                          serverChallengeQuestion:[TransactionSign_Logic serverChallenge:amount beneficiary:beneficiary]
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

// MARK: - Private Helpers

+ (id<EMSecureString>)serverChallenge:(NSString *)amount
                          beneficiary:(NSString *)beneficiary {
    return [self ocraChallenge:@[[KeyValue create:@"amount"         value:amount],
                                 [KeyValue create:@"beneficiary"    value:beneficiary]]];
}

+ (id<EMSecureString>)ocraChallenge:(NSArray<KeyValue *> *)values {
    // Use builder to append TLV
    NSMutableData *buffer = [NSMutableData new];
    
    // Go through all values, calculate and append TLV for each one of them.
    for (NSInteger i = 0; i < values.count; i++) {
        // Convert keyvalue to UTF8 string
        NSData *keyValueUTF8 = [values[i] keyValueUTF8];
        
        // TLV tag DF71 from first item.
        Byte tlvTag1 = 0xDF;
        Byte tlvTag2 = 0x71 + i;
        Byte tlvLength = (Byte)keyValueUTF8.length;
        
        [buffer appendBytes:&tlvTag1 length:1];
        [buffer appendBytes:&tlvTag2 length:1];
        [buffer appendBytes:&tlvLength length:1];
        [buffer appendData:keyValueUTF8];
    }
    
    // Calculate digest
    NSMutableData *retValue = [NSMutableData dataWithLength:CC_SHA256_DIGEST_LENGTH];
    CC_SHA256(buffer.bytes, (CC_LONG)buffer.length, retValue.mutableBytes);
    
    id <EMSecureContainerFactory> secureContainer = [[EMCore sharedInstance] secureContainerFactory];
    return [secureContainer secureStringFromString:[TransactionSign_Logic hexadecimalString:retValue]];
}

+ (NSString *)hexadecimalString:(NSData *)data {
    const unsigned char *dataBuffer = (const unsigned char *)[data bytes];
    
    if (!dataBuffer) {
        return [NSString string];
    }
    
    NSUInteger          dataLength  = [data length];
    NSMutableString     *hexString  = [NSMutableString stringWithCapacity:(dataLength * 2)];
    for (int i = 0; i < dataLength; ++i) {
        [hexString appendString:[NSString stringWithFormat:@"%02lx", (unsigned long)dataBuffer[i]]];
    }
    
    return [NSString stringWithString:hexString];
}

@end
