/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

#import "Setup_ViewController.h"

@interface Setup_ViewController()

@property (weak, nonatomic) IBOutlet LoadingIndicatorView *loadingIndicator;

@end

@implementation Setup_ViewController

// MARK: - Lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Set navigation bar title. 
    [self setTitle:[self caption]];
    
}

// MARK: - MainViewProtocol

- (NSString *)caption
{
    // Return application name based on plist configuration.
    return [[NSBundle mainBundle] objectForInfoDictionaryKey:(NSString*)kCFBundleNameKey];
}

- (void)displayMessageDialog:(NSString *)result
{
    // Main alert builder.
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:[self caption]
                                                                   message:result
                                                            preferredStyle:UIAlertControllerStyleAlert];
    
    // Add basic OK button without any handlers.
    [alert addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"STRING_OK", nil) style:UIAlertActionStyleDefault handler:nil]];
    
    // Present dialog.
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)displayMessageDialogError:(NSError *)error
{
    // Use display error in case of error.
    if (error) {
        [self displayMessageDialog:error.localizedDescription];
    }
}

- (void)displayOnCancelDialog:(NSString *)message completionHandler:(void (^)(BOOL))handler
{
    // Main alert builder.
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:[self caption]
                                                                   message:message
                                                            preferredStyle:UIAlertControllerStyleAlert];
    
    // Add ok button with handler.
    [alert addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"STRING_OK", nil)
                                              style:UIAlertActionStyleDestructive
                                            handler:^(UIAlertAction * _Nonnull action) {
                                                handler(YES);
                                            }]];
    
    // Add cancel button with handler.
    [alert addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"STRING_CANCEL", nil)
                                              style:UIAlertActionStyleCancel
                                            handler:^(UIAlertAction * _Nonnull action) {
                                                handler(NO);
                                            }]];
    
    // Present dialog.
    [self presentViewController:alert animated:true completion:nil];
    
}

- (BOOL)loadingBarIsPresent
{
    return _loadingIndicator.isPresent;
}

- (void)loadingBarShow:(NSString *)caption animated:(BOOL)animated
{
    [_loadingIndicator loadingBarShow:caption animated:animated];
    [self updateGUI];
}

- (void)loadingBarHide:(BOOL)animated
{
    [_loadingIndicator loadingBarHide:animated];
    [self updateGUI];
}

- (id<EMOathToken>)updateGUI
{
    // Override in 02 provisioning once we will have actual token.
    return nil;
}


@end
