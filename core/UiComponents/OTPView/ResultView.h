/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

// Review: SNE add javadoc
@interface ResultView : UIView

/**
 Hide all elements and disable all animations
 */
- (void)hide;

/**
 Show value with animated countdown.

 @param value Value to display.
 @param lifespan Current and maximum lifespan in seconds.
 */
- (void)show:(NSString *)value lifespan:(Lifespan)lifespan;

@end
