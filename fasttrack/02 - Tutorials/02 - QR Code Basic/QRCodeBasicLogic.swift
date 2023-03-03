/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.


/**
 Used as return value for QR Code Parser
 
 @param successful Whenever was operation successful
 @param userId Parsed user id.
 @param regCode Parsed registration code.
 @param error Description when operation did failed.
 */
typealias QRCodeManagerCompletion = (_ isSucceed: Bool, _ userId: String?, _ regCode: String?, _ error: Error?) -> Void


class QRCodeBasicLogic: NSObject {
    func parseQRCode(_ qrCodeData: String?, completionHandler: QRCodeManagerCompletion!) {
        var isSucceed = false
        var error: Error?
        var userId: String?
        var regCode: String?
        let utf9Text: String? = hexToStr(text: qrCodeData)
        
        // Two components in frame are user id and reg code.
        let components = utf9Text?.components(separatedBy: ",")
        if components?.count != 2 {
            error = NSError(domain: "\(object_getClassName(self))", code: -1, userInfo: [
                NSLocalizedDescriptionKey: "Unexpected components count."
            ])
        } else {
            userId = components?[0]
            regCode = components?[1]
            isSucceed = true
        }
        completionHandler(isSucceed, userId, regCode, error)
    }
    
    private func hexToStr(text: String?) -> String? {
        guard text != nil else {
            return nil
        }
        let regex = try! NSRegularExpression(pattern: "(0x)?([0-9A-Fa-f]{2})", options: .caseInsensitive)
        let textNS = text! as NSString
        let matchesArray = regex.matches(in: textNS as String, options: [], range: NSMakeRange(0, textNS.length))
        let characters = matchesArray.map {
            Character(UnicodeScalar(UInt32(textNS.substring(with: $0.range(at: 2)), radix: 16)!)!)
        }
        
        return String(characters)
    }
}
