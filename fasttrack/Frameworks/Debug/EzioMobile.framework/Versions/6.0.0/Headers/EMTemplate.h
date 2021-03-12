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
#import "EMDsTransactionData.h"

@protocol EMDsTransactionData;

/**
   A protocol representing a DS template.
 */
@protocol EMTemplate <NSObject>

/**
   Returns the template id.
 
   @return The template id.
 */
@property (assign, nonatomic, readonly) NSInteger templateId;

/**
   Returns the list of primitives that this primitive contains.
 
   @return The list of primitives.
 */
@property (copy, nonatomic, readonly) NSArray *primitives;

/**
   Returns the domains that this template is valid for.
  
   The `NSSet` contains instances of `NSNumber`. Each such instance holds
   a EMDomainType enum value.
  
   @return The domains.
 */
@property (copy, nonatomic, readonly) NSSet *domains;

/**
   Creates a new empty transaction data holder for this template.
 
   @return The new transaction data holder.
 */
- (id<EMDsTransactionData>)createTransactionData;

/**
   Returns a textual description of this template, this is mainly intended for debug purposes.
 
   @return The textual description.
 */
- (NSString *)description;

@end
