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
* Logic for OTP generation.
*/
class OtpLogic {

    /**
     * Generates an OTP.
     *
     * @param token
     *         Token to be used for OTP generation.
     * @param pin
     *         PIN.
     * @return Generated OTP.
     */
    class func generateOtp(token: EMProtectorOathTokenDevice,
                           pinAuthInput: EMProtectorAuthInput?,
                           pin: String?) throws -> OtpValue {
        if EMFastTrack.isJailbroken() {
            // Handle root status according to app policy.
        }
        
        var otp: String
        if let pinAuthInput = pinAuthInput {
            otp = try token.otp(authInput: pinAuthInput)
        } else if let pin = pin {
            otp = try token.otp(pin: pin)
        } else {
            throw "Invalid application usage. One of the pin input values must be provided."
        }
        
        return OtpValue(otp: otp, lifespan: Lifespan(current: token.lastOtpLifeSpan(), max: ProvisioningConfig.getTimeStep()))
    }
}

extension String: LocalizedError {
    public var errorDescription: String? { return self }
}
