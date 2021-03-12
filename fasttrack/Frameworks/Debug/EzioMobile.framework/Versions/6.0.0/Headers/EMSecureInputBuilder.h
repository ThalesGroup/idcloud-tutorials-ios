/** -----------------------------------------------------------------------------
 
 Copyright (c) 2017  -  GEMALTO DEVELOPMENT - R&D
 
 -----------------------------------------------------------------------------
 GEMALTO MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF
 THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 PARTICULAR PURPOSE, OR NON-INFRINGEMENT. GEMALTO SHALL NOT BE
 LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
 MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
 
 THIS SOFTWARE IS NOT DESIGNED OR INTENDED FOR USE OR RESALE AS ON-LINE
 CONTROL EQUIPMENT IN HAZARDOUS ENVIRONMENTS REQUIRING FAIL-SAFE
 PERFORMANCE, SUCH AS IN THE OPERATION OF NUCLEAR FACILITIES, AIRCRAFT
 NAVIGATION OR COMMUNICATION SYSTEMS, AIR TRAFFIC CONTROL, DIRECT LIFE
 SUPPORT MACHINES, OR WEAPONS SYSTEMS, IN WHICH THE FAILURE OF THE
 SOFTWARE COULD LEAD DIRECTLY TO DEATH, PERSONAL INJURY, OR SEVERE
 PHYSICAL OR ENVIRONMENTAL DAMAGE ("HIGH RISK ACTIVITIES"). GEMALTO
 SPECIFICALLY DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTY OF FITNESS FOR
 HIGH RISK ACTIVITIES.
 
 -----------------------------------------------------------------------------
 */

#import <UIKit/UIKit.h>
#import "EMUIUtil.h"

@protocol EMPinAuthInput;
@protocol EMSecureInputUi;

// because appledoc does not support constants, all constants have been commented out
// in the comment block of an enumeration. Cross ref to this file has been added
// in EMSecureInputBuilder class.

/**
 Secure Input Builder v2 constants
 
 Callback blocks that need to be passed along as EMPinAuthInput objects when creating a new secure input UI to receive events (Please take note that the clear text of passwords are not able to be extracted from EMPinAuthInput objects):
 
     typedef void (^EMSecureInputUiOnFinish)(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin);

 Callback blocks that need to be passed along as NSData objects when creating a new secure input UI to receive events (Please take note that the data encoding is NSUTF16StringEncoding):
 
     typedef void (^EMSecureInputUiOnFinishClearText)(NSData *firstPin, NSData *secondPin);

 Default show navigation bar:
 
     #define EMSecureInputBuilder_DEFAULT_SHOW_NAVIGATION_BAR               NO

 Default keys:
 
     #define EMSecureInputBuilder_DEFAULT_KEYS                              @"1234567890"
 
 Default button border width:
 
     #define EMSecureInputBuilder_DEFAULT_BUTTON_BORDER_WIDTH               1

 Default button border color:
 
     #define EMSecureInputBuilder_DEFAULT_BUTTON_BORDER_COLOR               EMUIColorFromRGBA(0xFFFFFFFF)

 Default keypad frame color and default keypad gradient start and end colors:
 
     #define EMSecureInputBuilder_DEFAULT_KEYPAD_FRAME_COLOR                EMUIColorFromRGBA(0x000000FF)

 Default number of columns:
 
     #define EMSecureInputBuilder_DEFAULT_NO_OF_COLUMNS                     3
 
 Default number of rows:
 
     #define EMSecureInputBuilder_DEFAULT_NO_OF_ROWS                        4
 
 Default screen background color:
 
     #define EMSecureInputBuilder_DEFAULT_SCREEN_BACKGROUND_COLOR           EMUIColorFromRGBA(0xFFFFFFFF)
 
 Default logo bar background color:

     #define EMSecureInputBuilder_DEFAULT_LOGO_BAR_BACKGROUND_COLOR         EMUIColorFromRGBA(0xFFFFFFFF)

 Default logo position:

     #define EMSecureInputBuilder_DEFAULT_LOGO_POSITION                     EMSecureInputUiLogoPositionCenter

 Default color:
 
     #define EMSecureInputBuilder_DEFAULT_KEY_COLOR                         EMUIColorFromRGBA(0x1b346cFF)
     #define EMSecureInputBuilder_DEFAULT_KEY_SELECTED_COLOR                EMUIColorFromRGBA(0x1b346cFF)
     #define EMSecureInputBuilder_DEFAULT_KEY_DISABLED_COLOR                EMUIColorFromRGBA(0x1b346cFF)
     #define EMSecureInputBuilder_DEFAULT_BUTTON_BACKGROUND_COLOR           EMUIColorFromRGBA(0xFFFFFFFF)
     #define EMSecureInputBuilder_DEFAULT_BUTTON_BACKGROUND_SELECTED_COLOR  EMUIColorFromRGBA(0x1b346c3F)
     #define EMSecureInputBuilder_DEFAULT_BUTTON_BACKGROUND_DISABLED_COLOR  EMUIColorFromRGBA(0xFFFFFFFF)
     #define EMSecureInputBuilder_DEFAULT_OK_BUTTON_TEXT_COLOR              EMUIColorFromRGBA(0x48a948ff)
     #define EMSecureInputBuilder_DEFAULT_OK_BUTTON_SELECTED_TEXT_COLOR     EMUIColorFromRGBA(0x48a948ff)
     #define EMSecureInputBuilder_DEFAULT_OK_BUTTON_DISABLED_TEXT_COLOR     EMUIColorFromRGBA(0xcccccc3f)
     #define EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_TEXT_COLOR          EMUIColorFromRGBA(0xdf0832ff)
     #define EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_SELECTED_TEXT_COLOR EMUIColorFromRGBA(0xdf0832ff)
     #define EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_DISABLED_TEXT_COLOR EMUIColorFromRGBA(0xcccccc3f)
     #define EMSecureInputBuilder_DEFAULT_SHIFT_BUTTON_TEXT_COLOR            EMUIColorFromRGBA(0x48a948ff)
     #define EMSecureInputBuilder_DEFAULT_SHIFT_BUTTON_SELECTED_TEXT_COLOR   EMUIColorFromRGBA(0x48a948ff)

 Default visible button press:

     // Note: For security reason, it's disabled by default. User won't be able to see
     // the selected state when the button is pressed.
     #define EMSecureInputBuilder_DEFAULT_VISIBLE_BUTTON_PRESS              NO

 Default display text:
 
     #define EMSecureInputBuilder_DEFAULT_FIRST_LABEL                       @"Enter PIN"
     #define EMSecureInputBuilder_DEFAULT_SECOND_LABEL                      @"Confirm PIN"

 Default display color:

     #define EMSecureInputBuilder_DEFAULT_LABEL_COLOR                       EMUIColorFromRGBA(0x1b346cFF)

 Default label font size:

     #define EMSecureInputBuilder_DEFAULT_LABEL_FONT_SIZE                   20

 Default label alignment:

     #define EMSecureInputBuilder_DEFAULT_LABEL_ALIGNMENT                   EMSecureInputUiLabelAlignmentCenter

 Default input field font size:
     #define EMSecureInputBuilder_DEFAULT_INPUT_FIELD_FONT_SIZE             20

 Default input length:
 
     #define EMSecureInputBuilder_DEFAULT_MINIMUM_INPUT_LENGTH              4
     #define EMSecureInputBuilder_DEFAULT_MAXIMUM_INPUT_LENGTH              8
 
 Default keypad height ratio:

     #define EMSecureInputBuilder_DEFAULT_KEYPAD_HEIGHT_RATIO               0.5

 Default OK button behavior:
 
     #define EMSecureInputBuilder_DEFAULT_OK_BUTTON_BEHAVIOR                EMSecureInputUiOkButtonAutomaticallyEnabled
 
 Default button image opacity:

     #define EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY              1.0

 Default input field background and border color (focus and unfocus):
 
     #define EMSecureInputBuilder_DEFAULT_INPUT_FIELD_BACKGROUND_FOCUS_COLOR EMUIColorFromRGBA(0x1b346c7f)
     #define EMSecureInputBuilder_DEFAULT_INPUT_FIELD_BACKGROUND_UNFOCUS_COLOR EMUIColorFromRGBA(0x1b346c3F)

     #define EMSecureInputBuilder_DEFAULT_INPUT_FIELD_FOCUS_COLOR           EMUIColorFromRGBA(0x1b346c8F)
     #define EMSecureInputBuilder_DEFAULT_INPUT_FIELD_UNFOCUS_COLOR         EMUIColorFromRGBA(0x1b346c3F)
 
 Default font for key button, OK button and Delete button:
 
     #define EMSecureInputBuilder_DEFAULT_BUTTON_FONT_NAME                  @"ArialMT"
     #define EMSecureInputBuilder_DEFAULT_BUTTON_FONT_SIZE                  24
 
 Default OK button name:
 
     #define EMSecureInputBuilder_DEFAULT_OK_BUTTON_NAME                    @"OK"

 Default Delete button name:
 
     #define EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_NAME                @" ⌫ "
 
 Default Shift button name:
 
     #define EMSecureInputBuilder_DEFAULT_SHIFT_BUTTON_NAME                @" ⇧ "

 Default Back button name:
 
     #define EMSecureInputBuilder_DEFAULT_BACK_BUTTON_NAME                  @"Back"

 Default Delete button enable:
 
     #define EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_ALWAYS_ENABLE       NO

 - Since: 4.4
 */
typedef NS_ENUM(NSInteger, EMSecureInputBuilderDefaultConfigurations) {
    /// Dummy enumeration declaration to include the constants for API doc.
    EMSecureInputBuilder_DEFAULT = 0
};

/**
 Secure input UI logo position.
 It determines the drawing position of the logo image.

 - Since: 4.4
 */
typedef NS_ENUM(NSInteger, EMSecureInputUiLogoPosition) {
    /**
     * Left position.
     */
    EMSecureInputUiLogoPositionLeft = 0,
    
    /**
     * Center position.
     */
    EMSecureInputUiLogoPositionCenter = 1,
    
    /**
     * Right position.
     */
    EMSecureInputUiLogoPositionRight = 2
};

/**
Secure input background image content mode

- Since: 6.0
*/
typedef NS_ENUM(NSInteger, EMSecureInputUiBackgroundImageContentMode) {
    /**
     * Center the image.
     */
    EMSecureInputUiBackgroundImageContentModeCenter = 0,
  
    /**
     * Stretch the image.
     */
    EMSecureInputUiBackgroundImageContentModeStretch = 1,
  
    /**
     * Tile the image.
     */
    EMSecureInputUiBackgroundImageContentModeTile = 2
};

/**
 Secure input UI label alignment.
 It determines the alignment of both first and second label.

 - Since: 4.4
 */
typedef NS_ENUM(NSInteger, EMSecureInputUiLabelAlignment) {
    /**
     * Left alignment.
     */
    EMSecureInputUiLabelAlignmentLeft = 0,

    /**
     * Center alignment.
     */
    EMSecureInputUiLabelAlignmentCenter = 1,

    /**
     * Right alignment.
     */
    EMSecureInputUiLabelAlignmentRight = 2
};

/**
 Secure input UI control focus state.
 It determines the focus state of both first and second input field.

 - Since: 4.4
 */
typedef NS_ENUM(NSInteger, EMSecureInputUiControlFocusState) {
    /**
     * Focus state of the secure input UI control.
     */
    EMSecureInputUiControlFocused = 0,
    
    /**
     * Unfocus state of the secure input UI control.
     */
    EMSecureInputUiControlUnfocused = 1
};

/**
 Secure input UI control state.
 It determines the state of all the buttons on the keypad.

 - Since: 4.4
 */
typedef NS_ENUM(NSInteger, EMSecureInputUiControlState) {
    /**
     * Normal state of the secure input UI control.
     */
    EMSecureInputUiControlStateNormal = 0,

    /**
     * Selected state of the secure input UI control.
     */
    EMSecureInputUiControlStateSelected = 1,

    /**
     * Disabled state of the secure input UI control.
     */
    EMSecureInputUiControlStateDisabled = 2
};

/**
 Secure Input UI OK button behavior.

 - Since: 4.4
 */
typedef NS_ENUM(NSInteger, EMSecureInputUiOkButtonBehavior) {
    /**
     * OK button is not visible on screen.<p>
     * OK button is automatically triggered when the input length reaches minimum/maximum input length.<p>
     * Runtime exception is thrown if the minimum input length does not equal to maximum input length.
     */
    EMSecureInputUiOkButtonNone = 0,

    /**
     * OK button is visible on screen. OK button is grayed out (disabled state) by default.<p>
     * OK button is automatically enabled (normal state) when the input length reaches minimum input length.
     */
    EMSecureInputUiOkButtonAutomaticallyEnabled = 1,

    /**
     * OK button is always visible on screen.<p>
     * User have to manually trigger the OK button.
     */
    EMSecureInputUiOkButtonAlwaysEnabled = 2,

    /**
     * OK button is always visible on screen.<p>
     * OK button is automatically triggered when the input length reaches minimum/maximum input length.
     * To override the OK button behavior, do set the [EMSecureInputUi customUiDelegate] and
     * handle the [EMSecureInputCustomUiDelegate secureInputUiOkButtonPressed:] callback respectively.<p>
     * Runtime exception is thrown if the minimum input length does not equal to maximum input length.
     */
    EMSecureInputUiOkButtonCustom = 3,
    
    /**
     * OK button does not exist.<p>
     * No automatic simulation of OK button is done.
     * Ok button is never automatically simulated, everything needs to be done programmatically
     * both in single input and double input mode.
     */
    EMSecureInputUiOkButtonNoneDisabled = 4
};

/**
 The visual effect to button touches.
 
 - Since: 5.0
 */

typedef NS_ENUM(NSInteger, EMButtonTouchVisualEffect)
{
    /** Button touch visual effect as highlight */
    EMButtonTouchVisualEffectHighlight,
    
    /** Button touch visual effect as ripple */
    EMButtonTouchVisualEffectRipple
};

/**
 Secure input UI display mode.
 
 - Since: 6.0
 */
typedef NS_ENUM(NSInteger, EMSecureInputUiDisplayMode)
{
    /** Full screen mode */
    EMSecureInputUiDisplayModeFullScreen = 0,
    
    /** Dialog mode */
    EMSecureInputUiDisplayModeDialog = 1,

    /** Embedded mode */
    EMSecureInputUiDisplayModeEmbedded = 2
};

/**
 <p>This callback method will return first and second PIN</p>
 <p>And please take note that the clear text of passwords are not able to be extracted from EMPinAuthInput objects in callback.</p>
 <ul>
 <li>'firstPin' The first (default) PIN that user entered. In the single-entry mode, this is the only variable that would be returned.</li>
 <li>'secondPin' In the double-entry mode, this second PIN is returned along with the first PIN. Note that there is NO guarantee that the two PINs entered are the same.</li>
 </ul>

 - Since: 4.4
 */
typedef void (^EMSecureInputUiOnFinish)(id<EMPinAuthInput> firstPin, id<EMPinAuthInput> secondPin);

/**
 <p>This callback method will return first and second input</p>
 <p>And please take note that the return value of this callback are in clear text.</p>
 <ul>
 <li>'firstInput' The first input that user entered. In the single-entry mode, this is the only variable that would be returned.</li>
 <li>'secondInput' In the double-entry mode, this second input is returned along with the first input. Note that there is NO guarantee that the two inputs entered are the same.</li>
 </ul>

 - Since: 6.0
 */
typedef void (^EMSecureInputUiOnFinishClearText)(NSData *firstInput, NSData *secondInput);

#define EMSecureInputBuilder_DEFAULT_SHOW_NAVIGATION_BAR                NO
#define EMSecureInputBuilder_DEFAULT_BUTTON_BORDER_WIDTH                1
#define EMSecureInputBuilder_DEFAULT_BUTTON_BORDER_COLOR                EMUIColorFromRGBA(0xFFFFFFFF)
#define EMSecureInputBuilder_DEFAULT_KEYPAD_FRAME_COLOR                 EMUIColorFromRGBA(0x000000FF)
#define EMSecureInputBuilder_DEFAULT_NO_OF_COLUMNS                      3
#define EMSecureInputBuilder_DEFAULT_NO_OF_ROWS                         4
#define EMSecureInputBuilder_DEFAULT_SCREEN_BACKGROUND_COLOR            EMUIColorFromRGBA(0xFFFFFFFF)
#define EMSecureInputBuilder_DEFAULT_LOGO_BAR_BACKGROUND_COLOR          EMUIColorFromRGBA(0xFFFFFFFF)
#define EMSecureInputBuilder_DEFAULT_LOGO_POSITION                      EMSecureInputUiLogoPositionCenter
#define EMSecureInputBuilder_DEFAULT_KEY_COLOR                          EMUIColorFromRGBA(0x1b346cFF)
#define EMSecureInputBuilder_DEFAULT_KEY_SELECTED_COLOR                 EMUIColorFromRGBA(0x1b346cFF)
#define EMSecureInputBuilder_DEFAULT_KEY_DISABLED_COLOR                 EMUIColorFromRGBA(0x1b346cFF)
#define EMSecureInputBuilder_DEFAULT_BUTTON_BACKGROUND_COLOR            EMUIColorFromRGBA(0xFFFFFFFF)
#define EMSecureInputBuilder_DEFAULT_BUTTON_BACKGROUND_SELECTED_COLOR   EMUIColorFromRGBA(0x1b346c3F)
#define EMSecureInputBuilder_DEFAULT_BUTTON_BACKGROUND_DISABLED_COLOR   EMUIColorFromRGBA(0xFFFFFFFF)
#define EMSecureInputBuilder_DEFAULT_OK_BUTTON_TEXT_COLOR               EMUIColorFromRGBA(0x48a948ff)
#define EMSecureInputBuilder_DEFAULT_OK_BUTTON_SELECTED_TEXT_COLOR      EMUIColorFromRGBA(0x48a948ff)
#define EMSecureInputBuilder_DEFAULT_OK_BUTTON_DISABLED_TEXT_COLOR      EMUIColorFromRGBA(0xcccccc3f)
#define EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_TEXT_COLOR           EMUIColorFromRGBA(0xdf0832ff)
#define EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_SELECTED_TEXT_COLOR  EMUIColorFromRGBA(0xdf0832ff)
#define EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_DISABLED_TEXT_COLOR  EMUIColorFromRGBA(0xcccccc3f)
#define EMSecureInputBuilder_DEFAULT_SHIFT_BUTTON_TEXT_COLOR            EMUIColorFromRGBA(0x48a948ff)
#define EMSecureInputBuilder_DEFAULT_SHIFT_BUTTON_SELECTED_TEXT_COLOR   EMUIColorFromRGBA(0x48a948ff)
#define EMSecureInputBuilder_DEFAULT_VISIBLE_BUTTON_PRESS               NO
#define EMSecureInputBuilder_DEFAULT_LABEL_COLOR                        EMUIColorFromRGBA(0x1b346cFF)
#define EMSecureInputBuilder_DEFAULT_LABEL_FONT_SIZE                    20
#define EMSecureInputBuilder_DEFAULT_LABEL_ALIGNMENT                    EMSecureInputUiLabelAlignmentCenter
#define EMSecureInputBuilder_DEFAULT_INPUT_FIELD_FONT_SIZE              18
#define EMSecureInputBuilder_DEFAULT_MINIMUM_INPUT_LENGTH               4
#define EMSecureInputBuilder_DEFAULT_MAXIMUM_INPUT_LENGTH               8
#define EMSecureInputBuilder_DEFAULT_KEYPAD_HEIGHT_RATIO                0.5
#define EMSecureInputBuilder_DEFAULT_OK_BUTTON_BEHAVIOR                 EMSecureInputUiOkButtonAutomaticallyEnabled
#define EMSecureInputBuilder_DEFAULT_BUTTON_IMAGE_OPACITY               1.0
#define EMSecureInputBuilder_DEFAULT_INPUT_FIELD_BACKGROUND_FOCUS_COLOR EMUIColorFromRGBA(0x1b346c7f)
#define EMSecureInputBuilder_DEFAULT_INPUT_FIELD_BACKGROUND_UNFOCUS_COLOR EMUIColorFromRGBA(0x1b346c3F)
#define EMSecureInputBuilder_DEFAULT_INPUT_FIELD_FOCUS_COLOR            EMUIColorFromRGBA(0x1b346c8F)
#define EMSecureInputBuilder_DEFAULT_INPUT_FIELD_UNFOCUS_COLOR          EMUIColorFromRGBA(0x1b346c3F)
#define EMSecureInputBuilder_DEFAULT_BUTTON_FONT_SIZE                   24
#define EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_ALWAYS_ENABLE        NO

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wstrict-prototypes"

///
extern NSString * EMSecureInputBuilder_DEFAULT_KEYS;
///
extern NSString * EMSecureInputBuilder_DEFAULT_FIRST_LABEL;
///
extern NSString * EMSecureInputBuilder_DEFAULT_SECOND_LABEL;
///
extern NSString * EMSecureInputBuilder_DEFAULT_BUTTON_FONT_NAME;
///
extern NSString * EMSecureInputBuilder_DEFAULT_OK_BUTTON_NAME;
///
extern NSString * EMSecureInputBuilder_DEFAULT_DELETE_BUTTON_NAME;
/// - Since: 6.0
extern NSString * EMSecureInputBuilder_DEFAULT_SHIFT_BUTTON_NAME;
///
extern NSString * EMSecureInputBuilder_DEFAULT_BACK_BUTTON_NAME;

#pragma clang diagnostic pop

/**
 The input builder v2 class that enables to build a secure input UI (secure keypad). <p>
 The secure input UI does not use the native UIKit keypad component but rather draws itself based on the configuration provided. <p>
 It supports the build of the secure input UI in both full screen and dialog mode, single or double entry UI. It also provides the flexibility for the application maker to fully customize the top screen UI or even override the custom OK button behavior. <p>
 The output of the secure keypad could be EMPinAuthInput or NSData. The integrator shall decide on which API to use depends on the application use case. <p>
 - Since: 4.4
 */
@protocol EMSecureInputBuilder <NSObject>

/**
 @brief Creates a secure input UI. The result of this API could be used directly to perform all OATH related operation e.g. generate OTP. <p>
 @warning This method should be called once all the necessary configurations have been done. Note that the default configuration will be applied for attributes that have not been set to custom values. The keys and shift keys (optional) shall be in alpha numeric format.
 @param isScrambling Indicates if the keypad would have a scrambled key locations. The scrambling is completely random and different for each time the keypad is shown.
 @param isDoubleInputField Indicates if the keypad would have two input fields to enter the key. This is useful in case of using the keypad for a new password and its confirmation. It's important to be aware that the keypad itself will NOT perform any comparison of the two key. The application developer can use method [EMSecureContainer isEqual:] for an equality confirmation.
 @param displayMode Indicates the keypad display mode (fullscreen, dialog or embedded).
 @param keyEnteredBlock Callback on finish. Depends on the OK button behavior settings, the finish callback could be triggered by the user or system. For double entry mode, trigger the OK button will trigger the callback only if both input field key count hit the minimum input length.
 @see EMSecureInputBuilderDefaultConfigurations for the default configurations of the keypad.
 @see EMSecureInputUiOkButtonBehavior
 @return The secure input UI. The secure input UI view controller can be fed into a navigation controller or presented as a modal view controller in the current view.
 @exception NSInvalidArgumentException The exception when the improper configuration is set
 - Since: 6.0
 */
- (id<EMSecureInputUi>)buildWithScrambling:(BOOL)isScrambling isDoubleInputField:(BOOL)isDoubleInputField displayMode:(EMSecureInputUiDisplayMode)displayMode onFinishBlock:(EMSecureInputUiOnFinish)keyEnteredBlock;

/**
 @brief Creates a secure input UI. The result of this API is raw data and could be used as a PIN/password for the application. <p>
 @warning This method should be called once all the necessary configurations have been done. Note that the default configuration will be applied for attributes that have not been set to custom values.
 @param isScrambling Indicates if the keypad would have a scrambled key locations. The scrambling is completely random and different for each time the keypad is shown.
 @param isDoubleInputField Indicates if the keypad would have two input fields to enter the key. This is useful in case of using the keypad for a new password and its confirmation. It's important to be aware that the keypad itself will NOT perform any comparison of the two key. The application developer can use method [EMSecureContainer isEqual:] for an equality confirmation.
 @param displayMode Indicates the keypad display mode (fullscreen, dialog or embedded).
 @param keyEnteredBlock Callback on finish. Depends on the OK button behavior settings, the finish callback could be triggered by the user or system. For double entry mode, trigger the OK button will trigger the callback only if both input field key count hit the minimum input length.
 @see EMSecureInputBuilderDefaultConfigurations for the default configurations of the keypad.
 @see EMSecureInputUiOkButtonBehavior
 @return The secure input UI. The secure input UI view controller can be fed into a navigation controller or presented as a modal view controller in the current view.
 @exception NSInvalidArgumentException The exception when the improper configuration is set
 - Since: 6.0
 */
- (id<EMSecureInputUi>)buildClearTextWithScrambling:(BOOL)isScrambling isDoubleInputField:(BOOL)isDoubleInputField displayMode:(EMSecureInputUiDisplayMode)displayMode onFinishBlock:(EMSecureInputUiOnFinishClearText)keyEnteredBlock;

/**
 Wipes all the sensitive data of the secure input builder. The method would also be automatically triggered upon the release of this object on the autorelease pool of the current thread.
 <p/>
 It's recommended to call this method at the end of the callback block `EMSecureInputUiOnFinish` or `EMSecureInputUiOnFinishClearText`. <br>
 <b>Note:</b> Other non-sensitive configuration such as color setting and text-label setting won't be reset in this function.
 - Since: 4.4
 */
- (void)wipe;

/**
 Set secure input UI screen background color.
 @param color screen background color. Screen background color cannot be nil.
 - Since: 4.4
 */
- (void)setScreenBackgroundColor:(UIColor *)color;

/**
 Set secure input UI screen background image. The screen background image will be drawn on top of screen background color.
 @param image screen background image. Screen background image cannot be nil.
 @param contentMode screen background image content mode.
 - Since: 6.0
 */
- (void)setScreenBackgroundImage:(UIImage *)image contentMode:(EMSecureInputUiBackgroundImageContentMode)contentMode;

/**
 Show or hide navigation bar.
 @param show show or hide navigation bar.
 - Since: 4.4
 */
- (void)showNavigationBar:(BOOL)show;

/**
 Show or hide top screen.
 @param show show or hide top screen. `YES` to show default secure input UI. `NO` allows developer to customize the top screen.
 @see [EMSecureInputUi customUiDelegate]
 - Since: 4.4
 */
- (void)showTopScreen:(BOOL)show;

/**
 Set logo image and position.
 @param image logo image. Logo image cannot be nil.
 @param position logo position.
 @note The logo image won't be drawn on screen for custom top UI ([EMSecureInputBuilder showTopScreen:] set to `NO`).
 @see EMSecureInputUiLogoPosition
 - Since: 4.4
 */
- (void)setLogoImage:(UIImage *)image andPosition:(EMSecureInputUiLogoPosition)position;

/**
 Set logo bar background color.
 @param color logo bar background color. Logo bar background color cannot be nil.
 @note The logo bar background won't be drawn on screen for custom top UI ([EMSecureInputBuilder showTopScreen:] set to `NO`).
 - Since: 4.4
 */
- (void)setLogoBarBackgroundColor:(UIColor *)color;

/**
 Sets the first label.
 @param text first label. First label cannot be nil. First label is assumed to be single line. Keep the first label as short as possible.
 @note The first label won't be drawn on screen for custom top UI ([EMSecureInputBuilder showTopScreen:] set to `NO`).
 - Since: 4.4
 */
- (void)setFirstLabel:(NSString *)text;

/**
 Set second text. Only applicable if double-entry mode is enabled when create the secure keypad.
 @param text second label. Second label cannot be nil. Second label is assumed to be single line. Keep the second label as short as possible.
 @note The second label won't be drawn on screen for custom top UI ([EMSecureInputBuilder showTopScreen:] set to `NO`).
 - Since: 4.4
 */
- (void)setSecondLabel:(NSString *)text;

/**
 Set label color.
 @param color label color. Label color cannot be nil.
 @note The label color won't be used for custom top UI ([EMSecureInputBuilder showTopScreen:] set to `NO`).
 - Since: 4.4
 */
- (void)setLabelColor:(UIColor *)color;

/**
 Set label font size.
 @param fontSize label font size. Label font size shall be greater than 0.
 @note The label font size won't be used for custom top UI ([EMSecureInputBuilder showTopScreen:] set to `NO`).
 - Since: 4.4
 */
- (void)setLabelFontSize:(CGFloat)fontSize;

/**
 Set label alignment.
 @param alignment label alignment.
 @note The label alignment won't be used for custom top UI ([EMSecureInputBuilder showTopScreen:] set to `NO`).
 @see EMSecureInputUiLabelAlignment
 - Since: 4.4
 */
- (void)setLabelAlignment:(EMSecureInputUiLabelAlignment)alignment;

/**
 Set input field font size.
 @param fontSize input field font size. Input field font size shall be greater than 0.
 @note The input field font size won't be used for custom top UI ([EMSecureInputBuilder showTopScreen:] set to `NO`).
 - Since: 4.4
 */
- (void)setInputFieldFontSize:(CGFloat)fontSize;

/**
 Set input field border color for corresponding UI control state.
 @param color input field border color. Input field border color cannot be nil.
 @param state UI control state.
 @note The input field border color won't be used for custom top UI ([EMSecureInputBuilder showTopScreen:] set to `NO`).
 @see EMSecureInputUiControlFocusState
 - Since: 4.4
 */
- (void)setInputFieldBorderColor:(UIColor *)color forState:(EMSecureInputUiControlFocusState)state;

/**
 Set input field background color for corresponding UI control state.
 @param color input field background color. Input field background color cannot be nil.
 @param state UI control state.
 @note The input field background color won't be used for custom top UI ([EMSecureInputBuilder showTopScreen:] set to `NO`).
 @see EMSecureInputUiControlFocusState
 - Since: 4.4
 */
- (void)setInputFieldBackgroundColor:(UIColor *)color forState:(EMSecureInputUiControlFocusState)state;

/**
 Set minimum and maximum input length. Minimum and maximum input length shall be identical for the following OK button behavior: `EMSecureInputUiOkButtonNone` and `EMSecureInputUiOkButtonCustom`.
 @param minimumLength minimum input length. Allowed minimum input length is [0,19]. Minimum input length should be smaller than maximum input length.
 @param maximumLength maximum input length. Allowed maximum input length is [1,19].
 @see [EMSecureInputBuilder setOkButtonBehavior:]
 @see EMSecureInputUiOkButtonBehavior
 - Since: 4.4
 */
- (void)setMinimumInputLength:(NSInteger)minimumLength andMaximumInputLength:(NSInteger)maximumLength;

/**
 Set number of rows and columns.
 @param numberOfRows number of rows. Allowed number of rows is [1,8].
 @param numberOfColumns number of columns. Allowed number of columns is [2,8].
 - Since: 4.4
 */
- (void)setNumberOfRows:(NSInteger)numberOfRows andColumns:(NSInteger)numberOfColumns;

/**
 Set keypad height ratio.
 @param ratio keypad height ratio. Allowed keypad height ratio is [0.25,0.5].
 - Since: 4.4
 */
- (void)setKeypadHeightRatio:(CGFloat)ratio;

/**
 By default, the OK button is located at the bottom left of the secure input UI and the Delete button is located at the bottom right of the secure input UI. Swap OK and Delete button if needed.
 - Since: 4.4
 */
- (void)swapOkAndDeleteButton;

/**
 Set keys. The keys encoding shall be in NSUTF16StringEncoding format, using different encoding technique results in wrong display.
 @param keys keypad keys. Keys cannot be nil. Allowed keys length is [1,32]. Keys length shall be smaller or equals to number of keypad matrix allocated.
 - Since: 6.0
 */
- (void)setKeys:(NSData *)keys;

/**
 Set keys and its subscripts.  The keys encoding shall be in NSUTF16StringEncoding format, using different encoding technique results in wrong display.
 @param keys keypad keys. Keys cannot be nil. Allowed keys length is [1,32]. Keys length shall be smaller or equals to number of keypad matrix allocated.
 @param subscripts subscripts. Subscripts can be nil. Allowed subscripts length is [0,4].
 - Since: 6.0
 */
- (void)setKeys:(NSData *)keys andSubscripts:(NSArray *)subscripts;

/**
 Set shift keys and its subscripts.  The shift keys encoding shall be in NSUTF16StringEncoding format, using different encoding technique results in wrong display.
 @param keys keypad keys. Keys cannot be nil. Allowed keys length is [1,32]. Keys length shall be smaller or equals to number of keypad matrix allocated.
 @param subscripts subscripts. Subscripts can be nil. Allowed subscripts length is [0,4].
 @exception NSInvalidArgumentException The API will throw exception if the swapOkAndDeleteButton is enabled along with shift support.
 - Since: 6.0
 */
- (void)setShiftKeys:(NSData *)keys andSubscripts:(NSArray *)subscripts;

/**
 Set OK button text.
 @param text OK button text. OK button text cannot be nil. Allowed OK button text length is [1,14].
 - Since: 4.4
 */
- (void)setOkButtonText:(NSString *)text;

/**
 Set Delete button text.
 @param text Delete button text. Delete button text cannot be nil. Allowed Delete button text length is [1,14].
 - Since: 4.4
 */
- (void)setDeleteButtonText:(NSString *)text;

/**
 Set Shift button text.
 @param text Shift button text. Shift button text cannot be nil. Allowed Shift button text length is [1,14].
 - Since: 4.4
 */
- (void)setShiftButtonText:(NSString *)text;

/**
 Set distance between key and subscript.
 @param distance distance between key and subscript. Allowed distance between key and subscript is [0.0,4.0].
 - Since: 4.4
 */
- (void)setDistanceBetweenKeyAndSubscript:(CGFloat)distance;

/**
 Set button border width.
 @param width button border width. Allowed button border width is [1,10].
 - Since: 4.4
 */
- (void)setButtonBorderWidth:(NSInteger)width;

/**
 Set keypad frame color.
 @param color keypad frame color. Keypad frame color cannot be nil.
 - Since: 4.6
 */
-(void)setKeypadFrameColor:(UIColor *)color;

/**
 Set the gradient start and end color for keypad grids which separates between the keys.
 @param startColor sets color at both ends of the inner keypad border.
 @param endColor sets color at middle of the inner keypad border.
 - Since: 4.6
 */
-(void)setKeypadGridGradientColors:(UIColor *)startColor gridGradientEndColor:(UIColor *)endColor;

/**
 Set button pressed visibility.
 @param visible `YES` to enable the selected state of the button when it's pressed. For security reason, it's disabled by default. User won't be able to see the selected state when the button is pressed.
 @see EMSecureInputBuilderDefaultConfigurations for the default configurations of the keypad.
 - Since: 4.4
 */
- (void)setButtonPressedVisibility:(BOOL)visible;

/**
 Set key font.
 @param font key font. Key font cannot be nil. Allowed key font size is [1.0,100.0].
 - Since: 4.4
 */
- (void)setKeyFont:(UIFont *)font;

/**
 Set subscript font.
 @param font subscript font. subscript font cannot be nil. Allowed subscript font size is [1,key font size].
 - Since: 4.4
 */
- (void)setSubscriptFont:(UIFont *)font;

/**
 Set OK button font.
 @param font OK button font. OK button font cannot be nil. Allowed OK button font size is [1.0,100.0].
 - Since: 4.4
 */
- (void)setOkButtonFont:(UIFont *)font;

/**
 Set Delete button font.
 @param font Delete button font. Delete button font cannot be nil. Allowed Delete button font size is [1.0,100.0].
 - Since: 4.4
 */
- (void)setDeleteButtonFont:(UIFont *)font;

/**
 Set Shift button font.
 @param font Shift button font. Shift button font cannot be nil. Allowed Shift button font size is [1.0,100.0].
 - Since: 6.0
 */
- (void)setShiftButtonFont:(UIFont *)font;

/**
 Set key color for corresponding UI state.
 @param color key color. Key color cannot be nil.
 @param state UI state.
 @see EMSecureInputUiControlState
 - Since: 4.4
 */
- (void)setKeyColor:(UIColor *)color forState:(EMSecureInputUiControlState)state;

/**
 Set subscript color for corresponding UI state.
 @param color subscript color. Subscript color cannot be nil.
 @param state UI state.
 @see EMSecureInputUiControlState
 - Since: 4.4
 */
- (void)setSubscriptColor:(UIColor *)color forState:(EMSecureInputUiControlState)state;

/**
 Set OK button text color for corresponding UI state.
 @param color OK button text color. OK button text color cannot be nil.
 @param state UI state.
 @see EMSecureInputUiControlState
 - Since: 4.4
 */
- (void)setOkButtonTextColor:(UIColor *)color forState:(EMSecureInputUiControlState)state;

/**
 Set Delete button text color for corresponding UI state.
 @param color Delete button text color. Delete button text color cannot be nil.
 @param state UI state.
 @see EMSecureInputUiControlState
 - Since: 4.4
 */
- (void)setDeleteButtonTextColor:(UIColor *)color forState:(EMSecureInputUiControlState)state;

/**
 Set Shift button text color for corresponding UI state.
 @param color Shift button text color. Shift button text color cannot be nil.
 @param state UI state. Shift button text color for disabled state is not supported.
 @see EMSecureInputUiControlState
 - Since: 6.0
 */
- (void)setShiftButtonTextColor:(UIColor *)color forState:(EMSecureInputUiControlState)state;

/**
 Set button background color for corresponding UI state.
 @param color button background color. Button background color cannot be nil.
 @param state UI state.
 @see EMSecureInputUiControlState
 - Since: 4.4
 */
- (void)setButtonBackgroundColor:(UIColor *)color forState:(EMSecureInputUiControlState)state;

/**
 Set button background image.
 @param image button background image. Button background image cannot be nil.
 - Since: 4.4
 */
- (void)setButtonBackgroundImage:(UIImage *)image;

/**
 Set button background image opacity for corresponding UI state.
 @param opacity button background image opacity. Allowed button background image opacity is [0.0,1.0].
 @param state UI state. Button background image opacity for selected state is not supported.
 @see EMSecureInputUiControlState
 - Since: 4.4
 */
- (void)setButtonBackgroundImageOpacity:(CGFloat)opacity forState:(EMSecureInputUiControlState)state;

/**
 Set OK button image.
 @param image OK button image. OK button image cannot be nil.
 - Since: 4.4
 */
- (void)setOkButtonImage:(UIImage *)image;

/**
 Set OK button image opacity for corresponding UI state.
 @param opacity OK button image opacity. Allowed OK button image opacity is [0.0,1.0].
 @param state UI state. OK button image opacity for selected state is not supported.
 @see EMSecureInputUiControlState
 - Since: 4.4
 */
- (void)setOkButtonImageOpacity:(CGFloat)opacity forState:(EMSecureInputUiControlState)state;

/**
 Set Delete button image.
 @param image Delete button image. Delete button image cannot be nil.
 - Since: 4.4
 */
- (void)setDeleteButtonImage:(UIImage *)image;

/**
 Set Delete button image opacity for corresponding UI state.
 @param opacity Delete button image opacity. Allowed Delete button image opacity is [0.0,1.0].
 @param state UI state. Delete button image opacity for selected state is not supported.
 @see EMSecureInputUiControlState
 - Since: 4.4
 */
- (void)setDeleteButtonImageOpacity:(CGFloat)opacity forState:(EMSecureInputUiControlState)state;

/**
 Set Shift button image.
 @param image Shift button image. Shift button image cannot be nil.
 - Since: 6.0
 */
- (void)setShiftButtonImage:(UIImage *)image;

/**
 Set Shift button image opacity for corresponding UI state.
 @param opacity Shift button image opacity. Allowed Shift button image opacity is [0.0,1.0].
 @param state UI state. Shift button image opacity for selected and disabled state are not supported.
 @see EMSecureInputUiControlState
 - Since: 6.0
 */
- (void)setShiftButtonImageOpacity:(CGFloat)opacity forState:(EMSecureInputUiControlState)state;

/**
 Set the start and end color of the button gradient for corresponding control state.
 @param startColor the gradient start color.
 @param endColor the gradient end color.
 @param state the control state.
 - Since: 4.8
 */
- (void)setButtonGradientColors:(UIColor *)startColor buttonGradientEndColor:(UIColor *)endColor forState:(EMSecureInputUiControlState)state;

/**
 Set the start and end color of the OK button gradient for corresponding control state.
 @param startColor the gradient start color.
 @param endColor the gradient end color.
 @param state the control state.
 - Since: 4.8
 */
- (void)setOkButtonGradientColors:(UIColor *)startColor buttonGradientEndColor:(UIColor *)endColor forState:(EMSecureInputUiControlState)state;

/**
 Set the start and end color of the Delete button gradient for corresponding control state.
 @param startColor the gradient start color.
 @param endColor the gradient end color.
 @param state the control state.
 - Since: 4.8
 */
- (void)setDeleteButtonGradientColors:(UIColor *)startColor buttonGradientEndColor:(UIColor *)endColor forState:(EMSecureInputUiControlState)state;

/**
 Set the start and end color of the Shift button gradient for corresponding control state.
 @param startColor the gradient start color.
 @param endColor the gradient end color.
 @param state the control state. Shift button gradient color for disabled state is not supported.
 - Since: 6.0
 */
- (void)setShiftButtonGradientColors:(UIColor *)startColor buttonGradientEndColor:(UIColor *)endColor forState:(EMSecureInputUiControlState)state;

/**
 Set OK button behavior. Minimum and maximum input length shall be identical for the following OK button behavior: `EMSecureInputUiOkButtonNone` and `EMSecureInputUiOkButtonCustom`.
 @param behavior OK button behavior.
 @see EMSecureInputUiOkButtonBehavior
 @see [EMSecureInputBuilder setMinimumInputLength:andMaximumInputLength:]
 - Since: 4.4
 */
- (void)setOkButtonBehavior:(EMSecureInputUiOkButtonBehavior)behavior;

/**
 Set delete button always enabled.
 @param isAlwaysEnabled to enable delete button irrespective of input.
 - Since: 4.6
 */
- (void)setIsDeleteButtonAlwaysEnabled:(BOOL)isAlwaysEnabled;

/**
 Enabled or disable the OK button.
 @param disabled to disable the OK button or not.
 - Since: 5.0
 */
- (void)setIsOkButtonDisabled:(BOOL)disabled;

/**
 Display or hide the delete button.
 @param visible to set the delete button visible or not.
 - Since: 5.0
 */
- (void)setIsDeleteButtonVisible:(BOOL)visible;

/**
 Display or hide the shift button.
 @param visible to set the shift button visible or not.
 - Since: 6.0
 */
- (void)setIsShiftButtonVisible:(BOOL)visible;

/**
 Set the button visual effect.
 @param buttonTouchVisualEffect The visual effect.
 - Since: 5.0
 */
- (void)setButtonTouchVisualEffect:(EMButtonTouchVisualEffect)buttonTouchVisualEffect;

/**
 Set the visual effect parameters after setting `setButtonTouchVisualEffect`.
 @param color The color of the touch button visual effect.
 @param milliseconds The duration in milliseconds.
 - Since: 5.0
 */
- (void)setRippleEffectParameters:(UIColor *)color duration:(long)milliseconds;

@end




