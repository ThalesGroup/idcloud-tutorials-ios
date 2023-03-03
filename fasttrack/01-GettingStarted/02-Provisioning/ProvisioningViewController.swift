/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
// Please make sure to review our IdCloud documentation, including security guidelines.

/**
 Provisioning View controller.
 */
class ProvisioningViewController: SetupViewController, ProvisioningViewDelegate {
    @IBOutlet weak var provisionView: ProvisionerView!
    
    // MARK: Lifecycle.
    override func viewDidLoad() {
        super.viewDidLoad()
        // Set provisioner UI delegate.
        provisionView.delegate = self
        // Update UI availability
        updateGui()
    }
    
    // MARK: MainViewProtocol methods.
    override func updateGui() {
        let token: EMProtectorOathTokenDevice? = ProvisioningLogic.getToken()
        provisionView.updateGUI(enabled: !isLoadingBarPresent(), token: token)
        onUpdateViewControllerSpecificUI()
    }
    
    func onProvision(userId: String, registrationCode: String) {
        loadingBarShow(caption: NSLocalizedString("STRING_PROVISION_LOADING", comment: ""), animated: true)
        ProvisioningLogic.provision(userId: userId, registrationCode: registrationCode) { (token: EMProtectorTokenDevice?, error: Error?) in
            self.loadingBarHide(animated: true)
            if token != nil {
                self.displayMessageDialog(result: NSLocalizedString("STRING_PROVISION_SUCCESS", comment: ""))
            } else if error != nil {
                self.displayMessageDialogError(error: error)
            } else {
                self.displayMessageDialog(result: NSLocalizedString("STRING_PROVISION_SUCCESS", comment: ""))
            }
        }
    }
    
    func onRemoveToken() {
        do {
            if try ProvisioningLogic.removeToken() {
                updateGui()
            }
        } catch {
            displayMessageDialogError(error: error)
        }
    }
    
    func onProvisionUsingQr() {
        //Implement in next chapter
    }
    
    func onUpdateViewControllerSpecificUI() {
        //Implement depends on each view controller
    }
}
