//
//  HCNXBase.h
//  HCNXBase
//
//  Created by Damien PRACA on 03/10/16.
//  Copyright © 2016 HighConnexion. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "const.h"
#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonHMAC.h>
#import <UIKit/UIKit.h>
#include <sys/sysctl.h>
#include <sys/utsname.h>
#import <unistd.h>

//! Project version number for HCNXBase.
FOUNDATION_EXPORT double HCNXBaseVersionNumber;

//! Project version string for HCNXBase.
FOUNDATION_EXPORT const unsigned char HCNXBaseVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <HCNXBase/PublicHeader.h>


#import <Foundation/Foundation.h>
#import <MessageUI/MessageUI.h>
#import <SafariServices/SafariServices.h>

@interface HCNXBase : NSObject {
    NSString * mToken;
    NSString * mHash;
    NSString * mHn_id;
    NSString * mIdfa;
    NSString * mUDID;
    NSString * mCustomerId;
    NSString * base_url;
    
    NSString * API_PUSH;
    NSString * SECRET_PUSH;
    NSURLSessionConfiguration *sessionConfig ;
}

#define ENVIRONNEMENT_PROD 0
#define ENVIRONNEMENT_RECETTE 1

/*!
 @brief Use this method to get the instance of HCNXBase
 */
+ (HCNXBase *)sharedInstance;

/*!
 @brief Use this method to configure the API_KEY and the HMAC_KEY
 @param pApiKey is an NSString provide by Highconnexion
 @param pHmacKey is an NSString provide by Highconnexion
 */
-(void)configureWithAPIKey:(NSString*)pApiKey andHmacKey:(NSString*)pHmacKey;

/*!
 @brief Use this method to set the IDFA
 @param IDFA is an NSString provide by Apple for advertising
 */
-(void)setIdfa:(NSString*)pIdfa;

/*!
 @brief Use this method to set the customerId
 @param pCustomerId is an NSString provide by the application
 */
-(void)setCustomerId:(NSString*)pCustomerId;

/*!
 @brief Use this method to switch between developments environments. By default we reach production environnement.
 @param pDebug is an constant provide by Hello SDK
 */
-(void)setEnvironnement:(NSInteger)pDebug;

/*!
 @brief Use this method return the Highconnexion id for push
 @return NSString Hn_id
 */
-(NSString*)getHn_id;

- (void)configureHCNX:(NSDictionary*) parameters andRequest:(NSMutableURLRequest*)request;
- (NSString *)addGetParameters:(NSString *)url andParam:(NSDictionary*)params;
- (NSString *)addPostParameters:(NSDictionary*)params;
- (NSString *)hmac_sha1:(NSString *)secret data:(NSString *)data;
- (UIViewController*) topMostController;

@end