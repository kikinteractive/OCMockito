//
//  OCMockito - MKTOngoingStubbing.h
//  Copyright 2012 Jonathan M. Reid. See LICENSE.txt
//

#import <Foundation/Foundation.h>
#import "MKTPrimitiveArgumentMatching.h"

@class MKTInvocationContainer;


/**
    Methods to invoke on @c given(methodCall) to return stubbed values.
 */
@interface MKTOngoingStubbing : NSObject <MKTPrimitiveArgumentMatching>

- (id)initWithInvocationContainer:(MKTInvocationContainer *)invocationContainer;

/// Stubs given object as return value.
- (MKTOngoingStubbing *)willReturn:(id)object;

/// Stubs given @c BOOL as return value.
- (MKTOngoingStubbing *)willReturnBool:(BOOL)value;

/// Stubs given @c char as return value.
- (MKTOngoingStubbing *)willReturnChar:(char)value;

/// Stubs given @c int as return value.
- (MKTOngoingStubbing *)willReturnInt:(int)value;

/// Stubs given @c short as return value.
- (MKTOngoingStubbing *)willReturnShort:(short)value;

/// Stubs given @c long as return value.
- (MKTOngoingStubbing *)willReturnLong:(long)value;

/// Stubs given <code>long long</code> as return value.
- (MKTOngoingStubbing *)willReturnLongLong:(long long)value;

/// Stubs given @c NSInteger as return value.
- (MKTOngoingStubbing *)willReturnInteger:(NSInteger)value;

/// Stubs given <code>unsigned char</code> as return value.
- (MKTOngoingStubbing *)willReturnUnsignedChar:(unsigned char)value;

/// Stubs given <code>unsigned int</code> as return value.
- (MKTOngoingStubbing *)willReturnUnsignedInt:(unsigned int)value;

/// Stubs given <code>unsigned short</code> as return value.
- (MKTOngoingStubbing *)willReturnUnsignedShort:(unsigned short)value;

/// Stubs given <code>unsigned long</code> as return value.
- (MKTOngoingStubbing *)willReturnUnsignedLong:(unsigned long)value;

/// Stubs given <code>unsigned long long</code> as return value.
- (MKTOngoingStubbing *)willReturnUnsignedLongLong:(unsigned long long)value;

/// Stubs given @c NSUInteger as return value.
- (MKTOngoingStubbing *)willReturnUnsignedInteger:(NSUInteger)value;

/// Stubs given @c float as return value.
- (MKTOngoingStubbing *)willReturnFloat:(float)value;

/// Stubs given @c double as return value.
- (MKTOngoingStubbing *)willReturnDouble:(double)value;


/**
 * Provides a facility to stub with all return values above, and also execute a block.
 */

- (MKTOngoingStubbing *)willDo:(void (^)(void))action andReturn:(id)object;

#define DEFINE_DO_AND_RETURN_METHOD_PROTO(type, typeName)                                        \
- (MKTOngoingStubbing *)willDo:(void (^)(void))action andReturn ## typeName:(type)value                      

DEFINE_DO_AND_RETURN_METHOD_PROTO(BOOL, Bool);
DEFINE_DO_AND_RETURN_METHOD_PROTO(char, Char);
DEFINE_DO_AND_RETURN_METHOD_PROTO(int, Int);
DEFINE_DO_AND_RETURN_METHOD_PROTO(short, Short);
DEFINE_DO_AND_RETURN_METHOD_PROTO(long, Long);
DEFINE_DO_AND_RETURN_METHOD_PROTO(long long, LongLong);
DEFINE_DO_AND_RETURN_METHOD_PROTO(NSInteger, Integer);
DEFINE_DO_AND_RETURN_METHOD_PROTO(unsigned char, UnsignedChar);
DEFINE_DO_AND_RETURN_METHOD_PROTO(unsigned int, UnsignedInt);
DEFINE_DO_AND_RETURN_METHOD_PROTO(unsigned short, UnsignedShort);
DEFINE_DO_AND_RETURN_METHOD_PROTO(unsigned long, UnsignedLong);
DEFINE_DO_AND_RETURN_METHOD_PROTO(unsigned long long, UnsignedLongLong);
DEFINE_DO_AND_RETURN_METHOD_PROTO(NSUInteger, UnsignedInteger);
DEFINE_DO_AND_RETURN_METHOD_PROTO(float, Float);
DEFINE_DO_AND_RETURN_METHOD_PROTO(double, Double);

@end
