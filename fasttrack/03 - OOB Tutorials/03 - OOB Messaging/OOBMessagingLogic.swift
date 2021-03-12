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

typealias OOBFetchMessageResponse = (EMFetchMessageResponse?, Error?) -> Void
class OOBMessagingLogic:OOBSetupLogic {
    
    func fetchMessage(completion: @escaping OOBFetchMessageResponse) {
        let mobileMessenger = EMMobileMessenger.sharedInstance()!
        if (!mobileMessenger.clientIds().isEmpty) {
            let clientId = mobileMessenger.clientIds().first
            do {
                let messageManager = try mobileMessenger.messageManager(clientId: clientId!, providerId: OOBSetupConfig.providerId())
                messageManager.fetchMessage(timeout: 30, customHeaders: nil) { (response: EMFetchMessageResponse?, err: Error?) in
                    completion(response, err)
                }
            } catch let err as NSError {
                completion(nil, err)
            }
            
        }
        
    }
    
    func signTransactionMessage(_ response: EMFetchMessageResponse!, value: EMTransactionSigningResponseValue, pin: String!) {
        guard let request = response.transactionSigningRequest else {
            return
        }
        let META = NSMutableDictionary()
        switch value {
        case .rejected:
            // Construct META for rejected message
            META.setValue("Rejected from the UI", forKey: "Message")
            _ = request.create(response: EMTransactionSigningResponseValue.rejected, otp: nil, meta: META as? [AnyHashable : Any])
        case .accepted:
            // Get the oath protector instance
            guard let protector = EMOathMobileProtector.sharedInstance() else {
                return
            }
            // Check if there's OATH token device that could be use to sign the request
            do {
                let tokenDeviceNames = try protector.tokenDeviceNames()
                if tokenDeviceNames.isEmpty {
                    print("error")
                } else {
                    // Get token device with uti, which get from transaction signing request object
                    let tokenDevice = try protector.tokenDevice(userTokenID: Int32(request.userTokenIdForSigning), fingerprintCustomData: nil)
                    let tokenDeviceName = tokenDeviceNames.first!
                    guard let serverChallengeData = request.ocraServerChallenge else {
                        return
                    }
                    guard let serverChallenge = String.init(data: serverChallengeData, encoding: .utf8) else {
                        return
                    }
                    
                    // Generate OTP using server challenge, password hash and session
                    let otp = try tokenDevice.ocra(pin: pin, serverChallengeQuestion: serverChallenge, clientChallengeQuestion: request.ocraClientChallenge, passwordHash: request.ocraPasswordHash, session: request.ocraSession)
                    // Construct META for accepted message
                    META.setValue(true, forKey: "shouldVerifyOTP")
                    META.setValue(tokenDeviceName, forKey: "user")
                    META.setValue("oathOcra", forKey: "otpType")
                    
                    _ = request.create(response: EMTransactionSigningResponseValue.accepted, otp: otp, meta: META as? [AnyHashable : Any])
                }
            } catch let err as NSError {
                // Print the error
                print(err.localizedDescription)
            }
        @unknown default:
            fatalError()
        }
    }
}
