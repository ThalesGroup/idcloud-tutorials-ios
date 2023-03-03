/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

class OOBRegistrationViewController: TransactionSignViewController {
    var oobRegistration = OOBRegistrationLogic()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        oobRegistration.initializeMobileMessenger { (error) in
            self.displayMessageDialogError(error: error)
        }
    }
    override func viewWillAppear(_ animated: Bool) {
    
    }
    
    override func updateGui() {
        //shouldn't involve parent class
        let token: EMProtectorOathTokenDevice? = ProvisioningLogic.getToken()
        provisionView.updateGUI(enabled: !isLoadingBarPresent(), token: token)
    }
    
    override func onProvision(userId: String, registrationCode: String) {
        oobRegistration.registration(userId: userId, registrationCode: registrationCode) { (isSucceed, error) in
            if isSucceed {
                super.onProvision(userId: userId, registrationCode: registrationCode)
            } else {
                self.displayMessageDialogError(error: error)
            }
        }
    }
    
    override func onRemoveToken() {
        super.onRemoveToken()
        oobRegistration.unregistration { (isSucceed, error) in
            if isSucceed {
            } else {
                self.displayMessageDialogError(error: error)
            }
        }
    }
}
