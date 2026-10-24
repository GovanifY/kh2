#include "../common/types.h"

// Agent R46k_0 (2026-10-23): FUN_00171690 (44 bytes), SLPM_666.75.
// Tail-calls FUN_00185278(obj[1], p[2] != 0, float at p+4), where obj = p[0].
// Pinned registers and empty asm barriers keep the load order of the original.
extern "C" u32 func_00185278(u32 a0, u32 a1, f32 f12);

u32 func_00171690(u32* p) {
    register u32* obj asm("$15");
    obj = (u32*)p[0];
    asm volatile("" : "+r"(obj));
    u32 a1 = p[2];
    asm volatile("" : "+r"(a1));
    register u32 t6 asm("$14");
    t6 = obj[1];
    asm volatile("" : "+r"(t6));
    f32 f = *(f32*)&p[1];
    a1 = a1 != 0;
    return func_00185278(t6, a1, f);
}
