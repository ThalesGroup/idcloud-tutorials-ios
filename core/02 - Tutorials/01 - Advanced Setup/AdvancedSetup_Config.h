/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

/**
 Define Token related behaviour on jailbroken devices.
 See EMTokenJailbreakPolicy for more details.
 
 @return Jailbreak policy
 */
static EMTokenJailbreakPolicy CFG_JAILBREAK_POLICY_OTP() {
    return EMTokenJailbreakPolicyIgnore;
}
