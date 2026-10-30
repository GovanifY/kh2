#include "../common/types.h"

// Agent R46p_137 (2026-10-29): FUN_002cff50 (68 bytes), SLPM_666.75.
// Calls FUN_002cf2d0 on this+2800, then zeroes the words at this+2828 and this+2804..2824.
// The callee has no func_ row, so it is called by numeric jal.
extern "C" void call_002cf2d0(void*) asm("0x2cf2d0");

void func_002cff50(u8* a0) {
    call_002cf2d0(a0 + 2800);
    *(u32*)(a0 + 2828) = 0; __asm__ volatile("" ::: "memory");
    *(u32*)(a0 + 2804) = 0; __asm__ volatile("" ::: "memory");
    *(u32*)(a0 + 2808) = 0; __asm__ volatile("" ::: "memory");
    *(u32*)(a0 + 2812) = 0; __asm__ volatile("" ::: "memory");
    *(u32*)(a0 + 2816) = 0; __asm__ volatile("" ::: "memory");
    *(u32*)(a0 + 2820) = 0; __asm__ volatile("" ::: "memory");
    *(u32*)(a0 + 2824) = 0;
}
