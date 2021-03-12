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

#import "EMEmvOptional.h"
#import "EMEmvDataObject.h"
#import "EMEmvMerchantInformationLanguageTemplate.h"
#import "EMEmvAdditionalDataFieldTemplate.h"
#import "EMEmvTemplateWithGui.h"
#import "EMEmvPrimitiveDataTypes.h"

/**
 * Represents a value of 'Tip or Convenience Indicator' data object if present in the QR code.
 *
 * - Since: 5.0
 */
typedef enum EMEmvTipOrConvenienceIndicator{
    
    /**
     * This enum might be used as optional for which case we can use this value.
     */
    EMEmvTipOrConvenienceIndicatorUndefined,
    
    /**
     * Used if the mobile application should prompt the consumer to enter a tip to be paid to the merchant.
     */
    EMEmvTipOrConvenienceIndicatorPromptConsumer,
    
    /**
     * Used to indicate inclusion of the data object 'Value of Convenience Fee Fixed'.
     */
    EMEmvTipOrConvenienceIndicatorFixed,
    
    /**
     * Used to indicate inclusion of the data object 'Value of Convenience Fee Percentage'.
     */
    EMEmvTipOrConvenienceIndicatorPercentage
} EMEmvTipOrConvenienceIndicator;

/**
 * Represents a value of 'Point of Initiation Method' data object if present in the QR code.
 */
typedef enum EMEmvPointOfInitiationMethod {
    /**
     * Value not provided in the QR code.
     */
    EMEmvPointOfInitiationMethodUndefined,
    
    /**
     * The Point of Initiation Method value of "11" is used when the same QR Code is shown for more than one transaction - i.e. QR Code is static.
     */
    EMEmvPointOfInitiationMethodStatic,
    
    /**
     * The Point of Initiation Method value of "12" is used when a new QR Code is shown for each transaction - i.e. QR Code is dynamic.
     */
    EMEmvPointOfInitiationMethodDynamic
}EMEmvPointOfInitiationMethod;

/**
 * Holds consolidated information about payment transaction.
 */
@protocol EMEmvTransactionInfo <NSObject>

/**
 * Defines the version of the QR Code template and hence the conventions on the identifiers, lengths, and values.
 *
 * @return Returns Payload Format Indicator as byte.
 */
- (Byte)payloadFormatIndicator;

/**
 * Identifies the communication technology (here QR Code) and whether the data is static or dynamic.
 * This parameter is optional.
 *
 * @return Point of Initiation Method value as enum `EMEmvPointOfInitiationMethod` value. If the data object
 * is not presents returns `EMEmvPointOfInitiationMethod.EMEmvPointOfInitiationMethodUndefined`.
 */
- (EMEmvPointOfInitiationMethod)pointOfInitiationMethod;

/**
 * Provides information about merchant's account. The format and value are specific to a payment system.
 *
 * @return Returns list of `EMEmvDataObject` defining merchant account information. The list contains either instances
 * of `EMEmvPrimitive` or `EMEmvTemplateWithGui` and `-[EMEmvDataObject type]` method should be used to distinguish them.
 */
- (NSArray<id<EMEmvDataObject>> *)merchantAccountInfo;

/**
 * Identifies merchant category code as defined by [ISO 18245] and assigned by the Acquirer.
 *
 * @return Returns numeric merchant category code as NSInteger.
 */
- (NSInteger)merchantCategoryCode;

/**
 * Identifies “doing business as” name for the merchant, recognizable to the consumer. This name may be displayed to the consumer by the
 * mobile application when processing the transaction.
 *
 * @return Returns merchant name as string.
 */
- (NSString *)merchantName;

/**
 * Identifies city of operations for the merchant. This name may be displayed to the consumer by the mobile application when processing
 * the transaction.
 *
 * @return Returns merchant city as string.
 */
- (NSString *)merchantCity;

/**
 * Indicates the country of the merchant acceptance device. The country may be displayed to the
 * consumer by the mobile application when processing the transaction.
 * <p>
 * A 2-character alpha value, as defined by [ISO 3166-1 alpha 2] and assigned by the Acquirer.
 *
 * @return Returns country code as string.
 */
- (NSString *)countryCode;

/**
 * Zip code or Pin code or Postal code of the merchant. If present, this value may be displayed to the consumer by the mobile
 * application when processing the transaction.
 * <p>
 * This value is optional.
 *
 * @return Returns postal code as string in `EMEmvOptional`.
 */
- (EMEmvOptional<NSString *> *)postalCode;

/**
 * The transaction amount, if known. For instance, "99.34". If present, this value is displayed to the consumer by the mobile
 * application when processing the transaction. If this data object is not present, the consumer is prompted to input the transaction
 * amount to be paid to the merchant.
 * <p>
 * This value is optional.
 *
 * @return Returns transaction amount as `NSNumber` in `EMEmvOptional`.
 */
- (EMEmvOptional<NSNumber *> *)transactionAmount;

/**
 * Indicates the currency code of the transaction. This value will be used by the mobile application to display a recognizable
 * currency to the consumer whenever an amount is being displayed or whenever the consumer is prompted to enter an amount.
 * <p>
 *
 * @return A 3-digit numeric currency code, as defined by [ISO 4217].
 */
- (NSInteger)currency;

/**
 * Indicates language Preference and Merchant Name—Alternate Language.
 * It may contain the Merchant City—Alternate Language.
 * <p>
 * All other IDs within the Merchant Information—Language Template are RFU for EMVCo.
 *
 * @return Returns `EMEmvMerchantInformationLanguageTemplate` object in `EMEmvOptional`.
 */
- (EMEmvOptional<id<EMEmvMerchantInformationLanguageTemplate>> *)merchantInformationLanguageTemplate;

/**
 * Indicates whether the consumer will be prompted to enter a tip or whether the merchant has determined that a flat, or percentage
 * convenience fee is charged.
 *
 * @return Returns `EMEmvTipOrConvenienceIndicator`.
 */
- (EMEmvTipOrConvenienceIndicator)tipOrConvenienceIndicator;

/**
 * Provides value of tip.
 * <p>
 * This parameter is optional.
 *
 * @return Returns Tip or Convenience value as `NSNumber`.
 */
- (EMEmvOptional<NSNumber *> *)tipOrConvenienceValue;

/**
 * Indicates optional parameters as additional data, that could be present in transaction object.
 *
 * @return Returns `EMEmvAdditionalDataFieldTemplate` object in `EMEmvOptional`.
 */
- (EMEmvOptional<id<EMEmvAdditionalDataFieldTemplate>> *)additionalDataFieldTemplate;

/**
 * Indicates data reserved for future use.
 *
 * @return Returns list of `EMEmvPrimitive` data objects reserved for future use of EMV or empty list of none are in the QR code.
 */
- (NSArray<id<EMEmvDataObject>> *)emvRfuDataObjects;

/**
 * Provides list of unreserved templates.
 *
 * @return Returns list of `EMEmvTemplateWithGui` data objects that are unreserved or empty list of none are in the QR code.
 */
- (NSArray<id<EMEmvTemplateWithGui>> *)unreservedTemplates;

@end
