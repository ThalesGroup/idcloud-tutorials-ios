/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
// Please make sure to review our IdCloud documentation, including security guidelines.

/**
 Logic for token provisioning using Mobile Protector SDK.
 */
class ProvisioningLogic {
    private static var sOathProtector: EMOathMobileProtector?
    private static var tokenName: String?
    private static var protectorOathTokenDevice: EMProtectorOathTokenDevice?

    // MARK: Public
    /**
     Provisions asynchronously a new token.
     
     @param userId User id.
     @param registrationCode Registration code.
     @param completionHandler Callback back to the application.
     */
    class func provision(userId: String, registrationCode: String, completionHandler: @escaping (_ token: EMProtectorTokenDevice?,_ error: Error?) -> Void) {
        let oathProtector: EMOathMobileProtector = getOathProtector()
        let totpSettings: EMProtectorTotpSettings = EMProtectorTotpSettings()
        totpSettings.timestepSize = ProvisioningConfig.getTimeStep()

        oathProtector.provision(tokenDeviceName: userId, registrationCode: registrationCode, totpSettings: totpSettings, optionalParameters: { (optionalParameters: EMProvisionerOptionalParameters) in
            optionalParameters.tlsConfiguration = ProvisioningConfig.getTlsConfiguration()
            let fingerprintSources: Set<NSValue> = [NSValue(nonretainedObject: EMFastTrackDeviceFingerprintType.soft)]
            optionalParameters.deviceFingerprintSource = EMFastTrackDeviceFingerprintSource(customData: ProvisioningConfig.getCustomFingerprintData(), deviceFingerprintType: fingerprintSources)
        }) { (oathTokenDevice: EMProtectorOathTokenDevice?, extensions: [AnyHashable: Any]?, error: Error?) in
            if error != nil {
                completionHandler(nil, error)
            } else {
                completionHandler(oathTokenDevice, nil)
            }
        }
    }
    /**
     Retrieves the first token.
     
     @return Token, or {@code null} if no Token available.
     */
    class func getToken() -> EMProtectorOathTokenDevice? {
        if protectorOathTokenDevice == nil {
            if let tokenNames: Set<String> = try? getOathProtector()?.tokenDeviceNames(), !tokenNames.isEmpty {
                protectorOathTokenDevice = try? getOathProtector()?.tokenDevice(name: tokenNames.first!, fingerprintCustomData: ProvisioningConfig.getCustomFingerprintData())
            }
        }
        return protectorOathTokenDevice
    }
    
    /**
     Removes the token.
     
     @return {@code True} if token was successfully removed, {@code false} if token was not removed successfully or no token was available.
     */
    class func removeToken() throws -> Bool {
        if let tokenNames = try getOathProtector()?.tokenDeviceNames(), !tokenNames.isEmpty {
            try getOathProtector()?.removeTokenDevice(name: tokenNames.first!)
            tokenName = nil
            protectorOathTokenDevice = nil
            return true
        }
        return false
    }
    
    /**
     Gets the singleton instance of {@code EMOathMobileProtector}.
     
     @return Singleton instance of {@code EMOathMobileProtector}.
     */
    class func getOathProtector() -> EMOathMobileProtector! {
        objc_sync_enter(self)
        if sOathProtector == nil {
            sOathProtector = EMFastTrack.sharedInstance()?.oathMobileProtector(url: ProvisioningConfig.getProvisioningUrl(),
                                                                               domain: ProvisioningConfig.getDomain(),
                                                                               provisioningProtocol: EMFastTrackProvisioningProtocol.version5,
                                                                               rsaKeyId: ProvisioningConfig.getRsaKeyId(),
                                                                               rsaExponent: ProvisioningConfig.getRsaKeyExponent(),
                                                                               rsaModulus: ProvisioningConfig.getRsaKeyModulus(),
                                                                               optionalParameters: nil)
        }
        objc_sync_exit(self)
        return sOathProtector!
    }
    
    class func isProvisioned() -> Bool {
        if ProvisioningLogic.getToken() != nil {
            return true
        }
        return false
    }
    
    class func getTokenName() -> String {
        if tokenName == nil {
            do {
                let tokenNames = try getOathProtector()?.tokenDeviceNames()
                if tokenNames!.isEmpty == false {
                    return tokenNames!.first ?? ""
                }
            } catch {
                return ""
            }
        }
        return tokenName ?? ""
    }
}
