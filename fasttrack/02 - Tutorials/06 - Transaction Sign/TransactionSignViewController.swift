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
    
    func generateOtp(_ token: EMProtectorOathTokenDevice, pinAuthInput: EMProtectorAuthInput, amount: String, beneficiary: String) {
        var otpValue: OtpValue?
        do {
            otpValue = try TransactionSignLogic.generateOtp(token, pinAuthInput: pinAuthInput, amount: amount, beneficiary: beneficiary)
            displayOTP(value: otpValue!.otp, lifespan: otpValue!.lifespan)
        } catch let error as NSError {
            displayMessageDialogError(error: error)
        }
    }
    
    @IBAction func buttonGenerateSignatureOTPPressed(_ sender: Any) {
        showSecureKeypadPinInput { [self] (pinInput) in
            let pinAuthInput = EMProtectorAuthInput.init(authInput: pinInput)
            self.generateOtp(ProvisioningLogic.getToken()!, pinAuthInput: pinAuthInput, amount: self.textAmountTextField.text!, beneficiary: self.textBeneficiaryTextField.text!)
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
