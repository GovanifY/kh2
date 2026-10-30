#include "../common/types.h"

// Agent R46p_137 (2026-10-29): FUN_002d0cf0 (84 bytes), SLPM_666.75.
// If this+2828 is set, calls FUN_001dc818 on it and clears the word. Then sets bits 0x80 in
// the word at this+268 and 0x403 in the word at this+264, and clears this+2832.
// The callee has no func_ row, so it is called by numeric jal.
extern "C" void call_001dc818(void*) asm("0x1dc818");

void func_002d0cf0(u8* a0) {
    void* p = *(void**)(a0 + 2828);
    if (p) {
        call_001dc818(p);
        *(u32*)(a0 + 2828) = 0;
    }
    register u32 w268 asm("$15");
    register u32 w264 asm("$14");
    w268 = *(u32*)(a0 + 268);
    w264 = *(u32*)(a0 + 264);
    w268 |= 0x80;
    __asm__ volatile("" ::: "memory");
    *(u32*)(a0 + 2832) = 0; __asm__ volatile("" ::: "memory");
    w264 |= 0x403;
    *(u32*)(a0 + 268) = w268;
    *(u32*)(a0 + 264) = w264;
}
