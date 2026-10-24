#include "../common/types.h"

// Agent R46j_1 (2026-10-23): FUN_001713f0 (40 bytes), SLPM_666.75.
// Reads p[0] (an object pointer), p[1], and the word at +4 of that object, then tail-calls
// FUN_00186a90(that word, p[1], float at p+8). The original keeps a 16-byte frame for ra.
// The empty asm barriers fix the load order and keep the pointer loads in the original order.
extern "C" u32 func_00186a90(...);

void func_001713f0(u32* p) {
    u32 obj = p[0];
    asm volatile("" : "+r"(obj));
    u32 a1 = p[1];
    asm volatile("" : "+r"(a1));
    register u32 t6 asm("$14");
    t6 = ((u32*)obj)[1];
    asm volatile("" : "+r"(t6));
    f32 f12 = *(f32*)((u8*)p + 8);
    ((void(*)(u32, u32, f32))func_00186a90)(t6, a1, f12);
}
