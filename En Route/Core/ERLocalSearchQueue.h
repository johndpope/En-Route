//
//  ERLocalSearchQueue.h
//  En Route
//
//  Created by Tanner on 1/16/16.
//  Copyright © 2016 Tanner Bennett. All rights reserved.
//

@import MapKit;


@interface ERLocalSearchQueue : NSObject

+ (instancetype)queueWithQuery:(NSString *)query radius:(CLLocationDistance)radius;

- (void)searchRoutes:(NSArray<MKRoute*> *)routes repeatedCallback:(ArrayBlock)callback completion:(VoidBlock)completion;
- (void)cancelRequests;

@property (nonatomic) CLLocationDistance searchRadius;
@property (nonatomic) NSString *query;
/// Whether or not we can make more requests immediately
@property (nonatomic, readonly) BOOL ready;

@property (nonatomic, copy) DebugBlock debugCallback;
@property (nonatomic, copy) IntBlock pauseCallback;
@property (nonatomic, copy) VoidBlock resumeCallback;
/// Calls completion afterwards.
@property (nonatomic, copy) VoidBlock errorCallback;
@property (nonatomic, copy) VoidBlock rateLimitingCallback;

@end
