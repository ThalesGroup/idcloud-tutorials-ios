/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.


class TransactionSignViewController: ChangePinViewController, UITextFieldDelegate {
    @IBOutlet weak var textAmountTextField: UITextField!
    @IBOutlet weak var textBeneficiaryTextField: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        textAmountTextField.delegate = self
        textBeneficiaryTextField.delegate = self
    }
    
    func generateOtp(_ token: EMProtectorOathTokenDevice,
                     pinAuthInput: EMProtectorAuthInput?,
                     pin: String?,
                     amount: String, beneficiary: String) {
        var otpValue: OtpValue?
        do {
            otpValue = try TransactionSignLogic.generateOtp(token, pinAuthInput: pinAuthInput, pin: pin, amount: amount, beneficiary: beneficiary)
            displayOTP(value: otpValue!.otp, lifespan: otpValue!.lifespan)
        } catch let error as NSError {
            displayMessageDialogError(error: error)
        }
    }
    
    @IBAction func buttonGenerateSignatureOTPPressed(_ sender: Any) {
        let oathProtector = ProvisioningLogic.getOathProtector()
        let ocraSettings = EMProtectorOcraSettings.init()
        ocraSettings.ocraSuite = OtpConfig.getOcraSuite()
        var token:EMProtectorOathTokenDevice?
        do {
            if let tokenNames: Set<String> = try? oathProtector?.tokenDeviceNames(), !tokenNames.isEmpty {
                token = try? oathProtector?.tokenDevice(name: tokenNames.first!, fingerprintCustomData: ProvisioningConfig.getCustomFingerprintData(), ocraSettings: ocraSettings)
            }
        }
        
        showPinInput { [self] authInput, pin in
            generateOtp(token!, pinAuthInput: authInput, pin: pin, amount: textAmountTextField.text!, beneficiary: textBeneficiaryTextField.text!)
        }
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        if textField.isEqual(self.textAmountTextField) {
            self.textBeneficiaryTextField .becomeFirstResponder()
        }
        return true
    }
}
