/*
 *  Copyright (c) 2018-present, Facebook, Inc.
 *
 *  This source code is licensed under the MIT license found in the LICENSE
 *  file in the root directory of this source tree.
 *
 */
#ifdef FB_SONARKIT_ENABLED

#import <Foundation/Foundation.h>
#import "SonarPlugin.h"
#import "FlipperStateUpdateListener.h"

/**
Represents a connection between the Sonar desktop och client side. Manages the lifecycle of attached
plugin instances.
*/
@interface SonarClient : NSObject

/**
The shared singleton SonarClient instance. It is an error to call this on non-debug builds to avoid leaking data.
*/
+ (instancetype)sharedClient;

/**
Register a plugin with the client.
*/
- (void)addPlugin:(NSObject<SonarPlugin> *)plugin;

/**
Unregister a plugin with the client.
*/
- (void)removePlugin:(NSObject<SonarPlugin> *)plugin;

/**
Retrieve the plugin with a given identifier which was previously registered with this client.
*/
- (NSObject<SonarPlugin> *)pluginWithIdentifier:(NSString *)identifier;

/**
Establish a connection to the Sonar desktop.
*/
- (void)start;

/**
Stop the connection to the Sonar desktop.
*/
- (void)stop;

/**
Get the log of state changes from the sonar client
*/
- (NSString *)getState;

/**
 Get the current summarized state of the sonar client
 */
- (NSArray<NSDictionary *> *)getStateElements;

/**
Subscribe a ViewController to state update change notifications
*/
- (void)subscribeForUpdates:(id<FlipperStateUpdateListener>)controller;

// initializers are disabled. You must use `+[SonarClient sharedClient]` instance.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

#endif
