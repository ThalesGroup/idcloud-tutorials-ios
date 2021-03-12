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
