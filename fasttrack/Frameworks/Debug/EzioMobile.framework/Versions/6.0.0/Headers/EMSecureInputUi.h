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

@protocol EMSecureInputCustomUiDelegate;

/**
 It contains all the information needed for the secure input UI.

 - Since: 4.4
 */
@protocol EMSecureInputUi <NSObject>

/**
 The secure input UI view controller can be fed into a navigation controller or presented as a modal view controller in the current view.
 - Since: 4.4
 */
@property (readonly, nonatomic) UIViewController *viewController;

/**
 The secure input UI keypad view.
 - Since: 4.8
 */
@property (readonly, nonatomic) UIView *keypadView;

/**
 It only useful for custom top UI. It contains information about the selected input field index.
 Application developer could then use the value to draw the custom top UI.
 Change the value if the selected input field on the custom top UI is changed.
 - Since: 4.4
 */
@property (nonatomic, assign) NSInteger selectedInputFieldIndex;

/**
 Secure input custom UI delegate.
 - Since: 4.4
 */
@property (nonatomic, assign) id<EMSecureInputCustomUiDelegate> customUiDelegate;

/**
 Secure input UI tag. Default it 0.
 - Since: 6.0
 */
@property (nonatomic, assign) NSInteger tag;

/**
 Simulate OK Button Press.
 - Since: 5.0
 */
- (void)simulateOkButtonPress;

/**
 Clears the text field.
 - Since: 5.0
 */
- (void)clearInputText;

/**
 Simulate Delete Input Button Press.
 - Since: 5.0
 */
- (void)simulateDeleteButtonPress;

/**
 Simulate Shift Button Press.
 - Since: 6.0
 */
- (void)simulateShiftButtonPress;

/**
 Build constraints for the keypad view in embedded mode.
 - Since: 6.0
 */
- (void)buildConstraintsForKeypadView;

@end
