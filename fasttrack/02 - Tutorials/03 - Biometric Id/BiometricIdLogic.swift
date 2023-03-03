/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

class BiometricIdLogic {
    var oathTokenDevice: EMProtectorOathTokenDevice? {
        let oathTokenDevice = ProvisioningLogic.getToken()
        return oathTokenDevice
    }
    
    var oathProtector: EMOathMobileProtector {
        let oathProtector = ProvisioningLogic.getOathProtector()!
        return oathProtector
    }
    
    func isSystemBiometricSupported() -> Bool {
        return oathProtector.isSystemBiometricModeSupported() && oathProtector.isSystemBiometricModeConfigured()
    }
    
    func isSystemBiometricActivated() -> Bool {
        return oathTokenDevice?.isSystemBiometricModeActivated() ?? false
    }
    
    func activateSystemBiometric(pinAuthInput: EMProtectorAuthInput?, pin: String?, completion: @escaping (Bool, Error?) -> Void) {
        do {
            if let pinAuthInput = pinAuthInput {
                try oathTokenDevice?.activateSystemBiometricMode(pinAuthInput: pinAuthInput)
            } else if let pin = pin {
                try oathTokenDevice?.activateSystemBiometricMode(pin: pin)
            } else {
                throw "Invalid application usage. One of the pin input values must be provided."
            }
            completion(true, nil)
        } catch {
            completion(false, error)
        }
    }
    
    func otpWithSystemBiometric(completion: @escaping (_ otp: String?,_ error: Error?) -> Void) {
        do {
            oathTokenDevice?.authenticateWithMessage(localizedMessage: "Authenticate to get totp", fallbackTitle: "Enter Pin", completionHandler: { (authInput, data, error) in
                if error == nil {
                    do {
                        let otp = try self.oathTokenDevice?.otp(authInput: authInput!)
                        completion(otp, nil)
                    } catch let error as NSError {
                        completion(nil,error)
                    }
                } else {
                    completion(nil,error)
                }
            })
        }
    }
    
    func deactivateSystemBiometric(completion: @escaping (Bool, Error?) -> Void) {
        do {
            if (oathTokenDevice?.isSystemBiometricModeActivated() ?? false) {
                try oathTokenDevice?.deactivateSystemBiometricMode()
                completion(true, nil)
            }
        } catch let error as NSError {
            completion(false, error)
        }
    }
}
