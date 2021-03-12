/** -----------------------------------------------------------------------------
 
        Copyright (c) 2013  -  GEMALTO DEVELOPMENT - R&D
 
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

#import <Foundation/Foundation.h>
#import "EMTemplate.h"
#import "EMSecureString.h"
#import "EMDsCapParameters.h"
#import "EMDsTransactionData.h"

/** The supported domains for Dynamic Signature using GPF. */
typedef NS_ENUM(NSInteger, EMDomainType)
{
    /** Login domain
     * Function name: "LOGIN V1"
     */
    EMDomainTypeLogin,
    /** Buy domain
     * Function name: "BUY V1"
     */
    EMDomainTypeBuy,
    /** Sign domain
     * Function name: "SIGN V1"
     */
    EMDomainTypeSign,
    /** Connected domain
     * Function name: "E-CODE V1"
     */
    EMDomainTypeConnected,
    /** Sign what you see domain
     * Function name: "SWYS V1"
     */
    EMDomainTypeSwys
};

/**
   A protocol representing a Dynamic Signature (DS) device.
 */
@protocol EMDsFormattingDevice <NSObject>

/**
   Get a DS template from a challenge.

   @param challenge The challenge.
   @return The template, `nil` if no template was encoded in the challenge.
 */
- (id<EMTemplate>)templateFromChallenge:(id<EMSecureString>)challenge;

/**
   Gets a DS template by id.

   @param templateId The id of the template.
   @return The template, `nil` if no template was found with that id.
 */
- (id<EMTemplate>)templateWithId:(NSInteger)templateId;

/**
   Gets a primitive by name.

   @param name The name of the primitive as defined in configuration file.
   @return The primitive, `nil` if no primitive was found with that name.
   - Since: 2.1
 */
- (id<EMPrimitive>)primitiveWithName:(NSString *)name;

/**
   Gets the CAP parameters for the given DS challenge and associated transaction data.

   @param challenge The challenge, a runtime error will be raised if it does not encode the same template as the transaction data is for. Can be `nil` to compute an OTP in connected mode.
   @param domain The template domain.
   @param capMode The CAP mode to generate input data for.
   @param dsTransactionData The template transaction data. Can be `nil` if the challenge does not contain a valid template identifier in unconnected mode.
   @return The CAP input parameters.
 */
-(EMDsCapParameters *)capParametersWithChallenge:(id<EMSecureString>)challenge domain:(EMDomainType)domain dsCapMode:(EMDsCapMode)capMode transactionData:(id<EMDsTransactionData>)dsTransactionData;


/**
   Gets the CAP parameters for the given domain and transaction data.

   @param domain The template domain.
   @param capMode The CAP mode to generate input data for.
   @param dsTransactionData The template transaction data. Can be `nil` if the challenge does not contain a valid template identifier in unconnected mode.
   @return The CAP input parameters.
   - Since: 2.1
 */
-(EMDsCapParameters *)capParametersWithDomain:(EMDomainType)domain dsCapMode:(EMDsCapMode)capMode transactionData:(id<EMDsTransactionData>)dsTransactionData;

@end
