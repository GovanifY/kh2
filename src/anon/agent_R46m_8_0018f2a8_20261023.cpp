#include "../common/types.h"

// Agent R46m_8: FUN_0018f2a8 (40 bytes).
// Code: calls FUN_001863a8(word 1 of *(arg0[0]), arg0[1], float at arg0+8) (tail call).
u32 func_001863a8(u32, u32, f32);

u32 func_0018f2a8(u32* a0) {
    register u32 t7 asm("$15");
    register u32 t6 asm("$14");
    t7 = a0[0];
    asm volatile("" : "+r"(t7) : : "memory");
    u32 a1 = a0[1];
    asm volatile("" : "+r"(a1) : : "memory");
    t6 = ((u32*)t7)[1];
    asm volatile("" : "+r"(t6) : : "memory");
    f32 f = *(f32*)((u8*)a0 + 8);
    return func_001863a8(t6, a1, f);
}
