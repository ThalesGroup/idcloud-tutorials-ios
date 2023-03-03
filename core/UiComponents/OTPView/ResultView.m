/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "ResultView.h"

@interface ResultView()

@property (weak, nonatomic) IBOutlet UILabel        *labelOTP;
@property (weak, nonatomic) IBOutlet UIProgressView *progressOTP;

@end

@implementation ResultView

// MARK: - Life Cycle

- (nullable instancetype)initWithCoder:(NSCoder *)decoder
{
    if (self = [super initWithCoder:decoder]) {
        [self setupWithFrame:self.bounds];
    }
    
    return self;
}

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        [self setupWithFrame:frame];
    }
    
    return self;
}

- (void)setupWithFrame:(CGRect)frame
{
    // Color is used as placeholder in case of disabled IB_DESIGNABLE
    self.backgroundColor = [UIColor clearColor];
    
    // Get our view from storyboard.
    UIView *contentView = [[[NSBundle bundleForClass:self.class] loadNibNamed:NSStringFromClass(self.class) owner:self options:nil] firstObject];
    contentView.frame = frame;
    
    // Add it as child of current View.
    [self addSubview:contentView];
}

// MARK: - Public API

- (void)hide
{
    [_labelOTP      setText:@""];
    [_labelOTP      setHidden:YES];
    [_progressOTP   setHidden:YES];
    
    [_progressOTP.layer removeAllAnimations];
}

- (void)show:(NSString *)value lifespan:(Lifespan)lifespan
{
    // Ignore same values
    if ([_labelOTP.text isEqualToString:value]) {
        return;
    }
    
    // Finish all previous animations.
    for (CALayer *layer in _progressOTP.layer.sublayers) {
        [layer removeAllAnimations];
    }
    
    // Unhide OTP label and set default values
    [_labelOTP  setTextColor:[UIColor blackColor]];
    [_labelOTP  setHidden:NO];
    [_labelOTP  setText:value];

    // Unhide progress and set value to current remaining value.
    [_progressOTP   setHidden:NO];
    [_progressOTP   setProgress:(CGFloat)lifespan.current / (CGFloat)lifespan.max];
    [_progressOTP   layoutIfNeeded];

    // Animate time.
    [UIView animateWithDuration:(CGFloat)lifespan.current animations:^{
        self.progressOTP.progress = .000001f; // .0f does not work on iOS 13.x
        [self.progressOTP layoutIfNeeded];
    } completion:^(BOOL finished) {
        if (finished) {
            [self.labelOTP setTextColor:[UIColor grayColor]];
        }
    }];
}

@end
