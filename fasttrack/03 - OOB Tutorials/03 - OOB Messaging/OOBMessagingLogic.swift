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
    var messageManager:EMMobileMessageManager? = nil
    
    func fetchMessage(completion: @escaping OOBFetchMessageResponse) {
        let mobileMessenger = EMMobileMessenger.sharedInstance()!
        if (!mobileMessenger.clientIds().isEmpty) {
            let clientId = mobileMessenger.clientIds().first
            do {
                self.messageManager = try mobileMessenger.messageManager(clientId: clientId!, providerId: OOBSetupConfig.providerId())
                self.messageManager?.fetchMessage(timeout: 30, customHeaders: nil) { (response: EMFetchMessageResponse?, err: Error?) in
                    completion(response, err)
                }
            } catch let err as NSError {
                completion(nil, err)
            }
            
        }
        
    }
    
    func signTransactionMessage(_ response: EMFetchMessageResponse, value: EMTransactionSigningResponseValue, pinAuthInput:EMProtectorAuthInput?, completion: @escaping (Error?) -> Void ) {
        guard let request = response.transactionSigningRequest else {
            return
        }
        let META = NSMutableDictionary()
        var transactionSigningRequest : EMOutgoingMessage?
        
        switch value {
        case .rejected:
            // Construct META for rejected message
            META.setValue("Rejected from the UI", forKey: "Message")
            transactionSigningRequest = request.create(response: EMTransactionSigningResponseValue.rejected, otp: nil, meta: META as? [AnyHashable : Any])
        case .accepted:
            // Check if there's OATH token device that could be use to sign the request
            do {
                guard let tokenDevice = ProvisioningLogic.getToken() else {
                    return
                }
                var otp:String
                if let serverChallengeData = request.ocraServerChallenge {
                    guard let serverChallenge = String.init(data: serverChallengeData, encoding: .utf8) else {
                        return
                    }
                    // Generate OTP using server challenge, password hash and session
                    otp = try tokenDevice.ocra(authInput: pinAuthInput!, serverChallengeQuestion: serverChallenge, clientChallengeQuestion: request.ocraClientChallenge, passwordHash: request.ocraPasswordHash, session: request.ocraSession)
                } else {
                    otp = try OtpLogic.generateOtp(token: tokenDevice, pinAuthInput: pinAuthInput!)!.otp
                }
                
                transactionSigningRequest = request.create(response: EMTransactionSigningResponseValue.accepted, otp: otp, meta: nil)
                
            } catch let err as NSError {
                // Print the error
                completion(err)
            }
        @unknown default:
            fatalError()
        }
        
        if let transactionSigningRequest = transactionSigningRequest, let mManager = messageManager{
            // Start send the message
            mManager.send(message: transactionSigningRequest, customHeaders: nil) {(response: EMSendMessageResponse?, err: Error?) in
                completion(err)
            }
        }
        
    }
}
