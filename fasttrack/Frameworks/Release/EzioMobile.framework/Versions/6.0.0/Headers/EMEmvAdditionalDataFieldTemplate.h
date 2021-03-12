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
 * Holds additional data fields that could be present in the QR code.
 * It provides a simple interface to retrieve value of such fields.
 *
 * - Since: 5.0
 */
@protocol EMEmvAdditionalDataFieldTemplate <EMEmvTemplate>

/**
 * Returns the invoice number or bill number, that could be provided by the merchant or could be an indication for the mobile
 * application to prompt the consumer to input a Bill Number.
 * <p>
 * For example, the Bill Number may be present when the QR Code is used for
 * bill payment.
 * <p>
 * This parameter is optional.
 *
 * @return Returns bill number as string wrapped in `EMEmvOptional`.
 */
- (EMEmvOptional<NSString*> *)billNumber;

/**
 * Returns the mobile number, that could be provided by the merchant or could be an indication for the mobile application to prompt the
 * consumer to input a Mobile Number.
 * <p>
 * For example, the Mobile Number to be used for multiple use cases, such as mobile top-up and bill
 * payment.
 * <p>
 * This parameter is optional.
 *
 * @return Returns mobile number as string wrapped in `EMEmvOptional`.
 */
- (EMEmvOptional<NSString*> *)mobileNumber;

/**
 * Returns a distinctive value associated to a store. This value could be provided by the merchant or could be an indication for the
 * mobile application to prompt the consumer to input a Store Label.
 * <p>
 * For example, the Store Label may be displayed to the consumer on
 * the mobile application identifying a specific store.
 * <p>
 * This parameter is optional.
 *
 * @return Returns store label as string wrapped in `EMEmvOptional`.
 */
- (EMEmvOptional<NSString*> *)storeLabel;

/**
 * Returns a loyalty card number. This number could be provided by the merchant, if known, or could be an indication for the
 * mobile application to prompt the consumer to input their Loyalty Number.
 * <p>
 * This parameter is optional.
 *
 * @return Returns Loyalty number as string wrapped in `EMEmvOptional`.
 */
- (EMEmvOptional<NSString*> *)loyaltyNumber;

/**
 * Returns transaction identification value. This value could be provided by the merchant or could be an indication for the mobile app
 * to prompt the consumer to input a transaction Reference Label.
 * <p>
 * For example, the Reference Label may be used by the consumer mobile
 * application for transaction logging or receipt display.
 * <p>
 * This parameter is optional.
 *
 * @return Returns reference label as string wrapped in `EMEmvOptional`.
 */
- (EMEmvOptional<NSString*> *)referenceLabel;

/**
 * Returns value identifying a specific consumer. This value could be provided by the merchant (if known), or could be an indication
 * for the mobile application to prompt the consumer to input their Customer Label.
 * <p>
 * For example, the Customer Label may be a subscriber
 * ID for subscription services, a student enrolment number, etc.
 * <p>
 * This parameter is optional.
 *
 * @return Returns customer label as string wrapped in `EMEmvOptional`.
 */
- (EMEmvOptional<NSString*> *)customerLabel;

/**
 * Returns a distinctive value associated to a terminal in the store. This value could be provided by the merchant or could be an
 * indication for the mobile application to prompt the consumer to input a Terminal Label.
 * <p>
 * For example, the Terminal Label may be
 * displayed to the consumer on the mobile application identifying a specific terminal.
 * <p>
 * This parameter is optional.
 *
 * @return Returns Terminal label as string wrapped in `EMEmvOptional`.
 */
- (EMEmvOptional<NSString*> *)terminalLabel;

/**
 * Returns value defining the purpose of the transaction. This value could be provided by the merchant or could be an indication for the
 * mobile application to prompt the consumer to input a value describing the purpose of the transaction.
 * <p>
 * For example, the Purpose of
 * Transaction may have the value "International Data Package" for display on the mobile application.
 * <p>
 * This parameter is optional.
 *
 * @return Returns purpose of transaction as string wrapped in `EMEmvOptional`.
 */
- (EMEmvOptional<NSString*> *)purposeOfTransaction;

/**
 * Contains indications that the mobile application is to provide the requested information in order to complete the transaction. The
 * information requested should be provided by the mobile application in the authorization without unnecessarily prompting the consumer.
 * <p>
 * For example, the Additional Consumer Data Request may indicate that the consumer mobile number is required to complete the
 * transaction, in which case the mobile application should be able to provide this number (that the mobile application has previously
 * stored) without unnecessarily prompting the consumer.
 * <p>
 * This parameter is optional.
 *
 * @return Returns additional consumer data request as string wrapped in `EMEmvOptional`.
 */
- (EMEmvOptional<NSString*> *)additionalConsumerDataRequest;

/**
 * Provides list of data objects reserved for future use of EMV
 *
 * @return Returns list of `EMEmvDataObject` or empty list if none are present in the QR code.
 * Note: It is advised to use `-[EMEmvDataObject type]` method to check concrete type and safely cast the list members.
 */
- (NSArray<id<EMEmvDataObject>> *)emvRfuDataObjects;

/**
 * Provides list of Payment System specific templates.
 *
 * @return Returns list of `EMEmvDataObject` or empty list if none are present in the QR code.
 * Note: It is advised to use `-[EMEmvDataObject type]` method to check concrete type and safely cast the list members.
 */
- (NSArray<id<EMEmvDataObject>> *)paymentSystemSpecificTemplates;

@end
