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


import Foundation

class OOBSetupConfig {
    class func messengerServerUrl() -> URL {
        let clientUrl = ""
        return URL(string: clientUrl)!
    }
    
    /**
     * Get applicationId
     */
    class func applicationId() -> String {
        return "0"
    }
    
    /**
     * Get domain
     */
    class func domain() -> String {
        return ""
    }
    
    /**
     * Get providerId
     */
    class func providerId() -> String {
        return "0"
    }
    
    /**
     * Get the public key - exponent
     */
    class func rsaExponent() -> Data {
        let exponent: Array<CUnsignedChar> = [0x00, 0x00, 0x00]
        return Data(bytes: exponent, count: exponent.count)
    }
    
    /**
     * Get the public key - modulus
     */
    class func rsaModulus() -> Data {
        let modulus: Array<CUnsignedChar> = [
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
            0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00
        ]
        return Data(bytes: modulus, count: modulus.count)
    }
    
    /**
     * Get obfuscation key
     */
    class func obfuscationKey() -> Data? {
        return nil
    }
    
    /**
     * Get public key for signature
     */
    class func signaturePublicKeyPem() -> String? {
        return nil
    }
}
