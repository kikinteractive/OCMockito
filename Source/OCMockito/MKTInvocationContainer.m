//
//  OCMockito - MKTInvocationContainer.m
//  Copyright 2012 Jonathan M. Reid. See LICENSE.txt
//

#import "MKTInvocationContainer.h"

#import "MKTStubbedInvocationMatcher.h"


@interface MKTInvocationContainer ()
{
    MKTMockingProgress *_mockingProgress;
    NSMutableArray *_stubbed;
}
@property (nonatomic, retain) MKTStubbedInvocationMatcher *invocationMatcherForStubbing;
@end


@implementation MKTInvocationContainer

@synthesize returnsVoid = _returnsVoid;
@synthesize registeredInvocations = _registeredInvocations;
@synthesize invocationMatcherForStubbing = _invocationMatcherForStubbing;

- (id)initWithMockingProgress:(MKTMockingProgress *)mockingProgress
{
    self = [super init];
    if (self)
    {
        _registeredInvocations = [[NSMutableArray alloc] init];
        _mockingProgress = [mockingProgress retain];
        _stubbed = [[NSMutableArray alloc] init];
    }
    return self;
}

- (void)dealloc
{
    [_registeredInvocations release];
    [_mockingProgress release];
    [_invocationMatcherForStubbing release];
    [_stubbed release];
    
    [super dealloc];
}

- (void)setInvocationForPotentialStubbing:(NSInvocation *)invocation
{
    [invocation retainArguments];
    [_registeredInvocations addObject:invocation];
    
    MKTStubbedInvocationMatcher *stubbedInvocationMatcher = [[MKTStubbedInvocationMatcher alloc] init];
    [stubbedInvocationMatcher setExpectedInvocation:invocation];
    [self setInvocationMatcherForStubbing:stubbedInvocationMatcher];
    [stubbedInvocationMatcher release];
}

- (void)setMatcher:(id <HCMatcher>)matcher atIndex:(NSUInteger)argumentIndex
{
    [_invocationMatcherForStubbing setMatcher:matcher atIndex:argumentIndex];
}

- (void)addAnswer:(id)answer
{
    [_registeredInvocations removeLastObject];
    
    [_invocationMatcherForStubbing setAnswer:answer];
    [_stubbed insertObject:_invocationMatcherForStubbing atIndex:0];
}


- (void)addAnswer:(id)answer action:(void (^)(void))action
{
    [self addAnswer:answer];
    [_invocationMatcherForStubbing setAction:action];
}

- (void)addAction:(void (^)(void))action
{
    _returnsVoid = YES;
    [_registeredInvocations removeLastObject];
    [_invocationMatcherForStubbing setAction:action];
    [_stubbed insertObject:_invocationMatcherForStubbing atIndex:0];
}

- (id)findAnswerFor:(NSInvocation *)invocation
{
    for (MKTStubbedInvocationMatcher *stubbedInvocationMatcher in _stubbed)
        if ([stubbedInvocationMatcher matches:invocation])
            return [stubbedInvocationMatcher answer];
    
    return nil;
}


- (void (^)(void))findActionFor:(NSInvocation *)invocation
{
    for (MKTStubbedInvocationMatcher *stubbedInvocationMatcher in _stubbed) {
        if ([stubbedInvocationMatcher matches:invocation]) {
            return [stubbedInvocationMatcher action];
        }
    }
    
    return nil;
}

@end
