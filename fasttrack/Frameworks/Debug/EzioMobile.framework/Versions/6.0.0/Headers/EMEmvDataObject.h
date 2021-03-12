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

#import <Foundation/Foundation.h>

/**
 * Defines the concrete type of data object instance.
 *
 * - Since: 5.0
 */
typedef enum EMEmvDataObjectType {
    /**
     * Type of data object that contains an unstructured string value. See `Primitive` class.
     */
    EMEmvDataObjectTypePrimitive,
    /**
     * Type of data object that contains an inner structure of data objects. See `Template` class.
     */
    EMEmvDataObjectTypeTemplate,
    /**
     * Type of data object inherited from `EMEmvTemplate`, which holds a Globally Unique Identifier (a `EMEmvPrimitive` data object with ID = 0)
     * and provides an easy interface to get it `-[EMEmvTemplateWithGui globallyUniqueIdentifier]`
     */
    EMEmvDataObjectTypeTemplateWithGui,
    /**
     * Type of data object inherited from `EMEmvTemplate`, which holds additional optional `EMEmvPrimitive` data objects
     * as defined in section 4.8 of the EMVCo specification and provides an easy interface to obtain these fields.
     * See `AdditionalDataFieldTemplate` class.
     */
    EMEmvDataObjectTypeAdditionalDataFieldTemplate,
    /**
     * Type of data object inherited from `EMEmvTemplate`, which holds merchant information in an alternate language
     * and provides an easy interface to obtain it. See `MerchantInformationLanguageTemplate` class.
     */
    EMEmvDataObjectTypeMerchantInformationLanguageTemplate
}EMEmvDataObjectType;

/**
 * Data object class providing the common interface.
 */
@protocol EMEmvDataObject

/**
 * Provides ID of the data object.
 *
 * @return Returns ID of the data object as byte.
 */
- (Byte)identifier;

/**
 * Provides type of the data object.
 *
 * @return Returns type of the data object
 */
- (EMEmvDataObjectType)type;

/**
 * Provides value of the `EMEmvPrimitive` data objects.
 *
 * @return Returns value of the data object as String if available. Null is provided for `EMEmvTemplate` data
 * objects for which the getDataObjects method should be used instead.
 */
- (NSString *)value;

/**
 * Provides inner structure for `EMEmvTemplate` data objects.
 * @return Returns a list of inner data objects if any. Empty list is provided for `EMEmvPrimitive` data objects.
 */
- (NSArray<id<EMEmvDataObject>> *)dataObjects;

@end
