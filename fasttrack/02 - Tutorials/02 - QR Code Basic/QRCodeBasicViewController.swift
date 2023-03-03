/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.


class QRCodeBasicViewController: OtpViewController, QrCodeReaderDelegate {
    override func viewDidLoad() {
        super.viewDidLoad()
        provisionView.setQrCodeButtonVisible()
    }
    
    override func onProvisionUsingQr() {
        let qrCodeReaderVC = QrCodeReader(delegate: self)
        self.navigationController?.pushViewController(qrCodeReaderVC, animated: true)
    }
    
    func onQRCodeProvided(sender: QrCodeReader, qrCode: String) {
        let qrCodeLogic = QRCodeBasicLogic()
        qrCodeLogic.parseQRCode(qrCode) { (isSucceed, userId, regCode, error) in
            if(isSucceed) {
                self.onProvision(userId: userId!, registrationCode: regCode!)
            } else {
                self.displayMessageDialogError(error: error)
            }
        }
    }
}
