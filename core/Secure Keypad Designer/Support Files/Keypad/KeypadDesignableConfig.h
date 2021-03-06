
@interface KeypadDesignableConfig : NSObject
@property (nonatomic, assign)   BOOL                            scrambled;
@property (nonatomic, assign)   BOOL                            isDoubleInput;
@property (nonatomic, copy)     NSString                        *firstLabel;
@property (nonatomic, copy)     NSString                        *secondLabel;
@property (nonatomic, strong)   UIColor                         *screenBackgroundColor;
@property (nonatomic, strong)   UIImage                         *screenBackgroundImage;
@property (nonatomic, assign)   EMSecureInputUiBackgroundImageContentMode screenBackgroundImageContentMode;
@property (nonatomic, strong)   UIColor                         *labelColor;
@property (nonatomic, assign)   CGFloat                         labelFontSize;
@property (nonatomic, assign)   EMSecureInputUiLabelAlignment   labelAlignment;
@property (nonatomic, assign)   CGFloat                         inputFieldFontSize;
@property (nonatomic, strong)   UIColor                         *inputFieldBorderColorForStateFocused;
@property (nonatomic, strong)   UIColor                         *inputFieldBorderColorForStateUnFocused;
@property (nonatomic, strong)   UIColor                         *inputFieldBackgroundColorForStateFocused;
@property (nonatomic, strong)   UIColor                         *inputFieldBackgroundColorForStateUnocused;
@property (nonatomic, assign)   NSInteger                       minimumInputLength;
@property (nonatomic, assign)   NSInteger                       maximumInputLength;
@property (nonatomic, assign)   NSInteger                       numberOfRows;
@property (nonatomic, assign)   NSInteger                       numberOfColumns;
@property (nonatomic, assign)   CGFloat                         keypadHeightRatio;
@property (nonatomic, assign)   BOOL                            swapOkAndDeleteButton;
@property (nonatomic, copy)     NSString                        *keys;
@property (nonatomic, copy)     NSArray                         *subscripts;
@property (nonatomic, copy)     NSString                        *okButtonText;
@property (nonatomic, copy)     NSString                        *deleteButtonText;
@property (nonatomic, assign)   CGFloat                         distanceBetweenKeyAndSubscript;
@property (nonatomic, assign)   NSInteger                       buttonBorderWidth;
//@property (nonatomic, strong)   UIColor                         *buttonBorderColor;
@property (nonatomic, strong)   UIColor                         *keypadFrameColor;
@property (nonatomic, strong)   UIColor                         *keypadGridGradientStartColor;
@property (nonatomic, strong)   UIColor                         *keypadGridGradientEndColor;
@property (nonatomic, assign)   BOOL                            buttonPressedVisibility;
@property (nonatomic, strong)   NSString                        *keyFontName;
@property (nonatomic, assign)   NSInteger                       keyFontSize;
@property (nonatomic, strong)   NSString                        *subscriptFontName;
@property (nonatomic, assign)   NSInteger                       subscriptFontSize;
@property (nonatomic, strong)   NSString                        *okButtonFontName;
@property (nonatomic, assign)   NSInteger                       okButtonFontSize;
@property (nonatomic, strong)   NSString                        *deleteButtonFontName;
@property (nonatomic, assign)   NSInteger                       deleteButtonFontSize;
@property (nonatomic, strong)   UIColor                         *keyColorForStateNormal;
@property (nonatomic, strong)   UIColor                         *keyColorForStateSelected;
@property (nonatomic, strong)   UIColor                         *keyColorForStateDisabled;
@property (nonatomic, strong)   UIColor                         *subscriptColorForStateNormal;
@property (nonatomic, strong)   UIColor                         *subscriptColorForStateSelected;
@property (nonatomic, strong)   UIColor                         *subscriptColorForStateDisabled;
@property (nonatomic, strong)   UIColor                         *okButtonTextColorForStateNormal;
@property (nonatomic, strong)   UIColor                         *okButtonTextColorForStateSelected;
@property (nonatomic, strong)   UIColor                         *okButtonTextColorForStateDisabled;
@property (nonatomic, strong)   UIColor                         *deleteButtonTextColorForStateNormal;
@property (nonatomic, strong)   UIColor                         *deleteButtonTextColorForStateSelected;
@property (nonatomic, strong)   UIColor                         *deleteButtonTextColorForStateDisabled;
@property (nonatomic, strong)   UIColor                         *buttonBackgroundColorForStateNormal;
@property (nonatomic, strong)   UIColor                         *buttonBackgroundColorForStateSelected;
@property (nonatomic, strong)   UIColor                         *buttonBackgroundColorForStateDisabled;
@property (nonatomic, strong)   UIImage                         *buttonBackgroundImage;
@property (nonatomic, assign)   CGFloat                         buttonBackgroundImageOpacityForStateNormal;
@property (nonatomic, assign)   CGFloat                         buttonBackgroundImageOpacityForStateSelected;
@property (nonatomic, assign)   CGFloat                         buttonBackgroundImageOpacityForStateDisabled;
@property (nonatomic, strong)   UIImage                         *okButtonImage;
@property (nonatomic, assign)   CGFloat                         okButtonImageOpacityForStateNormal;
@property (nonatomic, assign)   CGFloat                         okButtonImageOpacityForStateSelected;
@property (nonatomic, assign)   CGFloat                         okButtonImageOpacityForStateDisabled;
@property (nonatomic, strong)   UIImage                         *deleteButtonImage;
@property (nonatomic, assign)   CGFloat                         deleteButtonImageOpacityForStateNormal;
@property (nonatomic, assign)   CGFloat                         deleteButtonImageOpacityForStateSelected;
@property (nonatomic, assign)   CGFloat                         deleteButtonImageOpacityForStateDisabled;
@property (nonatomic, strong)   UIColor                         *buttonGradientColorStartForStateNormal;
@property (nonatomic, strong)   UIColor                         *buttonGradientColorStartForStateSelected;
@property (nonatomic, strong)   UIColor                         *buttonGradientColorStartForStateDisabled;
@property (nonatomic, strong)   UIColor                         *buttonGradientColorEndForStateNormal;
@property (nonatomic, strong)   UIColor                         *buttonGradientColorEndForStateSelected;
@property (nonatomic, strong)   UIColor                         *buttonGradientColorEndForStateDisabled;
@property (nonatomic, strong)   UIColor                         *okButtonGradientColorStartForStateNormal;
@property (nonatomic, strong)   UIColor                         *okButtonGradientColorStartForStateSelected;
@property (nonatomic, strong)   UIColor                         *okButtonGradientColorStartForStateDisabled;
@property (nonatomic, strong)   UIColor                         *okButtonGradientColorEndForStateNormal;
@property (nonatomic, strong)   UIColor                         *okButtonGradientColorEndForStateSelected;
@property (nonatomic, strong)   UIColor                         *okButtonGradientColorEndForStateDisabled;
@property (nonatomic, strong)   UIColor                         *deleteButtonGradientColorStartForStateNormal;
@property (nonatomic, strong)   UIColor                         *deleteButtonGradientColorStartForStateSelected;
@property (nonatomic, strong)   UIColor                         *deleteButtonGradientColorStartForStateDisabled;
@property (nonatomic, strong)   UIColor                         *deleteButtonGradientColorEndForStateNormal;
@property (nonatomic, strong)   UIColor                         *deleteButtonGradientColorEndForStateSelected;
@property (nonatomic, strong)   UIColor                         *deleteButtonGradientColorEndForStateDisabled;
@property (nonatomic, assign)   BOOL                            isDeleteButtonAlwaysEnabled;

- (void)printConfiguration;

@end
