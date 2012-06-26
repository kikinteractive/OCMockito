//
//  OCMockito - MKTInvocationContainer.h
//  Copyright 2012 Jonathan M. Reid. See LICENSE.txt
//

#import <Foundation/Foundation.h>

@class MKTMockingProgress;
@protocol HCMatcher;

@interface MKTInvocationContainer : NSObject
{
    BOOL _returnsVoid;
}
@property (readonly) BOOL returnsVoid;
@property (nonatomic, readonly) NSMutableArray *registeredInvocations;

- (id)initWithMockingProgress:(MKTMockingProgress *)mockingProgress;
- (void)setInvocationForPotentialStubbing:(NSInvocation *)invocation;
- (void)setMatcher:(id <HCMatcher>)matcher atIndex:(NSUInteger)argumentIndex;
- (void)addAnswer:(id)answer;
- (void)addAnswer:(id)answer action:(void (^)(void))action;
- (void)addAction:(void (^)(void))action;
- (id)findAnswerFor:(NSInvocation *)invocation;
- (void (^)(void))findActionFor:(NSInvocation *)invocation;

@end
