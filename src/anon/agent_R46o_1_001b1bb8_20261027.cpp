#include "../common/types.h"

// FUN_001b1bb8 (40 bytes): stores a1 at +20 of arg0, then bytes a4, a2, a3 at +23, +21, +22 of the same block; tail-calls 0x1b1be0.
extern "C" void func_001b1be0(void);

void r_FUN_001b1bb8(u8* a0, u32 a1, u32 a2, u32 a3, u32 a4) asm("func_001b1bb8");

void r_FUN_001b1bb8(u8* a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    register u8* t asm("$15");
    a0[20] = (u8)a1;
    t = a0 + 20;
    asm volatile("" : "+r"(t));
    t[3] = (u8)a4;
    asm volatile("" ::: "memory");
    t[1] = (u8)a2;
    asm volatile("" ::: "memory");
    t[2] = (u8)a3;
    func_001b1be0();
}
