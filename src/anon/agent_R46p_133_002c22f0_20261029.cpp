#include "../common/types.h"

// Agent R46p_133 (2026-10-29): func_002c22f0 (104 bytes), SLPM_666.75.
// Loops 3 times over u16 ids at a0 + 4, stepping 4 bytes. Each non-zero id goes to
// YS::PROGRESS::CheckFlag (0x00181500); each non-zero result increments a counter. Returns the counter.

extern "C" u32 func_00181500(u32);

u32 func_002c22f0(u32 a0) {
    u8* s0 = (u8*)(a0 + 4);
    u32 s2 = 0;
    s32 s1 = 2;
    do {
        u32 t = *(u16*)s0;
        s0 += 4;
        if (t) {
            u32 n = s2 + 1;
            if (func_00181500(t)) s2 = n;
        }
        s1--;
    } while (s1 >= 0);
    return s2;
}
