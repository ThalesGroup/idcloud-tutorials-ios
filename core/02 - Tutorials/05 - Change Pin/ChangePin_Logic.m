/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "ChangePin_Logic.h"


@implementation ChangePin_Logic

+ (NSString *)changePin:(id<EMToken>)token
                 oldPin:(id<EMPinAuthInput>)oldPin
                 newPin:(id<EMPinAuthInput>)newPin
          newPinConfirm:(id<EMPinAuthInput>)newPinConfirmation
{
    NSString *retValue = nil;
    
    // Check both entries consistency.
    if ([newPin isEqual:newPinConfirmation]) {
        
        // Try to change pin.
        NSError *internalErr;
        BOOL changed = [token changePinWithAuthInput:oldPin newPin:newPin error:&internalErr];
        
        // Wipe all auth inputs
        [oldPin wipe];
        [newPin wipe];
        [newPinConfirmation wipe];
        
        if (changed) {
            retValue = NSLocalizedString(@"STRING_CHANGE_PIN_SUCCESS", nil);
        } else if (internalErr) {
            retValue = internalErr.localizedDescription;
        }
    } else {
        retValue = NSLocalizedString(@"STRING_CHANGE_PIN_DIFFERENT", nil);
    }
        
    return retValue;
}

@end
