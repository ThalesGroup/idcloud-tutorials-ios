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
 Values needed for Token provisioning.
 */
class ProvisioningConfig {

    /**
     The URL of the Enrollment API endpoint, e.g: “https://api/provisioning/pp”

     @return Provision URL
     */
    class func getProvisioningUrl() -> URL {
        return URL(string: "")!
    }

    /**
     Identifier for the EPS server’s public RSA key.

     @return RSA key ID.
     */
    class func getRsaKeyId() -> String {
        return ""
    }

    /**
     The RSA modulus of the EPS public key (on provisioning protocol level, not transport level).

     @return RSA Key Modulus.
     */
    class func getRsaKeyModulus() -> Data {
        let raw: [UInt8] = [
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

        return Data(raw)
    }

    /**
     The RSA exponent of the EPS public key (on provisioning protocol level, not transport level).

     @return RSA Key Exponent.
     */
    class func getRsaKeyExponent() -> Data {
        let raw: [UInt8] = [0x00, 0x00, 0x00]
        return Data(raw)
    }

    /**
     * This configuration will allow to weaken TLS configuration for debug purposes. It’s not allowed to modify in release mode.
     *
     * @return TLS configuration.
     */
    class func getTlsConfiguration() -> EMFastTrackTlsConfiguration {
        return EMFastTrackTlsConfiguration(insecureConnectionAllowed: true, selfSignedCertAllowed: true, hostnameMismatchAllowed: true)
    }

    /**
     Gets the custom fingerprint data.

     @return Custom fingerprint data.
     */
    class func getCustomFingerprintData() -> Data {
        return "".data(using: .utf8)!
    }

    /**
     Gets the domain.

     @return Domain.
     */
    class func getDomain() -> String {
        return ""
    }

    /**
     Gets the timestep.
     */
    class func getTimeStep() -> Int {
        return 30
    }
}
