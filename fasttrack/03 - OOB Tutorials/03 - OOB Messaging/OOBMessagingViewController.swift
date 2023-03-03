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

class OOBMessagingViewController: OOBRegistrationViewController {
    @IBOutlet weak var fetchButton:UIButton!
    var oOBMessagingLogic = OOBMessagingLogic()
    
    override func updateGui() {
        super.updateGui()
        let token = ProvisioningLogic.getToken()
        fetchButton.isEnabled = (token != nil)
    }
    
    @IBAction func fetchButtonPressed(_ sender:Any) {
        oOBMessagingLogic.fetchMessage { (response, error) in
            if let err = error {
                self.displayMessageDialogError(error: err)
            }
            if let oobResponse = response {
                if oobResponse.hasIncomingMessage {
                    if oobResponse.messageType == .unsupported {
                        self.displayMessageDialog(result: "Fetch message is successful but message type not supported")
                    } else {
                        self.handleOOBIncomingMessage(oobResponse)
                    }
                }  else {
                    self.displayMessageDialog(result: "No messages")
                }
                
            }
        }
    }
    
    private func handleOOBIncomingMessage(_ response: EMFetchMessageResponse!) {
        var title : String!
        
        var positiveButtonLabel : String!
        var negativeButtonLabel : String!
        
        // Defined the dialog UI element base on the message type
        switch response.messageType {
        case .unsupported, .generic, .transactionVerifyRequest:
            //Not handle in this example
            return
        case .transactionSigningRequest:
            positiveButtonLabel = "Approve"
            negativeButtonLabel = "Deny"
            title = "Do you want to accept this message?"
        @unknown default:
            return
        }
        
        let alertController : UIAlertController = UIAlertController.init(title: title, message: nil, preferredStyle: .alert)
        let positiveButton : UIAlertAction = UIAlertAction.init(title: positiveButtonLabel, style: .default) { (_) in
            self.responseToAction(response, value: true)
        }
        let negativeButton : UIAlertAction = UIAlertAction.init(title: negativeButtonLabel, style: .cancel) { (_) in
            self.responseToAction(response, value: false)
        }
        alertController.addAction(positiveButton)
        alertController.addAction(negativeButton)
        self.present(alertController, animated: true, completion: nil)
    }
    
    private func responseToAction(_ response: EMFetchMessageResponse, value: Bool) {
        switch response.messageType {
        case .unsupported, .generic, .transactionVerifyRequest:
            return
        case .transactionSigningRequest:
            // If the message is asking to sign a transaction the user could decide to accept or reject it
            if (value) {
                self.showPinInput { authInput, pin in
                    self.signTransactionMessage(response, value: .accepted, pinAuthInput: authInput, pin: pin)

                }
            } else {
                // Reject the transaction
                self.signTransactionMessage(response, value: .rejected, pinAuthInput: nil, pin: nil)
            }
        @unknown default:
            return
        }
    }
    
    private func signTransactionMessage(_ response: EMFetchMessageResponse,
                                        value: EMTransactionSigningResponseValue,
                                        pinAuthInput: EMProtectorAuthInput?,
                                        pin: String?) {
        self.oOBMessagingLogic.signTransactionMessage(response, value: value, pinAuthInput: pinAuthInput, pin: pin, completion: { (error) in
            if let error = error {
                self.displayMessageDialogError(error: error)
            } else {
                self.displayMessageDialog(result: "This message is \(value == .accepted ? "ACCEPTED" : "REJECTED") successfully\n")
            }
        })
    }
    
}
