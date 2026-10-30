#include "../common/types.h"

// Agent R46p_133 (2026-10-29): func_002c22b8 (52 bytes), SLPM_666.75.
// Calls func_002fd248(a0, p + 8, word at p + 4, 16, 0x00324bb0), where p = word at 0x01e2bd00,
// and returns its result. The constant 0x00324bb0 is an address in the 0x320000 segment.

extern "C" u32 func_002fd248(u32, u32, u32, u32, u32);

u32 func_002c22b8(u32 a0) {
    u8* g = (u8*)0x01e30000;
    __asm__ volatile("" : "+r"(g));
    u8* h = (u8*)0x00320000;
    __asm__ volatile("" : "+r"(h));
    u32 p = *(u32*)(g - 17152);
    u32 r = func_002fd248(a0, p + 8, *(u32*)(p + 4), 16, (u32)(h + 0x4bb0));
    __asm__ volatile("" : "+r"(r) : : "memory");
    return r;
}
