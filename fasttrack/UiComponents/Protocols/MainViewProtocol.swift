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
