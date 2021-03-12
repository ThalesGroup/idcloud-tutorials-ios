/** -----------------------------------------------------------------------------
 
 Copyright (c) 2019  -  GEMALTO DEVELOPMENT - R&D
 
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

NS_ASSUME_NONNULL_BEGIN

/** iOS default timeout */
FOUNDATION_EXPORT NSTimeInterval const EMFastTrackTlsConfigurationDefaultTimeout;

/**
 * A class representing a TLS configuration.
 * - Since: 5.3
 */
@interface EMFastTrackTlsConfiguration : NSObject

/**
 Constructs a `EMFastTrackTlsConfiguration` object whose settings are
 all `NO`.
 
 This is the most secure configuration for the communication link.
 
 @return New instance of a `EMFastTrackTlsConfiguration`.
 */
- (instancetype)init;

/**
 Constructs a `EMFastTrackTlsConfiguration` object whose settings are
 all `NO`, with ability to set timeout interval.
 
 This is the most secure configuration for the communication link.
 
 @param timeout The timeout of the connection in seconds.
 
 @return New instance of a EMFastTrackTlsConfiguration.
 - Since: 5.3
 */
- (instancetype)initWithTimeout:(NSTimeInterval)timeout;

/**
 Constructs a `EMFastTrackTlsConfiguration` object whose settings are
 configured in this constructor.
 
 @warning It is not recommended to override these settings in a
 production environment.  Allowing any of these configurations will
 reduce the security of the communication link with the server.
 @warning The insecure permits could only used in debug build for
 test purpose. They were not allowed to be used in release mode since
 3.0 version.
 
 @param insecureConnectionAllowed If `YES`, then either an unencrypted
 (http) or an encrypted (https) connection is allowed.  If `NO`, then
 only encrypted connections are allowed.
 @param selfSignedCertAllowed If `YES`, then a connection will accept a
 self signed server certificate.  If `NO`, then a connection whose
 server certificate is not signed by a certificate authority on the
 device is rejected.
 @param hostnameMismatchAllowed If `YES`, then a connection will accept a
 server certificate whose common name (CN) does not match the URL's
 domain.  If `NO`, then a connection whose server certificate's CN does
 not match the URL's domain is rejected.  This setting is ignored if self
 signed certificates are allowed.
 
 @return New instance of a EMFastTrackTlsConfiguration.
 */
- (instancetype)initWithInsecureConnectionAllowed:(BOOL)insecureConnectionAllowed
                            selfSignedCertAllowed:(BOOL)selfSignedCertAllowed
                          hostnameMismatchAllowed:(BOOL)hostnameMismatchAllowed;

/**
 Constructs a `EMFastTrackTlsConfiguration` object whose settings are
 configured in this constructor.
 
 @warning It is not recommended to override these settings in a
 production environment.  Allowing any of these configurations will
 reduce the security of the communication link with the server.
 @warning The insecure permits could only used in debug build for
 test purpose. They were not allowed to be used in release mode since
 3.0 version.
 
 @param insecureConnectionAllowed If `YES`, then either an unencrypted
 (http) or an encrypted (https) connection is allowed.  If `NO`, then
 only encrypted connections are allowed.
 @param selfSignedCertAllowed If `YES`, then a connection will accept a
 self signed server certificate.  If `NO`, then a connection whose
 server certificate is not signed by a certificate authority on the
 device is rejected.
 @param hostnameMismatchAllowed If `YES`, then a connection will accept a
 server certificate whose common name (CN) does not match the URL's
 domain.  If `NO`, then a connection whose server certificate's CN does
 not match the URL's domain is rejected.  This setting is ignored if self
 signed certificates are allowed.
 @param timeout The timeout of the connection in seconds.
 
 @return New instance of a EMFastTrackTlsConfiguration.
 */
- (instancetype)initWithInsecureConnectionAllowed:(BOOL)insecureConnectionAllowed
                            selfSignedCertAllowed:(BOOL)selfSignedCertAllowed
                          hostnameMismatchAllowed:(BOOL)hostnameMismatchAllowed
                                          timeout:(NSTimeInterval)timeout;


/**
 Constructs a *EMFastTrackTlsConfiguration* object whose settings are
 configured in this constructor. This API will do the certificate
 pinning check.
 
 @warning It is not recommended to override these settings in a
 production environment other than the certificates to pin.
 Allowing any of these configurations will reduce the security
 of the communication link with the server.
 @warning The insecure permits could only used in debug build for
 test purpose. They were not allowed to be used in release mode since
 3.0 version.
 @warning iOS client only allows certificate from the content of file
 with the following format: X.509 Certificate (DER)
 @warning iOS client does not support certificate from the content of file
 with the following format: (1) X.509 Certificate (PEM), (2) X.509
 Certificate with chain (PEM), (3) X.509 Certificate (PKCS#7), and (4) X.509
 Certificate with chain (PKCS#7).
 
 @param certificates List of certificates data to be checked for pinning.
 @param insecureConnectionAllowed If `YES`, then either an unencrypted
 (http) or an encrypted (https) connection is allowed.  If `NO`, then
 only encrypted connections are allowed.
 @param selfSignedCertAllowed If `YES`, then a connection will accept a
 self signed server certificate.  If `NO`, then a connection whose
 server certificate is not signed by a certificate authority on the
 device is rejected.
 @param hostnameMismatchAllowed If `YES`, then a connection will accept a
 server certificate whose common name (CN) does not match the URL's
 domain.  If `NO`, then a connection whose server certificate's CN does
 not match the URL's domain is rejected.  This setting is ignored if self
 signed certificates are allowed.
 @param timeout The timeout of the connection in seconds.
 
 @return New instance of a *EMFastTrackTlsConfiguration*.
 
 - Since: 5.3
 */
- (instancetype)initWithCertificates:(nullable NSArray *)certificates
           insecureConnectionAllowed:(BOOL)insecureConnectionAllowed
               selfSignedCertAllowed:(BOOL)selfSignedCertAllowed
             hostnameMismatchAllowed:(BOOL)hostnameMismatchAllowed
                             timeout:(NSTimeInterval)timeout NS_DESIGNATED_INITIALIZER;

///////////////////////////////////////////////////////////////////////////////////////
/** Properties */
///////////////////////////////////////////////////////////////////////////////////////


/**
 Whether or not an insecure connection is allowed.
 
 @return If `YES`, then either an unencrypted (http) or an encrypted
 (https) connection is allowed.  If `NO`, then only encrypted
 connections are allowed.
 */
@property (nonatomic, readonly, getter = isInsecureConnectionAllowed) BOOL insecureConnectionAllowed;

/**
 Whether or not self signed certificate is allowed.
 
 @return If `YES`, then a connection will accept a self signed server
 certificate.  If `NO`, then a connection whose server certificate is
 not signed by a certificate authority on the device is rejected.
 */
@property (nonatomic, readonly, getter = isSelfSignedCertAllowed) BOOL selfSignedCertAllowed;

/**
 Whether or not to allow mismatch between common name (CN) of the server certificates and
 domain name of the URL.
 
 @return If `YES`, then a connection will accept a server certificate
 whose common name (CN) does not match the URL's domain.
 If `NO`, then the connection is rejected.
 This setting is ignored if self signed certificates are allowed.
 */
@property (nonatomic, readonly, getter = isHostnameMismatchAllowed) BOOL hostnameMismatchAllowed;

/**
 Gets the timeout of the connection.
 @return Returns the timeout in seconds.
 */
@property (nonatomic, assign, readonly) NSTimeInterval timeout;

/**
 Get the certificates.
 @return Returns the certificates.
 - Since: 5.3
 */
@property (nonatomic, readonly, nullable) NSArray *certificates;

@end

NS_ASSUME_NONNULL_END
