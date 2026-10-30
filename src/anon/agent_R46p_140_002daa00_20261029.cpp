#include "../common/types.h"

// Agent R46p_140 (2026-10-29): FUN_002daa00 (80 bytes, SLPM_666.75).

u32 func_0016c028(u32);
void func_002bc188(u32, u32);

// FUN_002daa00: if the word at +3060 of arg0 is non-zero, calls func_0016c028 with it, then
// tail-calls func_002bc188(arg1 + 0x56ab8, result).
void func_002daa00(u8* a0, u8* a1) {
    u32 p = *(u32*)(a0 + 3060);
    if (p != 0) {
        register u32 k asm("$15") = 0x56ab8u;
        u32 s0 = (u32)a1 + k;
        u32 r = func_0016c028(p);
        func_002bc188(s0, r);
    }
}
