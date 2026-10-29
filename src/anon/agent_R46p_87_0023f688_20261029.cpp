#include "../common/types.h"

// Agent R46p_87 (2026-10-29): FUN_0023f688 (52 bytes), SLPM_666.75.
// Saves a0 and a1 in s0 and s1, calls FUN_00139d78(a0), then stores a1 at +40 of a0.
// Same shape as FUN_0023f0c8 (+144), FUN_0023f6c0 (+72). Size is not a multiple of 8, so the object uses -falign-functions=1.
extern "C" void func_00139d78(u32) asm("_Z16u_call4_00139d78jjjj");

void func_0023f688(u32 a0, u32 a1) {
    func_00139d78(a0);
    *(u32*)(a0 + 40) = a1;
}
