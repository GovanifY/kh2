#include "../common/types.h"

// Agent R46o_0 (2026-10-27): FUN_00177bf8 (84 bytes, SLPM_666.75).

extern "C" u32 func_00177860(u32 a0);

u32 func_00177bf8(u32 a0) {
    register u32 s1 asm("$17");
    s1 = a0;
    asm volatile("" : "+r"(s1));
    u32 cur = *(u8*)(a0 + 2820);
    u32 v = func_00177860(a0);
    s32 lim = *(s8*)(v + 45);
    if ((s32)cur < lim) {
        return *(u8*)(s1 + 2820);
    }
    v = func_00177860(s1);
    return (u32)(s32)*(s8*)(v + 45);
}
