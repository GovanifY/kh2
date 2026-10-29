#include "../common/types.h"

extern "C" u32 func_00185da8(u32);
extern "C" u32 func_00186ce8(u32);

// FUN_0018f3a8 (100 bytes): walks FUN_00185da8 from a null start until it returns 0. Each non-null
// result is passed to FUN_00186ce8; a non-zero return bumps the counter. Stores the counter at a0[0].
// The conditional increment is a movn in an asm block. The call block sits after the store-and-return
// path, as in the original, which the goto shape keeps.
void func_0018f3a8(u32* a0) {
    u32 s0 = 0;
    u32 s1 = 0;
    u32 r;
top:
    s0 = func_00185da8(s0);
    if (s0 != 0) {
        goto call_blk;
    }
    a0[0] = s1;
    return;
call_blk:
    r = func_00186ce8(s0);
    {
        u32 t = s1 + 1;
        asm volatile("movn %0,%1,%2" : "+r"(s1) : "r"(t), "r"(r));
    }
    goto top;
}
