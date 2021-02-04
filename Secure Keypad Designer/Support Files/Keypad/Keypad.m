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

#import "Keypad.h"

static NSData * C_ACTIVATION_CODE()
{
    static const unsigned char raw[] =
    {   0x01, 0x47, 0x54, 0x4f, 0x52, 0x6e, 0x44, 0x30,
        0x31, 0xff, 0xff, 0xff, 0xff, 0x42, 0x92, 0xbb,
        0x8d, 0xae, 0x24, 0xfb, 0x2b, 0xd4, 0xe6, 0xfa,
        0xc9, 0xad, 0x26, 0xef, 0xbe, 0x7e, 0x54, 0x26,
        0x2c, 0x91, 0xa2, 0x0c, 0xf4, 0xcb, 0x1e, 0x90,
        0xea, 0x87, 0x95, 0xeb, 0x5d, 0x40, 0x9d, 0x4e,
        0xd1, 0x11, 0x1b, 0x24, 0xcd, 0x4c, 0x6f, 0xc9,
        0x72, 0x79, 0x09, 0xf1, 0xda, 0xeb, 0x15, 0x3c,
        0xff, 0xae, 0x9a, 0x49, 0x9d, 0x92, 0xc0, 0x62,
        0xb0, 0x7a, 0xc1, 0xe1, 0xf0
    };
    
    return [NSData dataWithBytes:raw length:sizeof(raw)];
}

static NSData * C_SECURE_LOG_RSA_KEY_MODULUS() {
    static const unsigned char  raw[] = {
        0x00, 0xa0, 0x86, 0x90, 0xbe, 0x3a, 0x7d, 0xfd, 0x3d, 0x84, 0x56, 0x38, 0x23, 0x97, 0xd4,
        0xb6, 0x5f, 0xeb, 0x1e, 0xc0, 0x17, 0x5a, 0xb3, 0x08, 0x92, 0x3b, 0x2a, 0x2b, 0x6c, 0xf6,
        0x71, 0xd6, 0x62, 0x1c, 0x7a, 0x4f, 0x96, 0xf9, 0x37, 0xa0, 0x77, 0xd6, 0x24, 0x27, 0x84,
        0x98, 0xfa, 0x7c, 0xb9, 0x3c, 0xfd, 0xc9, 0x58, 0xcd, 0xb7, 0x04, 0x08, 0xbb, 0x0b, 0x23,
        0x8b, 0x21, 0xaa, 0x4d, 0x2c, 0xfd, 0x19, 0xf6, 0xa9, 0xc9, 0x43, 0xe0, 0xe9, 0x63, 0xcc,
        0xa8, 0x5e, 0x8c, 0xf4, 0x57, 0x02, 0x13, 0x44, 0x0b, 0xfc, 0x0d, 0x5d, 0x05, 0xbf, 0x70,
        0xe2, 0xac, 0xad, 0xe9, 0x55, 0x85, 0x04, 0x61, 0xfc, 0x67, 0x25, 0xe8, 0xd2, 0x0f, 0xba,
        0x0b, 0x62, 0x1a, 0x1d, 0x55, 0xa0, 0x6c, 0x08, 0x83, 0xde, 0xd4, 0xbe, 0x39, 0x95, 0xe6,
        0x7b, 0xe6, 0xc9, 0x44, 0x9b, 0xf8, 0x54, 0xb8, 0x4e, 0xe3, 0x75, 0xa6, 0xaf, 0xfa, 0x89,
        0x39, 0x3e, 0xaf, 0xfd, 0x4e, 0xf7, 0xd8, 0x2f, 0x80, 0x0d, 0xa9, 0x7c, 0xf7, 0xa7, 0x53,
        0x1d, 0x18, 0x95, 0x6a, 0x35, 0x98, 0x48, 0x24, 0xcf, 0x29, 0x52, 0xd7, 0x5f, 0xe0, 0x6b,
        0xce, 0x61, 0xe4, 0x71, 0x13, 0xd6, 0x82, 0xf3, 0xd9, 0x41, 0x74, 0x5f, 0x5b, 0x85, 0xc6,
        0x56, 0xa6, 0x1f, 0x8b, 0xd2, 0xc4, 0xa7, 0x57, 0x9c, 0xed, 0x82, 0xca, 0x2f, 0xd7, 0x84,
        0x47, 0x26, 0x65, 0x43, 0xd9, 0x76, 0x95, 0xf5, 0x20, 0xd1, 0x03, 0xf4, 0xeb, 0x00, 0x34,
        0x19, 0xca, 0x40, 0x40, 0x34, 0xe2, 0xfb, 0xbd, 0xe3, 0x64, 0x02, 0xcb, 0xe7, 0x1b, 0x87,
        0x69, 0xac, 0x3b, 0x7a, 0xae, 0x51, 0x3d, 0x4b, 0x32, 0x57, 0x24, 0xe2, 0x03, 0x34, 0x71,
        0x10, 0xda, 0x60, 0x77, 0x48, 0x26, 0xcb, 0x3c, 0x63, 0x0b, 0xa9, 0x49, 0xa4, 0x92, 0x53,
        0x69, 0x53
    };
    return [NSData dataWithBytes:raw length:sizeof(raw)];
}

static NSData * C_SECURE_LOG_RSA_KEY_EXPONENT() {
    static const unsigned char raw[] = {0x01, 0x00, 0x01};
    return [NSData dataWithBytes:raw length:sizeof(raw)];
}

@implementation KeypadRoot

@end

// MARK: -

@implementation InputFielsLabels
- (void)setFirstLabel:(NSString *)firstLabel
{
    self.config.firstLabel = firstLabel;
    [self setNeedsLayout];
}

- (void)setSecondLabel:(NSString *)secondLabel
{
    self.config.secondLabel = secondLabel;
    [self setNeedsLayout];
}
- (void)setColorLabels:(UIColor *)labelColor
{
    self.config.labelColor = labelColor;
    [self setNeedsLayout];
}

- (void)setFontSizeLabels:(CGFloat)labelFontSize
{
    self.config.labelFontSize = labelFontSize;
    [self setNeedsLayout];
}

- (void)setAlignmentLabels:(NSInteger)labelAlignment
{
    self.config.labelAlignment = labelAlignment;
    [self setNeedsLayout];
}
@end

// MARK: - 

@implementation InputFiels

- (void)setIsDoubleInputField:(BOOL)isDoubleInput
{
    self.config.isDoubleInput = isDoubleInput;
    [self setNeedsLayout];
}

- (void)setFontSizeInputField:(CGFloat)inputFieldFontSize
{
    self.config.inputFieldFontSize = inputFieldFontSize;
    [self setNeedsLayout];
}

- (void)setBorderColorFocusedInputField:(UIColor *)inputFieldBorderColorForStateFocused
{
    self.config.inputFieldBorderColorForStateFocused = inputFieldBorderColorForStateFocused;
    [self setNeedsLayout];
}

- (void)setBorderColorUnFocusedInputField:(UIColor *)inputFieldBorderColorForStateUnFocused
{
    self.config.inputFieldBorderColorForStateUnFocused = inputFieldBorderColorForStateUnFocused;
    [self setNeedsLayout];
}

- (void)setBackgroundColorFocusedInputField:(UIColor *)inputFieldBackgroundColorForStateFocused
{
    self.config.inputFieldBackgroundColorForStateFocused = inputFieldBackgroundColorForStateFocused;
    [self setNeedsLayout];
}

- (void)setBackgroundColorUnocusedInputField:(UIColor *)inputFieldBackgroundColorForStateUnocused
{
    self.config.inputFieldBackgroundColorForStateUnocused = inputFieldBackgroundColorForStateUnocused;
    [self setNeedsLayout];
}

- (void)setMinimumLengthInputField:(NSInteger)minimumInputLength
{
    self.config.minimumInputLength = minimumInputLength;
    [self setNeedsLayout];
}

- (void)setMaximumLengthInputField:(NSInteger)maximumInputLength
{
    self.config.maximumInputLength = maximumInputLength;
    [self setNeedsLayout];
}

@end

// MARK: -

@implementation OkButton

- (void)setImageOkButton:(UIImage *)okButtonImage
{
    self.config.okButtonImage = okButtonImage;
    [self setNeedsLayout];
}

- (void)setImageOpacityNormalOkButton:(CGFloat)okButtonImageOpacityForStateNormal
{
    self.config.okButtonImageOpacityForStateNormal = okButtonImageOpacityForStateNormal;
    [self setNeedsLayout];
}

- (void)setImageOpacitySelectedOkButton:(CGFloat)okButtonImageOpacityForStateSelected
{
    self.config.okButtonImageOpacityForStateSelected = okButtonImageOpacityForStateSelected;
    [self setNeedsLayout];
}

- (void)setImageOpacityDisabledOkButton:(CGFloat)okButtonImageOpacityForStateDisabled
{
    self.config.okButtonImageOpacityForStateDisabled = okButtonImageOpacityForStateDisabled;
    [self setNeedsLayout];
}

- (void)setGradientColorStartNormalOkButton:(UIColor *)okButtonGradientColorStartForStateNormal
{
    self.config.okButtonGradientColorStartForStateNormal = okButtonGradientColorStartForStateNormal;
    [self setNeedsLayout];
}

- (void)setGradientColorStartSelectedOkButton:(UIColor *)okButtonGradientColorStartForStateSelected
{
    self.config.okButtonGradientColorStartForStateSelected = okButtonGradientColorStartForStateSelected;
    [self setNeedsLayout];
}

- (void)setGradientColorStartDisabledOkButton:(UIColor *)okButtonGradientColorStartForStateDisabled
{
    self.config.okButtonGradientColorStartForStateDisabled = okButtonGradientColorStartForStateDisabled;
    [self setNeedsLayout];
}

- (void)setGradientColorEndNormalOkButton:(UIColor *)okButtonGradientColorEndForStateNormal
{
    self.config.okButtonGradientColorEndForStateNormal = okButtonGradientColorEndForStateNormal;
    [self setNeedsLayout];
}

- (void)setGradientColorEndSelectedOkButton:(UIColor *)okButtonGradientColorEndForStateSelected
{
    self.config.okButtonGradientColorEndForStateSelected = okButtonGradientColorEndForStateSelected;
    [self setNeedsLayout];
}

- (void)setGradientColorEndDisabledOkButton:(UIColor *)okButtonGradientColorEndForStateDisabled
{
    self.config.okButtonGradientColorEndForStateDisabled = okButtonGradientColorEndForStateDisabled;
    [self setNeedsLayout];
}

- (void)setTextColorNormalOkButton:(UIColor *)okButtonTextColorForStateNormal
{
    self.config.okButtonTextColorForStateNormal = okButtonTextColorForStateNormal;
    [self setNeedsLayout];
}

- (void)setTextColorSelectedOkButton:(UIColor *)okButtonTextColorForStateSelected
{
    self.config.okButtonTextColorForStateSelected = okButtonTextColorForStateSelected;
    [self setNeedsLayout];
}

- (void)setTextColorDisabledOkButton:(UIColor *)okButtonTextColorForStateDisabled
{
    self.config.okButtonTextColorForStateDisabled = okButtonTextColorForStateDisabled;
    [self setNeedsLayout];
}

- (void)setTextOkButton:(NSString *)okButtonText
{
    self.config.okButtonText = okButtonText;
    [self setNeedsLayout];
}

- (void)setFontOkButtonName:(NSString *)fontOkButtonName
{
    self.config.okButtonFontName = fontOkButtonName;
    [self setNeedsLayout];
}

- (void)setFontOkButtonSize:(NSInteger)fontOkButtonSize
{
    self.config.okButtonFontSize = fontOkButtonSize;
    [self setNeedsLayout];
}

@end

// MARK: -

@implementation DeleteButton

- (void)setImageDeleteButton:(UIImage *)deleteButtonImage
{
    self.config.deleteButtonImage = deleteButtonImage;
    [self setNeedsLayout];
}

- (void)setImageOpacityNormalDeleteButton:(CGFloat)deleteButtonImageOpacityForStateNormal
{
    self.config.deleteButtonImageOpacityForStateNormal = deleteButtonImageOpacityForStateNormal;
    [self setNeedsLayout];
}

- (void)setImageOpacitySelectedDeleteButton:(CGFloat)deleteButtonImageOpacityForStateSelected
{
    self.config.deleteButtonImageOpacityForStateSelected = deleteButtonImageOpacityForStateSelected;
    [self setNeedsLayout];
}

- (void)setImageOpacityDisabledDeleteButton:(CGFloat)deleteButtonImageOpacityForStateDisabled
{
    self.config.deleteButtonImageOpacityForStateDisabled = deleteButtonImageOpacityForStateDisabled;
    [self setNeedsLayout];
}

- (void)setGradientColorStartNormalDeleteButton:(UIColor *)deleteButtonGradientColorStartForStateNormal
{
    self.config.deleteButtonGradientColorStartForStateNormal = deleteButtonGradientColorStartForStateNormal;
    [self setNeedsLayout];
}

- (void)setGradientColorStartSelectedDeleteButton:(UIColor *)deleteButtonGradientColorStartForStateSelected
{
    self.config.deleteButtonGradientColorStartForStateSelected = deleteButtonGradientColorStartForStateSelected;
    [self setNeedsLayout];
}

- (void)setGradientColorStartDisabledDeleteButton:(UIColor *)deleteButtonGradientColorStartForStateDisabled
{
    self.config.deleteButtonGradientColorStartForStateDisabled = deleteButtonGradientColorStartForStateDisabled;
    [self setNeedsLayout];
}

- (void)setGradientColorEndNormalDeleteButton:(UIColor *)deleteButtonGradientColorEndForStateNormal
{
    self.config.deleteButtonGradientColorEndForStateNormal = deleteButtonGradientColorEndForStateNormal;
    [self setNeedsLayout];
}

- (void)setGradientColorEndSelectedDeleteButton:(UIColor *)deleteButtonGradientColorEndForStateSelected
{
    self.config.deleteButtonGradientColorEndForStateSelected = deleteButtonGradientColorEndForStateSelected;
    [self setNeedsLayout];
}

- (void)setGradientColorEndDisabledDeleteButton:(UIColor *)deleteButtonGradientColorEndForStateDisabled
{
    self.config.deleteButtonGradientColorEndForStateDisabled = deleteButtonGradientColorEndForStateDisabled;
    [self setNeedsLayout];
}

- (void)setTextColorNormalDeleteButton:(UIColor *)deleteButtonTextColorForStateNormal
{
    self.config.deleteButtonTextColorForStateNormal = deleteButtonTextColorForStateNormal;
    [self setNeedsLayout];
}

- (void)setTextColorSelectedDeleteButton:(UIColor *)deleteButtonTextColorForStateSelected
{
    self.config.deleteButtonTextColorForStateSelected = deleteButtonTextColorForStateSelected;
    [self setNeedsLayout];
}

- (void)setTextColorDisabledDeleteButton:(UIColor *)deleteButtonTextColorForStateDisabled
{
    self.config.deleteButtonTextColorForStateDisabled = deleteButtonTextColorForStateDisabled;
    [self setNeedsLayout];
}

- (void)setTextDeleteButton:(NSString *)deleteButtonText
{
    self.config.deleteButtonText = deleteButtonText;
    [self setNeedsLayout];
}

- (void)setFontDeleteButtonName:(NSString *)fontDeleteButtonName
{
    self.config.deleteButtonFontName = fontDeleteButtonName;
    [self setNeedsLayout];
}

- (void)setFontDeleteButtonSize:(NSInteger)fontDeleteButtonSize
{
    self.config.deleteButtonFontSize = fontDeleteButtonSize;
    [self setNeedsLayout];
}

- (void)setIsAlwaysEnabledDeleteButton:(BOOL)isDeleteButtonAlwaysEnabled
{
    self.config.isDeleteButtonAlwaysEnabled = isDeleteButtonAlwaysEnabled;
    [self setNeedsLayout];
}

@end

// MARK: -

@interface Keypad()

@property (weak, nonatomic) IBOutlet UILabel *textError;
@property (nonatomic, weak) UIView* keypad;
@property (nonatomic, weak) UIView* contentView;

@end

@implementation Keypad

// MARK: - Life Cycle

- (nullable instancetype)initWithCoder:(NSCoder *)decoder
{
    if (self = [super initWithCoder:decoder]) {
        [self initXib];
    }
    
    return self;
}

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        [self initXib];
    }
    
    return self;
}

- (void)initXib
{
    // Prepare default config
    self.config = [KeypadDesignableConfig new];
    
    // Init SDK
    if (![EMCore isConfigured]) {
        // Configure core with secure log.
        SecureLogConfig *secureLogConfig = [[SecureLogConfig alloc] initWithConfigComponentsBuilder:^(SecureLogConfigComponents * _Nonnull components) {
            components.publicKeyExponent = C_SECURE_LOG_RSA_KEY_EXPONENT();
            components.publicKeyModulus = C_SECURE_LOG_RSA_KEY_MODULUS();
        }];
        [EMCore configureSecureLog:secureLogConfig];

        // OTP module is required for token management and OTP calculation.
        
        // Configure core with given key and set of required modules.
        [EMCore configureWithActivationCode:C_ACTIVATION_CODE()
                             configurations:nil];
    }
    
    // Color is used as placeholder in case of disabled IB_DESIGNABLE
    self.backgroundColor = [UIColor clearColor];
    
    // Get our view from storyboard.
    self.contentView = [[[NSBundle bundleForClass:self.class] loadNibNamed:NSStringFromClass(self.class) owner:self options:nil] firstObject];
    
    // Add it as child of current View.
    [self addSubview:_contentView];
    
    [self setNeedsLayout];
}

- (void)layoutSubviews
{
    [super layoutSubviews];
 
    _contentView.frame = self.bounds;
    
    @try {

        [self reloadKeypad];
        
        static BOOL exported = NO;
        if (!exported) {
            [self.config printConfiguration];
            exported = YES;
        }
        _textError.hidden = YES;
    } @catch (NSException *exception) {
        _textError.text = exception.description;
        _textError.hidden = NO;
        return;
    }
}

// MARK: - Helpers

- (void)reloadKeypad
{
    if (_keypad) {
        [_keypad removeFromSuperview];
        _keypad = nil;
    }
    
    // Get secure keypad builder.
    id<EMSecureInputBuilder> builder = [[EMSecureInputService serviceWithModule:[EMUIModule uiModule]] secureInputBuilder];
    
    if (self.config.firstLabel) {
        [builder setFirstLabel:self.config.firstLabel];
    }
    if (self.config.secondLabel) {
        [builder setSecondLabel:self.config.secondLabel];
    }
    if (self.config.screenBackgroundColor) {
        [builder setScreenBackgroundColor:self.config.screenBackgroundColor];
    }
    if (self.config.screenBackgroundImage) {
        [builder setScreenBackgroundImage:self.config.screenBackgroundImage contentMode:self.config.screenBackgroundImageContentMode];
    }
    if (self.config.labelColor) {
        [builder setLabelColor:self.config.labelColor];
    }
    [builder setLabelFontSize:self.config.labelFontSize];
    [builder setLabelAlignment:self.config.labelAlignment];
    [builder setInputFieldFontSize:self.config.inputFieldFontSize];
    if (self.config.inputFieldBorderColorForStateFocused) {
        [builder setInputFieldBorderColor:self.config.inputFieldBorderColorForStateFocused forState:EMSecureInputUiControlFocused];
    }
    if (self.config.inputFieldBorderColorForStateUnFocused) {
        [builder setInputFieldBorderColor:self.config.inputFieldBorderColorForStateUnFocused forState:EMSecureInputUiControlUnfocused];
    }
    if (self.config.inputFieldBackgroundColorForStateFocused) {
        [builder setInputFieldBackgroundColor:self.config.inputFieldBackgroundColorForStateFocused forState:EMSecureInputUiControlFocused];
    }
    if (self.config.inputFieldBackgroundColorForStateUnocused) {
        [builder setInputFieldBackgroundColor:self.config.inputFieldBackgroundColorForStateUnocused forState:EMSecureInputUiControlUnfocused];
    }
    [builder setMinimumInputLength:self.config.minimumInputLength andMaximumInputLength:self.config.maximumInputLength];
    [builder setNumberOfRows:self.config.numberOfRows andColumns:self.config.numberOfColumns];
    [builder setKeypadHeightRatio:self.config.keypadHeightRatio];
    if (self.config.swapOkAndDeleteButton) {
        [builder swapOkAndDeleteButton];
    }
    if (self.config.keys.length && self.config.subscripts.count) {
        [builder setKeys:[self.config.keys dataUsingEncoding:NSUTF16StringEncoding] andSubscripts:self.config.subscripts];
    } else if (self.config.keys.length) {
        [builder setKeys:[self.config.keys dataUsingEncoding:NSUTF16StringEncoding]];
    }
    if (self.config.okButtonText) {
        [builder setOkButtonText:self.config.okButtonText];
    }
    if (self.config.deleteButtonText) {
        [builder setDeleteButtonText:self.config.deleteButtonText];
    }
    [builder setDistanceBetweenKeyAndSubscript:self.config.distanceBetweenKeyAndSubscript];
    [builder setButtonBorderWidth:self.config.buttonBorderWidth];
    //    if (self.config.buttonBorderColor)
    //        [builder setButtonBorderColor:self.config.buttonBorderColor];
    if (self.config.keypadFrameColor) {
        [builder setKeypadFrameColor:self.config.keypadFrameColor];
    }
    if (self.config.keypadGridGradientStartColor && self.config.keypadGridGradientEndColor) {
        [builder setKeypadGridGradientColors:self.config.keypadGridGradientStartColor gridGradientEndColor:self.config.keypadGridGradientEndColor];
    }
    [builder setButtonPressedVisibility:self.config.buttonPressedVisibility];
    
    [self getFont:self.config.keyFontName size:self.config.keyFontSize caption:@"Key" handler:^(UIFont *font) {
        [builder setKeyFont:font];
    }];
    
    [self getFont:self.config.subscriptFontName size:self.config.subscriptFontSize caption:@"Subscript" handler:^(UIFont *font) {
        [builder setSubscriptFont:font];
    }];
    
    [self getFont:self.config.okButtonFontName size:self.config.okButtonFontSize caption:@"Ok Button" handler:^(UIFont *font) {
        [builder setOkButtonFont:font];
    }];
    
    [self getFont:self.config.deleteButtonFontName size:self.config.deleteButtonFontSize caption:@"Delete Button" handler:^(UIFont *font) {
        [builder setDeleteButtonFont:font];
    }];

    if (self.config.keyColorForStateNormal) {
        [builder setKeyColor:self.config.keyColorForStateNormal forState:EMSecureInputUiControlStateNormal];
    }
    if (self.config.keyColorForStateSelected) {
        [builder setKeyColor:self.config.keyColorForStateSelected forState:EMSecureInputUiControlStateSelected];
    }
    if (self.config.keyColorForStateDisabled) {
        [builder setKeyColor:self.config.keyColorForStateDisabled forState:EMSecureInputUiControlStateDisabled];
    }
    if (self.config.subscriptColorForStateNormal) {
        [builder setSubscriptColor:self.config.subscriptColorForStateNormal forState:EMSecureInputUiControlStateNormal];
    }
    if (self.config.subscriptColorForStateSelected) {
        [builder setSubscriptColor:self.config.subscriptColorForStateSelected forState:EMSecureInputUiControlStateSelected];
    }
    if (self.config.subscriptColorForStateDisabled) {
        [builder setSubscriptColor:self.config.subscriptColorForStateDisabled forState:EMSecureInputUiControlStateDisabled];
    }
    if (self.config.okButtonTextColorForStateNormal) {
        [builder setOkButtonTextColor:self.config.okButtonTextColorForStateNormal forState:EMSecureInputUiControlStateNormal];
    }
    if (self.config.okButtonTextColorForStateSelected) {
        [builder setOkButtonTextColor:self.config.okButtonTextColorForStateSelected forState:EMSecureInputUiControlStateSelected];
    }
    if (self.config.okButtonTextColorForStateDisabled) {
        [builder setOkButtonTextColor:self.config.okButtonTextColorForStateDisabled forState:EMSecureInputUiControlStateDisabled];
    }
    if (self.config.deleteButtonTextColorForStateNormal) {
        [builder setDeleteButtonTextColor:self.config.deleteButtonTextColorForStateNormal forState:EMSecureInputUiControlStateNormal];
    }
    if (self.config.deleteButtonTextColorForStateSelected) {
        [builder setDeleteButtonTextColor:self.config.deleteButtonTextColorForStateSelected forState:EMSecureInputUiControlStateSelected];
    }
    if (self.config.deleteButtonTextColorForStateDisabled) {
        [builder setDeleteButtonTextColor:self.config.deleteButtonTextColorForStateDisabled forState:EMSecureInputUiControlStateDisabled];
    }
    if (self.config.buttonBackgroundColorForStateNormal) {
        [builder setButtonBackgroundColor:self.config.buttonBackgroundColorForStateNormal forState:EMSecureInputUiControlStateNormal];
    }
    if (self.config.buttonBackgroundColorForStateSelected) {
        [builder setButtonBackgroundColor:self.config.buttonBackgroundColorForStateSelected forState:EMSecureInputUiControlStateSelected];
    }
    if (self.config.buttonBackgroundColorForStateDisabled) {
        [builder setButtonBackgroundColor:self.config.buttonBackgroundColorForStateDisabled forState:EMSecureInputUiControlStateDisabled];
    }
    if (self.config.buttonBackgroundImage) {
        [builder setButtonBackgroundImage:self.config.buttonBackgroundImage];
    }
    [builder setButtonBackgroundImageOpacity:self.config.buttonBackgroundImageOpacityForStateNormal forState:EMSecureInputUiControlStateNormal];
    [builder setButtonBackgroundImageOpacity:self.config.buttonBackgroundImageOpacityForStateSelected forState:EMSecureInputUiControlStateSelected];
    [builder setButtonBackgroundImageOpacity:self.config.buttonBackgroundImageOpacityForStateDisabled forState:EMSecureInputUiControlStateDisabled];
    if (self.config.okButtonImage) {
        [builder setOkButtonImage:self.config.okButtonImage];
    }
    [builder setOkButtonImageOpacity:self.config.okButtonImageOpacityForStateNormal forState:EMSecureInputUiControlStateNormal];
    [builder setOkButtonImageOpacity:self.config.okButtonImageOpacityForStateSelected forState:EMSecureInputUiControlStateSelected];
    [builder setOkButtonImageOpacity:self.config.okButtonImageOpacityForStateDisabled forState:EMSecureInputUiControlStateDisabled];
    if (self.config.deleteButtonImage) {
        [builder setDeleteButtonImage:self.config.deleteButtonImage];
    }
    [builder setDeleteButtonImageOpacity:self.config.deleteButtonImageOpacityForStateNormal forState:EMSecureInputUiControlStateNormal];
    [builder setDeleteButtonImageOpacity:self.config.deleteButtonImageOpacityForStateSelected forState:EMSecureInputUiControlStateSelected];
    [builder setDeleteButtonImageOpacity:self.config.deleteButtonImageOpacityForStateDisabled forState:EMSecureInputUiControlStateDisabled];
    
    if (self.config.buttonGradientColorStartForStateNormal && self.config.buttonGradientColorEndForStateNormal) {
        [builder setButtonGradientColors:self.config.buttonGradientColorStartForStateNormal
                  buttonGradientEndColor:self.config.buttonGradientColorEndForStateNormal
                                forState:EMSecureInputUiControlStateNormal];
    }
    
    if (self.config.buttonGradientColorStartForStateSelected && self.config.buttonGradientColorEndForStateSelected) {
        [builder setButtonGradientColors:self.config.buttonGradientColorStartForStateSelected
                  buttonGradientEndColor:self.config.buttonGradientColorEndForStateSelected
                                forState:EMSecureInputUiControlStateSelected];
    }
    
    if (self.config.buttonGradientColorStartForStateDisabled && self.config.buttonGradientColorEndForStateDisabled) {
        [builder setButtonGradientColors:self.config.buttonGradientColorStartForStateDisabled
                  buttonGradientEndColor:self.config.buttonGradientColorEndForStateDisabled
                                forState:EMSecureInputUiControlStateDisabled];
    }
    
    if (self.config.okButtonGradientColorStartForStateNormal && self.config.okButtonGradientColorEndForStateNormal) {
        [builder setOkButtonGradientColors:self.config.okButtonGradientColorStartForStateNormal
                    buttonGradientEndColor:self.config.okButtonGradientColorEndForStateNormal
                                  forState:EMSecureInputUiControlStateNormal];
    }
    
    if (self.config.okButtonGradientColorStartForStateSelected && self.config.okButtonGradientColorEndForStateSelected) {
        [builder setOkButtonGradientColors:self.config.okButtonGradientColorStartForStateSelected
                    buttonGradientEndColor:self.config.okButtonGradientColorEndForStateSelected
                                  forState:EMSecureInputUiControlStateSelected];
    }
    
    if (self.config.okButtonGradientColorStartForStateDisabled && self.config.okButtonGradientColorEndForStateDisabled) {
        [builder setOkButtonGradientColors:self.config.okButtonGradientColorStartForStateDisabled
                    buttonGradientEndColor:self.config.okButtonGradientColorEndForStateDisabled
                                  forState:EMSecureInputUiControlStateDisabled];
    }
    
    if (self.config.deleteButtonGradientColorStartForStateNormal && self.config.deleteButtonGradientColorEndForStateNormal) {
        [builder setDeleteButtonGradientColors:self.config.deleteButtonGradientColorStartForStateNormal
                        buttonGradientEndColor:self.config.deleteButtonGradientColorEndForStateNormal
                                      forState:EMSecureInputUiControlStateNormal];
    }
    
    if (self.config.deleteButtonGradientColorStartForStateSelected && self.config.deleteButtonGradientColorEndForStateSelected) {
        [builder setDeleteButtonGradientColors:self.config.deleteButtonGradientColorStartForStateSelected
                        buttonGradientEndColor:self.config.deleteButtonGradientColorEndForStateSelected
                                      forState:EMSecureInputUiControlStateSelected];
    }
    
    if (self.config.deleteButtonGradientColorStartForStateDisabled && self.config.deleteButtonGradientColorEndForStateDisabled) {
        [builder setDeleteButtonGradientColors:self.config.deleteButtonGradientColorStartForStateDisabled
                        buttonGradientEndColor:self.config.deleteButtonGradientColorEndForStateDisabled
                                      forState:EMSecureInputUiControlStateDisabled];
    }
    
    [builder setIsDeleteButtonAlwaysEnabled:self.config.isDeleteButtonAlwaysEnabled];
    
    // Build keypad and add handler.
    id<EMSecureInputUi> secureInput = [builder buildWithScrambling:self.config.scrambled isDoubleInputField:self.config.isDoubleInput displayMode:EMSecureInputUiDisplayModeFullScreen onFinishBlock:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin) {
        [builder wipe];
    }];
    
    // Push in secure input UI view controller to the current view controller
    self.keypad = secureInput.viewController.view;
    [self addSubview:_keypad];
}

- (void)getFont:(NSString *)name size:(NSInteger)size caption:(NSString *)caption handler:(void (^)(UIFont *font))handler
{
    if (name && size == -1) {
        @throw [NSException exceptionWithName:@"Font"
                                       reason:[NSString stringWithFormat:@"%@ also need to specify size.", caption]
                                     userInfo:nil];
    } else if (!name && size != -1) {
        @throw [NSException exceptionWithName:@"Font"
                                       reason:[NSString stringWithFormat:@"%@ also need to specify name.", caption]
                                     userInfo:nil];
    } else if (name && size != -1) {
        UIFont *fnt = [UIFont fontWithName:name size:size];
        if (fnt) {
            handler(fnt);
        } else {
            @throw [NSException exceptionWithName:@"Font"
                                           reason:[NSString stringWithFormat:@"Failed to load %@ font: %@", caption, name]
                                         userInfo:nil];
        }
    }
    

}

// MARK: - Designable

- (void)setScrambled:(BOOL)scrambled
{
    self.config.scrambled = scrambled;
    [self setNeedsLayout];
}

- (void)setScreenBackgroundColor:(UIColor *)color
{
    self.config.screenBackgroundColor = color;
    [self setNeedsLayout];
}

- (void)setScreenBackgroundImage:(UIImage *)image
{
    self.config.screenBackgroundImage = image;
    [self setNeedsLayout];
}

- (void)setScreenBackgroundImageContentMode:(NSInteger)contentMode
{
    self.config.screenBackgroundImageContentMode = contentMode;
    [self setNeedsLayout];
}

- (void)setNumberOfRows:(NSInteger)numberOfRows
{
    self.config.numberOfRows = numberOfRows;
    [self setNeedsLayout];
}

- (void)setNumberOfColumns:(NSInteger)numberOfColumns
{
    self.config.numberOfColumns = numberOfColumns;
    [self setNeedsLayout];
}

- (void)setKeypadHeightRatio:(CGFloat)keypadHeightRatio
{
    self.config.keypadHeightRatio = keypadHeightRatio;
    [self setNeedsLayout];
}

- (void)setSwapOkAndDeleteButton:(BOOL)swapOkAndDeleteButton
{
    self.config.swapOkAndDeleteButton = swapOkAndDeleteButton;
    [self setNeedsLayout];
}

- (void)setKeys:(NSString *)keys
{
    self.config.keys = keys;
    [self setNeedsLayout];
}

- (void)setSubscripts:(NSString *)subscripts
{
    self.config.subscripts = [subscripts componentsSeparatedByString:@"|"];
    [self setNeedsLayout];
}

- (void)setDistanceBetweenKeyAndSubscript:(CGFloat)distanceBetweenKeyAndSubscript
{
    self.config.distanceBetweenKeyAndSubscript = distanceBetweenKeyAndSubscript;
    [self setNeedsLayout];
}

- (void)setButtonBorderWidth:(NSInteger)buttonBorderWidth
{
    self.config.buttonBorderWidth = buttonBorderWidth;
    [self setNeedsLayout];
}

// Deprecated
//- (void)setButtonBorderColor:(UIColor *)buttonBorderColor
//{
//    self.config.buttonBorderColor = buttonBorderColor;
//    [self setNeedsLayout];
//}

- (void)setKeypadFrameColor:(UIColor *)keypadFrameColor
{
    self.config.keypadFrameColor = keypadFrameColor;
    [self setNeedsLayout];
}

- (void)setKeypadGridGradientStartColor:(UIColor *)keypadGridGradientStartColor
{
    self.config.keypadGridGradientStartColor = keypadGridGradientStartColor;
    [self setNeedsLayout];
}

- (void)setKeypadGridGradientEndColor:(UIColor *)keypadGridGradientEndColor
{
    self.config.keypadGridGradientEndColor = keypadGridGradientEndColor;
    [self setNeedsLayout];
}

- (void)setButtonPressedVisibility:(BOOL)buttonPressedVisibility
{
    self.config.buttonPressedVisibility = buttonPressedVisibility;
    [self setNeedsLayout];
}

- (void)setKeyFontName:(NSString *)keyFontName
{
    self.config.keyFontName = keyFontName;
    [self setNeedsLayout];
}

- (void)setKeyFontSize:(NSInteger)keyFontSize
{
    self.config.keyFontSize = keyFontSize;
    [self setNeedsLayout];
}

- (void)setSubscriptFontName:(NSString *)subscriptFontName
{
    self.config.subscriptFontName = subscriptFontName;
    [self setNeedsLayout];
}

- (void)setSubscriptFontSize:(NSInteger)subscriptFontSize
{
    self.config.subscriptFontSize = subscriptFontSize;
    [self setNeedsLayout];
}

- (void)setKeyColorForStateNormal:(UIColor *)keyColorForStateNormal
{
    self.config.keyColorForStateNormal = keyColorForStateNormal;
    [self setNeedsLayout];
}

- (void)setKeyColorForStateSelected:(UIColor *)keyColorForStateSelected
{
    self.config.keyColorForStateSelected = keyColorForStateSelected;
    [self setNeedsLayout];
}

- (void)setKeyColorForStateDisabled:(UIColor *)keyColorForStateDisabled
{
    self.config.keyColorForStateDisabled = keyColorForStateDisabled;
    [self setNeedsLayout];
}

- (void)setSubscriptColorForStateNormal:(UIColor *)subscriptColorForStateNormal
{
    self.config.subscriptColorForStateNormal = subscriptColorForStateNormal;
    [self setNeedsLayout];
}

- (void)setSubscriptColorForStateSelected:(UIColor *)subscriptColorForStateSelected
{
    self.config.subscriptColorForStateSelected = subscriptColorForStateSelected;
    [self setNeedsLayout];
}

- (void)setSubscriptColorForStateDisabled:(UIColor *)subscriptColorForStateDisabled
{
    self.config.subscriptColorForStateDisabled = subscriptColorForStateDisabled;
    [self setNeedsLayout];
}

- (void)setButtonBackgroundColorForStateNormal:(UIColor *)buttonBackgroundColorForStateNormal
{
    self.config.buttonBackgroundColorForStateNormal = buttonBackgroundColorForStateNormal;
    [self setNeedsLayout];
}

- (void)setButtonBackgroundColorForStateSelected:(UIColor *)buttonBackgroundColorForStateSelected
{
    self.config.buttonBackgroundColorForStateSelected = buttonBackgroundColorForStateSelected;
    [self setNeedsLayout];
}

- (void)setButtonBackgroundColorForStateDisabled:(UIColor *)buttonBackgroundColorForStateDisabled
{
    self.config.buttonBackgroundColorForStateDisabled = buttonBackgroundColorForStateDisabled;
    [self setNeedsLayout];
}

- (void)setButtonBackgroundImage:(UIImage *)buttonBackgroundImage
{
    self.config.buttonBackgroundImage = buttonBackgroundImage;
    [self setNeedsLayout];
}

- (void)setButtonBackgroundImageOpacityForStateNormal:(CGFloat)buttonBackgroundImageOpacityForStateNormal
{
    self.config.buttonBackgroundImageOpacityForStateNormal = buttonBackgroundImageOpacityForStateNormal;
    [self setNeedsLayout];
}

- (void)setButtonBackgroundImageOpacityForStateSelected:(CGFloat)buttonBackgroundImageOpacityForStateSelected
{
    self.config.buttonBackgroundImageOpacityForStateSelected = buttonBackgroundImageOpacityForStateSelected;
    [self setNeedsLayout];
}

- (void)setButtonBackgroundImageOpacityForStateDisabled:(CGFloat)buttonBackgroundImageOpacityForStateDisabled
{
    self.config.buttonBackgroundImageOpacityForStateDisabled = buttonBackgroundImageOpacityForStateDisabled;
    [self setNeedsLayout];
}

- (void)setButtonGradientColorStartForStateNormal:(UIColor *)buttonGradientColorStartForStateNormal
{
    self.config.buttonGradientColorStartForStateNormal = buttonGradientColorStartForStateNormal;
    [self setNeedsLayout];
}

- (void)setButtonGradientColorStartForStateSelected:(UIColor *)buttonGradientColorStartForStateSelected
{
    self.config.buttonGradientColorStartForStateSelected = buttonGradientColorStartForStateSelected;
    [self setNeedsLayout];
}

- (void)setButtonGradientColorStartForStateDisabled:(UIColor *)buttonGradientColorStartForStateDisabled
{
    self.config.buttonGradientColorStartForStateDisabled = buttonGradientColorStartForStateDisabled;
    [self setNeedsLayout];
}

- (void)setButtonGradientColorEndForStateNormal:(UIColor *)buttonGradientColorEndForStateNormal
{
    self.config.buttonGradientColorEndForStateNormal = buttonGradientColorEndForStateNormal;
    [self setNeedsLayout];
}

- (void)setButtonGradientColorEndForStateSelected:(UIColor *)buttonGradientColorEndForStateSelected
{
    self.config.buttonGradientColorEndForStateSelected = buttonGradientColorEndForStateSelected;
    [self setNeedsLayout];
}

- (void)setButtonGradientColorEndForStateDisabled:(UIColor *)buttonGradientColorEndForStateDisabled
{
    self.config.buttonGradientColorEndForStateDisabled = buttonGradientColorEndForStateDisabled;
    [self setNeedsLayout];
}

@end
