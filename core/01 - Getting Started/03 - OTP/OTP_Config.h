/*
 * Copyright © 2020-2023 THALES. All rights reserved.
 */

// IMPORTANT: This source code is intended to serve training information purposes only.
//            Please make sure to review our IdCloud documentation, including security guidelines.

/**
 Suite will set all relevant OCRA settings accordingly.
 
 @return OCRA Suite
 */
static id<EMSecureString> CFG_OCRA_SUITE()
{
    return [[[EMCore sharedInstance] secureContainerFactory] secureStringFromString:@""];
}

