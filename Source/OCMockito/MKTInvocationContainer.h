//
//  OCMockito - MKTInvocationContainer.h
//  Copyright 2012 Jonathan M. Reid. See LICENSE.txt
//

#import <Foundation/Foundation.h>

@class MKTMockingProgress;
@protocol HCMatcher;

/**
 * The type for optional actions to be performed for stubbed methods, in conjunction with
 * optionally returning a value.
 */
typedef void (^MKTMockStubAction)(void);

@interface MKTInvocationContainer : NSObject

@property (nonatomic, readonly) NSMutableArray *registeredInvocations;

- (id)initWithMockingProgress:(MKTMockingProgress *)mockingProgress;
- (void)setInvocationForPotentialStubbing:(NSInvocation *)invocation;
- (void)setMatcher:(id <HCMatcher>)matcher atIndex:(NSUInteger)argumentIndex;
- (void)addAnswer:(id)answer;
- (void)addAnswer:(id)answer action:(MKTMockStubAction)action;
- (id)findAnswerFor:(NSInvocation *)invocation;
- (MKTMockStubAction)findActionFor:(NSInvocation *)invocation;
@end
