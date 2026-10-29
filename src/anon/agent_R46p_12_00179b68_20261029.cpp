#include "../common/types.h"

// Agent R46p_12 (2026-10-29): FUN_00179b68 (96 bytes, SLPM_666.75).

extern "C" u32 func_001a6a20(u32, u32);
extern "C" u32 func_00176a90(u32);

// FUN_00179b68: p = FUN_001a6a20(0x10002, 12); the result is s1, set to 1 when p->word4 is nonzero
// or when FUN_00176a90(a0) is nonzero.
u32 func_00179b68(u32 a0) {
    register u32 s1 asm("$17");
    s1 = 0;
    u32* obj = (u32*)func_001a6a20(0x10002u, 12u);
    asm volatile("" : "+r"(s1));
    if (obj[1] != 0) {
        goto set_one;
    }
    if (func_00176a90(a0) == 0) {
        return s1;
    }
set_one:
    s1 = 1;
    asm volatile("" : "+r"(s1));
    return s1;
}
