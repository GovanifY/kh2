#include "../common/types.h"

// Agent R46p_134 (2026-10-29): func_002c6420 (108 bytes), SLPM_666.75.
// Clears the word at +84, calls func_00106a60(1) and keeps its result s1. Calls func_00107368(s1, a0+16),
// func_00107478(s1, a0+32), then func_00106a18(1) and getFOV(result, 0) (float). Stores the float at +80
// and zero at +88. The empty asm barrier keeps the +88 store before the +80 store, as in the original.
// Needs -falign-functions=1 (size 108).

extern "C" u32 func_00106a60(u32);
extern "C" void func_00107368(u32, u32);
extern "C" void func_00107478(u32, u32);
extern "C" u32 func_00106a18(u32);
extern "C" float func_00106f30(u32, u32) asm("_ZNK2kn10Projection6getFOVENS0_4WorHE");

void func_002c6420(u32 a0) {
    *(u32*)(a0 + 84) = 0;
    u32 s1 = func_00106a60(1);
    func_00107368(s1, a0 + 16);
    func_00107478(s1, a0 + 32);
    u32 p = func_00106a18(1);
    float f = func_00106f30(p, 0);
    *(u32*)(a0 + 88) = 0;
    __asm__ volatile("" : : : "memory");
    *(float*)(a0 + 80) = f;
}
