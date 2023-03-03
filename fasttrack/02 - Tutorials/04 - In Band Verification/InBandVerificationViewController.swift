/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

class InBandVerificationViewController: BiometricIdViewController {
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func updateGui() {
        super.updateGui()
    }
    
    override func onUpdateViewControllerSpecificUI() {
        //Do nothing,don't need to inherit from previous UI buttons
    }
    
    @IBAction private func buttonAuthenticatePressed(_ sender: Any) {
        showPinInput { pinAuthInput, pin in
            InBandVerificationLogic().verifyToken(withToken: ProvisioningLogic.getToken()!,
                                                  pinAuthInput: pinAuthInput,
                                                  pin: pin) { _, message, error in
                if let error = error {
                    self.displayMessageDialogError(error: error)
                } else {
                    self.displayMessageDialog(result: message ?? "Unknown result.")
                }
            }
        }
    }
}
