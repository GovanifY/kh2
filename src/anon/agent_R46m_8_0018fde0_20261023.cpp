#include "../common/types.h"

// Agent R46m_8: FUN_0018fde0 (44 bytes).
// Code: calls FUN_001b50e0(arg0[0], arg0[1], float at arg0+8, arg0[3] != 0) (tail call).
u32 func_001b50e0(u32, u32, f32, u32);

u32 func_0018fde0(u32* a0) {
    register u32 t7 asm("$15");
    u32 a2raw = a0[3];
    asm volatile("" : "+r"(a2raw) : : "memory");
    t7 = a0[0];
    asm volatile("" : "+r"(t7) : : "memory");
    f32 f = *(f32*)((u8*)a0 + 8);
    asm volatile("" : "+f"(f) : : "memory");
    u32 flag = a2raw != 0;
    asm volatile("" : "+r"(flag) : : "memory");
    u32 a1 = a0[1];
    return func_001b50e0(t7, a1, f, flag);
}
