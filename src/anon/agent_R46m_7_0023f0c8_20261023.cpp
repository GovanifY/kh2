#include "../common/types.h"

// Agent R46m_7 (2026-10-23): FUN_0023f0c8 (52 bytes), SLPM_666.75.
// Saves a0 and a1 in s0 and s1, calls FUN_00139d78(a0), then stores a1 at +144 of a0.
// Same shape as FUN_0023f628 (+64), FUN_0023f688 (+40) and FUN_0023f6c0 (+72).
// Size is not a multiple of 8, so this object uses -falign-functions=1.
extern "C" void func_00139d78(u32) asm("_Z16u_call4_00139d78jjjj");

void func_0023f0c8(u32 a0, u32 a1) {
    func_00139d78(a0);
    *(u32*)(a0 + 144) = a1;
}
