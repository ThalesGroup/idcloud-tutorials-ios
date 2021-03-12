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
 Main {@code UIViewController} for OTP use case.
 */
class OtpViewController: ProvisioningViewController {
    @IBOutlet weak var resultView: ResultView!
    @IBOutlet weak var buttonOtp: UIButton!
    
    // MARK: Lifecycle.
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        resultView.hide()
    }
    
    // MARK: - Private API
    /**
     Displays result OTP.
     */
    func displayOTP(value: String, lifespan: Lifespan) {
        resultView.show(value: value, lifespan: lifespan)
    }
    
    /**
     Generates OTP.
     */
    private func generateAndDisplayOtp(token: EMProtectorOathTokenDevice, pinAuthInput: EMProtectorAuthInput) {
        do {
            let otpValue: OtpValue = try OtpLogic.generateOtp(token: token, pinAuthInput: pinAuthInput)
            displayOTP(value: otpValue.otp, lifespan: otpValue.lifespan)
        } catch {
            displayMessageDialogError(error: error)
        }
    }
    
    /**
     Retrieves user PIN and generates OTP.
     */
    private func getPinAndGenerateOtp() {
        showSecureKeypadPinInput { (pinInput) in
            let pinAuthInput = EMProtectorAuthInput.init(authInput: pinInput)
            if let token: EMProtectorOathTokenDevice = ProvisioningLogic.getToken() {
                self.generateAndDisplayOtp(token: token, pinAuthInput: pinAuthInput)
            }
        }
    }
    
    // MARK: MainViewProtocol methods.
    override func updateGui() {
        // All token related error is solved in previous chapter.
        super.updateGui()
        if ProvisioningLogic.isProvisioned() {
            buttonOtp.isEnabled = !loadingIndicator.isPresent
        } else {
            buttonOtp.isEnabled = false
        }
    }
    
    // MARK: Actions.
    @IBAction private func onButtonPressedGenerateOtp(_ sender: Any) {
        getPinAndGenerateOtp()
    }

    // MARK: Show Secure Keypad
    func showSecureKeypadPinInput(completion: @escaping (EMPinAuthInput) -> Void) {
         /* SDK Limitation: Reference for dismissing modal view on finish, although self.presentedViewController could do the work */
         var keyPadVC: UIViewController!
         // 1. Create the builder for the keypad
         let uiModule: EMUIModule = EMUIModule.init()
         let secureInputService: EMSecureInputService = EMSecureInputService.init(module: uiModule)
         let sBuilder: EMSecureInputBuilder = secureInputService.secureInputBuilder()
         sBuilder.setFirstLabel("Enter PIN")
         /* 2. Build the EMSecureInputUi which contains the view controller and keypadview */
         let inputUI: EMSecureInputUi = sBuilder.build(withScrambling: true, isDoubleInputField: false, displayMode: EMSecureInputUiDisplayMode.fullScreen) { [weak self](firstPin, _) in
             if self != nil {
                 /* 4.1 Dismiss the view */
                 keyPadVC.dismiss(animated: true, completion: nil)
                 /* 4.2 Always wipe the builder after use */
                 sBuilder.wipe()
                 keyPadVC = nil
                 completion(firstPin!)
             }
         }
         /* 3.1 Get the view controller from the EMSecureInputUi object and present accordingly */
         keyPadVC = inputUI.viewController
         /* 3.2 Present according presentation style */
         self.present(keyPadVC, animated: true, completion: nil)
     }
}
