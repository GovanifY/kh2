#include "../common/types.h"

// Agent R46p_6 (2026-10-29): FUN_00188bb0 (72 bytes), SLPM_666.75.
// Reads the byte at a0+15. If it is below 99, calls func_001b6fb0(a1, byte), then returns the
// word at the returned pointer minus the word at 0x0032f210. Otherwise returns 0.
// Matching: plain C gives the same prologue and branch shape. The base 0x330000 is pinned in
// $15 with lui so that the word at 0x32f210 is loaded as lw -3568($15), as in the original.
// The size is a multiple of 8, so no Makefile flag is needed.
extern "C" u32 func_001b6fb0(u32 a0, u32 a1);

u32 func_00188bb0(u8* a0, u32 a1) {
    u32 b = a0[15];
    if (b < 99) {
        u32* p = (u32*)func_001b6fb0(a1, b);
        register u32 g asm("$15");
        asm volatile("lui $15,0x33" : "=r"(g));
        return p[0] - *(u32*)(g - 3568);
    }
    return 0;
}
