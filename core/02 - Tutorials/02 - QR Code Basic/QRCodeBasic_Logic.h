/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

/**
 Completion handler for QR Parser.

 @param successful YES if operation was successful.
 @param userId Parsed User Id.
 @param regCode Parsed Registration code in secure string container.
 @param error Optional error description.
 */
typedef void (^QRCodeHandler)(BOOL successful, NSString *userId, id<EMSecureString> regCode, NSError *error);

// Review: SNE Add javadoc
@interface QRCodeBasic_Logic : NSObject

/**
 Basic QR code parser. It will parse HEX data from reader in order to get stored User ID and Registration code.

 @param code Raw QR code data in HEX string representation.
 @param handler Completion handler triggered once operation is done. Returned in the same thread.
 */
+ (void)parseQRCode:(NSString *)code completionHandler:(QRCodeHandler)handler;

@end
