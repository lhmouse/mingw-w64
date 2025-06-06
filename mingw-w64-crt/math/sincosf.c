/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>

void sincosf(float x, float *s, float *c)
{
    *s = sinf(x);
    *c = cosf(x);
}
