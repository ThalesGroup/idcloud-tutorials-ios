/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "QRCodeBasic_Logic.h"

// Review: SNE Document private methods
@implementation QRCodeBasic_Logic

// MARK: - Public API

+ (void)parseQRCode:(NSString *)code completionHandler:(QRCodeHandler)handler
{
    BOOL                retValue    = NO;
    NSError             *error      = nil;
    NSString            *userId     = nil;
    id<EMSecureString>  regCode     = nil;
    
    do {
        // Two components in frame are user id and reg code.
        NSString            *plainData  = [QRCodeBasic_Logic utf8FromHex:code];
        NSArray<NSString *> *components = [plainData componentsSeparatedByString:@","];
        if (components.count != 2) {
            error = [NSError errorWithDomain:NSStringFromClass(self)
                                        code:-1
                                    userInfo:@{NSLocalizedDescriptionKey: NSLocalizedString(@"STRING_QR_CODE_BASIC_FAILED_TO_PARSE", nil)}];
        }
        BREAK_IF_NOT_NULL(error);
        
        // Get actual values.
        userId      = components[0];
        regCode     = [[[EMCore sharedInstance] secureContainerFactory] secureStringFromString:components[1]];
        retValue    = YES;
        
    } while (NO);
    
    // Notify handler.
    handler(retValue, userId, regCode, error);
}

// MARK: - Private Helpers

+ (NSString *)utf8FromHex:(NSString *)hexString
{
    // Ignore invalid inputs.
    if (!hexString || !hexString.length || (hexString.length % 2) != 0) {
        return nil;
    }
    
    // Prepare output string.
    NSMutableString *retValue   = [NSMutableString new];
    
    // Iterate through all hex chars and find utf8 values.
    for (NSUInteger location = 0; location < hexString.length; location = location + 2) {
        int32_t value = 0;
        sscanf([[hexString substringWithRange: NSMakeRange(location, 2)] cStringUsingEncoding:NSASCIIStringEncoding], "%x", &value);
        [retValue appendFormat:@"%c", (char)value];
    }
    
    return retValue;
}

@end
