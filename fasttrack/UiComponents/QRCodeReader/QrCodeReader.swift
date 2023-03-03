/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

import AVFoundation

class QrCodeReader:UIViewController {
    
    // MARK: - Defines
    
    private var captureSession: AVCaptureSession!
    private var capturePreview: AVCaptureVideoPreviewLayer!
    weak var delegate: QrCodeReaderDelegate?
    private var wasProcessed: Bool = false
    
    @IBOutlet weak var cameraLayer: UIView!
    
    // MARK: - Life Cycle
    
    class func readerWithDelegate(delegate: QrCodeReaderDelegate!) -> QrCodeReader {
        return QrCodeReader(delegate: delegate)
    }
    
    init(delegate: QrCodeReaderDelegate) {
        super.init(nibName: "QrCodeReader",
                   bundle: Bundle(for: QrCodeReader.self))
        
        modalPresentationStyle = UIModalPresentationStyle.fullScreen
        self.delegate = delegate
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        captureStart()
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        captureStop()
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        
        // This is enough to have proper size, but orientation might not be handled.
        captureUpdateBounds()
    }
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
        // This way we might reload constraint multiple times, but it will solve issue with 180 degree landscape change.
        // And trigger viewDidLayoutSubviews even during such rotation.
        cameraLayer.setNeedsLayout()
        view.setNeedsLayout()
    }
    
    // MARK: - Helpers
    
    func caption() -> String {
        return Bundle.main.infoDictionary!["CFBundleName"] as! String
    }
    
    private func captureStart() {
        // We want to notify handler just once.
        wasProcessed = false
        
        // Try to prepare capture device. This is not going to work on emulator and devices without camera in general.
        // Also user might not give permissions for camera.
        guard let captureDevice = AVCaptureDevice.default(for: AVMediaType.video) else {
            self.displayMessageDialog(message: "Failed to create capture device.")
            return
        }
        do {
            let input = try AVCaptureDeviceInput(device: captureDevice)
            // Setup capture session. Output must be added before setting metadata types.
            let captureMetadataOutput = AVCaptureMetadataOutput()
            captureSession = AVCaptureSession()
            captureSession.addInput(input)
            captureSession.addOutput(captureMetadataOutput)
            
            // Define callback and detection type to QR.
            captureMetadataOutput.setMetadataObjectsDelegate(self, queue: DispatchQueue.main)
            captureMetadataOutput.metadataObjectTypes = [AVMetadataObject.ObjectType.qr]
            
            // Add preview layer to UI.
            capturePreview = AVCaptureVideoPreviewLayer(session: captureSession)
            capturePreview.videoGravity = AVLayerVideoGravity.resizeAspectFill
            cameraLayer.layer.addSublayer(capturePreview)
            
            // Update default bounds. But at this point it might not be loaded yet.
            captureUpdateBounds()
            
            // Run capturing
            captureSession.startRunning()
        } catch let error {
            self.displayMessageDialog(message:error.localizedDescription)
        }
    }
    
    private func captureStop() {
        // Stop and release all reader related items.
        if captureSession != nil {
            captureSession.stopRunning()
            captureSession = nil
            
            capturePreview.removeFromSuperlayer()
            capturePreview = nil
        }
        delegate = nil
    }
    
    private func captureUpdateBounds() {
        // In case that something went wrong during init.
        if (capturePreview == nil) {
            return
        }
        
        // Fill up full view frame
        capturePreview.frame = view.layer.bounds
        capturePreview.position = CGPoint(x: capturePreview.frame.midX, y: capturePreview.frame.midY)
        
        // Update orientation
        if let connection = capturePreview.connection, connection.isVideoOrientationSupported {
            connection.videoOrientation = videoOrientation()
        }
    }
    
    // Return proper otientation for preview. Enum is different than statusbar one.
    private func videoOrientation() -> AVCaptureVideoOrientation {
        switch UIApplication.shared.statusBarOrientation {
        case .landscapeLeft:
            return AVCaptureVideoOrientation.landscapeLeft
        case .landscapeRight:
            return AVCaptureVideoOrientation.landscapeRight
        case .portrait, .unknown:
            return AVCaptureVideoOrientation.portrait
        case .portraitUpsideDown:
            return AVCaptureVideoOrientation.portraitUpsideDown
        @unknown default:
            return AVCaptureVideoOrientation.portrait
        }
    }
    
    func displayMessageDialog(message: String) {
        // Main alert builder.
        let alert = UIAlertController(title: caption(), message: message, preferredStyle: .alert)
        // Add basic OK button without any handlers.
        alert.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
        // Present dialog.
        present(alert, animated: true)
    }
    
    // MARK: - User Interface
    
    @IBAction private func onButtonPressedCancel(_ sender: UIButton) {
        dismiss(animated: true, completion: nil)
    }
}

// MARK: - AVCaptureMetadataOutputObjectsDelegate

extension QrCodeReader: AVCaptureMetadataOutputObjectsDelegate {
    func metadataOutput(_ output: AVCaptureMetadataOutput,
                        didOutput metadataObjects: [AVMetadataObject],
                        from connection: AVCaptureConnection) {
        // Continue only if there is just one item detected and nothing was processed yet.
        if metadataObjects.count != 1 || wasProcessed {
            return
        }
        
        // We are interested in QR only.
        guard let metadataObj = metadataObjects.first as? AVMetadataMachineReadableCodeObject, metadataObj.type == AVMetadataObject.ObjectType.qr else {
            return
        }
        
        // Process only valid QR codes.
        if let qrCode = metadataObj.stringValue {
            // Mark as processed so we will not trigger handler multiple times.
            wasProcessed = true
            
            // Notify listener
            delegate?.onQRCodeProvided(sender: self, qrCode: qrCode)
        }
        self.navigationController?.popViewController(animated: true)
    }
}

protocol QrCodeReaderDelegate: AnyObject {
    /**
     Triggered once QR code is successfully parsed.
     
     @param sender Instance of QR Code reader. So we can check custom tag etc.
     @param qrCode Parsed code data.
     */
    func onQRCodeProvided(sender: QrCodeReader, qrCode: String)
}
