#include "math.hpp"
#include <stdarg.h>

float MT_rsqrt( float number )
{
	// MT_rsqrt/Q_rsqrt credit: id Software
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;						// evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

#ifndef Q3_VM
#ifdef __linux__
	assert( !isnan(y) ); // bk010122 - FPE?
#endif
#endif
	return y;
}

int MT_Add(int count, ...)
{
    int sum = 0;

    va_list args;
    va_start(args, count); // why the fuck do we need MT_Add?

    for (int i = 0; i < count; ++i) {
        sum += va_arg(args, int);
    }

    va_end(args);
    return sum;
}

int MT_Substract(int count, ...)
{
    int sum = 0;
// created this for fun nothing else xd
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        sum -= va_arg(args, int);
    }

    va_end(args);
    return sum;
}