/** -----------------------------------------------------------------------------
 
        Copyright (c) 2014  -  GEMALTO DEVELOPMENT - R&D
 
     -----------------------------------------------------------------------------
    GEMALTO MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF
    THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
    TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
    PARTICULAR PURPOSE, OR NON-INFRINGEMENT. GEMALTO SHALL NOT BE
    LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
    MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
  
    THIS SOFTWARE IS NOT DESIGNED OR INTENDED FOR USE OR RESALE AS ON-LINE
    CONTROL EQUIPMENT IN HAZARDOUS ENVIRONMENTS REQUIRING FAIL-SAFE
    PERFORMANCE, SUCH AS IN THE OPERATION OF NUCLEAR FACILITIES, AIRCRAFT
    NAVIGATION OR COMMUNICATION SYSTEMS, AIR TRAFFIC CONTROL, DIRECT LIFE
    SUPPORT MACHINES, OR WEAPONS SYSTEMS, IN WHICH THE FAILURE OF THE
    SOFTWARE COULD LEAD DIRECTLY TO DEATH, PERSONAL INJURY, OR SEVERE
    PHYSICAL OR ENVIRONMENTAL DAMAGE ("HIGH RISK ACTIVITIES"). GEMALTO
    SPECIFICALLY DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTY OF FITNESS FOR
    HIGH RISK ACTIVITIES.
  
    -----------------------------------------------------------------------------
 */

#ifndef libmobilesdk_EMTokenCapability_h
#define libmobilesdk_EMTokenCapability_h

#ifdef __cplusplus
extern "C" {
#endif
        
    /**
     * The token capability attribute dictates how the token can be used within
     * the Mobile Protector SDK, potentially limiting or expanding its use.
     */
    typedef enum EMTokenCapability
    {
        /**
         * Token computes OTPs as a client. This is the default capability and
         * therefore is used by any token whose capability is not explicitly provided
         */
        EMTokenCapabilityOTP,
        
        /**
         * Token computes OTPs from one of two selectable keys in the token
         * (SDK acts as a client).
         * <p>
         * <b>Warning: </b> Do not use this capability on arbitrary provisioning
         * requests. When creating a token with this capability, the
         * registration code (RC) used for the provisioning request on the
         * Enrollment Provisioning Server (EPS) must be associated with a dual
         * seed enrollment request.
         * <p>
         * The following constraints apply:
         * <ul>
         * <li>`EMMobileProvisioningProtocolVersion3`</li>
         * <li> OATH, time based </li>
         * <li> 64 byte seed (32 byte keys) </li>
         * <li> Single PIN for both keys </li>
         * </ul>
         */
        EMTokenCapabilityDUAL_SEED
    } EMTokenCapability;

#ifdef __cplusplus
}
#endif

#endif
