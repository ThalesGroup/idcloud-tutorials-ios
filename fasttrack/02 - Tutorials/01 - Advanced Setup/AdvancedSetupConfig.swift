/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

class AdvancedSetupConfig {
    static var CFG_JAILBREAK_POLICY_OTP: EMMobileProtectorTokenJailbreakPolicy = .ignore
    
    static var obfuscationKey: Data? {
        return nil
    }
    
    static var signaturePublicKeyPem: String? {
        return nil
    }
}
