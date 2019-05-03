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

#import "OTP_Logic.h"
#import "OTP_Config.h"

@implementation OTP_Logic

+ (id<EMSecureString>)generateOtp:(id<EMOathToken>)token
                    withAuthInput:(id<EMAuthInput>)authInput
                            error:(NSError *__autoreleasing *)error
{
    NSError             *internalErr = nil;
    id<EMSecureString>  retValue     = nil;
    
    do {
        // Detect jailbreak status.
        if (EMJailbreakDetectorGetJailbreakStatus() != EMJailbreakStatusNotJailbroken)
            break;
        
        // Get oath factory and prepare oath settings.
        EMOathFactory *factory = [[EMOathService serviceWithModule:[EMOtpModule otpModule]] oathFactory];
        id<EMMutableSoftOathSettings> oathSettings = [factory mutableSoftOathSettings];
        [oathSettings setOcraSuite:C_OCRA_SUITE()];

        // Create device based on specific ocra suite.
        id<EMOathDevice> deviceOath = [factory createSoftOathDeviceWithToken:(id<EMSoftOathToken>)token
                                                                    settings:oathSettings
                                                                       error:&internalErr];
        BREAK_IF_NOT_NULL(internalErr);
        
        // Calculate OTP.
        retValue = [deviceOath totpWithAuthInput:authInput error:&internalErr];
    } while (false);
    
    // Something went wrong? Propagate error.
    if (internalErr && error)
        *error = internalErr;

    return retValue;
}

+ (void)getUserPin:(UINavigationController *)parent
 completionHandler:(EMSecureInputUiOnFinish)completionHandler
{
    // Get secure keypad builder.
    id<EMSecureInputBuilderV2> builder = [[EMSecureInputService serviceWithModule:[EMUIModule uiModule]] secureInputBuilderV2];
    
    // Configure secure keypad behaviour and visual.
    [builder showNavigationBar:YES];
    [builder validateUiConfiguration];
    
    // Build keypad and add handler.
    id<EMSecureInputUi> secureInput =
    [builder buildWithScrambling:NO isDoubleInputField:NO isDialog:NO onFinishBlock:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin) {
        // Wipe pinpad builder for security purpose.
        // This part is also important because of builder life cycle, otherwise this block will never be triggered!
        [builder wipe];
        
        // Dismiss the keypad and delete the secure input UI.
        [parent popViewControllerAnimated:YES];
        
        // Notify handler.
        completionHandler(firstPin, secondPin);
    }];
    
    // Push in secure input UI view controller to the current view controller
    [parent pushViewController:secureInput.viewController animated:YES];
}

@end
