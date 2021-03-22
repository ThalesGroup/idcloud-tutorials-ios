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
