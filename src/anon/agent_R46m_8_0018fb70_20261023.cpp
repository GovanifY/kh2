#include "../common/types.h"

// Agent R46m_8: FUN_0018fb70 (36 bytes).
// Code: loads word 0 of arg0 and passes it, with words 1 and 2 of arg0, to FUN_001a49a0 (tail call).
u32 func_001a49a0(u32, u32, u32);

u32 func_0018fb70(u32* a0) {
    register u32 t7 asm("$15");
    t7 = a0[0];
    asm volatile("" : "+r"(t7) : : "memory");
    u32 a2 = a0[2];
    asm volatile("" : "+r"(a2) : : "memory");
    u32 a1 = a0[1];
    return func_001a49a0(t7, a1, a2);
}
