#include "../common/types.h"

extern "C" f32 func_002e50f8(u32);

// FUN_002dd218 (48 bytes)
// Code: r = func_002e50f8(a0 + 256); return -(r + K), where K is a float constant at 0x375db8.
// Guess: negated offset of a sub-object's value.
f32 func_002dd218(u32 a0) {
    f32 r = func_002e50f8(a0 + 256);
    u32 kp = 0x00370000u;
    __asm__("" : "+r"(kp));
    kp += 23992u;
    f32 k = *(volatile f32*)kp;
    return -(r + k);
}
