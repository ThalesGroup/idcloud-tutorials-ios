/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
// Please make sure to review our IdCloud documentation, including security guidelines.

/**
 Logic for Mobile Protector SDK setup. This setup is used only for the basic Mobile Protector OTP use case.
 */
class SetupLogic {

    /**
     Setups Mobile Protector SDK.
     */
    class func setup() {
        if !EMFastTrack.isConfigured() {
            // Configure fasttrack API with secure log.
            EMFastTrack.configureSecureLog(config: SetupConfig.getSecureLogConfig())

            EMFastTrack.configure(optionalParameters: { (params: EMFastTrackOptionalParameters) in
                params.activationCode = SetupConfig.getActivationCode()
            })
        }
    }
}
