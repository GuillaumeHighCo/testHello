//
//  Hello.h
//  HelloFramework
//
//  Created by Guillaume MARTINEZ on 25/05/2016.
//  Copyright © 2016 Guillaume MARTINEZ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HCNXBase/HCNXBase.h>

/*!
 @file Hello
 @class Hello
 @discussion Hello is a singleton used to register to Hello server and to subsribe or unsubsribe to channels<br>
 To use this singleton, you need :<br>
 - an API_KEY provided by Highconnexion<br>
 - a HMAC_KEY provided by Highconnexion<br>
 - an tokenDevice provide by Apple
 @version 1.0
 @author contact.supportpro@highconnexion
 */


@interface Hello : HCNXBase <MFMessageComposeViewControllerDelegate, MFMailComposeViewControllerDelegate, SFSafariViewControllerDelegate>

/*!
 @brief Use this method to get the instance of Hello
 */
+ (Hello *)sharedInstance;

/*!
 @brief Use this method to ask the notification push permission
 */
- (void)askPermission;

/*!
 @brief Use this method to set the Apple tokenDevice
 @param pTokenDevice is an NSString provide by Apple
 */
- (void)setTokenDevice:(NSString*)pTokenDevice;

/*!
 @brief Use this method return the Apple tokenDevice
 @return NSString mToken
 */
- (NSString*)getTokenDevice;

/*!
 @brief Refresh the list of the channels for this app, with subscription status
 @return NSArray * channels the list of all the channels for this app, NSError * error if an error occured
 */
- (void)getChannels:(void (^)(NSArray * channels, NSError* error)) onCompletion;


/*!
 @brief Manage channels
 @param subChannelList is an NSArray fill with channel_code, list of all channels code that should be subscribed. Could be nil.
 @param unSubChannelList is an NSArray fill with channel_code, list of all channels code that should be subscribed. Could be nil.
 @brief if both of the parameters are fill the unSubscribe method will be executed
 @return NSError * error if an error occured
 */
- (void)manageChannels:(NSArray*) subChannelList andUnSubChannelList:(NSArray*)unSubChannelList completion:(void (^)(NSError* error)) onCompletion;


/*!
 @brief Subscribe to channels
 @param channelList is an NSArray fill with channel_code, list of all channels code that should be subscribed
 @return NSError * error if an error occured
 */
- (void)subscribeToChannel:(NSArray*) channelList completion:(void (^)(NSError* error)) onCompletion DEPRECATED_ATTRIBUTE;

/*!
 @brief Unsubscribe to channels
 @param channelList is an NSArray fill with channel_code, list of all channels code that should be unsubscribed
 @return NSError * error if an error occured
 */
- (void)unSubscribeToChannel:(NSArray*) channelList  completion:(void (^)(NSError* error)) onCompletion DEPRECATED_ATTRIBUTE;


/*!
 @brief Subscribe to defaults channels
 @return NSError * error if an error occured
 */
- (void)subscribeToDefaultChannels:(void (^)(NSError * error))onCompletion DEPRECATED_ATTRIBUTE;

- (void)getHours:(void (^)(NSArray * hours, NSError * error))onCompletion;

- (void)manageHours:(NSArray*) hourList andUnSubHour:(NSArray*) unSubHourList completion:(void (^)(NSError* error)) onCompletion;

- (id)handleRedirect:(NSDictionary *) payLoad;

- (void)getCampaignsInApp:(void (^)(NSArray * campaigns, NSError * error))onCompletion;


@end
