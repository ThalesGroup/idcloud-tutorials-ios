/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

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
