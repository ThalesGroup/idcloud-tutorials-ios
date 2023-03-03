/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "InBandVerification_ViewController.h"

// Review: SNE add javadoc
@interface ChangePin_ViewController : InBandVerification_ViewController

/**
 Display secure keypad to get old and new pin input from user.

 @param completionHandler Handler triggered once operation is finshed.
 */
- (void)userPinInputsWithCompletionHandler:(EMSecureInputUiOnFinish)completionHandler;

@end

