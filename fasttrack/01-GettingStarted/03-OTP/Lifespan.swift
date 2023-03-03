/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
// Please make sure to review our IdCloud documentation, including security guidelines.

/**
 OTP lifespan.
 */
class Lifespan {
    let current: Int
    let max: Int
    /**
     Creates a new {@code OtpValue} object.
     @param otp OTP value.
     @param lifespan Lifespan of OTP.
     */
    init(current currentValue: Int, max maxValue: Int) {
        current = currentValue
        max = maxValue
    }
}
