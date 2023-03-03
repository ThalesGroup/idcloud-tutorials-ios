/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.


class AdvancedSetupViewController: UIViewController {
    override func viewDidLoad() {
        super.viewDidLoad()
        AdvancedSetupLogic.setup()
        title = caption()
    }
    
    func caption() -> String {
        return Bundle.main.infoDictionary!["CFBundleName"] as! String
    }
    
    func displayMessageDialog(result: String) {
         // Main alert builder.
         let alert = UIAlertController(title: caption(), message: result, preferredStyle: .alert)
         // Add basic OK button without any handlers.
         alert.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
         // Present dialog.
         present(alert, animated: true)
     }
}
