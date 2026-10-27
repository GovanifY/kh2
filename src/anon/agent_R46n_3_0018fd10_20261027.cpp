#include "../common/types.h"

// FUN_0018fd10 (48 bytes): s0 = a0; *s0 = FUN_001a6a20(*s0, s0[1]).
// Reads both fields before the call; the result is stored back to +0.
u32 func_001a6a20(u32, u32);

void r_FUN_0018fd10(u32 a0) asm("func_0018fd10");

void r_FUN_0018fd10(u32 a0) {
    u32* p = (u32*)a0;
    u32 x = p[0];
    u32 y = p[1];
    p[0] = func_001a6a20(x, y);
}
