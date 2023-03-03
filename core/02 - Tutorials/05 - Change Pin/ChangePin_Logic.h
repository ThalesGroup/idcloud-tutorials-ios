/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

// Review: SNE add javadoc
@interface ChangePin_Logic : NSObject

/**
 Verify new entry and change token pin.

 @param token Token we want to change pin.
 @param oldPin Original token pin.
 @param newPin New token pin.
 @param newPinConfirmation New token pin confirmation.
 @return Result description.
 */
+ (NSString *)changePin:(id<EMToken>)token
                 oldPin:(id<EMPinAuthInput>)oldPin
                 newPin:(id<EMPinAuthInput>)newPin
          newPinConfirm:(id<EMPinAuthInput>)newPinConfirmation;

@end
