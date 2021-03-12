/* -----------------------------------------------------------------------------
 *
 *     Copyright (c) 2018  -  GEMALTO DEVELOPMENT - R&D
 *
 * -----------------------------------------------------------------------------
 * GEMALTO MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF
 * THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, OR NON-INFRINGEMENT. GEMALTO SHALL NOT BE
 * LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
 * MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
 *
 * THIS SOFTWARE IS NOT DESIGNED OR INTENDED FOR USE OR RESALE AS ON-LINE
 * CONTROL EQUIPMENT IN HAZARDOUS ENVIRONMENTS REQUIRING FAIL-SAFE
 * PERFORMANCE, SUCH AS IN THE OPERATION OF NUCLEAR FACILITIES, AIRCRAFT
 * NAVIGATION OR COMMUNICATION SYSTEMS, AIR TRAFFIC CONTROL, DIRECT LIFE
 * SUPPORT MACHINES, OR WEAPONS SYSTEMS, IN WHICH THE FAILURE OF THE
 * SOFTWARE COULD LEAD DIRECTLY TO DEATH, PERSONAL INJURY, OR SEVERE
 * PHYSICAL OR ENVIRONMENTAL DAMAGE ("HIGH RISK ACTIVITIES"). GEMALTO
 * SPECIFICALLY DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTY OF FITNESS FOR
 * HIGH RISK ACTIVITIES.
 *
 * -----------------------------------------------------------------------------
 */

#ifndef em_auth_pin_enums_h
#define em_auth_pin_enums_h

/**
 * Integer parameter definition, defines pin type
 * - Since: 4.1
 */
typedef enum EMPinType {
    /**
     * PIN used for token on the application side
     */
    EMPinTypeUserPin  = 1,
    
    /**
     * PIN used for token on the server side
     */
    EMPinTypeServerPin = 2,
    
    /**
     * No PIN, the SDK handle
     */
    EMPinTypeNoPin = 3,
    
    /**
     * EMPinTypeUnknown - unknown parameter
     */
    EMPinTypeUnknown
} EMPinType;

/**
 * Defines the complexity of the PIN/passcode
 * - Since: 4.1
 */
typedef enum EMPinComplexity {
    
    /**
     * Numeric PIN, 0-9
     */
    EMPinComplexityNumeric,
    
    /**
     * AlphaNumeric PIN, 0-9, a-z, A-Z
     */
    EMPinComplexityAlphaNumeric,
    
    /**
     * AlphaNumeric PIN, 0-9, a-z, A-Z,
     * at least 1 number, 1 upper case, 1 lower case
     */
    EMPinComplexityStrongAlphaNumeric,
    
    /**
     * AlphaNumeric PIN, 0-9, a-z, A-Z,
     * at least 1 number, 1 upper case, 1 lower case
     * no consecutive repetition
     */
    EMPinComplexityComplexAlphaNumeric,
    
    /**
     * EMPinComplexityUnknown - unknown parameter
     */
    EMPinComplexityUnknown
} EMPinComplexity;

/**
 * Type of PIN policy.
 *
 * - PinPolicyTypeDskppV1ServerPin: DSKPP V1 server PIN policy.
 * - PinPolicyTypeDskppV1LocalPin: DSKPP V1 local (user, no-pin) PIN policy.
 */
typedef enum EMPinPolicyType{
    
    /**
     * Undefined policy type.
     */
    EMPinPolicyTypeUndefined        = 0,
    
    /**
     * DSKPP V1 server PIN policy.
     */
    EMPinPolicyTypeDskppV1ServerPin = 1,
    
    /**
     * DSKPP V1 local (user, no-pin) PIN policy.
     */
    EMPinPolicyTypeDskppV1LocalPin  = 2
} EMPinPolicyType;

#endif /* em_auth_pin_enums_h */
