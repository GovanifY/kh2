#include "../common/types.h"

// Agent R46p_25 (2026-10-29): FUN_001a2710 (68 bytes), SLPM_666.75.
// If bit 0 of the word at a0+592 is set, calls func_0013dad0(a0), then clears that bit.
extern "C" void func_0013dad0(u32* a0);

void func_001a2710(u32* a0) {
    s32 t = a0[148] & 1;
    if (t != 0) {
        func_0013dad0(a0);
        a0[148] &= 0xfffffffeu;
    }
}
