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
