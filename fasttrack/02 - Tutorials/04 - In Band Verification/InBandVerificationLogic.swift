/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

typealias GenericOTPHandler = (Bool, String?, Error?) -> Void
typealias HTTPResponse   = (Data?, URLResponse?, Error?) -> Void

class InBandVerificationLogic {
    
    func verifyToken(withToken tokenDevice: EMProtectorOathTokenDevice,
                     pinAuthInput: EMProtectorAuthInput?, pin: String?,
                     completion: @escaping GenericOTPHandler) {
        do {
            let otpValue = try OtpLogic.generateOtp(token: tokenDevice, pinAuthInput: pinAuthInput, pin: pin)
            verifyToken(withTokenName: ProvisioningLogic.getTokenName(), otpValue: otpValue, completion: completion)
        } catch let error as NSError {
            completion(false, nil, error)
        }
    }
    
    func verifyToken(withTokenName tokenName: String, otpValue: OtpValue, completion: @escaping GenericOTPHandler) {
        var headers = [String:String]()
        headers["Authorization"] = InBandVerificationConfig.CFG_BASIC_AUTH_JWT
        headers["X-API-KEY"] = InBandVerificationConfig.CFG_BASIC_AUTH_API_KEY
        
        let input = [
            "userId": tokenName,
            "otp":otpValue.otp
        ]
        
        let body:[String:Any] = [
            "name": "Auth_OTP",
            "input": input
        ]
        
        requestPOST(InBandVerificationConfig.CFG_URL_AUTH, headers: headers, payload: body) { (data, urlResponse, error) in
            if error == nil && data != nil {
                do {
                    let responseDict = try JSONSerialization.jsonObject(with: data!, options: JSONSerialization.ReadingOptions(rawValue: 0)) as? [String:Any]
                    if let code = responseDict?.stringValue(path: "state.result.code") {
                        let message = responseDict?.stringValue(path: "state.result.message")!
                        completion(code == "0", message, nil)
                    } else {
                        completion(false, "Error parsing response from server", nil)
                    }
                }
                catch let error as NSError{
                    completion(false, nil, error)
                }
            } else {
                completion(false, nil, error)
            }
        }
    }
    
    func requestPOST(_ url: String, headers: [String: String], payload: [String: Any], completion: @escaping HTTPResponse) {
        var jsonData:Data! = nil
        do {
            jsonData = try JSONSerialization.data(withJSONObject: payload, options: JSONSerialization.WritingOptions(rawValue: 0))
        }
        catch let error as NSError{
            completion(nil, nil, error)
        }
        
        let sessionConfiguration:URLSessionConfiguration = URLSessionConfiguration.default
        let session:URLSession = URLSession.init(configuration: sessionConfiguration)
        let url:NSURL = NSURL.init(string: url)!
        let request:NSMutableURLRequest = NSMutableURLRequest.init(url: url as URL)
        request.timeoutInterval = 15
        request.addValue("application/json", forHTTPHeaderField: "Content-Type")
        request.addValue("application/json", forHTTPHeaderField: "Accept")
        request.addValue("\(jsonData.count)", forHTTPHeaderField: "Content-Length")
        for (headerKey, headerValue) in headers {
            request.addValue(headerValue, forHTTPHeaderField:headerKey )
        }
        request.httpBody = jsonData
        request.httpMethod = "POST"
        let postDataTask:URLSessionTask = session.dataTask(with: request as URLRequest) { (data, urlResponse, error) in
            DispatchQueue.main.async {
                completion(data, urlResponse, error)
            }
        }
        postDataTask.resume()
    }
    
}

extension Dictionary {
    func stringValue(path: String) -> String? {
        if let value = (self as NSDictionary).value(forKeyPath: path) as? String {
            return value
        } else {
            return nil
        }
    }
}
