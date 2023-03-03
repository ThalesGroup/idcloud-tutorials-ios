/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

/**
 Loading overlay
 */
//IB_DESIGNABLE
@interface LoadingIndicatorView : UIView

/**
 Whenever is overlay visible or not.
 */
@property (nonatomic, readonly) BOOL isPresent;

- (void)loadingBarShow:(NSString *)caption animated:(BOOL)animated;

- (void)loadingBarHide:(BOOL)animated;

@property (nonatomic) IBInspectable CGFloat cornerRadius;

@end
