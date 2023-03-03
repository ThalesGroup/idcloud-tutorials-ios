/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
// Please make sure to review our IdCloud documentation, including security guidelines.

/**
 Main view protocol.
 */
protocol MainViewProtocol: NSObject {
    /**
     Caption will be displayed in navigation bar as name of current sample app.
     
     @return Name of sample app.
     */
    func caption() -> String
    /**
     Common method to display information to user. Currently implemented as simple dialog with app name in caption.
     
     @param result Message to be displayed.
     */
    func displayMessageDialog(result: String)
    
    /**
     Display description of error if it's not nil using displayMessageDialog method.
     
     @param error Application error or nil.
     */
    func displayMessageDialogError(error: Error?)
    /**
     Display generic On / Cancel dialog with asynchronous handler.
     
     @param message Desired dialog message.
     @param handler Completion handler triggered once user will select either option.
     */
    func displayOnCancelDialog(message: String, completionHandler: @escaping (_ result: Bool) -> Void)
    /**
     Return whenever is loading overlay displayd.
     
     @return YES if loading overlay is present, otherwise NO.
     */
    func isLoadingBarPresent() -> Bool
    /**
     Display overlay loading view and call update method so rest of UI might be disabled.
     
     @param caption Text displayed on loading bar.
     @param animated Whenever should be displayed with animation or instantly.
     */
    func loadingBarShow(caption: String, animated: Bool)
    /**
     Hide loading bar if it's present and call update method for rest of UI.
     
     @param animated Whenever should be hide with animation or instantly.
     */
    func loadingBarHide(animated: Bool)
    /**
     Method triggered whenever logic layer is updated so UI can reflect this change.
    */
    func updateGui()
}
