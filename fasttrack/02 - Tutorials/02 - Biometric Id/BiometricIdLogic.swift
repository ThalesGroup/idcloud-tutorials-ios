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
    
    func activateSystemBiometric(pinAuthInput: EMProtectorAuthInput, completion: @escaping (Bool, Error?) -> Void) {
        do {
            try oathTokenDevice?.activateSystemBiometricMode(pinAuthInput: pinAuthInput)
            completion(true, nil)
        } catch let error as NSError {
            completion(false, error)
        }
    }
    
    func otpWithSystemBiometric(completion: @escaping (_ otp: String?,_ error: Error?) -> Void) {
        do {
            oathTokenDevice?.authenticateWithMessage(localizedMessage: "Authenticate to get TOTP", fallbackTitle: "Enter Pin", completionHandler: { (authInput, data, error) in
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
