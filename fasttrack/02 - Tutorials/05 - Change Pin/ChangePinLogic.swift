/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

class ChangePinLogic {
    func changePin(oldAuthInput: EMProtectorAuthInput?,
                   newAuthInput: EMProtectorAuthInput?,
                   oldPin: String?,
                   newPin: String?,
                   completion: @escaping (Bool, Error?) -> Void) {
        do {
            guard let oathTokenDevice = ProvisioningLogic.getToken() else {
                completion(false, nil)
                return
            }
            if let oldAuthInput = oldAuthInput, let newAuthInput = newAuthInput {
                try oathTokenDevice.changePin(oldPinAuthInput: oldAuthInput, newPinAuthInput: newAuthInput)
            } else if let oldPin = oldPin, let newPin = newPin {
                try oathTokenDevice.changePin(oldPin: oldPin, newPin: newPin)

            } else {
                throw "Invalid application usage. One of the pin input values must be provided."
            }
            completion(true, nil)
        } catch let error as NSError {
            completion(false, error)
        }
    }
}
