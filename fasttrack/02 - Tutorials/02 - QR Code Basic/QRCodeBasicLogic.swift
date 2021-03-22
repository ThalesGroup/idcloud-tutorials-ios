//  MIT License
//
//  Copyright (c) 2020 Thales DIS
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

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
