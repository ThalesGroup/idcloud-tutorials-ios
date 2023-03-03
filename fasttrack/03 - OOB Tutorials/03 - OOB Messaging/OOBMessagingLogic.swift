/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

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
    
    func signTransactionMessage(_ response: EMFetchMessageResponse,
                                value: EMTransactionSigningResponseValue,
                                pinAuthInput:EMProtectorAuthInput?,
                                pin: String?,
                                completion: @escaping (Error?) -> Void ) {
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
                    if let pinAuthInput = pinAuthInput {
                        otp = try tokenDevice.ocra(authInput: pinAuthInput,
                                                   serverChallengeQuestion: serverChallenge,
                                                   clientChallengeQuestion: request.ocraClientChallenge,
                                                   passwordHash: request.ocraPasswordHash,
                                                   session: request.ocraSession)
                    } else if let pin = pin {
                        otp = try tokenDevice.ocra(pin: pin,
                                                   serverChallengeQuestion: serverChallenge,
                                                   clientChallengeQuestion: request.ocraClientChallenge,
                                                   passwordHash: request.ocraPasswordHash,
                                                   session: request.ocraSession)
                    } else {
                        throw "Invalid application usage. One of the pin input values must be provided."
                    }
                } else {
                    otp = try OtpLogic.generateOtp(token: tokenDevice, pinAuthInput: pinAuthInput, pin: pin).otp
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
