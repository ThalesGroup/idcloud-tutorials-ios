/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

typealias OOBRegistrationHandler = (Bool, Error?) -> Void

let C_CLIENT_ID:String = "CLIENT_ID"

class OOBRegistrationLogic {
    func initializeMobileMessenger(completion: @escaping (Error?) -> Void) {
        let fastTrack = EMFastTrack.sharedInstance()!
        do {
            try fastTrack.mobileMessenger(url: OOBSetupConfig.messengerServerUrl(), domain: OOBSetupConfig.domain(), applicationId: OOBSetupConfig.applicationId(), rsaExponent: OOBSetupConfig.rsaExponent(), rsaModulus: OOBSetupConfig.rsaModulus(), optionalParameters: nil)
            completion(nil)
        } catch let err as NSError {
            completion(err)
        }
    }
    
    func registration(userId: String, registrationCode: String, completion: @escaping OOBRegistrationHandler ) {
        let mobileMessenger = EMMobileMessenger.sharedInstance()!
        // 3.1 Do Mobile Messenger registration by providing Callback
        mobileMessenger.register(userId: userId, userAlias: userId, registrationCode: registrationCode, customHeaders: nil) { [weak self](response: EMRegistrationResponse?, err: Error?) in
            if let err = err {
                completion(false, err)
            }
            if let response = response {
                // Get the client id from the response
                let clientId = response.clientId
                self?.writeToUserDefaults(clientId, forKey: C_CLIENT_ID)
                do {
                    // With the client id, it is possible now to construct Message Manager
                    try mobileMessenger.messageManager(clientId: clientId, providerId: OOBSetupConfig.providerId())
                    completion(true, nil)
                } catch let err as NSError {
                    completion(false, err)
                }
            }
        }
    }
    
    func unregistration(completion:@escaping OOBRegistrationHandler) {
        let mobileMessenger = EMMobileMessenger.sharedInstance()!
        let clientId = readValueFromUserDefaults(key: C_CLIENT_ID)
        if clientId != nil {
            mobileMessenger.unregister(clientId: clientId!, customHeaders: nil, completionHandler: { (status, error) in
                if status == true {
                    self.writeToUserDefaults(nil, forKey: C_CLIENT_ID)
                    completion(true, nil)
                } else {
                    completion(false, error)
                }
            })
        } else {
            completion(false, nil)
        }
    }
    
    func writeToUserDefaults(_ value:String?, forKey key:String) {
        let defaults = UserDefaults.standard
        defaults.setValue(value, forKey: key)
        defaults.synchronize()
    }
    
    func readValueFromUserDefaults(key: String) -> String? {
        let defaults = UserDefaults.standard
        let value = defaults.value(forKey: key)
        return value as? String
    }
}
