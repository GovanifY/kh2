#include "../common/types.h"

// Agent R46l_2: FUN_00172440 (68 bytes), SLPM_666.75.
// Calls func_00180378(p[0]->[1] + 320, p[1]->[1], p[2], float p[3]) and stores the result at p[0].
// s0 is pinned to hold p so the later loads and the store use $16 as base, as in the original.
extern "C" u32 func_00180378(u32 a0, u32 a1, u32 a2, f32 f12);

void func_00172440(u32* p) {
    register u32* s0 asm("$16");
    s0 = p;
    asm volatile("" : "+r"(s0) : : "memory");
    u32* t6 = (u32*)p[1];
    asm volatile("" : "+r"(t6) : : "memory");
    u32* t7 = (u32*)p[0];
    asm volatile("" : "+r"(t7) : : "memory");
    u32 a2 = s0[2];
    asm volatile("" : "+r"(a2) : : "memory");
    u32 a0 = t7[1];
    asm volatile("" : "+r"(a0) : : "memory");
    f32 f = *(f32*)&s0[3];
    asm volatile("" : "+f"(f) : : "memory");
    u32 a1 = t6[1];
    u32 r = func_00180378(a0 + 320, a1, a2, f);
    s0[0] = r;
}
