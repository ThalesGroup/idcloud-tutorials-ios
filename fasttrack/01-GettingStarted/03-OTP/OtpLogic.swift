/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

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
