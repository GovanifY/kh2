#include "../common/types.h"

extern u8 D_003616f0[];
void func_002b6adc(u32 a0, u32 a1);
void func_002b6ab8();

// Agent R46p_128 (2026-10-29): FUN_002bd1c0 (88 bytes), SLPM_666.75.
// Calls func_002b6adc(2, word) and func_002b6adc(0, word) for 14 consecutive words starting at
// 0x00361724, then tail-calls func_002b6ab8 (no arguments). The base 0x003616f8 is pinned so the
// lui/addiu pair and the +44 match the original.
void func_002bd1c0() {
    u8* t = D_003616f0 + 8;
    asm volatile("" : "+r"(t));
    u32* s0 = (u32*)(t + 44);
    int s1 = 13;
    do {
        func_002b6adc(2, *s0);
        s1--;
        func_002b6adc(0, *s0);
        s0++;
    } while (s1 >= 0);
    func_002b6ab8();
}
