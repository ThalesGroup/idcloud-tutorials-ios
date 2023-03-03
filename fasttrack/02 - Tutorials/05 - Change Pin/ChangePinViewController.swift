/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.


class ChangePinViewController: InBandVerificationViewController {
    
    @IBAction private func changePinButtonPressed(_ sender: Any) {
        showPinInput { pinAuthInput, pin in
            InBandVerificationLogic().verifyToken(withToken: ProvisioningLogic.getToken()!, pinAuthInput: pinAuthInput, pin: pin) { isSucceed, message, error in
                if !isSucceed {
                    self.displayMessageDialog(result: message ?? "Unknown error.")
                    return
                }
                
                if let error = error {
                    self.displayMessageDialogError(error: error)
                    return
                }
                
                self.changePin(pinAuthInput: pinAuthInput, pin: pin)
            }
        }
    }
    
    private func changePin(pinAuthInput: EMProtectorAuthInput?, pin: String?) {
        showConfirmPin(useSecureKeypad: pinAuthInput != nil) { newAutInput, newPin in
            ChangePinLogic().changePin(oldAuthInput: pinAuthInput, newAuthInput: newAutInput,
                                       oldPin: pin, newPin: newPin) { isSucceed, error in
                if isSucceed {
                    self.displayMessageDialog(result: "Pin changed successfully!")
                } else {
                    self.displayMessageDialogError(error: error)
                }
            }
        }
    }
        
    private func showConfirmPin(useSecureKeypad: Bool, completion: @escaping (EMProtectorAuthInput?, String?) -> Void) {
        if useSecureKeypad {
            showSecureKeypadConfirmPin { newAutInput, newAutInputConfirmation in
                if newAutInput.isEqual(newAutInputConfirmation) {
                    let retValue = EMProtectorAuthInput.init(authInput: newAutInput)
                    completion(retValue, nil)
                } else {
                    self.displayMessageDialog(result: "The pins must be equal")
                }
            }
        } else {
            showPlainTextConfirmPin { newPin, newPinConfirmation in
                if newPin.isEqual(newPinConfirmation) {
                    completion(nil, newPin)
                } else {
                    self.displayMessageDialog(result: "The pins must be equal")
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
    
    private func showPlainTextConfirmPin(completion: @escaping (String, String) -> Void) {
        let alertController = UIAlertController(title: "Change pin", message: "Input new pin and pin confirmation.", preferredStyle: .alert)
        alertController.addTextField { textField -> Void in
            textField.placeholder = "pin"
            textField.textColor = UIColor.blue
            textField.keyboardType = .numberPad
            textField.clearButtonMode = .whileEditing
            textField.borderStyle = .roundedRect
        }
        alertController.addTextField { textField -> Void in
            textField.placeholder = "pin confirmation"
            textField.textColor = UIColor.blue
            textField.keyboardType = .numberPad
            textField.clearButtonMode = .whileEditing
            textField.borderStyle = .roundedRect
        }
        alertController.addAction(UIAlertAction(title: "OK", style: .default, handler: { action in
            guard let pinFieldFirst = alertController.textFields?[0], let pin = pinFieldFirst.text, !pin.isEmpty,
                  let pinFieldSecond = alertController.textFields?[1], let pinConfirmation = pinFieldSecond.text, !pinConfirmation.isEmpty else {
                self.displayMessageDialog(result: "Both pin entries must be filled.")
                return
            }
            
            completion(pin, pinConfirmation)
        }))
        alertController.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        present(alertController, animated: true)
    }
    
    override func onUpdateViewControllerSpecificUI() {
        //Do nothing,don't need to inherit from previous UI buttons
    }
}
