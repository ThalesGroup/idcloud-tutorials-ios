/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

@class QRCodeReaderVC;

/**
 QR Code Reader response
 */
@protocol QRCodeReaderDelegate
/**
 Triggered once QR code is successfuly parsed.

 @param sender Instance of QR Code reader.
 @param qrCode Parsed code data.
 */
- (void)onQRCodeProvided:(QRCodeReaderVC *)sender qrCode:(NSString *)qrCode;
@end

/**
 VC With camera preview used to detect and read QR Code data.
 */
@interface QRCodeReaderVC : UIViewController

/**
 Delegate which will be triggered
 */
@property (nonatomic, weak, readonly)   id<QRCodeReaderDelegate>    delegate;

/**
 Reader might have multiple uses. This way app can identify which one was used.
 */
@property (nonatomic, assign, readonly) NSInteger                   customTag;

+ (instancetype)readerWithDelegate:(id<QRCodeReaderDelegate>)delegate customTag:(NSInteger)customTag;

@end
