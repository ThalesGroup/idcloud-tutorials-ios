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


class BiometricIdViewController: OtpViewController {
    @IBOutlet weak private var systemBiometricSwitch: UISwitch!
    @IBOutlet weak private var otpWithSystemBiometricButton: UIButton!
    var biometricIdLogic = BiometricIdLogic()
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        systemBiometricSwitch.isEnabled = biometricIdLogic.isSystemBiometricSupported() && ProvisioningLogic.isProvisioned()
        systemBiometricSwitch.isOn = biometricIdLogic.isSystemBiometricActivated()
        otpWithSystemBiometricButton.isEnabled = biometricIdLogic.isSystemBiometricActivated()
    }
    
    override func updateGui() {
        super.updateGui()
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
                showSecureKeypadPinInput { (pinAuthInput) in
                    self.biometricIdLogic.activateSystemBiometric(pinAuthInput: pinAuthInput) { (isSucceed, error) in
                        self.otpWithSystemBiometricButton.isEnabled = isSucceed
                        sender.isOn = isSucceed
                        if let error = error {
                            self.displayMessageDialogError(error: error)
                        }
                    }
                }
            }
        } else {
            biometricIdLogic.deactivateSystemBiometric { (isSucceed, error) in
                self.otpWithSystemBiometricButton.isEnabled = !isSucceed
                sender.isOn = !isSucceed
                if let error = error {
                    self.displayMessageDialogError(error: error)
                }
            }

        }
    }
}
