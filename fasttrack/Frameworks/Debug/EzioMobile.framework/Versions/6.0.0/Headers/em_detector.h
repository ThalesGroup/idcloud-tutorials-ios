/** -----------------------------------------------------------------------------

Copyright (c) 2020  -  GEMALTO DEVELOPMENT - R&D

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

#ifndef _EM_DETECTOR_H_
#define _EM_DETECTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <objc/objc.h>

/** Success */
#define EM_DETECTOR_STATUS_SUCCESS                  0
/** Failed */
#define EM_DETECTOR_STATUS_FAILED                   1
/** Invalid arguments */
#define EM_DETECTOR_STATUS_INVALID_ARGUMENTS        2

/**
 Detection result 'Negative' meaning is determined by the API call.
 For hook detection API, this means the protected Objective-C method(s) or
 native C function(s) are not hooked.
 For jailbreak detection API, this means the device is not jailbroken.
 For debugger detection API, this means there is no debugger attached.
 */
#define EM_DETECTOR_RESULT_NEGATIVE                 0
/**
 Detection result 'Positive' meaning is determined by the API call.
 For hook detection API, this means the protected Objective-C methods or
 native C functions are hooked.
 For jailbreak detection API, this means the device is jailbroken.
 For debugger detection API, this means there is a debugger attached.

 @warning The application developer should take any appropriate action depends
 on the application requirement. For example: exit the application, display
 warning message, etc.
 */
#define EM_DETECTOR_RESULT_POSITIVE                 1

/**
   Gets the jailbreak detection status.
     
   @param result    [out] The debugger detection result. EM_DETECTOR_RESULT_POSITIVE if the device is jailbroken, otherwise EM_DETECTOR_RESULT_NEGATIVE.
   @return The jailbreak detection status: EM_DETECTOR_STATUS_SUCCESS, EM_DETECTOR_STATUS_INVALID_ARGUMENTS
   - Since: 5.4
*/
int EMDetectorJailbreakStatus(int *result);

/**
   Gets the ObjC method hook detection status.
   ObjC hook detection has the following limitations:
   * It should not be used to protect System APIs e.g. NSString, NSURL
   * It should not be used to protect APIs in ObjC categories.
   * It should not be used to protect methods overridden from NSObject e.g. init, description.
   * Method swizzling is not allowed on protected API.
   * For Swift, this function only protect the Swift class derived from ObjC class.

   @param result    [out] The hook detection result. EM_DETECTOR_RESULT_POSITIVE if it's hooked, otherwise EM_DETECTOR_RESULT_NEGATIVE.
   @param clazz     [in] The class to be checked.
   @param selSize   [in] The count of selectors(methods) passed in the sels.
   @param sels      [in] (Optional) The selectors'(methods) list.

   @return The hook detection status: EM_DETECTOR_STATUS_SUCCESS, EM_DETECTOR_STATUS_FAILED and EM_DETECTOR_STATUS_INVALID_ARGUMENTS for invalid
   - Since: 5.4
 */
int EMDetectorObjCMethodHookingStatus(int *result, Class clazz, size_t selSize, SEL *sels);

/**
   Gets the ObjC method list hook detection status.
   ObjC hook detection has the following limitations:
   * It should not be used to protect System APIs e.g. NSString, NSURL
   * It should not be used to protect APIs in ObjC categories.
   * It should not be used to protect methods overridden from NSObject e.g. init, description.
   * Method swizzling is not allowed on protected API.
   * For Swift, this function only protect the Swift class derived from ObjC class.
     
   @param result    [out] The hook detection result. EM_DETECTOR_RESULT_POSITIVE if it's hooked, otherwise EM_DETECTOR_RESULT_NEGATIVE.
   @param clazz     [in] The class to be checked.
   @param selSize   [in] The count of selectors(methods) passed in the sel arguments.
   @param sel       [in] (Optional) The selector.
   @param ...       [in] (Optional) Remaining selector.

   @return The hook detection status: EM_DETECTOR_STATUS_SUCCESS, EM_DETECTOR_STATUS_FAILED and EM_DETECTOR_STATUS_INVALID_ARGUMENTS for invalid
   - Since: 5.4
   */
int EMDetectorObjCMethodListHookingStatus(int *result, Class clazz, size_t selSize, SEL sel, ...);

/**
   Gets the Native C function hook detection status.

   @param result    [out] The hook detection result. EM_DETECTOR_RESULT_POSITIVE if it's hooked, otherwise EM_DETECTOR_RESULT_NEGATIVE.
   @param funcs     [in] The list of function pointers.
   @param funcSize  [in] The count of the function pointers passed in the funcs.

   @return The hook detection status: EM_DETECTOR_STATUS_SUCCESS, EM_DETECTOR_STATUS_FAILED and EM_DETECTOR_STATUS_INVALID_ARGUMENTS for invalid
   - Since: 5.4
*/
int EMDetectorCFunctionsHookingStatus(int *result, void **funcs, size_t funcSize);

/**
    Gets the debugger detection status.
     
    @param result    [out] The debugger detection result. EM_DETECTOR_RESULT_POSITIVE if a debugger is attached, otherwise EM_DETECTOR_RESULT_NEGATIVE.
    @return The debugger detection status: EM_DETECTOR_STATUS_SUCCESS, EM_DETECTOR_STATUS_INVALID_ARGUMENTS
    - Since: 5.4
*/
int EMDetectorDebuggerStatus(int *result);

#ifdef __cplusplus
}
#endif

#endif
