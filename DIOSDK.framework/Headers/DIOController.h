//
//  DIOController.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/17/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "DIOPlacement.h"
#import "DIOServiceClient.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOController : NSObject <CLLocationManagerDelegate>

@property (nonatomic) BOOL initialized;
@property (nonatomic, strong) NSMutableDictionary *placements;
@property (nonatomic, strong) CLLocation *lastKnownLocation;

/**
 @return The DIOController singleton.
 */
+ (DIOController*)sharedInstance;

/**
 Initializes the DIOController. This should be called only once during the application lifecycle.
 
 This operation is asynchronous.
 
 @param appId The application id as defined in the Display.io control panel.
 @param completionHandler A block object to be executed when the task finishes successfully.
 @param errorHandler A block object to be executed when something is going wrong. This block takes one argument: the error message.
 */
- (void)initializeWithAppId:(NSString*)appId completionHandler:(void (^)(void))completionHandler errorHandler:(void (^)(NSString*))errorHandler;

/**
 @param placementId The placement id as defined in the Display.io control panel.
 
 @return The corresponding placement object.
 
 @throw An expection if DIOController is not initialized or if no placement object is found.
*/
- (DIOPlacement*)placementWithId:(NSString*)placementId;

/**
 Allows to control if location based targeting should be used (enabled by default.)
 
 Should be called before -initializeWithAppId:completionHandler:errorHandler:
 
 @param enabled Whether to enable or not.
 */
- (void)setLocationBasedTargeting:(BOOL)enabled;

/**
 Allows to control if first call to Display.io server should use https protocol
 (otherwise http will be used)
 
 Should be called before -initializeWithAppId:completionHandler:errorHandler:
 */
- (void)requireHttpsInitialization;

- (NSString*)appId;
- (DIOServiceClient*)serviceClient;
- (id)iabConsentData;
- (void)logWithMessage:(NSString*)message;
- (void)logWithError:(NSString*)error trace:(NSArray<NSString*>*)trace data:(id)data;

- (void)uninitialize;
- (void)setCourseWithURLString:(NSString*)urlString;
- (void)setHyperGeoWithIp:(NSString*)ip;
- (void)handleUncaughtException:(NSException*)exception;
- (BOOL)shouldApplyGDPRConstraints;
- (BOOL)shouldApplyCOPPACompliance;
- (BOOL)doesRequireHttpsInit;

@end

NS_ASSUME_NONNULL_END
