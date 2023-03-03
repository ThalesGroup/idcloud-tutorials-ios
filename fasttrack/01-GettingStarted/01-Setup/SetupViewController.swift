/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
// Please make sure to review our IdCloud documentation, including security guidelines.

/**
 Main {@code UIViewController} for Setup use case.
 */
class SetupViewController: UIViewController, MainViewProtocol {

    @IBOutlet weak var loadingIndicator: LoadingView!

    override func viewDidLoad() {
        super.viewDidLoad()
        title = caption()
        SetupLogic.setup()
    }

    // MARK: MainViewProtocol methods.

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

    func displayMessageDialogError(error: Error?) {
        if let error = error {
            displayMessageDialog(result: error.localizedDescription)
        }
    }
    func displayOnCancelDialog(message: String, completionHandler: @escaping (Bool) -> Void) {
        // Main alert builder.
        let alert = UIAlertController(title: caption(), message: message, preferredStyle: .alert)

        // Add ok button with handler.
        alert.addAction(UIAlertAction(title: "Ok", style: .destructive, handler: {(action: UIAlertAction) -> Void in
            completionHandler(true)
        }))

        // Add cancel button with handler.
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: {(action: UIAlertAction) -> Void in
            completionHandler(false)
        }))

        // Present dialog.
        present(alert, animated: true)
    }

    func isLoadingBarPresent() -> Bool {
        return loadingIndicator.isPresent
    }

    func loadingBarShow(caption: String, animated: Bool) {
        loadingIndicator.loadingBarShow(caption: caption, animated: animated)
        updateGui()
    }

    func loadingBarHide(animated: Bool) {
        loadingIndicator.loadingBarHide(animated: animated)
        updateGui()
    }

    func updateGui() {
    }
}
