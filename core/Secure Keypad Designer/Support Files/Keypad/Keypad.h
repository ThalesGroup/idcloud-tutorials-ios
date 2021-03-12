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

#import "KeypadDesignableConfig.h"

@interface KeypadRoot : UIView
@property (nonatomic, strong) KeypadDesignableConfig *config;
@end


@interface InputFielsLabels : KeypadRoot

@property (nonatomic) IBInspectable NSString    *firstLabel;
@property (nonatomic) IBInspectable NSString    *secondLabel;
@property (nonatomic) IBInspectable UIColor     *colorLabels;
@property (nonatomic) IBInspectable CGFloat     fontSizeLabels;
@property (nonatomic) IBInspectable NSInteger   alignmentLabels;

@end

@interface InputFiels : InputFielsLabels

@property (nonatomic) IBInspectable BOOL        isDoubleInputField;
@property (nonatomic) IBInspectable CGFloat     fontSizeInputField;
@property (nonatomic) IBInspectable UIColor     *borderColorFocusedInputField;
@property (nonatomic) IBInspectable UIColor     *borderColorUnFocusedInputField;
@property (nonatomic) IBInspectable UIColor     *backgroundColorFocusedInputField;
@property (nonatomic) IBInspectable UIColor     *backgroundColorUnocusedInputField;
@property (nonatomic) IBInspectable NSInteger   minimumLengthInputField;
@property (nonatomic) IBInspectable NSInteger   maximumLengthInputField;

@end

@interface OkButton : InputFiels

@property (nonatomic) IBInspectable UIImage     *imageOkButton;
@property (nonatomic) IBInspectable CGFloat     imageOpacityNormalOkButton;
@property (nonatomic) IBInspectable CGFloat     imageOpacitySelectedOkButton;
@property (nonatomic) IBInspectable CGFloat     imageOpacityDisabledOkButton;
@property (nonatomic) IBInspectable UIColor     *gradientColorStartNormalOkButton;
@property (nonatomic) IBInspectable UIColor     *gradientColorEndNormalOkButton;
@property (nonatomic) IBInspectable UIColor     *gradientColorStartSelectedOkButton;
@property (nonatomic) IBInspectable UIColor     *gradientColorEndSelectedOkButton;
@property (nonatomic) IBInspectable UIColor     *gradientColorStartDisabledOkButton;
@property (nonatomic) IBInspectable UIColor     *gradientColorEndDisabledOkButton;
@property (nonatomic) IBInspectable UIColor     *textColorNormalOkButton;
@property (nonatomic) IBInspectable UIColor     *textColorSelectedOkButton;
@property (nonatomic) IBInspectable UIColor     *textColorDisabledOkButton;
@property (nonatomic) IBInspectable NSString    *textOkButton;
@property (nonatomic) IBInspectable NSString    *fontOkButtonName;
@property (nonatomic) IBInspectable NSInteger   fontOkButtonSize;
//- (void)setOkButtonBehavior:(EMSecureInputUiOkButtonBehavior)behavior;

@end

@interface DeleteButton : OkButton

@property (nonatomic) IBInspectable UIImage     *imageDeleteButton;
@property (nonatomic) IBInspectable CGFloat     imageOpacityNormalDeleteButton;
@property (nonatomic) IBInspectable CGFloat     imageOpacitySelectedDeleteButton;
@property (nonatomic) IBInspectable CGFloat     imageOpacityDisabledDeleteButton;
@property (nonatomic) IBInspectable UIColor     *gradientColorStartNormalDeleteButton;
@property (nonatomic) IBInspectable UIColor     *gradientColorEndNormalDeleteButton;
@property (nonatomic) IBInspectable UIColor     *gradientColorStartSelectedDeleteButton;
@property (nonatomic) IBInspectable UIColor     *gradientColorEndSelectedDeleteButton;
@property (nonatomic) IBInspectable UIColor     *gradientColorStartDisabledDeleteButton;
@property (nonatomic) IBInspectable UIColor     *gradientColorEndDisabledDeleteButton;
@property (nonatomic) IBInspectable UIColor     *textColorNormalDeleteButton;
@property (nonatomic) IBInspectable UIColor     *textColorSelectedDeleteButton;
@property (nonatomic) IBInspectable UIColor     *textColorDisabledDeleteButton;
@property (nonatomic) IBInspectable NSString    *textDeleteButton;
@property (nonatomic) IBInspectable NSString    *fontDeleteButtonName;
@property (nonatomic) IBInspectable NSInteger   fontDeleteButtonSize;
@property (nonatomic) IBInspectable BOOL        isAlwaysEnabledDeleteButton;

@end


IB_DESIGNABLE
@interface Keypad : DeleteButton

@property (nonatomic) IBInspectable BOOL        scrambled;
@property (nonatomic) IBInspectable UIColor     *screenBackgroundColor;
@property (nonatomic) IBInspectable UIImage     *screenBackgroundImage;
@property (nonatomic) IBInspectable NSInteger   screenBackgroundImageContentMode;
@property (nonatomic) IBInspectable NSInteger   numberOfRows;
@property (nonatomic) IBInspectable NSInteger   numberOfColumns;
@property (nonatomic) IBInspectable CGFloat     keypadHeightRatio;
@property (nonatomic) IBInspectable BOOL        swapOkAndDeleteButton;
@property (nonatomic) IBInspectable NSString    *keys;
@property (nonatomic) IBInspectable NSString    *subscripts;
@property (nonatomic) IBInspectable CGFloat     distanceBetweenKeyAndSubscript;
@property (nonatomic) IBInspectable NSInteger   buttonBorderWidth;
//@property (nonatomic) IBInspectable UIColor     *buttonBorderColor;
@property (nonatomic) IBInspectable UIColor     *keypadFrameColor;
@property (nonatomic) IBInspectable UIColor     *keypadGridGradientStartColor;
@property (nonatomic) IBInspectable UIColor     *keypadGridGradientEndColor;
@property (nonatomic) IBInspectable BOOL        buttonPressedVisibility;
@property (nonatomic) IBInspectable NSString    *keyFontName;
@property (nonatomic) IBInspectable NSInteger   keyFontSize;
@property (nonatomic) IBInspectable NSString    *subscriptFontName;
@property (nonatomic) IBInspectable NSInteger   subscriptFontSize;

@property (nonatomic) IBInspectable UIColor     *keyColorForStateNormal;
@property (nonatomic) IBInspectable UIColor     *keyColorForStateSelected;
@property (nonatomic) IBInspectable UIColor     *keyColorForStateDisabled;

@property (nonatomic) IBInspectable UIColor     *subscriptColorForStateNormal;
@property (nonatomic) IBInspectable UIColor     *subscriptColorForStateSelected;
@property (nonatomic) IBInspectable UIColor     *subscriptColorForStateDisabled;

@property (nonatomic) IBInspectable UIColor     *buttonBackgroundColorForStateNormal;
@property (nonatomic) IBInspectable UIColor     *buttonBackgroundColorForStateSelected;
@property (nonatomic) IBInspectable UIColor     *buttonBackgroundColorForStateDisabled;

@property (nonatomic) IBInspectable UIImage     *buttonBackgroundImage;
@property (nonatomic) IBInspectable CGFloat     buttonBackgroundImageOpacityForStateNormal;
@property (nonatomic) IBInspectable CGFloat     buttonBackgroundImageOpacityForStateSelected;
@property (nonatomic) IBInspectable CGFloat     buttonBackgroundImageOpacityForStateDisabled;

@property (nonatomic) IBInspectable UIColor     *buttonGradientColorStartForStateNormal;
@property (nonatomic) IBInspectable UIColor     *buttonGradientColorEndForStateNormal;
@property (nonatomic) IBInspectable UIColor     *buttonGradientColorStartForStateSelected;
@property (nonatomic) IBInspectable UIColor     *buttonGradientColorEndForStateSelected;
@property (nonatomic) IBInspectable UIColor     *buttonGradientColorStartForStateDisabled;
@property (nonatomic) IBInspectable UIColor     *buttonGradientColorEndForStateDisabled;

@end
