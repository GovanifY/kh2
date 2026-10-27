#include "../common/types.h"

extern "C" u32 func_002dc7c8(u32);

// FUN_002dc248 (48 bytes)
// Code: p = func_002dc7c8(a0); return K - p->f112, where K is a float constant at 0x375d44.
// Guess: a distance or offset query on a sub-object.
f32 func_002dc248(u32 a0) {
    u32 p = func_002dc7c8(a0);
    u32 kp = 0x00370000u;
    __asm__("" : "+r"(kp));
    kp += 23876u;
    f32 k = *(volatile f32*)kp;
    return k - *(f32*)(p + 112);
}
