#include "../common/types.h"

extern "C" void func_002ba2e8(u32, u32) asm("_ZN5SOUND12systemSePlayEii");

// FUN_001bd618 (80 bytes)
// Code: stores zero through the pointer at arg0+2240, then compares the
// pointer value at arg0+2240 with arg0+2536. Equal: clears the field. Not
// equal: stores the field minus 4. If the low byte of arg1 is non-zero,
// tail-calls SOUND::systemSePlay(4, 0).
// Guess: pops one entry off a stack kept in the object.
void func_001bd618(u8* a0, u8 a1) {
    u32 b = a1;
    asm volatile("" : "+r"(b));
    register u32 end asm("$13") = (u32)a0 + 2536;
    asm volatile("" : "+r"(end) : : "memory");
    register u32* p asm("$14") = *(u32**)(a0 + 2240);
    *p = 0;
    asm volatile("" ::: "memory");
    register u32 t7 asm("$15") = *(u32*)(a0 + 2240);
    if (t7 == end) {
        *(u32*)(a0 + 2240) = 0;
    } else {
        u32 t6 = t7 - 4;
        *(u32*)(a0 + 2240) = t6;
    }
    if (b == 0) return;
    func_002ba2e8(4, 0);
}
