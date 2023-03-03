/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "SDKStateView.h"
#import "AdvancedSetup_Logic.h"

@interface SDKStateView()

@property (weak, nonatomic) IBOutlet UILabel    *labelStateValue;
@property (weak, nonatomic) IBOutlet UITextView *textLog;

@end

@implementation SDKStateView

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
    
    // Register notifications
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(onLogStateChanged:)
                                                 name:C_NOTIFICATION_ID_LOG_STATE_CHANGED
                                               object:nil];
    
    // Load current values
    [self onLogStateChanged:nil];
}

- (void) dealloc
{
    // Unregister all notifications.
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

// MARK: - Notifications

- (void)onLogStateChanged:(NSNotification *) notification
{
    NSString *log = [AdvancedSetup_Logic log];
    
    [_textLog setText:log];
    [_textLog scrollRangeToVisible:NSMakeRange(log.length, 0)];
}

// MARK: - IBInspectable

- (void)setBorderColor:(UIColor *)borderColor
{
    self.layer.borderColor = borderColor.CGColor;
}

-(void)setBorderWidth:(CGFloat)borderWidth
{
    self.layer.borderWidth = borderWidth;
}

-(void)setCornerRadius:(CGFloat)cornerRadius
{
    self.layer.cornerRadius = cornerRadius;
}

@end
