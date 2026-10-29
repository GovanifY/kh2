#include "../common/types.h"

// Agent R46p_35 (2026-10-29): FUN_001b2488 (52 bytes, SLPM_666.75).
// Code: s0 = a0; AREA::Free(a0->field_20) (lw in the jal delay slot); then tail-calls
// func_003201e8(&D_01d48c80, s0).
extern "C" void area_free_r46p35(u32) asm("_ZN4AREA4FreeEPv");
extern "C" void func_003201e8(u32, u32);
extern u8 D_01d48c80[];

void func_001b2488(u32 a0) {
    u32 self = a0;
    area_free_r46p35(*(u32 *)(self + 20));
    func_003201e8((u32)&D_01d48c80[0], self);
}
