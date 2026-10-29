#include "../common/types.h"

// Agent R46p_39 (2026-10-29): FUN_001b0448 (80 bytes, SLPM_666.75).
// Saves a1 in s0 and calls func_0016bc20(a1, 12, -1). If the result is non-null,
// stores a1 at +0 of arg0 and the halfword at +6 of the result at +12 of arg0.
extern "C" void* func_0016bc20(u32 a0, s32 a1, s32 a2);

void func_001b0448(u32* a0, u32 a1) {
    u16* v = (u16*)func_0016bc20(a1, 12, -1);
    if (v != 0) {
        a0[0] = a1;
        asm volatile("" ::: "memory");
        a0[3] = v[3];
    }
}
