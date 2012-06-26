//
//  OCMockito - MKTStubbedInvocationMatcher.m
//  Copyright 2012 Jonathan M. Reid. See LICENSE.txt
//

#import "MKTStubbedInvocationMatcher.h"


@implementation MKTStubbedInvocationMatcher

@synthesize answer = _answer;
@synthesize action;

- (void)dealloc
{
    self.action = nil;
    [_answer release];
    [super dealloc];
}

@end
