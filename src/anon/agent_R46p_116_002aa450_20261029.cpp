#include "../common/types.h"

// Agent R46p_116 (2026-10-29): FUN_002aa450 (84 bytes). base = JmNewInfo::GetSram(). Sets bit (a0 & 31) in the
// u32 word at base+316 indexed by a0 >> 5, but only when that bit was clear (the store is in a branch-likely delay slot).
extern "C" u32 r_GetSram(void) asm("_ZN2Tz9JmNewInfo7GetSramEv");

void func_002aa450(u32 a0) {
    u32 base = r_GetSram();
    u32 *tab = (u32 *)(base + 316);
    u32 idx = a0 >> 5;
    u32 w = tab[idx];
    u32 m = 1u << (a0 & 31);
    if ((w & m) == 0) {
        tab[idx] = w | m;
    }
}
