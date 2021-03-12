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


#ifndef em_otp_enums_h
#define em_otp_enums_h

/**
 * Type of token policy.
 *
 * - TokenPolicyTypeDskppV1: DSKPP V1 token policy.
 */
typedef enum EMTokenPolicyType
{
    /**
     * Undefined token policy.
     */
    EMTokenPolicyTypeUndefined  = 0,

    /**
     * DSKPP V1 token policy.
     */
    EMTokenPolicyTypeDskppV1    = 1
} EMTokenPolicyType;

/**
 * The kek pseudo random function
 * - Since: 5.0
 */
typedef enum EMKekPrfAlgorithm
{
    /**
     * HMAC_SHA1
     */
    EMKekPrfAlgorithm_HMACSHA1      = 0,
    
    /**
     * HMAC_SHA256
     */
    EMKekPrfAlgorithm_HMACSHA256    = 1,
    
    /**
     * HMAC_SHA512
     */
    EMKekPrfAlgorithm_HMACSHA512    = 2
} EMKekPrfAlgorithm;

/**
 * Token Usage
 * - Since: 5.0
 */
typedef enum EMTokenUsage
{
    /**
     * Undefined Token Usage
     */
    EMTokenUsage_Undefined          = 0,
    /**
     * Normal Token Usage
     */
    EMTokenUsage_NormalToken        = 1,
    /**
     * Low platform coupling Token Usage
     */
    EMTokenUsage_LowPlatformCouplingToken= 2
} EMTokenUsage;



#endif /* em_otp_enums_h */
