/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
// Please make sure to review our IdCloud documentation, including security guidelines.

/**
 Indicator view.
 */
@IBDesignable
class LoadingView: UIView {
    private static let VISIBILITY: CGFloat = 0.75
    @IBOutlet weak var indicator: UIActivityIndicatorView!
    @IBOutlet weak var labelCaption: UILabel!
    private (set) var isPresent: Bool = true
    
    // MARK: Life cycle.
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        setup(withFrame: frame)
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
        setup(withFrame: bounds)
    }
    // MARK: Public methods.
    /**
     Shows the loading bar.
     
     @param caption Label caption.
     @param animated {@code True} if animated, else {@code false}.
     */
    func loadingBarShow(caption: String, animated: Bool) {
        loadingBarShow(caption, show: true, animated: animated)
    }
    
    /**
     Hides the loading bar.
     
     @param caption Label caption.
     @param animated {@code True} if animated, else {@code false}.
     */
    func loadingBarHide(animated: Bool) {
        loadingBarShow(nil, show: false, animated: animated)
    }
    
    // MARK: Private methods.
    /**
     Shows / hides the loading bar.
     
     @param caption Label caption.
     @param show {@code True} if loading bar should be shown, {@code false} if loding bar should be hidden.
     @param animated {@code True} if animated, else {@code false}.
     */
    private func loadingBarShow(_ caption: String?, show: Bool, animated: Bool) {
        // Avoid multiple call with same result.
        if isPresent == show {
            return
        }

        // Start / Stop iOS loading indicator animation.
        if show {
            indicator.startAnimating()
        } else {
            indicator.stopAnimating()
        }

        // Stop any possible previous animations since we are not waiting for result.
        layer.removeAllAnimations()

        // Animate transition.
        if animated {
            if show {
                // Update caption
                labelCaption.text = caption
                isHidden = false
            }

            // Animate loading bar with some easing.
            UIView.animate(withDuration: 0.5, delay: 0.0, options: .curveEaseOut, animations: {
                self.alpha = show ? LoadingView.VISIBILITY : 0.0
            }) { (finished: Bool) in
                if finished && !show {
                    self.labelCaption.text = nil
                    self.isHidden = true
                }
            }
        } else {
            // Update caption
            labelCaption.text = caption

            alpha = show ? LoadingView.VISIBILITY : 0.0
            isHidden = !show
        }

        isPresent = show
    }

    /**
     Setups the view.
     */
    private func setup(withFrame frame: CGRect) {
        // Color is used as placeholder in case of disabled IB_DESIGNABLE
        backgroundColor = UIColor.clear

        // Get our view from storyboard.
        if let contentView = Bundle.main.loadNibNamed("LoadingView", owner: self, options: nil)?.first as? UIView {
            contentView.layer.cornerRadius = 20.0
            contentView.frame = frame
            // Add it as child of current View.
            addSubview(contentView)
        }

        // Set visibility to true so internal check will not skip call
        isPresent = true

        // By default it should be hidden.
        loadingBarHide(animated: false)
    }
}
