#include "../common/types.h"

// Agent R46p_8 (2026-10-29): FUN_0018fe80 (104 bytes, SLPM_666.75).
// p = func_001b58f0(arg0[0], arg0[1], arg0[3], 0). If p is non-zero, r = func_001dc5f8(p).
// If r != arg0[2], copies 16 bytes from arg0[2] to r. Then stores p at arg0[0] on all paths.

typedef int u128 __attribute__((mode(TI)));

extern "C" u32 func_001b58f0(u32 a0, u32 a1, u32 a2, u32 a3);
extern "C" u32 func_001dc5f8(u32 a0);

void func_0018fe80(u32* a0) {
    u32 p = func_001b58f0(a0[0], a0[1], a0[3], 0);
    if (p != 0) {
        u32 r = func_001dc5f8(p);
        register u32* src asm("$15");
        src = (u32*)a0[2];
        asm volatile("" : "+r"(src));
        if (r != (u32)src) {
            register u128 tmp asm("$8");
            tmp = *(u128*)src;
            *(u128*)r = tmp;
        }
    }
    a0[0] = p;
}
