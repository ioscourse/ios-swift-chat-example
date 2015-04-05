//
//  MessagesViewController.swift
//  FireChat-Swift
//
//  Created by Chuck Konkol 4/1/2015.

#ifndef FireChat_Swift_TwitterAuthHelper_h
#define FireChat_Swift_TwitterAuthHelper_h

#import <Firebase/Firebase.h>

@interface TwitterAuthHelper : NSObject

@property (strong, nonatomic) ACAccountStore *store;
@property (strong, nonatomic) Firebase *ref;
@property (strong, nonatomic) NSString *appId;

- (id) initWithFirebaseRef:(Firebase *)ref twitterAppId:(NSString *)appId;

// Step 1a
- (void) selectTwitterAccountWithCallback:(void (^)(NSError *error, NSArray *accounts))callback;

// Step 1b through 3:
- (void) authenticateAccount:(ACAccount *)account withCallback:(void (^)(NSError *error, FAuthData *authData))callback;

@end

typedef NS_ENUM(NSInteger, AuthHelperError) {
    AuthHelperErrorAccountAccessDenied = -1
};

#endif