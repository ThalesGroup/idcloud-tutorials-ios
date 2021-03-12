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

// ###########################
// MARK: - Validation domain.
// ###########################
///
extern NSString *const EM_C_ERR_DOMAIN_VALIDATION;

/**
 * Indicates that the QR code data does not start with correct Payload Format Indicator value
 * - i.e. probably not an EMVCo QR Code
 */
extern NSInteger const EM_C_ERR_CODE_INVALID_START_OF_QR_CODE;

/**
 * Indicates that the QR code does not end with a 16bit CRC - i.e. probably not an EMVCo QR Code
 */
extern NSInteger const EM_C_ERR_CODE_INVALID_END_OF_QR_CODE;

/**
 * Indicates that the CRC value is incorrect.
 */
extern NSInteger const EM_C_ERR_CODE_INCORRECT_CRC;

/**
 * Indicates that a data object structure (ID-Length-Value) was not identified in the input data.
 */
extern NSInteger const EM_C_ERR_CODE_DATA_OBJECT_NOT_FOUND;

/**
 * Indicates that a data object in the input is incomplete (value is truncated).
 */
extern NSInteger const EM_C_ERR_CODE_DATA_OBJECT_INCOMPLETE;

/**
 * Indicates that an unexpected data object was encountered (see cause for details).
 */
extern NSInteger const EM_C_ERR_CODE_DATA_OBJECT_UNEXPECTED;

/**
 * Indicates that a data object is redundant (there is another object already present).
 */
extern NSInteger const EM_C_ERR_CODE_DATA_OBJECT_REDUNDANT;

/**
 * Indicates that the given data object has invalid format (see cause for details).
 */
extern NSInteger const EM_C_ERR_CODE_INVALID_DATA_OBJECT_FORMAT;

/**
 * Indicates that referenced mandatory data object is missing in the input.
 */
extern NSInteger const EM_C_ERR_CODE_DATA_OBJECT_MISSING;

/**
 * Indicates violation of EMVCo requirement 4.3.1.2: There shall be only one occurrence of a data object
 * with a specific ID under the root and there shall be only one occurrence of a specific ID within a template.
 */
extern NSInteger const EM_C_ERR_CODE_DATA_OBJECT_DUPLICATE;

// ###########################
// MARK: - Mapper domain.
// ###########################

///
extern NSString *const EM_C_ERR_DOMAIN_MAPPER;

/**
 * Indicates that mapper for specific descriptor is missing.
 */
extern NSInteger const EM_C_ERR_CODE_MISSING_MAPPER;

#define C_ERR_DOMAIN_VALIDATION                 EM_C_ERR_DOMAIN_VALIDATION
#define C_ERR_CODE_INVALID_START_OF_QR_CODE     EM_C_ERR_CODE_INVALID_START_OF_QR_CODE
#define C_ERR_CODE_INVALID_END_OF_QR_CODE       EM_C_ERR_CODE_INVALID_END_OF_QR_CODE
#define C_ERR_CODE_INCORRECT_CRC                EM_C_ERR_CODE_INCORRECT_CRC
#define C_ERR_CODE_DATA_OBJECT_NOT_FOUND        EM_C_ERR_CODE_DATA_OBJECT_NOT_FOUND
#define C_ERR_CODE_DATA_OBJECT_INCOMPLETE       EM_C_ERR_CODE_DATA_OBJECT_INCOMPLETE
#define C_ERR_CODE_DATA_OBJECT_UNEXPECTED       EM_C_ERR_CODE_DATA_OBJECT_UNEXPECTED
#define C_ERR_CODE_DATA_OBJECT_REDUNDANT        EM_C_ERR_CODE_DATA_OBJECT_REDUNDANT
#define C_ERR_CODE_INVALID_DATA_OBJECT_FORMAT   EM_C_ERR_CODE_INVALID_DATA_OBJECT_FORMAT
#define C_ERR_CODE_DATA_OBJECT_MISSING          EM_C_ERR_CODE_DATA_OBJECT_MISSING
#define C_ERR_CODE_DATA_OBJECT_DUPLICATE        EM_C_ERR_CODE_DATA_OBJECT_DUPLICATE
#define C_ERR_DOMAIN_MAPPER                     EM_C_ERR_DOMAIN_MAPPER
#define C_ERR_CODE_MISSING_MAPPER               EM_C_ERR_CODE_MISSING_MAPPER

///
@interface EMEmvError : NSError

/**
 * Provides error detailed information message
 * @return multiline detailed error message
 */
- (NSString *)errorDetails;

@end
