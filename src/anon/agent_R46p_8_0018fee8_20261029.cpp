#include "../common/types.h"

// Agent R46p_8 (2026-10-29): FUN_0018fee8 (60 bytes, SLPM_666.75).
// arg0[0] = func_001b58f0(arg0[0], arg0[1], arg0[3], word at +4 of *(arg0+8)).

extern "C" u32 func_001b58f0(u32 a0, u32 a1, u32 a2, u32 a3);

void func_0018fee8(u32* a0) {
    u32* obj = (u32*)a0[2];
    a0[0] = func_001b58f0(a0[0], a0[1], a0[3], obj[1]);
}
