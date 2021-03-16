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
 Result view.
 */
class ResultView: UIView {
    @IBOutlet weak var labelOtp: UILabel!
    @IBOutlet var progressOtp: UIProgressView!
    
    // MARK: Life cycle.
    override init(frame: CGRect) {
        super.init(frame: frame)
        
        setup(withFrame: frame)
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
        setup(withFrame: bounds)
    }
    
    // MARK: - Public API
    /**
     Hides the OTP view.
     */
    func hide() {
        labelOtp.text = ""
        labelOtp.isHidden = true
        progressOtp.isHidden = true
        progressOtp.layer.removeAllAnimations()
    }
    /**
     Shows the OTP view.
     @param value OTP value.
     @param lifespan OTP lifespan.
     */
    func show(value: String, lifespan: Lifespan) {
        // Ignore same values
        if labelOtp.text == value {
            return
        }
        // Finish all previous animations.
        if let sublayers: [CALayer] = progressOtp.layer.sublayers {
            for layer in sublayers {
                layer.removeAllAnimations()
            }
        }
        // Unhide OTP label and set default values
        labelOtp.textColor = UIColor.black
        labelOtp.isHidden = false
        labelOtp.text = value
        // Unhide progress and set value to current remaining value.
        progressOtp.isHidden = false
        progressOtp.progress = Float(lifespan.current) / Float(lifespan.max)
        progressOtp.layoutIfNeeded()
        // Animate time.
        UIView.animate(withDuration: Double(lifespan.current), animations: {
            self.progressOtp.progress = 0.000001 // .0f does not work on iOS 13.x
            self.progressOtp.layoutIfNeeded()
        }) { (finished: Bool) in
            if finished {
                self.labelOtp.textColor = UIColor.gray
            }
        }
    }
    
    // MARK: Private methods.
    /**
     Setups the view.
     */
    private func setup(withFrame frame: CGRect) {
        // Color is used as placeholder in case of disabled IB_DESIGNABLE
        backgroundColor = UIColor.clear
        // Get our view from storyboard.
        if let contentView = Bundle.main.loadNibNamed("ResultView", owner: self, options: nil)?.first as? UIView {
            // Add it as child of current View.
            contentView.frame = frame
            addSubview(contentView)
        }
    }
}
