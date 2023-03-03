/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

/**
 Define OOB related behaviour on jailbroken devices.
 See EMOobJailbreakPolicy for more details.
 
 @return Jailbreak policy
 */
static EMOobJailbreakPolicy CFG_JAILBREAK_POLICY_OOB() {
    return EMOobJailbreakPolicyIgnore;
}

/**
 This configuration will allow to weaken TLS configuration for debug purposes. It’s not allowed to modify in release mode.
 
 @return TLS Configuration
 */
static EMTlsConfiguration *CFG_TLS_CONFIGURATION() {
    return [[EMTlsConfiguration alloc] initWithInsecureConnectionAllowed:NO
                                                   selfSignedCertAllowed:NO
                                                 hostnameMismatchAllowed:NO];
}

// Review: SNE add javadoc
static EMDeviceFingerprintSource *CFG_DEVICE_FINGERPRINT_SOURCE() {
    NSData *customFP = [@"" dataUsingEncoding:NSUTF8StringEncoding];
    return [[EMDeviceFingerprintSource alloc] initWithCustomData:customFP
                                           deviceFingerprintType:[NSSet setWithObject:@(EMDeviceFingerprintTypeSoft)]];
}
