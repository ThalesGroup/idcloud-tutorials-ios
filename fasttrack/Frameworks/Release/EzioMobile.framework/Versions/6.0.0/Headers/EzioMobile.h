
/** ----------------------------------------------------------------------------
 *
 *     Copyright (c)  2019  -  GEMALTO DEVELOPEMENT - R&D
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

#ifndef lib_EzioMobile_h
#define lib_EzioMobile_h

/* iOS Version Support */

#ifndef __IPHONE_11_0
    #define __IPHONE_11_0        110000
#endif

#define __EZIO_MINIMUM_IOS_VERSION_SUPPORT           __IPHONE_11_0

#ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
    #if __IPHONE_OS_VERSION_MIN_REQUIRED < __EZIO_MINIMUM_IOS_VERSION_SUPPORT
        #warning Ezio SDK supports Minimum iOS SDK 11.0.0. Set Deployment target to 11.0.
    #endif
#endif


#import <EzioMobile/EMAuthInput.h>
#import <EzioMobile/EMAuthMode.h>
#import <EzioMobile/EMAuthModule.h>
#import <EzioMobile/EMAuthService.h>
#import <EzioMobile/EMAuthenticatable.h>
#import <EzioMobile/EMBioFingerprintAuthInput.h>
#import <EzioMobile/EMBioFingerprintAuthMode.h>
#import <EzioMobile/EMBioFingerprintAuthService.h>
#import <EzioMobile/EMBioFingerprintContainer.h>
#import <EzioMobile/EMCapDevice.h>
#import <EzioMobile/EMCapFactory.h>
#import <EzioMobile/EMCapService.h>
#import <EzioMobile/EMCapSettings.h>
#import <EzioMobile/EMCapToken.h>
#import <EzioMobile/EMCapTokenManager.h>
#import <EzioMobile/EMCapTools.h>
#import <EzioMobile/EMCore.h>
#import <EzioMobile/EMDcvOathDevice.h>
#import <EzioMobile/EMDecimalInputDialogPrimitive.h>
#import <EzioMobile/EMDeviceFingerprintSource.h>
#import <EzioMobile/EMDeviceFingerprintTokenPolicy.h>
#import <EzioMobile/EMDsCapParameters.h>
#import <EzioMobile/EMDsFormattingDevice.h>
#import <EzioMobile/EMDsFormattingFactory.h>
#import <EzioMobile/EMDsFormattingService.h>
#import <EzioMobile/EMDsFormattingTools.h>
#import <EzioMobile/EMDsTransactionData.h>
#import <EzioMobile/EMDskppKeyInformation.h>
#import <EzioMobile/EMDskppLocalPinCallback.h>
#import <EzioMobile/EMDskppPinPolicy.h>
#import <EzioMobile/EMDskppPolicy.h>
#import <EzioMobile/EMDskppPolicyParser.h>
#import <EzioMobile/EMDskppProvisioningCallback.h>
#import <EzioMobile/EMDskppServerPinCallback.h>
#import <EzioMobile/EMDskppTlsConfiguration.h>
#import <EzioMobile/EMDualSeedOathToken.h>
#import <EzioMobile/EMDualSeedSoftOathToken.h>
#import <EzioMobile/EMEmvAdditionalDataFieldTemplate.h>
#import <EzioMobile/EMEmvDataObject.h>
#import <EzioMobile/EMEmvError.h>
#import <EzioMobile/EMEmvFactory.h>
#import <EzioMobile/EMEmvMap.h>
#import <EzioMobile/EMEmvMerchantInformationLanguageTemplate.h>
#import <EzioMobile/EMEmvModule.h>
#import <EzioMobile/EMEmvMpmDecoder.h>
#import <EzioMobile/EMEmvOptional.h>
#import <EzioMobile/EMEmvPrimitive.h>
#import <EzioMobile/EMEmvPrimitiveDataTypes.h>
#import <EzioMobile/EMEmvService.h>
#import <EzioMobile/EMEmvTemplate.h>
#import <EzioMobile/EMEmvTemplateWithGui.h>
#import <EzioMobile/EMEmvTransactionInfo.h>
#import <EzioMobile/EMEnumSet.h>
#import <EzioMobile/EMErrorDomain.h>
#import <EzioMobile/EMException.h>
#import <EzioMobile/EMFreeTextPrimitive.h>
#import <EzioMobile/EMGemaltoOathDevice.h>
#import <EzioMobile/EMGpfDsDevice.h>
#import <EzioMobile/EMGpfDsFactory.h>
#import <EzioMobile/EMGpfDsService.h>
#import <EzioMobile/EMGroupedInputDialogPrimitive.h>
#import <EzioMobile/EMHiddenTextPrimitive.h>
#import <EzioMobile/EMInformationPrimitive.h>
#import <EzioMobile/EMInputDialogPrimitive.h>
#import <EzioMobile/EMInputPrimitive.h>
#import <EzioMobile/EMJailbreakDetector.h>
#import <EzioMobile/EMMessageDialogPrimitive.h>
#import <EzioMobile/EMModule.h>
#import <EzioMobile/EMModuleConfiguration.h>
#import <EzioMobile/EMMspBaseAlgorithm.h>
#import <EzioMobile/EMMspCapData.h>
#import <EzioMobile/EMMspConfiguration.h>
#import <EzioMobile/EMMspData.h>
#import <EzioMobile/EMMspException.h>
#import <EzioMobile/EMMspFactory.h>
#import <EzioMobile/EMMspField.h>
#import <EzioMobile/EMMspFrame.h>
#import <EzioMobile/EMMspFrameType.h>
#import <EzioMobile/EMMspGpfdsData.h>
#import <EzioMobile/EMMspModule.h>
#import <EzioMobile/EMMspOathData.h>
#import <EzioMobile/EMMspParser.h>
#import <EzioMobile/EMMspRegistration.h>
#import <EzioMobile/EMMspService.h>
#import <EzioMobile/EMMutableSoftCapSettings.h>
#import <EzioMobile/EMMutableSoftDcvOathSettings.h>
#import <EzioMobile/EMMutableSoftGemaltoOathSettings.h>
#import <EzioMobile/EMMutableSoftGpfDsSettings.h>
#import <EzioMobile/EMMutableSoftOathSettings.h>
#import <EzioMobile/EMNumericInputDialogPrimitive.h>
#import <EzioMobile/EMOathDevice.h>
#import <EzioMobile/EMOathFactory.h>
#import <EzioMobile/EMOathService.h>
#import <EzioMobile/EMOathToken.h>
#import <EzioMobile/EMOathTokenManager.h>
#import <EzioMobile/EMOobConfiguration.h>
#import <EzioMobile/EMOobErrorMessage.h>
#import <EzioMobile/EMOobException.h>
#import <EzioMobile/EMOobFetchMessageResponse.h>
#import <EzioMobile/EMOobGenericIncomingMessage.h>
#import <EzioMobile/EMOobGenericOutgoingMessage.h>
#import <EzioMobile/EMOobIncomingMessage.h>
#import <EzioMobile/EMOobIncomingMessageBase.h>
#import <EzioMobile/EMOobIncomingMessageHandler.h>
#import <EzioMobile/EMOobJailbreakPolicy.h>
#import <EzioMobile/EMOobManager.h>
#import <EzioMobile/EMOobMessage.h>
#import <EzioMobile/EMOobMessageBase.h>
#import <EzioMobile/EMOobMessageHandler.h>
#import <EzioMobile/EMOobMessageHandlerRegistry.h>
#import <EzioMobile/EMOobMessageManager.h>
#import <EzioMobile/EMOobMessageMeta.h>
#import <EzioMobile/EMOobMessageResponse.h>
#import <EzioMobile/EMOobModule.h>
#import <EzioMobile/EMOobNotificationManager.h>
#import <EzioMobile/EMOobNotificationProfile.h>
#import <EzioMobile/EMOobNotificationProfilesResponse.h>
#import <EzioMobile/EMOobOutgoingMessage.h>
#import <EzioMobile/EMOobOutgoingMessageBase.h>
#import <EzioMobile/EMOobOutgoingMessageHandler.h>
#import <EzioMobile/EMOobProviderToUserMessage.h>
#import <EzioMobile/EMOobRegistrationManager.h>
#import <EzioMobile/EMOobRegistrationRequest.h>
#import <EzioMobile/EMOobRegistrationResponse.h>
#import <EzioMobile/EMOobRequestParameter.h>
#import <EzioMobile/EMOobResponse.h>
#import <EzioMobile/EMOobTransactionSigningRequest.h>
#import <EzioMobile/EMOobTransactionSigningResponse.h>
#import <EzioMobile/EMOobTransactionVerifyRequest.h>
#import <EzioMobile/EMOobTransactionVerifyResponse.h>
#import <EzioMobile/EMOobUnregistrationManager.h>
#import <EzioMobile/EMOobUserMessageAttachment.h>
#import <EzioMobile/EMOobUserToProviderMessage.h>
#import <EzioMobile/EMOtpConfiguration.h>
#import <EzioMobile/EMOtpException.h>
#import <EzioMobile/EMOtpModule.h>
#import <EzioMobile/EMOtpTools.h>
#import <EzioMobile/EMPasswordManager.h>
#import <EzioMobile/EMPinAuthInput.h>
#import <EzioMobile/EMPinAuthMode.h>
#import <EzioMobile/EMPinAuthService.h>
#import <EzioMobile/EMPinPolicy.h>
#import <EzioMobile/EMPinRule.h>
#import <EzioMobile/EMPinRuleIdentical.h>
#import <EzioMobile/EMPinRuleLength.h>
#import <EzioMobile/EMPinRulePalindrome.h>
#import <EzioMobile/EMPinRuleSeries.h>
#import <EzioMobile/EMPinRuleUniform.h>
#import <EzioMobile/EMPrimitive.h>
#import <EzioMobile/EMPrimitiveTags.h>
#import <EzioMobile/EMPrimitiveValue.h>
#import <EzioMobile/EMPropertyStorage.h>
#import <EzioMobile/EMProvisioningConfiguration.h>
#import <EzioMobile/EMSecureByteArray.h>
#import <EzioMobile/EMSecureContainer.h>
#import <EzioMobile/EMSecureContainerFactory.h>
#import <EzioMobile/EMSecureInputBuilder.h>
#import <EzioMobile/EMSecureInputCustomUiDelegate.h>
#import <EzioMobile/EMSecureInputService.h>
#import <EzioMobile/EMSecureInputUi.h>
#import <EzioMobile/EMSecureStorageManager.h>
#import <EzioMobile/EMSecureStorageModule.h>
#import <EzioMobile/EMSecureString.h>
#import <EzioMobile/EMSecurityDetectionService.h>
#import <EzioMobile/EMSelectableKey.h>
#import <EzioMobile/EMSelectionInputDialogPrimitive.h>
#import <EzioMobile/EMSignatureKey.h>
#import <EzioMobile/EMSoftCapSettings.h>
#import <EzioMobile/EMSoftCapToken.h>
#import <EzioMobile/EMSoftDcvOathSettings.h>
#import <EzioMobile/EMSoftGemaltoOathSettings.h>
#import <EzioMobile/EMSoftGpfDsSettings.h>
#import <EzioMobile/EMSoftOathSettings.h>
#import <EzioMobile/EMSoftOathToken.h>
#import <EzioMobile/EMSoftVicToken.h>
#import <EzioMobile/EMSystemBioFingerprintAuthInput.h>
#import <EzioMobile/EMSystemBioFingerprintAuthMode.h>
#import <EzioMobile/EMSystemBioFingerprintAuthService.h>
#import <EzioMobile/EMSystemBioFingerprintContainer.h>
#import <EzioMobile/EMSystemFaceAuthContainer.h>
#import <EzioMobile/EMSystemFaceAuthInput.h>
#import <EzioMobile/EMSystemFaceAuthMode.h>
#import <EzioMobile/EMSystemFaceAuthService.h>
#import <EzioMobile/EMTagValue.h>
#import <EzioMobile/EMTemplate.h>
#import <EzioMobile/EMTextPrimitive.h>
#import <EzioMobile/EMTlsConfiguration.h>
#import <EzioMobile/EMToken.h>
#import <EzioMobile/EMTokenCapability.h>
#import <EzioMobile/EMTokenJailbreakPolicy.h>
#import <EzioMobile/EMTokenManager.h>
#import <EzioMobile/EMTokenPolicy.h>
#import <EzioMobile/EMUIModule.h>
#import <EzioMobile/EMUIUtil.h>
#import <EzioMobile/EMVicDevice.h>
#import <EzioMobile/EMVicFactory.h>
#import <EzioMobile/EMVicService.h>
#import <EzioMobile/EMVicToken.h>
#import <EzioMobile/EMVicTokenManager.h>
#import <EzioMobile/EMWipeable.h>
#import <EzioMobile/SecureLog.h>
#import <EzioMobile/SecureLogConfig.h>
#import <EzioMobile/common.h>
#import <EzioMobile/em_auth_pin_enums.h>
#import <EzioMobile/em_detector.h>
#import <EzioMobile/em_otp_enums.h>
#import <EzioMobile/em_status.h>


#endif

