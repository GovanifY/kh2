#include "../common/types.h"

// Agent R46k_2: FUN_00171930 (48 bytes), SLPM_666.75.
// Copies 16 bytes from *(arg0+4) into a stack buffer, then tail-returns
// FUN_0016b010(word at +4 of *(arg0+0), &buffer).
extern "C" u32 func_0016b010(u32 a0, void* a1);
extern "C" u32 func_00171930(u32* a0);

u32 func_00171930(u32* a0) {
    register u32 src asm("$15");
    register u32 obj asm("$14");
    register u32 bp asm("$5");
    u32 buf[4] __attribute__((aligned(16)));
    src = a0[1];
    asm volatile("lq $8,0(%1)\n\tsq $8,0(%2)" : "=m"(buf) : "r"(src), "r"(buf) : "$8", "memory");
    obj = a0[0];
    bp = (u32)buf;
    asm volatile("" : "+r"(obj), "+r"(bp));
    return func_0016b010(((u32*)obj)[1], (void*)bp);
}
