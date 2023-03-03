/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "SecureKeypad_ViewController.h"

@interface SecureKeypad_ViewController() <EMSecureInputCustomUiDelegate>

@end

// Review: SNE document private methods
@implementation SecureKeypad_ViewController

- (void)secureInputUi:(id)caller keyPressedCountChanged:(NSInteger)count forInputField:(NSInteger)inputFieldIndex; {
    NSLog(@"%s", __FUNCTION__);
}
- (void)secureInputUi:(id)caller selectedInputFieldChanged:(NSInteger)inputFieldIndex {
    NSLog(@"%s", __FUNCTION__);
}

- (void)secureInputUiOkButtonPressed:(id)caller {
    NSLog(@"%s", __FUNCTION__);
}

- (void)secureInputUiDeleteButtonPressed:(id)caller {
    NSLog(@"%s", __FUNCTION__);
}

// MARK: - User interface
- (IBAction)onButtonPressedVariant01:(UIButton *)sender
{
    NSLog(@"%@", [EMCore version]);
    
    id<EMSecureInputBuilder> builder = [[EMSecureInputService serviceWithModule:[EMUIModule uiModule]] secureInputBuilder];
    
    [builder setScreenBackgroundColor:[UIColor colorWithRed:249 green:254 blue:255 alpha:1]];
    [builder setKeys:[@"1234567890" dataUsingEncoding:NSUTF16StringEncoding] andSubscripts:@[@"1", @"2", @"3", @"4", @"5", @"6", @"7", @"8", @"9", @"0"]];
    [builder setOkButtonText:@" "];
    [builder setDeleteButtonText:@" "];
    [builder setDistanceBetweenKeyAndSubscript:2];
    [builder setKeypadGridGradientColors:[UIColor colorWithRed:84 green:84 blue:84 alpha:1]
                    gridGradientEndColor:[UIColor colorWithRed:0 green:0 blue:0 alpha:1]];
    [builder setButtonPressedVisibility:YES];
    [builder setOkButtonImage:[UIImage imageNamed:@"baseline_done_outline_black_48pt"]];
    [builder setOkButtonImageOpacity:0.75f forState:EMSecureInputUiControlStateNormal];
    [builder setOkButtonImageOpacity:0.5f forState:EMSecureInputUiControlStateSelected];
    [builder setOkButtonImageOpacity:0.25f forState:EMSecureInputUiControlStateDisabled];
    [builder setDeleteButtonImage:[UIImage imageNamed:@"baseline_delete_outline_black_48pt"]];
    [builder setDeleteButtonImageOpacity:0.75f forState:EMSecureInputUiControlStateNormal];
    [builder setDeleteButtonImageOpacity:0.5f forState:EMSecureInputUiControlStateSelected];
    [builder setDeleteButtonImageOpacity:0.25f forState:EMSecureInputUiControlStateDisabled];
    [builder setButtonGradientColors:[UIColor colorWithRed:255 green:255 blue:255 alpha:1]
              buttonGradientEndColor:[UIColor colorWithRed:239 green:239 blue:244 alpha:1]
                            forState:EMSecureInputUiControlStateNormal];
    [builder setButtonGradientColors:[UIColor colorWithRed:239 green:239 blue:244 alpha:1]
              buttonGradientEndColor:[UIColor colorWithRed:239 green:239 blue:244 alpha:1]
                            forState:EMSecureInputUiControlStateSelected];
    
    [builder setMinimumInputLength:3 andMaximumInputLength:3];
    [builder setOkButtonBehavior:EMSecureInputUiOkButtonCustom];
    
    // Build keypad and add handler.
    id<EMSecureInputUi> secureInput =
    [builder buildWithScrambling:NO
              isDoubleInputField:NO displayMode:EMSecureInputUiDisplayModeFullScreen onFinishBlock:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin) {
                  // Wipe pinpad builder for security purpose.
                  // This part is also important because of builder life cycle, otherwise this block will never be triggered!
                  [builder wipe];
                  
                  // Dismiss the keypad and delete the secure input UI.
                  [self.navigationController popViewControllerAnimated:YES];
              }];
    
    secureInput.customUiDelegate = self;
    
    // Push in secure input UI view controller to the current view controller
    [self.navigationController pushViewController:secureInput.viewController animated:YES];
}

- (IBAction)onButtonPressedVariant02:(UIButton *)sender
{
    id<EMSecureInputBuilder> builder = [[EMSecureInputService serviceWithModule:[EMUIModule uiModule]] secureInputBuilder];
    
    [builder setNumberOfRows:4 andColumns:4];
    [builder setKeypadHeightRatio:0.25];
    [builder setButtonBorderWidth:3];
    [builder setKeypadFrameColor:[UIColor colorWithRed:121 green:128 blue:255 alpha:1]];
    [builder setKeypadGridGradientColors:[UIColor colorWithRed:121 green:128 blue:255 alpha:1]
                    gridGradientEndColor:[UIColor colorWithRed:121 green:128 blue:255 alpha:1]];
    
    // Build keypad and add handler.
    id<EMSecureInputUi> secureInput =
    [builder buildWithScrambling:YES
              isDoubleInputField:YES displayMode:EMSecureInputUiDisplayModeFullScreen onFinishBlock:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin) {
                  
                  // Wipe pinpad builder for security purpose.
                  // This part is also important because of builder life cycle, otherwise this block will never be triggered!
                  [builder wipe];
                  
                  // Dismiss the keypad and delete the secure input UI.
                  [self.navigationController popViewControllerAnimated:YES];
              }];
    
    // Push in secure input UI view controller to the current view controller
    [self.navigationController pushViewController:secureInput.viewController animated:YES];
}

- (IBAction)onButtonPressedVariant03:(UIButton *)sender
{
    id<EMSecureInputBuilder> builder = [[EMSecureInputService serviceWithModule:[EMUIModule uiModule]] secureInputBuilder];
    
    [builder setFirstLabel:@"Old Pin"];
    [builder setSecondLabel:@"New Pin"];
    [builder setLabelColor:[UIColor colorWithRed:0 green:0 blue:0 alpha:1]];
    [builder setLabelFontSize:30];
    [builder setLabelAlignment:EMSecureInputUiLabelAlignmentLeft];
    [builder setInputFieldBackgroundColor:[UIColor colorWithRed:121 green:128 blue:255 alpha:1] forState:EMSecureInputUiControlFocused];
    
    // Build keypad and add handler.
    id<EMSecureInputUi> secureInput =
    [builder buildWithScrambling:NO
              isDoubleInputField:YES displayMode:EMSecureInputUiDisplayModeFullScreen onFinishBlock:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin) {
                  
                  // Wipe pinpad builder for security purpose.
                  // This part is also important because of builder life cycle, otherwise this block will never be triggered!
                  [builder wipe];
                  
                  // Dismiss the keypad and delete the secure input UI.
                  [self.navigationController popViewControllerAnimated:YES];
              }];
    
    // Push in secure input UI view controller to the current view controller
    [self.navigationController pushViewController:secureInput.viewController animated:YES];
}

- (IBAction)onButtonPressedVariant04:(UIButton *)sender
{
    id<EMSecureInputBuilder> builder = [[EMSecureInputService serviceWithModule:[EMUIModule uiModule]] secureInputBuilder];
    
    [builder setFirstLabel:@"Enter Password"];
    [builder setMinimumInputLength:6 andMaximumInputLength:16];
    [builder setNumberOfRows:6 andColumns:6];
    [builder setKeys:[@"abcdefghijklmnopqrstuvwxyz" dataUsingEncoding:NSUTF16StringEncoding]];
    [builder setIsDeleteButtonAlwaysEnabled:YES];
    
    // Build keypad and add handler.
    id<EMSecureInputUi> secureInput =
    [builder buildWithScrambling:YES
              isDoubleInputField:NO displayMode:EMSecureInputUiDisplayModeFullScreen onFinishBlock:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin) {
                  
                  // Wipe pinpad builder for security purpose.
                  // This part is also important because of builder life cycle, otherwise this block will never be triggered!
                  [builder wipe];
                  
                  // Dismiss the keypad and delete the secure input UI.
                  [self.navigationController popViewControllerAnimated:YES];
              }];
    
    // Push in secure input UI view controller to the current view controller
    [self.navigationController pushViewController:secureInput.viewController animated:YES];
}

@end
