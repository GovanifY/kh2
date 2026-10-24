#include "../common/types.h"

extern "C" void func_002ba2e8(u32, u32) asm("_ZN5SOUND12systemSePlayEii");

// FUN_001bd5b0 (100 bytes)
// Code: if the pointer at arg0+2240 is zero, stores arg0+2536 there. Otherwise
// stores the pointer plus 4. Reloads that pointer, and stores arg0 + arg1*116 + 36
// through it. If the low byte of arg2 is non-zero, tail-calls
// SOUND::systemSePlay(3, 0).
// Guess: allocates a 116-byte record from a slot in the object and links it.
void func_001bd5b0(u8* a0, u32 a1, u8 a2) {
    register u32 end asm("$13") = (u32)a0 + 2536;
    asm volatile("" : "+r"(end) : : "memory");
    u32 b = a2;
    asm volatile("" : "+r"(b));
    u32 t7 = *(u32*)(a0 + 2240);
    if (t7 == 0) {
        *(u32*)(a0 + 2240) = end;
    } else {
        *(u32*)(a0 + 2240) = t7 + 4;
    }
    u32 p = *(u32*)(a0 + 2240);
    *(u32*)p = (u32)a0 + a1 * 116 + 36;
    if (b == 0) return;
    func_002ba2e8(3, 0);
}
