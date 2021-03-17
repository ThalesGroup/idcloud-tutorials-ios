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


class ChangePinViewController: InBandVerificationViewController {
    
    @IBAction private func changePinButtonPressed(_ sender: Any) {
        showSecureKeypadPinInput { (pinAuthInput) in
            InBandVerificationLogic().verifyToken(withToken: ProvisioningLogic.getToken()!, pinAuthInput: pinAuthInput) { (isSucceed,message,error) in
                if error == nil {
                    if isSucceed {
                        self.showSecureKeypadConfirmPin { (newPin, newPinConfirmation) in
                            if newPin.isEqual(newPinConfirmation) {
                                //check the pin confirmation here
                                let newPinAuthInput = EMProtectorAuthInput.init(authInput: newPin)
                                ChangePinLogic().changePinWithAuthInput(pinAuthInput, newPinAuthInput) { (isSucceed, error) in
                                    if let error = error {
                                        self.displayMessageDialogError(error: error)
                                    } else {
                                        self.displayMessageDialog(result: "Pin changed successfully!")
                                    }
                                }
                            } else {
                                self.displayMessageDialog(result: "The pins must be equal")
                            }
                        }
                    } else {
                        self.displayMessageDialog(result: message!)
                    }
                } else {
                    self.displayMessageDialogError(error: error)
                }
            }
        }
    }
    
    private func showSecureKeypadConfirmPin(completion: @escaping (EMPinAuthInput, EMPinAuthInput) -> Void) {
        var keyPadVC: UIViewController!
        // 1. Create the builder for the keypad
        let uiModule: EMUIModule = EMUIModule.init()
        let secureInputService: EMSecureInputService = EMSecureInputService.init(module: uiModule)
        let sBuilder: EMSecureInputBuilder = secureInputService.secureInputBuilder()
        sBuilder.setNumberOfRows(4, andColumns: 4)
        sBuilder.setKeypadHeightRatio(0.25)
        sBuilder.setButtonBorderWidth(3)
        sBuilder.setKeypadFrameColor(UIColor.init(red: 121, green: 128, blue: 255, alpha: 1))
        sBuilder.setKeypadGridGradientColors(UIColor.init(red: 121, green: 128, blue: 255, alpha: 1), gridGradientEnd: UIColor.init(red: 121, green: 128, blue: 255, alpha: 1))
        /* 2. Build the EMSecureInputUi which contains the view controller and keypadview */
        let inputUI: EMSecureInputUi = sBuilder.build(withScrambling: true, isDoubleInputField: true, displayMode: EMSecureInputUiDisplayMode.fullScreen) { [weak self](firstPin, secondPin) in
            if self != nil {
                /* 4.1 Dismiss the view */
                keyPadVC.dismiss(animated: true, completion: nil)
                /* 4.2 Always wipe the builder after use */
                sBuilder.wipe()
                keyPadVC = nil
                completion(firstPin!, secondPin!)
            }
        }
        /* 3.1 Get the view controller from the EMSecureInputUi object and present accordingly */
        keyPadVC = inputUI.viewController
        /* 3.2 Present according presentation style */
        self.present(keyPadVC, animated: true, completion: nil)
    }
}
