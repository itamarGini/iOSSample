//
//  DIOServiceClient.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/13/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOServiceClient : NSObject

@property (nonatomic, strong) NSString *urlString;

- (void)placementsForAppId:(NSString*)appId completionHandler:(void (^)(id, NSString*))completionHandler;
- (void)placementForAppId:(NSString*)appId placementId:(NSString*)placementId data:(id)data completionHandler:(void (^)(id, NSString*))completionHandler;
- (void)reportErrorForAppId:(NSString*)appId messageLog:(NSString*)messageLog error:(NSString*)error trace:(NSString*)trace data:(id)data;
- (void)addWithKey:(NSString*)key value:(NSString*)value;
- (void)callBeaconWithURLString:(NSString*)urlString;

@end

NS_ASSUME_NONNULL_END
