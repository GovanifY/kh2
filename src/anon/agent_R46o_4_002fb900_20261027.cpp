#include "../common/types.h"

// FUN_002fb900 (40 bytes): float copysign. Keeps |a| and takes the sign bit of b. Args in $f12/$f13, result in $f0.
f32 func_002fb900(f32 a, f32 b) {
    union { f32 f; u32 u; } x, y;
    register u32 xb asm("$13");
    register u32 yb asm("$15");
    x.f = a;
    y.f = b;
    xb = x.u;
    yb = y.u;
    xb &= 0x7fffffffu;
    yb &= 0x80000000u;
    asm("or %0,%0,%1" : "+r"(xb) : "r"(yb));
    x.u = xb;
    return x.f;
}
