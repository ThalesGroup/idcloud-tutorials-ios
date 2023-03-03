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
// Please make sure to review our IdCloud documentation, including security guidelines.

/**
 Configuration values needed for Mobile Protector SDK setup. This setup is used only for the basic
 Mobile Protector OTP use case.
 */
class SetupConfig {

    /**
     Retrieves the activation code.

     @return Activation code.
     */
    class func getActivationCode() -> String? {
        return nil
    }

    /**
     Get secure log config.
     
     @return secure log config.
     */
    class func getSecureLogConfig() -> SecureLogConfig {
        let secureLogConfig: SecureLogConfig = SecureLogConfig.init { (components) in
            let CFG_SECURE_LOG_RSA_KEY_MODULUS_RAW: [UInt8] = [0x00, 0xa0, 0x86, 0x90, 0xbe, 0x3a, 0x7d, 0xfd, 0x3d, 0x84, 0x56, 0x38, 0x23, 0x97, 0xd4,
                                                               0xb6, 0x5f, 0xeb, 0x1e, 0xc0, 0x17, 0x5a, 0xb3, 0x08, 0x92, 0x3b, 0x2a, 0x2b, 0x6c, 0xf6,
                                                               0x71, 0xd6, 0x62, 0x1c, 0x7a, 0x4f, 0x96, 0xf9, 0x37, 0xa0, 0x77, 0xd6, 0x24, 0x27, 0x84,
                                                               0x98, 0xfa, 0x7c, 0xb9, 0x3c, 0xfd, 0xc9, 0x58, 0xcd, 0xb7, 0x04, 0x08, 0xbb, 0x0b, 0x23,
                                                               0x8b, 0x21, 0xaa, 0x4d, 0x2c, 0xfd, 0x19, 0xf6, 0xa9, 0xc9, 0x43, 0xe0, 0xe9, 0x63, 0xcc,
                                                               0xa8, 0x5e, 0x8c, 0xf4, 0x57, 0x02, 0x13, 0x44, 0x0b, 0xfc, 0x0d, 0x5d, 0x05, 0xbf, 0x70,
                                                               0xe2, 0xac, 0xad, 0xe9, 0x55, 0x85, 0x04, 0x61, 0xfc, 0x67, 0x25, 0xe8, 0xd2, 0x0f, 0xba,
                                                               0x0b, 0x62, 0x1a, 0x1d, 0x55, 0xa0, 0x6c, 0x08, 0x83, 0xde, 0xd4, 0xbe, 0x39, 0x95, 0xe6,
                                                               0x7b, 0xe6, 0xc9, 0x44, 0x9b, 0xf8, 0x54, 0xb8, 0x4e, 0xe3, 0x75, 0xa6, 0xaf, 0xfa, 0x89,
                                                               0x39, 0x3e, 0xaf, 0xfd, 0x4e, 0xf7, 0xd8, 0x2f, 0x80, 0x0d, 0xa9, 0x7c, 0xf7, 0xa7, 0x53,
                                                               0x1d, 0x18, 0x95, 0x6a, 0x35, 0x98, 0x48, 0x24, 0xcf, 0x29, 0x52, 0xd7, 0x5f, 0xe0, 0x6b,
                                                               0xce, 0x61, 0xe4, 0x71, 0x13, 0xd6, 0x82, 0xf3, 0xd9, 0x41, 0x74, 0x5f, 0x5b, 0x85, 0xc6,
                                                               0x56, 0xa6, 0x1f, 0x8b, 0xd2, 0xc4, 0xa7, 0x57, 0x9c, 0xed, 0x82, 0xca, 0x2f, 0xd7, 0x84,
                                                               0x47, 0x26, 0x65, 0x43, 0xd9, 0x76, 0x95, 0xf5, 0x20, 0xd1, 0x03, 0xf4, 0xeb, 0x00, 0x34,
                                                               0x19, 0xca, 0x40, 0x40, 0x34, 0xe2, 0xfb, 0xbd, 0xe3, 0x64, 0x02, 0xcb, 0xe7, 0x1b, 0x87,
                                                               0x69, 0xac, 0x3b, 0x7a, 0xae, 0x51, 0x3d, 0x4b, 0x32, 0x57, 0x24, 0xe2, 0x03, 0x34, 0x71,
                                                               0x10, 0xda, 0x60, 0x77, 0x48, 0x26, 0xcb, 0x3c, 0x63, 0x0b, 0xa9, 0x49, 0xa4, 0x92, 0x53,
                                                               0x69, 0x53]
            let CFG_SECURE_LOG_RSA_KEY_EXPONENT_RAW: [UInt8] = [0x01, 0x00, 0x01]

            components.publicKeyModulus = Data(bytes: CFG_SECURE_LOG_RSA_KEY_MODULUS_RAW, count: CFG_SECURE_LOG_RSA_KEY_MODULUS_RAW.count)
            components.publicKeyExponent = Data(bytes: CFG_SECURE_LOG_RSA_KEY_EXPONENT_RAW, count: CFG_SECURE_LOG_RSA_KEY_EXPONENT_RAW.count)
        }

        return secureLogConfig
    }
}
