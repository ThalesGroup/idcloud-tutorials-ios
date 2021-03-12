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

/**
 Secure input custom UI delegate.

 - Since: 4.4
 */
@protocol EMSecureInputCustomUiDelegate <NSObject>

/**
 Secure input UI key pressed count changed event.
 @param caller caller.
 @param count number of key pressed count for the following input field.
 @param inputFieldIndex input field index. Input field index 0 for first input field, and 1 for second input field.
 - Since: 4.4
 */
- (void)secureInputUi:(id)caller keyPressedCountChanged:(NSInteger)count forInputField:(NSInteger)inputFieldIndex;

/**
 Secure input UI selected input field changed event.
 @param caller caller.
 @param inputFieldIndex input field index. Input field index 0 for first input field, and 1 for second input field.
 - Since: 4.4
 */
- (void)secureInputUi:(id)caller selectedInputFieldChanged:(NSInteger)inputFieldIndex;

/**
 Secure input UI on OK button pressed.
 @param caller caller.
 - Since: 4.4
 */
- (void)secureInputUiOkButtonPressed:(id)caller;

/**
 Secure input UI on Delete button pressed.
 @param caller caller.
 - Since: 4.4
 */
- (void)secureInputUiDeleteButtonPressed:(id)caller;

@end
