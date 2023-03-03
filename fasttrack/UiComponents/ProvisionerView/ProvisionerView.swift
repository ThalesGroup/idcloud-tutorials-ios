/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
// Please make sure to review our IdCloud documentation, including security guidelines.

/**
 Provisioning view delegate.
 */
protocol ProvisioningViewDelegate: NSObject {
    /**
     User triggered provision process.
     
     @param userId User identifier.
     @param regCode Registration code.
     */
    func onProvision(userId: String, registrationCode: String)
    
    /**
     * User triggered provision process using Qr Code Reader.
     */
    func onProvisionUsingQr()
    
    /**
     Triggered when user decided to remove token.
     */
    func onRemoveToken()
}

/**
 Provisioning view.
 */
@IBDesignable
class ProvisionerView: UIView {
    @IBOutlet weak var textUserId: UITextField!
    @IBOutlet weak var textRegistrationCode: UITextField!
    @IBOutlet weak var buttonProvision: UIButton!
    @IBOutlet weak var buttonProvisionUsingQR: UIButton!
    @IBOutlet weak var buttonRemoveToken: UIButton!
    weak var delegate: (ProvisioningViewDelegate & MainViewProtocol)? = nil
    
    // MARK: Life cycle.
    override init(frame: CGRect) {
        super.init(frame: frame)
        setup(withFrame: frame)
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
        setup(withFrame: bounds)
    }
    
    // MARK: Public methods
    func updateGUI(enabled: Bool, token: EMProtectorOathTokenDevice?) {
        textUserId.isUserInteractionEnabled = enabled && token == nil
        textRegistrationCode.isUserInteractionEnabled = enabled && token == nil
        buttonProvision.isEnabled = enabled && token == nil
        buttonProvisionUsingQR.isEnabled = enabled && token == nil
        buttonRemoveToken.isEnabled = enabled && token != nil
    }
    // MARK: Private methods.
    /**
     Setups the view.
     */
    private func setup(withFrame frame: CGRect) {
        // Color is used as placeholder in case of disabled IB_DESIGNABLE
        backgroundColor = UIColor.clear
        // Get our view from storyboard.
        if let contentView = Bundle.main.loadNibNamed("ProvisionerView", owner: self, options: nil)?.first as? UIView {
            // Add it as child of current View.
            contentView.layer.cornerRadius = 20.0
            contentView.frame = frame
            addSubview(contentView)
        }
        buttonProvisionUsingQR.isHidden = true
        // Used to handle return key.
        textUserId.delegate = self
        textRegistrationCode.delegate = self
    }
    // MARK: - User Interface
    /**
     Pressed provision button.
     */
    @IBAction private func onButtonPressedProvision(_ sender: Any) {
        if textUserId.text?.count == 0 {
            delegate?.displayMessageDialog(result: NSLocalizedString("STRING_PROVISION_MISSING_USER_ID", comment: ""))
            return
        } else if textRegistrationCode.text?.count == 0 {
            delegate?.displayMessageDialog(result: NSLocalizedString("STRING_PROVISION_MISSING_REG_CODE", comment: ""))
            return
        }
        delegate?.onProvision(userId: textUserId.text!, registrationCode: textRegistrationCode.text!)
    }
    /**
     Pressed remove token button.
     */
    @IBAction private func onButtonPressedRemoveToken(_ sender: Any) {
        delegate?.displayOnCancelDialog(message: "", completionHandler: { (result: Bool) in
            if result {
                self.delegate?.onRemoveToken()
            }
        })
    }
    
    @IBAction private func onProvisionUsingQr (_ sender: Any) {
        delegate?.onProvisionUsingQr()
    }
    
    func setQrCodeButtonVisible() {
        self.buttonProvisionUsingQR.isHidden = false
    }
}

// MARK: - UITextFieldDelegate

extension ProvisionerView: UITextFieldDelegate {
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        // Hide current keyboard.
        textField.resignFirstResponder()
        // Jump to next one.
        if textField.isEqual(textUserId) {
            textRegistrationCode.becomeFirstResponder()
        }
        return true
    }
}
