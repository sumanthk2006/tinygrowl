// Created by Satoshi Nakagawa.
// You can redistribute it and/or modify it under the new BSD license.

#import <Cocoa/Cocoa.h>


@interface TinyGrowlClient : NSObject
{
	id delegate;
	NSString* appName;
	NSArray* allNotifications;
	NSArray* defaultNotifications;
	NSImage* appIcon;
	NSTimeInterval lastCallbackTime;
}

@property (nonatomic, assign) id delegate;
@property (nonatomic, copy) NSString* appName;
@property (nonatomic, retain) NSArray* allNotifications;
@property (nonatomic, retain) NSArray* defaultNotifications;
@property (nonatomic, retain) NSImage* appIcon;

- (void)registerApplication;

- (void)notifyWithType:(NSString*)type
				 title:(NSString*)title
		   description:(NSString*)desc;


- (void)notifyWithType:(NSString*)type
				 title:(NSString*)title
		   description:(NSString*)desc
		  clickContext:(id)context;

- (void)notifyWithType:(NSString*)type
				 title:(NSString*)title
		   description:(NSString*)desc
		  clickContext:(id)context
				sticky:(BOOL)sticky;

- (void)notifyWithType:(NSString*)type
				 title:(NSString*)title
		   description:(NSString*)desc
		  clickContext:(id)context
				sticky:(BOOL)sticky
			  priority:(int)priority
				  icon:(NSImage*)icon;

@end


@interface NSObject (TinyGrowlClient)
- (void)tinyGrowlClient:(TinyGrowlClient*)sender didClick:(id)context;
- (void)tinyGrowlClient:(TinyGrowlClient*)sender didTimeOut:(id)context;
@end