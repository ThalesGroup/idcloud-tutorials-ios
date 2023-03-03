/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.


class SecureKeypadViewController: UIViewController {
    override func viewDidLoad() {
        AdvancedSetupLogic.setup()
    }
    
    // MARK: - User interface
    @IBAction private func variant1ButtonPressed(_ sender: Any) {
        /* SDK Limitation: Reference for dismissing modal view on finish, although self.presentedViewController could do the work */
        var keyPadVC: UIViewController!
        // 1. Create the builder for the keypad
        let uiModule: EMUIModule = EMUIModule.init()
        let secureInputService: EMSecureInputService = EMSecureInputService.init(module: uiModule)
        let sBuilder: EMSecureInputBuilder = secureInputService.secureInputBuilder()
        sBuilder.setScreenBackgroundColor(UIColor.init(red: 249, green: 254, blue: 255, alpha: 1))
        sBuilder.setKeys("1234567890".data(using: .utf16), andSubscripts: ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"])
        sBuilder.setOkButtonText(" ")
        sBuilder.setDeleteButtonText(" ")
        sBuilder.setDistanceBetweenKeyAndSubscript(2)
        sBuilder.setKeypadGridGradientColors(UIColor.init(red: 84, green: 84, blue: 84, alpha: 1), gridGradientEnd: UIColor.init(red: 0, green: 0, blue: 0, alpha: 1))
        sBuilder.setButtonPressedVisibility(true)
        sBuilder.setOkButtonImage(UIImage.init(named: "baseline_done_outline_black_48pt"))
        sBuilder.setOkButtonImageOpacity(0.75, for: .normal)
        sBuilder.setOkButtonImageOpacity(0.5, for: .selected)
        sBuilder.setOkButtonImageOpacity(0.25, for: .disabled)
        sBuilder.setDeleteButtonImage(UIImage.init(named: "baseline_delete_outline_black_48pt"))
        sBuilder.setOkButtonImageOpacity(0.75, for: .normal)
        sBuilder.setOkButtonImageOpacity(0.5, for: .selected)
        sBuilder.setOkButtonImageOpacity(0.25, for: .disabled)
        sBuilder.setButtonGradientColors(UIColor.init(red: 255, green: 255, blue: 255, alpha: 1), buttonGradientEnd: UIColor.init(red: 239, green: 239, blue: 244, alpha: 1), for: .normal)
        sBuilder.setButtonGradientColors(UIColor.init(red: 239, green: 239, blue: 244, alpha: 1), buttonGradientEnd: UIColor.init(red: 239, green: 239, blue: 244, alpha: 1), for: .selected)
        sBuilder.setMinimumInputLength(3, andMaximumInputLength: 3)
        sBuilder.setOkButtonBehavior(.custom)
        /* 2. Build the EMSecureInputUi which contains the view controller and keypadview */
        let inputUI: EMSecureInputUi = sBuilder.build(withScrambling: false, isDoubleInputField: false, displayMode: EMSecureInputUiDisplayMode.fullScreen) { [weak self](firstPin, secondPin) in
            if self != nil {
                /* 4.1 Dismiss the view */
                keyPadVC.dismiss(animated: true, completion: nil)
                /* 4.2 Always wipe the builder after use */
                sBuilder.wipe()
                keyPadVC = nil
            }
        }
        /* 3.1 Get the view controller from the EMSecureInputUi object and present accordingly */
        keyPadVC = inputUI.viewController
        /* 3.2 Present according presentation style */
        self.present(keyPadVC, animated: true, completion: nil)
    }
    
    @IBAction private func variant2ButtonPressed(_ sender: Any) {
        /* SDK Limitation: Reference for dismissing modal view on finish, although self.presentedViewController could do the work */
        var keyPadVC: UIViewController!
        // 1. Create the builder for the keypad
        let uiModule: EMUIModule = EMUIModule.init()
        let secureInputService: EMSecureInputService = EMSecureInputService.init(module: uiModule)
        let sBuilder: EMSecureInputBuilder = secureInputService.secureInputBuilder()
        sBuilder.setNumberOfRows(4, andColumns: 4)
        sBuilder.setKeypadHeightRatio(0.25)
        sBuilder.setButtonBorderWidth(3)
        sBuilder.setKeypadFrameColor(UIColor.init(red: 121, green: 128, blue: 255, alpha: 1))
        sBuilder.setKeypadGridGradientColors(UIColor.init(red: 121, green: 128, blue: 255, alpha: 1), gridGradientEnd: UIColor.init(red: 121, green: 128, blue: 255, alpha: 1))
        /* 2. Build the EMSecureInputUi which contains the view controller and keypadview */
        let inputUI: EMSecureInputUi = sBuilder.build(withScrambling: true, isDoubleInputField: true, displayMode: EMSecureInputUiDisplayMode.fullScreen) { [weak self](firstPin, secondPin) in
            if self != nil {
                /* 4.1 Dismiss the view */
                keyPadVC.dismiss(animated: true, completion: nil)
                /* 4.2 Always wipe the builder after use */
                sBuilder.wipe()
                keyPadVC = nil
            }
        }
        /* 3.1 Get the view controller from the EMSecureInputUi object and present accordingly */
        keyPadVC = inputUI.viewController
        /* 3.2 Present according presentation style */
        self.present(keyPadVC, animated: true, completion: nil)
    }
    
    @IBAction private func variant3ButtonPressed(_ sender: Any) {
        /* SDK Limitation: Reference for dismissing modal view on finish, although self.presentedViewController could do the work */
        var keyPadVC: UIViewController!
        // 1. Create the builder for the keypad
        let uiModule: EMUIModule = EMUIModule.init()
        let secureInputService: EMSecureInputService = EMSecureInputService.init(module: uiModule)
        let sBuilder: EMSecureInputBuilder = secureInputService.secureInputBuilder()
        sBuilder.setFirstLabel("Old Pin")
        sBuilder.setSecondLabel("New Pin")
        sBuilder.setLabel(UIColor.init(red: 0, green: 0, blue: 0, alpha: 1))
        sBuilder.setLabelFontSize(30)
        sBuilder.setLabelAlignment(.left)
        sBuilder.setInputFieldBackgroundColor(UIColor.init(displayP3Red: 121, green: 128, blue: 255, alpha: 1), for: .focused)
        /* 2. Build the EMSecureInputUi which contains the view controller and keypadview */
        let inputUI: EMSecureInputUi = sBuilder.build(withScrambling: false, isDoubleInputField: true, displayMode: EMSecureInputUiDisplayMode.fullScreen) { [weak self](firstPin, secondPin) in
            if self != nil {
                /* 4.1 Dismiss the view */
                keyPadVC.dismiss(animated: true, completion: nil)
                /* 4.2 Always wipe the builder after use */
                sBuilder.wipe()
                keyPadVC = nil
            }
        }
        /* 3.1 Get the view controller from the EMSecureInputUi object and present accordingly */
        keyPadVC = inputUI.viewController
        /* 3.2 Present according presentation style */
        self.present(keyPadVC, animated: true, completion: nil)
    }
    
    @IBAction private func variant4ButtonPressed(_ sender: Any) {
        /* SDK Limitation: Reference for dismissing modal view on finish, although self.presentedViewController could do the work */
        var keyPadVC: UIViewController!
        // 1. Create the builder for the keypad
        let uiModule: EMUIModule = EMUIModule.init()
        let secureInputService: EMSecureInputService = EMSecureInputService.init(module: uiModule)
        let sBuilder: EMSecureInputBuilder = secureInputService.secureInputBuilder()
        sBuilder.setFirstLabel("Enter Password")
        sBuilder.setMinimumInputLength(6, andMaximumInputLength: 16)
        sBuilder.setNumberOfRows(6, andColumns: 6)
        sBuilder.setKeys("abcdefghijklmnopqrstuvwxyz" .data(using: .utf16))
        sBuilder.setIsDeleteButtonAlwaysEnabled(true)
        /* 2. Build the EMSecureInputUi which contains the view controller and keypadview */
        let inputUI: EMSecureInputUi = sBuilder.build(withScrambling: true, isDoubleInputField: false, displayMode: EMSecureInputUiDisplayMode.fullScreen) { [weak self](firstPin, secondPin) in
            if self != nil {
                /* 4.1 Dismiss the view */
                keyPadVC.dismiss(animated: true, completion: nil)
                /* 4.2 Always wipe the builder after use */
                sBuilder.wipe()
                keyPadVC = nil
            }
        }
        /* 3.1 Get the view controller from the EMSecureInputUi object and present accordingly */
        keyPadVC = inputUI.viewController
        /* 3.2 Present according presentation style */
        self.present(keyPadVC, animated: true, completion: nil)
    }
}
