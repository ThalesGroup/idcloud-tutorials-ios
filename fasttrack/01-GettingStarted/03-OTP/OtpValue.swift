/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
// Please make sure to review our IdCloud documentation, including security guidelines.

/**
 OTP value encapsuling the OTP value and lifespan.
 */
class OtpValue {
    let otp: String
    let lifespan: Lifespan
    /**
     Creates a new {@code OtpValue} object.
     @param otp OTP value.
     @param lifespan Lifespan of OTP.
     */
    init(otp otpValue: String, lifespan lifespanValue: Lifespan) {
        otp = otpValue
        lifespan = lifespanValue
    }
}
