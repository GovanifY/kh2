#include "../common/types.h"

// Agent R46p_10 (2026-10-29): FUN_001886d0 (104 bytes). Calls func_001c0cd8(obj->inner) and, if that is zero,
// func_0019c090(obj->inner). Returns 0 when the second call is nonzero. Otherwise returns
// (inner->flags_352 & 0x200) == 0. The first load reads from a0 (lw t7,136(a0)), the rest from s0.
// s1 is opaque-zeroed so gcc keeps it in a callee-saved reg.
extern "C" u32 func_001c0cd8(u32);
extern "C" u32 func_0019c090(u32);

u32 func_001886d0(u8* a0) {
    u32 first = *(u32*)(a0 + 136);
    u8* s0 = a0;
    u32 s1 = 0;
    __asm__ __volatile__("" : "+r"(s0), "+r"(s1));
    if (func_001c0cd8(*(u32*)(first + 4)) == 0) {
        if (func_0019c090(*(u32*)(*(u32*)(s0 + 136) + 4)) != 0) {
            return s1;
        }
    }
    {
        u32 t6 = *(u32*)(*(u32*)(*(u32*)(s0 + 136) + 4) + 352) & 0x200u;
        s1 = (t6 == 0);
    }
    return s1;
}
