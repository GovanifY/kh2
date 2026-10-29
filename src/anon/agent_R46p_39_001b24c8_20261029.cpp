#include "../common/types.h"

// Agent R46p_39 (2026-10-29): FUN_001b24c8 (84 bytes, SLPM_666.75).
// Walks a linked list from the word at D_01d50000-29568 through +24 (next pointer).
// For each non-null node, calls func_001b2488(node) then AREA::Free(node).
extern u8 D_01d50000[];
extern "C" void func_001b2488(u32 a0);
extern "C" void _ZN4AREA4FreeEPv(u32 a0);

void func_001b24c8(void) {
    u32 s0 = *(u32*)&D_01d50000[-29568];
    u32 s1;
    if (s0 == 0) {
        return;
    }
    do {
        asm volatile("" : "+r"(s0));
        if (s0 != 0) {
            s1 = *(u32*)(s0 + 24);
            asm volatile("" ::: "memory");
            func_001b2488(s0);
            _ZN4AREA4FreeEPv(s0);
        } else {
            s1 = *(u32*)(s0 + 24);
        }
        s0 = s1;
    } while (s1 != 0);
}
