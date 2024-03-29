/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "KeypadDesignableConfig.h"

typedef NS_ENUM(NSUInteger, EPlatform) {
    EPlatform_iOS,
    EPlatform_Android
};

@implementation KeypadDesignableConfig

- (instancetype)init
{
    if (self = [super init]) {
        self.scrambled                                      = NO;
        self.isDoubleInput                                  = NO;
        self.firstLabel                                     = EMSecureInputBuilder_DEFAULT_FIRST_LABEL;
        self.secondLabel                                    = EMSecureInputBuilder_DEFAULT_SECOND_LABEL;
        self.screenBackgroundColor                          = EMSecureInputBuilder_DEFAULT_SCREEN_BACKGROUND_COLOR;
        self.screenBackgroundImage                          = nil;
        self.screenBackgroundImageContentMode               = EMSecureInputUiBackgroundImageContentModeStretch;
        self.labelColor                                     = EMSecureInputBuilder_DEFAULT_LABEL_COLOR;
        self.labelFontSize                                  = EMSecureInputBuilder_DEFAULT_LABEL_FONT_SIZE;
        self.labelAlignment                                 = EMSecureInputBuilder_DEFAULT_LABEL_ALIGNMENT;
        self.inputFieldFontSize                             = EMSecureInputBuilder_DEFAULT_INPUT_FIELD_FONT_SIZE;
        self.inputFieldBorderColorForStateFocused           = EMSecureInputBuilder_DEFAULT_INPUT_FIELD_FOCUS_COLOR;
        self.inputFieldBorderColorForStateUnFocused         = EMSecureInputBuilder_DEFAULT_INPUT_FIELD_UNFOCUS_COLOR;
        self.inputFieldBackgroundColorForStateFocused       = EMSecureInputBuilder_DEFAULT_INPUT_FIELD_BACKGROUND_FOCUS_COLOR;
        self.inputFieldBackgroundColorForStateUnocused      = EMSecureInputBuilder_DEFAULT_INPUT_FIELD_BACKGROUND_UNFOCUS_COLOR;
        self.minimumInputLength                             = EMSecureInputBuilder_DEFAULT_MINIMUM_INPUT_LENGTH;
        self.maximumInputLength                             = EMSecureInputBuilder_DEFAULT_MAXIMUM_INPUT_LENGTH;
        self.numberOfRows                                   = EMSecureInputBuilder_DEFAULT_NO_OF_ROWS;
        self.numberOfColumns                                = EMSecureInputBuilder_DEFAULT_NO_OF_COLUMNS;
        self.keypadHeightRatio                              = EMSecureInputBuilder_DEFAULT_KEYPAD_HEIGHT_RATIO;
        self.swapOkAndDeleteButton                          = NO;
        self.keys                                           = EMSecureInputBuilder_DEFAULT_KEYS;
        self.subscripts                                     = nil;
        self.okButtonText                                   = EMSecureInputBuilder_DEFAULT_OK_BUTTON_NAME;
        self.deleteButtonText                               = EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_NAME;
        self.distanceBetweenKeyAndSubscript                 = .0f;
        self.buttonBorderWidth                              = EMSecureInputBuilder_DEFAULT_BUTTON_BORDER_WIDTH;
        //        self.buttonBorderColor                          = EMSecureInputBuilder_DEFAULT_BUTTON_BORDER_COLOR;
        self.keypadFrameColor                               = EMSecureInputBuilder_DEFAULT_KEYPAD_FRAME_COLOR;
        self.keypadGridGradientStartColor                   = nil;
        self.keypadGridGradientEndColor                     = nil;
        self.buttonPressedVisibility                        = EMSecureInputBuilder_DEFAULT_VISIBLE_BUTTON_PRESS;
        self.keyFontName                                    = nil;
        self.keyFontSize                                    = -1;
        self.subscriptFontName                              = nil;
        self.subscriptFontSize                              = -1;
        self.okButtonFontName                               = nil;
        self.okButtonFontSize                               = -1;
        self.deleteButtonFontName                           = nil;
        self.deleteButtonFontSize                           = -1;
        self.keyColorForStateNormal                         = EMSecureInputBuilder_DEFAULT_KEY_COLOR;
        self.keyColorForStateSelected                       = EMSecureInputBuilder_DEFAULT_KEY_SELECTED_COLOR;
        self.keyColorForStateDisabled                       = EMSecureInputBuilder_DEFAULT_KEY_DISABLED_COLOR;
        self.subscriptColorForStateNormal                   = nil;
        self.subscriptColorForStateSelected                 = nil;
        self.subscriptColorForStateDisabled                 = nil;
        self.okButtonTextColorForStateNormal                = EMSecureInputBuilder_DEFAULT_OK_BUTTON_TEXT_COLOR;
        self.okButtonTextColorForStateSelected              = EMSecureInputBuilder_DEFAULT_OK_BUTTON_SELECTED_TEXT_COLOR;
        self.okButtonTextColorForStateDisabled              = EMSecureInputBuilder_DEFAULT_OK_BUTTON_DISABLED_TEXT_COLOR;
        self.deleteButtonTextColorForStateNormal            = EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_TEXT_COLOR;
        self.deleteButtonTextColorForStateSelected          = EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_SELECTED_TEXT_COLOR;
        self.deleteButtonTextColorForStateDisabled          = EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_DISABLED_TEXT_COLOR;
        self.buttonBackgroundColorForStateNormal            = EMSecureInputBuilder_DEFAULT_BUTTON_BACKGROUND_COLOR;
        self.buttonBackgroundColorForStateSelected          = EMSecureInputBuilder_DEFAULT_BUTTON_BACKGROUND_SELECTED_COLOR;
        self.buttonBackgroundColorForStateDisabled          = EMSecureInputBuilder_DEFAULT_BUTTON_BACKGROUND_DISABLED_COLOR;
        self.buttonBackgroundImage                          = nil;
        self.buttonBackgroundImageOpacityForStateNormal     = EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY;
        self.buttonBackgroundImageOpacityForStateSelected   = EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY;
        self.buttonBackgroundImageOpacityForStateDisabled   = EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY;
        self.okButtonImage                                  = nil;
        self.okButtonImageOpacityForStateNormal             = EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY;
        self.okButtonImageOpacityForStateSelected           = EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY;
        self.okButtonImageOpacityForStateDisabled           = EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY;
        self.deleteButtonImage                              = nil;
        self.deleteButtonImageOpacityForStateNormal         = EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY;
        self.deleteButtonImageOpacityForStateSelected       = EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY;
        self.deleteButtonImageOpacityForStateDisabled       = EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY;
        self.buttonGradientColorStartForStateNormal         = nil;
        self.buttonGradientColorStartForStateSelected       = nil;
        self.buttonGradientColorStartForStateDisabled       = nil;
        self.buttonGradientColorEndForStateNormal           = nil;
        self.buttonGradientColorEndForStateSelected         = nil;
        self.buttonGradientColorEndForStateDisabled         = nil;
        self.okButtonGradientColorStartForStateNormal       = nil;
        self.okButtonGradientColorStartForStateSelected     = nil;
        self.okButtonGradientColorStartForStateDisabled     = nil;
        self.okButtonGradientColorEndForStateNormal         = nil;
        self.okButtonGradientColorEndForStateSelected       = nil;
        self.okButtonGradientColorEndForStateDisabled       = nil;
        self.deleteButtonGradientColorStartForStateNormal   = nil;
        self.deleteButtonGradientColorStartForStateSelected = nil;
        self.deleteButtonGradientColorStartForStateDisabled = nil;
        self.deleteButtonGradientColorEndForStateNormal     = nil;
        self.deleteButtonGradientColorEndForStateSelected   = nil;
        self.deleteButtonGradientColorEndForStateDisabled   = nil;
        self.isDeleteButtonAlwaysEnabled                    = NO;
    }
    
    return self;
}

- (NSString *)EMSecureInputUiControlFocusStateToString:(EMSecureInputUiControlFocusState)state platform:(EPlatform)platform shortcut:(BOOL)sc
{
    switch (state) {
        case EMSecureInputUiControlFocused:
            if (sc) {
                return @"Focused";
            } else if (platform == EPlatform_iOS) {
                return @"EMSecureInputUiControlFocused";
            } else {
                return @"SecureInputBuilder.UiControlFocusState.FOCUSED";
            }
        case EMSecureInputUiControlUnfocused:
            if (sc) {
                return @"Unfocused";
            } else if (platform == EPlatform_iOS) {
                return @"EMSecureInputUiControlUnfocused";
            } else {
                return @"SecureInputBuilder.UiControlFocusState.UNFOCUSED";
            }
    }
    
    return @"Unknown";
}

- (NSString *)EMSecureInputUiLabelAlignmentToString:(EMSecureInputUiLabelAlignment)alignment platform:(EPlatform)platform
{
    switch (alignment)
    {
        case EMSecureInputUiLabelAlignmentLeft:
            if (platform == EPlatform_iOS) {
                return @"EMSecureInputUiLabelAlignmentLeft";
            } else {
                return @"SecureInputBuilder.LabelAlignment.LEFT";
            }
        case EMSecureInputUiLabelAlignmentCenter:
            if (platform == EPlatform_iOS) {
                return @"EMSecureInputUiLabelAlignmentCenter";
            } else {
                return @"SecureInputBuilder.LabelAlignment.CENTER";
            }
        case EMSecureInputUiLabelAlignmentRight:
            if (platform == EPlatform_iOS) {
                return @"EMSecureInputUiLabelAlignmentRight";
            } else {
                return @"SecureInputBuilder.LabelAlignment.RIGHT";
            }
    }
    
    return @"Unknown";
}

- (NSString *)EMSecureInputUiControlStateToString:(EMSecureInputUiControlState)state platform:(EPlatform)platform shortcut:(BOOL)sc
{
    switch (state) {
        case EMSecureInputUiControlStateNormal:
            if (sc) {
                return @"Normal";
            } else if (platform == EPlatform_iOS) {
                return @"EMSecureInputUiControlStateNormal";
            } else {
                return @"SecureInputBuilder.UiControlState.NORMAL";
            }
        case EMSecureInputUiControlStateSelected:
            if (sc) {
                return @"Selected";
            } else if (platform == EPlatform_iOS) {
                return @"EMSecureInputUiControlStateSelected";
            } else {
                return @"SecureInputBuilder.UiControlState.SELECTED";
            }
        case EMSecureInputUiControlStateDisabled:
            if (sc) {
                return @"Disabled";
            } else if (platform == EPlatform_iOS) {
                return @"EMSecureInputUiControlStateDisabled";
            } else {
                return @"SecureInputBuilder.UiControlState.DISABLED";
            }
    }
    
    return @"Unknown";
}

- (NSString *)EMSecureInputUiBackgroundImageContentModeToString:(EMSecureInputUiBackgroundImageContentMode)contentMode platform:(EPlatform)platform
{
    switch (contentMode)
    {
        case EMSecureInputUiBackgroundImageContentModeStretch:
            if (platform == EPlatform_iOS) {
                return @"EMSecureInputUiBackgroundImageContentModeStretch";
            } else {
                return @"SecureInputBuilder.ImageMode.STRETCH";
            }
        case EMSecureInputUiBackgroundImageContentModeTile:
            if (platform == EPlatform_iOS) {
                return @"EMSecureInputUiBackgroundImageContentModeTile";
            } else {
                return @"SecureInputBuilder.ImageMode.TILE";
            }
        case EMSecureInputUiBackgroundImageContentModeCenter:
            if (platform == EPlatform_iOS) {
                return @"EMSecureInputUiBackgroundImageContentModeCenter";
            } else {
                return @"SecureInputBuilder.ImageMode.CENTER";
            }
    }
    
    return @"Unknown";
}

- (NSString *)colorToString:(UIColor *)color platform:(EPlatform)platform name:(NSString *)name
{
    if (!color) {
        return nil;
    } else {
        CGFloat red = .0f, green = .0f, blue = .0f, alpha = .0f;
        [color getRed:&red green:&green blue:&blue alpha:&alpha];
        if (platform == EPlatform_iOS) {
            return [NSString stringWithFormat:@"[UIColor colorWithRed:%d green:%d blue:%d alpha:%g]",
                    (Byte)(255.f * red), (Byte)(255.f * green), (Byte)(255.f * blue), alpha];
        } else {
            return [NSString stringWithFormat:@"<color name=\"%@\">#%02X%02X%02X%02X</color>", name,
                    (Byte)(255.f * alpha), (Byte)(255.f * red), (Byte)(255.f * green), (Byte)(255.f * blue)];
            
        }
    }
}

- (void)addFlt:(NSMutableString *)ret
           key:(NSString *)key
         value:(CGFloat)value
       default:(CGFloat)def
      platform:(EPlatform)platform
{
    if (value != def) {
        if (platform == EPlatform_iOS) {
            [ret appendFormat:@"[builder set%@:%g];\n", key, value];
        } else {
            [ret appendFormat:@"builder.set%@(%gf);\n", key, value];
        }
    }
}

- (void)addInt:(NSMutableString *)ret
           key:(NSString *)key
         value:(NSInteger)value
       default:(NSInteger)def
      platform:(EPlatform)platform
{
    if (value != def) {
        if (platform == EPlatform_iOS) {
            [ret appendFormat:@"[builder set%@:%ld];\n", key, value];
        } else {
            [ret appendFormat:@"builder.set%@(%ld);\n", key, value];
        }
    }
}

- (void)addFlt:(NSMutableString *)ret
           key:(NSString *)key
         value:(CGFloat)value
       default:(CGFloat)def
      ctrState:(EMSecureInputUiControlState)state
      platform:(EPlatform)platform
{
    if (value != def) {
        NSString *stateValue = [self EMSecureInputUiControlStateToString:state platform:platform shortcut:NO];
        
        if (platform == EPlatform_iOS) {
            [ret appendFormat:@"[builder set%@:%gf forState:%@];\n", key, value, stateValue];
        } else {
            [ret appendFormat:@"builder.set%@(%@, %gf);\n", key, stateValue, value];
        }
    }
}

- (void)addBol:(NSMutableString *)ret
           key:(NSString *)key
         value:(BOOL)value
       default:(BOOL)def
      platform:(EPlatform)platform
{
    if (value != def) {
        if (platform == EPlatform_iOS) {
            [ret appendFormat:@"[builder set%@:%@];\n", key, value ? @"YES" : @"NO"];
        } else {
            [ret appendFormat:@"builder.set%@(%@);\n", key, value ? @"true" : @"false"];
        }
    }
}

- (void)addRct:(NSMutableString *)ret
           key:(NSString *)key
         value:(CGRect)value
       default:(CGRect)def
      platform:(EPlatform)platform
{
    if (!CGRectEqualToRect(value, def)) {
        [ret appendFormat:@"[builder set%@:CGRectMake(%g, %g, %g, %g)];\n", key, value.origin.x, value.origin.y, value.size.width, value.size.width];
    }
}

- (void)addStr:(NSMutableString *)ret
           key:(NSString *)key
         value:(NSString *)value
       default:(NSString *)def
      platform:(EPlatform)platform
{
    if (value && ![value isEqualToString:def]) {
        if (platform == EPlatform_iOS) {
            [ret appendFormat:@"[builder set%@:@\"%@\"];\n", key, value];
        } else {
            [ret appendFormat:@"builder.set%@(\"%@\");\n", key, value];
        }
    }
}

- (void)addFnt:(NSMutableString *)ret
           key:(NSString *)key
         value:(UIFont *)value
      platform:(EPlatform)platform
{
    if (value) {
        if (platform == EPlatform_iOS) {
            [ret appendFormat:@"[builder set%@:[UIFont fontWithName:@\"%@\" size:%g]];\n", key, value.fontName, value.fontDescriptor.pointSize];
        } else {
            UIFontDescriptorSymbolicTraits traits = value.fontDescriptor.symbolicTraits;
            BOOL isBold     = (traits & UIFontDescriptorTraitBold) != 0;
            BOOL isItalic   = (traits & UIFontDescriptorTraitItalic) != 0;
            
            NSString *type = @"Typeface.NORMAL";
            if (isBold && isItalic) {
                type = @"Typeface.BOLD_ITALIC";
            } else if (isBold) {
                type = @"Typeface.BOLD";
            } else if (isItalic) {
                type = @"Typeface.ITALIC";
            }
            
            [ret appendFormat:@"builder.set%@(Typeface.create(\"%@\", %@));\n", key, value.fontName, type];
            [ret appendFormat:@"builder.set%@Size(%ld);\n", key, (NSInteger)value.fontDescriptor.pointSize];
        }
    }
}

- (void)addImg:(NSMutableString *)ret
           key:(NSString *)key
         value:(UIImage *)value
       default:(UIImage *)def
      platform:(EPlatform)platform
{
    if (value && ![value isEqual:def]) {
        if (platform == EPlatform_iOS) {
            [ret appendFormat:@"[builder set%@:[UIImage imageNamed:@\"%@\"]];\n", key, value.accessibilityIdentifier];
        } else {
            [ret appendFormat:@"builder.set%@(R.drawable.%@);\n", key, value.accessibilityIdentifier];
        }
    }
}

- (void)addClr:(NSMutableString *)ret
        assets:(NSMutableString *)assets
           key:(NSString *)key
         value:(UIColor *)value
       default:(UIColor *)def
      platform:(EPlatform)platform
{
    if (value && ![value isEqual:def]) {
        NSString *name          = [NSString stringWithFormat:@"skc%@", key];
        NSString *colorValue    = [self colorToString:value platform:platform name:name];
        
        if (platform == EPlatform_iOS) {
            [ret appendFormat:@"[builder set%@:%@];\n", key, colorValue];
        } else {
            [ret appendFormat:@"builder.set%@(context.getResources().getColor(R.color.%@));\n", key, name];
            [assets appendFormat:@"%@\n", colorValue];
        }
    }
}

- (void)addClr:(NSMutableString *)ret
        assets:(NSMutableString *)assets
           key:(NSString *)key
         value:(UIColor *)value
       default:(UIColor *)def
    focusState:(EMSecureInputUiControlFocusState)state
      platform:(EPlatform)platform
{
    if (value && ![value isEqual:def]) {
        NSString *stateValueShort   = [self EMSecureInputUiControlFocusStateToString:state platform:platform shortcut:YES];
        NSString *stateValue        = [self EMSecureInputUiControlFocusStateToString:state platform:platform shortcut:NO];
        NSString *name              = [NSString stringWithFormat:@"skc%@%@", key, stateValueShort];
        NSString *colorValue        = [self colorToString:value platform:platform name:name];
        
        if (platform == EPlatform_iOS) {
            [ret appendFormat:@"[builder set%@:%@ forState:%@];\n", key, colorValue, stateValue];
        } else {
            [ret appendFormat:@"builder.set%@(%@, context.getResources().getColor(R.color.%@));\n", key, stateValue, name];
            [assets appendFormat:@"%@\n", colorValue];
        }
    }
}

- (void)addClr:(NSMutableString *)ret
        assets:(NSMutableString *)assets
           key:(NSString *)key
         value:(UIColor *)value
       default:(UIColor *)def
      ctrState:(EMSecureInputUiControlState)state
      platform:(EPlatform)platform
{
    if (value && ![value isEqual:def]) {
        NSString *stateValueShort   = [self EMSecureInputUiControlStateToString:state platform:platform shortcut:YES];
        NSString *stateValue        = [self EMSecureInputUiControlStateToString:state platform:platform shortcut:NO];
        NSString *name              = [NSString stringWithFormat:@"skc%@%@", key, stateValueShort];
        NSString *colorValue        = [self colorToString:value platform:platform name:name];
        
        if (platform == EPlatform_iOS) {
            [ret appendFormat:@"[builder set%@:%@ forState:%@];\n", key, colorValue, stateValue];
        } else {
            [ret appendFormat:@"builder.set%@(%@, context.getResources().getColor(R.color.%@));\n", key, stateValue, name];
            [assets appendFormat:@"%@\n", colorValue];
        }
    }
}

- (void)addGrd:(NSMutableString *)ret
        assets:(NSMutableString *)assets
           key:(NSString *)key
         start:(UIColor *)start
           end:(UIColor *)end
      ctrState:(EMSecureInputUiControlState)state
      platform:(EPlatform)platform
{
    if (start && end) {
        NSString *stateValueShort   = [self EMSecureInputUiControlStateToString:state platform:platform shortcut:YES];
        NSString *stateValue        = [self EMSecureInputUiControlStateToString:state platform:platform shortcut:NO];
        NSString *nameStart         = [NSString stringWithFormat:@"skc%@%@Start", key, stateValueShort];
        NSString *nameEnd           = [NSString stringWithFormat:@"skc%@%@End", key, stateValueShort];
        NSString *colorValueStart   = [self colorToString:start platform:platform name:nameStart];
        NSString *colorValueEnd     = [self colorToString:end platform:platform name:nameEnd];
        
        if (platform == EPlatform_iOS) {
            [ret appendFormat:@"[builder set%@:%@\n          buttonGradientEndColor:%@\n                         forState:%@];\n",
             key, colorValueStart, colorValueEnd, stateValue];
        } else {
            [ret appendFormat:@"builder.set%@(%@, context.getResources().getColor(R.color.%@), context.getResources().getColor(R.color.%@));\n", key, stateValue, nameStart, nameEnd];
            [assets appendFormat:@"%@\n", colorValueStart];
            [assets appendFormat:@"%@\n", colorValueEnd];
        }
    }
}

- (void)printConfiguration
{
    [self printConfiguration:EPlatform_iOS];
    [self printConfiguration:EPlatform_Android];
}


- (void)printConfiguration:(EPlatform)platform
{
    NSMutableString *assets     = [NSMutableString new]; // Android only
    NSMutableString *builder    = [NSMutableString stringWithString:@"\n\n\n\n"];

    if (platform == EPlatform_iOS) {
        [builder appendString:@"#############\n##   iOS   ##\n#############\n\n"];
        [builder appendString:@"id<EMSecureInputBuilder> builder = [[EMSecureInputService serviceWithModule:[EMUIModule uiModule]] secureInputBuilder];\n\n"];
    } else {
        [builder appendString:@"#############\n## Android ##\n#############\n\n"];
        [builder appendString:@"final SecureInputBuilder builder = SecureInputService.create(UiModule.create()).getSecureInputBuilder();\n\n"];
    }
    
    [self addStr:builder
             key:@"FirstLabel"
           value:_firstLabel
         default:EMSecureInputBuilder_DEFAULT_FIRST_LABEL
        platform:platform];
    
    [self addStr:builder
             key:@"SecondLabel"
           value:_secondLabel
         default:EMSecureInputBuilder_DEFAULT_SECOND_LABEL
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"ScreenBackgroundColor"
           value:_screenBackgroundColor
         default:EMSecureInputBuilder_DEFAULT_SCREEN_BACKGROUND_COLOR
        platform:platform];
    
    if (_screenBackgroundImage) {
        if (platform == EPlatform_iOS) {
            [builder appendFormat:@"[builder setScreenBackgroundImage:[UIImage imageNamed:@\"%@\"] contentMode:%@];\n", _screenBackgroundImage.accessibilityIdentifier, [self EMSecureInputUiBackgroundImageContentModeToString:_screenBackgroundImageContentMode platform:platform]];
        } else {
            [builder appendFormat:@"builder.setScreenBackgroundImage(R.drawable.%@, %@);\n", _screenBackgroundImage.accessibilityIdentifier, [self EMSecureInputUiBackgroundImageContentModeToString:_screenBackgroundImageContentMode platform:platform]];
        }
    }
    
    [self addClr:builder
          assets:assets
             key:@"LabelColor"
           value:_labelColor
         default:EMSecureInputBuilder_DEFAULT_LABEL_COLOR
        platform:platform];
    
    [self addFlt:builder
             key:@"LabelFontSize"
           value:_labelFontSize
         default:EMSecureInputBuilder_DEFAULT_LABEL_FONT_SIZE
        platform:platform];
    
    if (_labelAlignment != EMSecureInputBuilder_DEFAULT_LABEL_ALIGNMENT) {
        if (platform == EPlatform_iOS) {
            [builder appendFormat:@"[builder setLabelAlignment:%@];\n", [self EMSecureInputUiLabelAlignmentToString:_labelAlignment platform:platform]];
        } else {
            [builder appendFormat:@"builder.setLabelAlignment(%@);\n", [self EMSecureInputUiLabelAlignmentToString:_labelAlignment platform:platform]];
        }
    }
    
    [self addFlt:builder
             key:@"InputFieldFontSize"
           value:_inputFieldFontSize
         default:EMSecureInputBuilder_DEFAULT_INPUT_FIELD_FONT_SIZE
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"InputFieldBorderColor"
           value:_inputFieldBorderColorForStateFocused
         default:EMSecureInputBuilder_DEFAULT_INPUT_FIELD_FOCUS_COLOR
      focusState:EMSecureInputUiControlFocused
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"InputFieldBorderColor"
           value:_inputFieldBorderColorForStateUnFocused
         default:EMSecureInputBuilder_DEFAULT_INPUT_FIELD_UNFOCUS_COLOR
      focusState:EMSecureInputUiControlUnfocused
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"InputFieldBackgroundColor"
           value:_inputFieldBackgroundColorForStateFocused
         default:EMSecureInputBuilder_DEFAULT_INPUT_FIELD_BACKGROUND_FOCUS_COLOR
      focusState:EMSecureInputUiControlFocused
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"InputFieldBackgroundColor"
           value:_inputFieldBackgroundColorForStateUnocused
         default:EMSecureInputBuilder_DEFAULT_INPUT_FIELD_BACKGROUND_UNFOCUS_COLOR
      focusState:EMSecureInputUiControlUnfocused
        platform:platform];
    
    if (_minimumInputLength != EMSecureInputBuilder_DEFAULT_MINIMUM_INPUT_LENGTH || _maximumInputLength != EMSecureInputBuilder_DEFAULT_MAXIMUM_INPUT_LENGTH) {
        if (platform == EPlatform_iOS) {
            [builder appendFormat:@"[builder setMinimumInputLength:%ld andMaximumInputLength:%ld];\n", (long)_minimumInputLength, (long)_maximumInputLength];
        } else {
            [builder appendFormat:@"builder.setMaximumAndMinimumInputLength(%ld, %ld);\n", (long)_maximumInputLength, (long)_minimumInputLength];
        }
    }
    
    if (_numberOfRows != EMSecureInputBuilder_DEFAULT_NO_OF_ROWS || _numberOfColumns != EMSecureInputBuilder_DEFAULT_NO_OF_COLUMNS) {
        if (platform == EPlatform_iOS) {
            [builder appendFormat:@"[builder setNumberOfRows:%ld andColumns:%ld];\n", (long)_numberOfRows, (long)_numberOfColumns];
        } else {
            [builder appendFormat:@"builder.setKeypadMatrix(%ld, %ld);\n", (long)_numberOfRows, (long)_numberOfColumns];
        }
    }
    
    [self addFlt:builder
             key:@"KeypadHeightRatio"
           value:_keypadHeightRatio
         default:EMSecureInputBuilder_DEFAULT_KEYPAD_HEIGHT_RATIO
        platform:platform];
    
    if (_swapOkAndDeleteButton) {
        if (platform == EPlatform_iOS) {
            [builder appendFormat:@"[builder swapOkAndDeleteButton];\n"];
        } else {
            [builder appendFormat:@"builder.swapOkAndDeleteButton();\n"];
        }
    }
    
    if (platform == EPlatform_iOS) {
        if (_keys.length && _subscripts.count) {
            NSMutableString *subscripts = [NSMutableString new];
            for (NSString *subscript in _subscripts) {
                [subscripts appendFormat:@"@\"%@\", ", subscript];
            }
            // Remove last separator.
            [subscripts deleteCharactersInRange:NSMakeRange(subscripts.length - 2, 2)];
            
            [builder appendFormat:@"[builder setKeys:[@\"%@\" dataUsingEncoding:NSUTF16StringEncoding] andSubscripts:@[%@]];\n", _keys, subscripts];
        } else if (_keys.length) {
            [builder appendFormat:@"[builder setKeys:[@\"%@\" dataUsingEncoding:NSUTF16StringEncoding]];\n", _keys];
        }
    } else {
        if (_keys.length) {
            [self addStr:builder
                     key:@"Keys"
                   value:_keys
                 default:EMSecureInputBuilder_DEFAULT_KEYS
                platform:platform];
        }
        if (_subscripts.count) {
            NSMutableString *subscripts = [NSMutableString stringWithString:@"Arrays.asList("];
            for (NSString *subscript in _subscripts) {
                [subscripts appendFormat:@"\"%@\", ", subscript];
            }
            // Remove last separator.
            [subscripts deleteCharactersInRange:NSMakeRange(subscripts.length - 2, 2)];
            [builder appendFormat:@"builder.setSubscripts(%@));\n", subscripts];
        }
    }
    
    [self addStr:builder
             key:@"OkButtonText"
           value:_okButtonText
         default:EMSecureInputBuilder_DEFAULT_OK_BUTTON_NAME
        platform:platform];
    
    [self addStr:builder
             key:@"DeleteButtonText"
           value:_deleteButtonText
         default:EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_NAME
        platform:platform];
    
    [self addFlt:builder
             key:@"DistanceBetweenKeyAndSubscript"
           value:_distanceBetweenKeyAndSubscript
         default:.0f
        platform:platform];
    
    [self addInt:builder
             key:@"ButtonBorderWidth"
           value:_buttonBorderWidth
         default:EMSecureInputBuilder_DEFAULT_BUTTON_BORDER_WIDTH
        platform:platform];
    
    // Deprecated.
    //    if (_buttonBorderColor)
    //        [builder setButtonBorderColor:_buttonBorderColor];
    
    [self addClr:builder
          assets:assets
             key:@"KeypadFrameColor"
           value:_keypadFrameColor
         default:EMSecureInputBuilder_DEFAULT_KEYPAD_FRAME_COLOR
        platform:platform];
    
    if (_keypadGridGradientStartColor && _keypadGridGradientEndColor) {
        if (platform == EPlatform_iOS) {
            [builder appendFormat:@"[builder setKeypadGridGradientColors:%@ gridGradientEndColor:%@];\n",
             [self colorToString:_keypadGridGradientStartColor platform:platform name:nil],
             [self colorToString:_keypadGridGradientEndColor platform:platform name:nil]];
        } else {
            NSString *nameStart = @"skcKeypadGridGradientColorStart";
            NSString *nameEnd = @"skcKeypadGridGradientColorEnd";
            
            [builder appendFormat:@"builder.setKeypadGridGradientColors(context.getResources().getColor(R.color.%@), context.getResources().getColor(R.color.%@));\n", nameStart, nameEnd];
            [assets appendFormat:@"%@\n", [self colorToString:_keypadGridGradientStartColor platform:platform name:nameStart]];
            [assets appendFormat:@"%@\n", [self colorToString:_keypadGridGradientEndColor platform:platform name:nameEnd]];
        }
    }
    
    [self addBol:builder
             key:platform == EPlatform_iOS ? @"ButtonPressedVisibility" : @"ButtonPressVisibility"
           value:_buttonPressedVisibility
         default:EMSecureInputBuilder_DEFAULT_VISIBLE_BUTTON_PRESS
        platform:platform];
    
    if (_keyFontName && _keyFontSize != -1) {
        [self addFnt:builder
                 key:@"KeyFont"
               value:[UIFont fontWithName:_keyFontName size:_keyFontSize]
            platform:platform];
    }
    
    if (platform == EPlatform_iOS) {
        if (_subscriptFontName && _subscriptFontSize != -1) {
            [self addFnt:builder
                     key:@"SubscriptFont"
                   value:[UIFont fontWithName:_subscriptFontName size:_subscriptFontSize]
                platform:platform];
        }
    } else if (_subscriptFontSize != -1) {
        // Android does not have font. Just size.
        [self addInt:builder
                 key:@"SubscriptFontSize"
               value:_subscriptFontSize
             default:-1
            platform:platform];
    }
    
    if (_okButtonFontName && _okButtonFontSize != -1) {
        [self addFnt:builder
                 key:@"OkButtonFont"
               value:[UIFont fontWithName:_okButtonFontName size:_okButtonFontSize]
            platform:platform];
    }
    
    if (_deleteButtonFontName && _deleteButtonFontSize != -1) {
        [self addFnt:builder
                 key:@"DeleteButtonFont"
               value:[UIFont fontWithName:_deleteButtonFontName size:_deleteButtonFontSize]
            platform:platform];
    }
    
    [self addClr:builder
          assets:assets
             key:@"KeyColor"
           value:_keyColorForStateNormal
         default:EMSecureInputBuilder_DEFAULT_KEY_COLOR
        ctrState:EMSecureInputUiControlStateNormal
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"KeyColor"
           value:_keyColorForStateSelected
         default:EMSecureInputBuilder_DEFAULT_KEY_SELECTED_COLOR
        ctrState:EMSecureInputUiControlStateSelected
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"KeyColor"
           value:_keyColorForStateDisabled
         default:EMSecureInputBuilder_DEFAULT_KEY_DISABLED_COLOR
        ctrState:EMSecureInputUiControlStateDisabled
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"SubscriptColor"
           value:_subscriptColorForStateNormal
         default:nil
        ctrState:EMSecureInputUiControlStateNormal
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"SubscriptColor"
           value:_subscriptColorForStateSelected
         default:nil
        ctrState:EMSecureInputUiControlStateSelected
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"SubscriptColor"
           value:_subscriptColorForStateDisabled default:nil
        ctrState:EMSecureInputUiControlStateDisabled
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"OkButtonTextColor"
           value:_okButtonTextColorForStateNormal
         default:EMSecureInputBuilder_DEFAULT_OK_BUTTON_TEXT_COLOR
        ctrState:EMSecureInputUiControlStateNormal
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"OkButtonTextColor"
           value:_okButtonTextColorForStateSelected
         default:EMSecureInputBuilder_DEFAULT_OK_BUTTON_SELECTED_TEXT_COLOR
        ctrState:EMSecureInputUiControlStateSelected
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"OkButtonTextColor"
           value:_okButtonTextColorForStateDisabled
         default:EMSecureInputBuilder_DEFAULT_OK_BUTTON_DISABLED_TEXT_COLOR
        ctrState:EMSecureInputUiControlStateDisabled
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"DeleteButtonTextColor"
           value:_deleteButtonTextColorForStateNormal
         default:EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_TEXT_COLOR
        ctrState:EMSecureInputUiControlStateNormal
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"DeleteButtonTextColor"
           value:_deleteButtonTextColorForStateSelected
         default:EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_SELECTED_TEXT_COLOR
        ctrState:EMSecureInputUiControlStateSelected
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"DeleteButtonTextColor"
           value:_deleteButtonTextColorForStateDisabled
         default:EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_DISABLED_TEXT_COLOR
        ctrState:EMSecureInputUiControlStateDisabled
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"ButtonBackgroundColor"
           value:_buttonBackgroundColorForStateNormal
         default:EMSecureInputBuilder_DEFAULT_BUTTON_BACKGROUND_COLOR
        ctrState:EMSecureInputUiControlStateNormal
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"ButtonBackgroundColor"
           value:_buttonBackgroundColorForStateSelected
         default:EMSecureInputBuilder_DEFAULT_BUTTON_BACKGROUND_SELECTED_COLOR
        ctrState:EMSecureInputUiControlStateSelected
        platform:platform];
    
    [self addClr:builder
          assets:assets
             key:@"ButtonBackgroundColor"
           value:_buttonBackgroundColorForStateDisabled
         default:EMSecureInputBuilder_DEFAULT_BUTTON_BACKGROUND_DISABLED_COLOR
        ctrState:EMSecureInputUiControlStateDisabled
        platform:platform];
    
    [self addImg:builder
             key:@"ButtonBackgroundImage"
           value:_buttonBackgroundImage
         default:nil
        platform:platform];
    
    [self addFlt:builder
             key:@"ButtonBackgroundImageOpacity"
           value:_buttonBackgroundImageOpacityForStateNormal
         default:EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY
        ctrState:EMSecureInputUiControlStateNormal
        platform:platform];
    
    [self addFlt:builder
             key:@"ButtonBackgroundImageOpacity"
           value:_buttonBackgroundImageOpacityForStateSelected
         default:EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY
        ctrState:EMSecureInputUiControlStateSelected
        platform:platform];
    
    [self addFlt:builder
             key:@"ButtonBackgroundImageOpacity"
           value:_buttonBackgroundImageOpacityForStateDisabled
         default:EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY
        ctrState:EMSecureInputUiControlStateDisabled
        platform:platform];
    
    [self addImg:builder
             key:@"OkButtonImage"
           value:_okButtonImage
         default:nil
        platform:platform];
    
    [self addFlt:builder
             key:@"OkButtonImageOpacity"
           value:_okButtonImageOpacityForStateNormal
         default:EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY
        ctrState:EMSecureInputUiControlStateNormal
        platform:platform];
    
    [self addFlt:builder
             key:@"OkButtonImageOpacity"
           value:_okButtonImageOpacityForStateSelected
         default:EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY
        ctrState:EMSecureInputUiControlStateSelected
        platform:platform];
    
    [self addFlt:builder
             key:@"OkButtonImageOpacity"
           value:_okButtonImageOpacityForStateDisabled
         default:EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY
        ctrState:EMSecureInputUiControlStateDisabled
        platform:platform];
    
    [self addImg:builder
             key:@"DeleteButtonImage"
           value:_deleteButtonImage
         default:nil
        platform:platform];
    
    [self addFlt:builder
             key:@"DeleteButtonImageOpacity"
           value:_deleteButtonImageOpacityForStateNormal
         default:EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY
        ctrState:EMSecureInputUiControlStateNormal
        platform:platform];
    
    [self addFlt:builder
             key:@"DeleteButtonImageOpacity"
           value:_deleteButtonImageOpacityForStateSelected
         default:EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY
        ctrState:EMSecureInputUiControlStateSelected
        platform:platform];
    
    [self addFlt:builder
             key:@"DeleteButtonImageOpacity"
           value:_deleteButtonImageOpacityForStateDisabled
         default:EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY
        ctrState:EMSecureInputUiControlStateDisabled
        platform:platform];
    
    [self addGrd:builder
          assets:assets
             key:platform == EPlatform_iOS ? @"ButtonGradientColors" : @"ButtonGradientColor"
           start:_buttonGradientColorStartForStateNormal
             end:_buttonGradientColorEndForStateNormal
        ctrState:EMSecureInputUiControlStateNormal platform:platform];
    
    [self addGrd:builder
          assets:assets
             key:platform == EPlatform_iOS ? @"ButtonGradientColors" : @"ButtonGradientColor"
           start:_buttonGradientColorStartForStateSelected
             end:_buttonGradientColorEndForStateSelected
        ctrState:EMSecureInputUiControlStateSelected platform:platform];
    
    [self addGrd:builder
          assets:assets
             key:platform == EPlatform_iOS ? @"ButtonGradientColors" : @"ButtonGradientColor"
           start:_buttonGradientColorStartForStateDisabled
             end:_buttonGradientColorEndForStateDisabled
        ctrState:EMSecureInputUiControlStateDisabled platform:platform];
    
    [self addGrd:builder
          assets:assets
             key:platform == EPlatform_iOS ? @"OkButtonGradientColors" : @"OkButtonGradientColor"
           start:_okButtonGradientColorStartForStateNormal
             end:_okButtonGradientColorEndForStateNormal
        ctrState:EMSecureInputUiControlStateNormal platform:platform];
    
    [self addGrd:builder
          assets:assets
             key:platform == EPlatform_iOS ? @"OkButtonGradientColors" : @"OkButtonGradientColor"
           start:_okButtonGradientColorStartForStateSelected
             end:_okButtonGradientColorEndForStateSelected
        ctrState:EMSecureInputUiControlStateSelected platform:platform];
    
    [self addGrd:builder
          assets:assets
             key:platform == EPlatform_iOS ? @"OkButtonGradientColors" : @"OkButtonGradientColor"
           start:_okButtonGradientColorStartForStateDisabled
             end:_okButtonGradientColorEndForStateDisabled
        ctrState:EMSecureInputUiControlStateDisabled platform:platform];
    
    [self addGrd:builder
          assets:assets
             key:platform == EPlatform_iOS ? @"DeleteButtonGradientColors" : @"DeleteButtonGradientColor"
           start:_deleteButtonGradientColorStartForStateNormal
             end:_deleteButtonGradientColorEndForStateNormal
        ctrState:EMSecureInputUiControlStateNormal platform:platform];
    
    [self addGrd:builder
          assets:assets
             key:platform == EPlatform_iOS ? @"DeleteButtonGradientColors" : @"DeleteButtonGradientColor"
           start:_deleteButtonGradientColorStartForStateSelected
             end:_deleteButtonGradientColorEndForStateSelected
        ctrState:EMSecureInputUiControlStateSelected platform:platform];
    
    [self addGrd:builder
          assets:assets
             key:platform == EPlatform_iOS ? @"DeleteButtonGradientColors" : @"DeleteButtonGradientColor"
           start:_deleteButtonGradientColorStartForStateDisabled
             end:_deleteButtonGradientColorEndForStateDisabled
        ctrState:EMSecureInputUiControlStateDisabled platform:platform];
    
    [self addBol:builder
             key:@"IsDeleteButtonAlwaysEnabled"
           value:_isDeleteButtonAlwaysEnabled
         default:NO
        platform:platform];
    
    if (platform == EPlatform_iOS) {
        [builder appendFormat:@"\n// Build keypad and add handler.\nid<EMSecureInputUi> secureInput =\n[builder buildWithScrambling:%@\n          isDoubleInputField:%@\n                 displayMode:EMSecureInputUiDisplayModeFullScreen\n               onFinishBlock:^(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin) {\n\n              // Wipe pinpad builder for security purpose.\n              // This part is also important because of builder life cycle, otherwise this block will never be triggered!\n              [builder wipe];\n          }];", _scrambled ? @"YES" : @"NO", _isDoubleInput ? @"YES" : @"NO"];
    } else {
        [builder appendFormat:
        @"final SecureInputUi secureInputUi = builder.buildKeypad(%@, %@, true, new SecureKeypadListener() {\n\
            @Override\n\
            public void onKeyPressedCountChanged(final int count, final int inputField) {\n\
                // Handle on key pressed.\n\
            }\n\
            \n\
            @Override\n\
            public void onInputFieldSelected(final int inputField) {\n\
                // Handle on input field selected.\n\
            }\n\
            \n\
            @Override\n\
            public void onOkButtonPressed() {\n\
                // Handle on Button pressed.\n\
            }\n\
            \n\
            @Override\n\
            public void onDeleteButtonPressed() {\n\
                // Handle on delete button pressed.\n\
            }\n\
            \n\
            @Override\n\
            public void onFinish(final PinAuthInput pinAuthInput, final PinAuthInput pinAuthInput1) {\n\
                builder.wipe();\n\
            }\n\
            \n\
            @Override\n\
            public void onError(final String errorMessage) {\n\
                builder.wipe();\n\
            }\n\
        });\n\
         ", _scrambled ? @"true" : @"false", _isDoubleInput ? @"true" : @"false"];
    }
        
    // Append android assets if there are any.
    if (assets.length) {
        [builder appendFormat:@"\n\nASSETS:\n%@", assets];
    }
    
    NSLog(@"%@", builder);
    
}

@end
