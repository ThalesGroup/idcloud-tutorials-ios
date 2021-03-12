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

#import "EMEmvTemplate.h"

/**
 * Class that holds the Language Preference and Merchant Name—Alternate Language.
 * It may contain the Merchant City—Alternate Language.
 * All other IDs within the Merchant Information—Language Template are RFU for EMVCo.
 *
 * - Since: 5.0
 */
@protocol EMEmvMerchantInformationLanguageTemplate <EMEmvTemplate>

/**
 * Returns 2 alphabetical characters coded to a value defined by [ISO 639].
 *
 * @return Returns language preference as NSString.
 */
- (NSString *)languagePreference;

/**
 * Returns name for the merchant in the merchant’s local language.
 *
 * @return Returns alternate language merchant name as NSString.
 */
- (NSString *)alternateLanguageMerchantName;

/**
 * Returns city in which the merchant transacts in the merchant’s local language.
 *
 * @return Returns alternate language merchant city as string wrapped in `EMEmvOptional`.
 */
- (EMEmvOptional<NSString *> *)alternateLanguageMerchantCity;

@end
