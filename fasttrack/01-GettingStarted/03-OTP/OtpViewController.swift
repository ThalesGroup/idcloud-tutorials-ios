/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

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
        DispatchQueue.main.async {
            self.resultView.show(value: value, lifespan: lifespan)
        }
    }
    
    /**
     Generates OTP.
     */
    private func generateAndDisplayOtp(token: EMProtectorOathTokenDevice,
                                       pinAuthInput: EMProtectorAuthInput?,
                                       pin: String?) {
        do {
            let otpValue: OtpValue = try OtpLogic.generateOtp(token: token, pinAuthInput: pinAuthInput, pin: pin)
            displayOTP(value: otpValue.otp, lifespan: otpValue.lifespan)
        } catch {
            displayMessageDialogError(error: error)
        }
    }
    
    /**
     Retrieves user PIN and generates OTP.
     */
    private func getPinAndGenerateOtp() {
        guard let token: EMProtectorOathTokenDevice = ProvisioningLogic.getToken() else  {
            return
        }
        
        showPinInput { (pinAuthInput, pin) in
            self.generateAndDisplayOtp(token: token, pinAuthInput: pinAuthInput, pin: pin)
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
    
    // MARK: Show Pin Input
    func showPinInput(completion: @escaping (EMProtectorAuthInput?, String?) -> Void) {
        if SetupConfig.getActivationCode() != nil {
            userPinSecureKeypad(completion: completion)
        } else {
            userPinFromPlainInput(completion: completion)
        }
    }
    
    private func userPinSecureKeypad(completion: @escaping (EMProtectorAuthInput?, String?) -> Void) {
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
                let pinInput = EMProtectorAuthInput.init(authInput: firstPin!)
                completion(pinInput, nil)
            }
        }
        /* 3.1 Get the view controller from the EMSecureInputUi object and present accordingly */
        keyPadVC = inputUI.viewController
        /* 3.2 Present according presentation style */
        self.present(keyPadVC, animated: true, completion: nil)
    }
    
    private func userPinFromPlainInput(completion: @escaping (EMProtectorAuthInput?, String?) -> Void) {
        let alertController = UIAlertController(title: "Pin", message: "Input pin for OTP calculation", preferredStyle: .alert)
        alertController.addTextField { textField -> Void in
            textField.placeholder = "pin"
            textField.textColor = UIColor.blue
            textField.keyboardType = .numberPad
            textField.clearButtonMode = .whileEditing
            textField.borderStyle = .roundedRect
        }
        alertController.addAction(UIAlertAction(title: "OK", style: .default, handler: { action in
            guard let pinField = alertController.textFields?.first, let pin = pinField.text, !pin.isEmpty else {
                self.displayMessageDialog(result: "Pin entry can't be empty")
                return
            }
            
            completion(nil, pin)
        }))
        alertController.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        present(alertController, animated: true)
    }
}
