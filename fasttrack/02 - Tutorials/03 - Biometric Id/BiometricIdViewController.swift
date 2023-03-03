/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.


class BiometricIdViewController: QRCodeBasicViewController {
    @IBOutlet weak private var systemBiometricSwitch: UISwitch!
    @IBOutlet weak private var otpWithSystemBiometricButton: UIButton!
    var biometricIdLogic = BiometricIdLogic()
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewWillAppear(_ animated: Bool) {
    }
    
    override func updateGui() {
        super.updateGui()
    }
    
    override func onUpdateViewControllerSpecificUI() {
        systemBiometricSwitch.isEnabled = biometricIdLogic.isSystemBiometricSupported() && ProvisioningLogic.isProvisioned()
        systemBiometricSwitch.isOn = biometricIdLogic.isSystemBiometricActivated()
        otpWithSystemBiometricButton.isEnabled = biometricIdLogic.isSystemBiometricActivated()
    }
    
    @IBAction private func buttonGenerateOTPWithSystemBiometricPressed(_ sender: Any) {
        biometricIdLogic.otpWithSystemBiometric { (otp, error) in
            if let otpError = error {
                self.displayMessageDialogError(error: otpError)
            } else {
                self.displayOTP(value: otp!, lifespan: Lifespan.init(current: self.biometricIdLogic.oathTokenDevice!.lastOtpLifeSpan(), max: 30))
            }
        }
    }
    
    @IBAction private func buttonSystemBiometricToggled(_ sender: UISwitch) {
        let shouldEnabled = sender.isOn
        if shouldEnabled {
            if biometricIdLogic.isSystemBiometricActivated() {
                displayMessageDialog(result: "system biometric is already activated")
            } else {
                showPinInput { pinAuthInput, pin in
                    self.biometricIdLogic.activateSystemBiometric(pinAuthInput: pinAuthInput, pin: pin) { (isSucceed, error) in
                        self.otpWithSystemBiometricButton.isEnabled = isSucceed
                        sender.isOn = isSucceed
                        self.displayMessageDialogError(error: error)
                    }
                }
            }
        } else {
            biometricIdLogic.deactivateSystemBiometric { (isSucceed, error) in
                self.otpWithSystemBiometricButton.isEnabled = !isSucceed
                sender.isOn = !isSucceed
                self.displayMessageDialogError(error: error)
            }
        }
    }
}
