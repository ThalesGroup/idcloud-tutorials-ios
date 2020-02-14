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
    
    id<EMSecureInputBuilderV2> builder = [[EMSecureInputService serviceWithModule:[EMUIModule uiModule]] secureInputBuilderV2];
    
    [builder setScreenBackgroundColor:[UIColor colorWithRed:249 green:254 blue:255 alpha:1]];
    [builder setKeys:@"1234567890" andSubscripts:@[@"1", @"2", @"3", @"4", @"5", @"6", @"7", @"8", @"9", @"0"]];
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
    
    // Make sure, that configuration is valid.
    [builder validateUiConfiguration];
    
    // Build keypad and add handler.
    id<EMSecureInputUi> secureInput =
    [builder buildWithScrambling:NO
              isDoubleInputField:NO isDialog:NO onFinishBlock:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin) {
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
    id<EMSecureInputBuilderV2> builder = [[EMSecureInputService serviceWithModule:[EMUIModule uiModule]] secureInputBuilderV2];
    
    [builder setNumberOfRows:4 andColumns:4];
    [builder setKeypadHeightRatio:0.25];
    [builder setButtonBorderWidth:3];
    [builder setKeypadFrameColor:[UIColor colorWithRed:121 green:128 blue:255 alpha:1]];
    [builder setKeypadGridGradientColors:[UIColor colorWithRed:121 green:128 blue:255 alpha:1]
                    gridGradientEndColor:[UIColor colorWithRed:121 green:128 blue:255 alpha:1]];
    
    // Make sure, that configuration is valid.
    [builder validateUiConfiguration];
    
    // Build keypad and add handler.
    id<EMSecureInputUi> secureInput =
    [builder buildWithScrambling:YES
              isDoubleInputField:YES isDialog:NO onFinishBlock:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin) {
                  
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
    id<EMSecureInputBuilderV2> builder = [[EMSecureInputService serviceWithModule:[EMUIModule uiModule]] secureInputBuilderV2];
    
    [builder setFirstLabel:@"Old Pin"];
    [builder setSecondLabel:@"New Pin"];
    [builder setLabelColor:[UIColor colorWithRed:0 green:0 blue:0 alpha:1]];
    [builder setLabelFontSize:30];
    [builder setLabelAlignment:EMSecureInputUiLabelAlignmentLeft];
    [builder setInputFieldBackgroundColor:[UIColor colorWithRed:121 green:128 blue:255 alpha:1] forState:EMSecureInputUiControlFocused];
    
    // Make sure, that configuration is valid.
    [builder validateUiConfiguration];
    
    // Build keypad and add handler.
    id<EMSecureInputUi> secureInput =
    [builder buildWithScrambling:NO
              isDoubleInputField:YES isDialog:NO onFinishBlock:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin) {
                  
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
    id<EMSecureInputBuilderV2> builder = [[EMSecureInputService serviceWithModule:[EMUIModule uiModule]] secureInputBuilderV2];
    
    [builder setFirstLabel:@"Enter Password"];
    [builder setMinimumInputLength:6 andMaximumInputLength:16];
    [builder setNumberOfRows:6 andColumns:6];
    [builder setKeys:@"abcdefghijklmnopqrstuvwxyz"];
    [builder setIsDeleteButtonAlwaysEnabled:YES];
    
    // Make sure, that configuration is valid.
    [builder validateUiConfiguration];
    
    // Build keypad and add handler.
    id<EMSecureInputUi> secureInput =
    [builder buildWithScrambling:YES
              isDoubleInputField:NO isDialog:NO onFinishBlock:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin) {
                  
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
