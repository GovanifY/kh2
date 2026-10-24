#include "../common/types.h"

// FUN_00174af8 (48 bytes). Passes the four words at +0, +4, +8, +12 of arg0 and the float at +16
// to func_001b1bb8, with 128 as the sixth argument, and tail-calls it.
// Matching: the asm barriers set the order li t0 / lw a0 / lwc1 / lw a1..a3 as in the original.
extern "C" void func_001b1bb8(f32, u32, u32, u32, u32, u32);

void func_00174af8(u32 *s) {
    u32 k = 128;
    asm volatile("" : "+r"(k));
    u32 x0 = s[0];
    asm volatile("" : "+r"(x0));
    f32 f = *(f32 *)&s[4];
    asm volatile("" : "+f"(f));
    u32 x1 = s[1];
    u32 x2 = s[2];
    asm volatile("" : "+r"(x2));
    u32 x3 = s[3];
    func_001b1bb8(f, x0, x1, x2, x3, k);
}
