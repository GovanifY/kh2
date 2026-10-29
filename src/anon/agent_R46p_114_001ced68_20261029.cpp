#include "../common/types.h"

// Agent R46p_114 (2026-10-29): FUN_001ced68 (88 bytes). Same body as FUN_001ced10 (bytes verified identical).
// Calls func_00177dc8(a0, a1, 0, a2, a3) (5th argument in t0), then clears two words in the object, stores a
// table address at offset 0, calls func_001d56f0(a0 + 2932), and sets bit 2 of the word at +1420.
extern "C" u32 func_00177dc8(u32, u32, u32, u32, u32);
extern "C" void func_001d56f0(u32);
extern u8 D_00350000[];

void func_001ced68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u8* s = (u8*)a0;
    func_00177dc8(a0, a1, 0, a2, a3);
    *(u32*)(s + 2920) = 0;
    u32 v = (u32)&D_00350000[8672];
    asm volatile("" : "+r"(v));
    *(u32*)(s + 2928) = 0;
    asm volatile("" ::: "memory");
    *(u32*)s = v;
    asm volatile("" ::: "memory");
    func_001d56f0(a0 + 2932);
    u32 w = *(u32*)(s + 1420);
    *(u32*)(s + 1420) = w | 4;
}
