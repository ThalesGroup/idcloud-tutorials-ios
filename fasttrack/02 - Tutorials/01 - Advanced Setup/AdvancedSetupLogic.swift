/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.


import Foundation

class AdvancedSetupLogic {
    
    class func setup() {
        if (!EMFastTrack.isConfigured()) {
            
            EMFastTrack.configureSecureLog(config: SetupConfig.getSecureLogConfig())
            
            EMFastTrack.configure(optionalParameters: { (params: EMFastTrackOptionalParameters) in
                if let obfuscationKey = AdvancedSetupConfig.obfuscationKey {
                    params.obfuscationKeys = [obfuscationKey]
                }
                if let signaturePublicKeyPem = AdvancedSetupConfig.signaturePublicKeyPem {
                    let transactionSignatureKey: EMTransactionSignatureKey = EMTransactionSignatureKey.init(publicKeyPem: signaturePublicKeyPem)
                    params.signatureKeys = [transactionSignatureKey]
                }
                params.activationCode = SetupConfig.getActivationCode()
                
            })
        }
    }
}
