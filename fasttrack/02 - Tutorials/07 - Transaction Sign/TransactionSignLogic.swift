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

import CommonCrypto

class TransactionSignLogic {
    class func generateOtp(_ token: EMProtectorOathTokenDevice,
                           pinAuthInput: EMProtectorAuthInput?,
                           pin: String?,
                           amount: String, beneficiary: String) throws -> OtpValue? {
        var ocraOtp: String
        let serverChallenge = serverChallenge(amount: amount, beneficiary: beneficiary)
        if let pinAuthInput = pinAuthInput {
            ocraOtp = try token.ocra(authInput: pinAuthInput,
                                     serverChallengeQuestion:serverChallenge,
                                     clientChallengeQuestion:nil,
                                     passwordHash: nil,
                                     session: nil)
        } else if let pin = pin {
            ocraOtp = try token.ocra(pin: pin,
                                     serverChallengeQuestion:serverChallenge,
                                     clientChallengeQuestion:nil,
                                     passwordHash: nil,
                                     session: nil)
        } else {
            throw "Invalid application usage. One of the pin input values must be provided."
        }
        
        return OtpValue(otp: ocraOtp, lifespan: Lifespan(current: token.lastOtpLifeSpan(), max: ProvisioningConfig.getTimeStep()))
    }
    
    class func serverChallenge(amount: String, beneficiary: String) -> String {
        return ocraChallenge([
            KeyValue(key: "amount", value: amount),
            KeyValue(key: "beneficiary", value: beneficiary)
        ])
    }
    
    class func ocraChallenge(_ values: [KeyValue]) -> String {
        // Use builder to append TLV
        let buffer = NSMutableData()
        
        // Go through all values, calculate and append TLV for each one of them.
        for i in 0..<values.count {
            // Convert keyvalue to UTF8 string
            let keyValueUTF8 = values[i].keyValueUTF8()
            // TLV tag DF71 from first item.
            var tlvTag1: UInt8 = 0xdf
            var tlvTag2 = UInt8(0x71 + i)
            var tlvLength = UInt8(keyValueUTF8.count)
            buffer.append(&tlvTag1, length: 1)
            buffer.append(&tlvTag2, length: 1)
            buffer.append(&tlvLength, length: 1)
            buffer.append(keyValueUTF8)
        }
        var hash = [UInt8](repeating: UInt8(), count: Int(CC_SHA256_DIGEST_LENGTH))
        CC_SHA256(buffer.bytes, CC_LONG(buffer.count), &hash)
        return hexadecimalString(hash)
    }
    
    class func hexadecimalString(_ data: [UInt8]?) -> String {
        if let dataBuffer = data {
            let dataLength = dataBuffer.count
            var hexString = ""
            for i in 0..<dataLength {
                hexString += String(format: "%02lx", UInt(dataBuffer[i]))
            }
            return hexString
        } else {
            return ""
        }
    }
}

class KeyValue: NSObject {
    private (set) var key: String
    private (set) var value: String
    
    init(key: String, value: String) {
        self.key = key
        self.value = value
    }
    
    func keyValueUTF8() -> Data {
        let keyValue = "\(key):\(value)"
        return (keyValue.data(using: .utf8))!
    }
}
