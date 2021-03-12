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
#import "EMDsFormattingDevice.h"
#import "EMToken.h"

/**
 A factory for creating DS related entities.
 
 For information on how use custom templates and primitives, please read The Programmer's Guide.
 */
@interface EMDsFormattingFactory : NSObject

/**
 Creates a DS device for the given token.
 
 @param token The token.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The DS device.
 */
- (id<EMDsFormattingDevice>)createDsDeviceWithToken:(id<EMToken>)token error:(NSError **)error;

/**
 Creates a DS device for the given token.
 
 @param token The token.
 @param path The path to a custom Dynamic Signature configuration file.
 @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in `NULL`.
 @return The DS device.
 */
- (id<EMDsFormattingDevice>)createDsDeviceWithToken:(id<EMToken>)token dsConfigurationPath:(NSString *)path error:(NSError **)error;

/** Creates an empty EMDsTransactionData
 
 This factory should be used in connected mode where no template is used to have a list of primitive.
 
 @return The EMDsTransactionData.
 - Since: 2.1
 */
- (id<EMDsTransactionData>)createDsTransactionData;

@end