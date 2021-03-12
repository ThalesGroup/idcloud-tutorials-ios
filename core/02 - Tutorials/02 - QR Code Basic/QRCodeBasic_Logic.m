//  MIT License
//
//  Copyright (c) 2020 Thales DIS
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
