#include "../common/types.h"

// FUN_002e8070 (36 bytes): loads three words from arg0 (+0, +4, +8) and tail-calls 0x2e9cb8 with them.
extern "C" void func_002e9cb8(u32 a, u32 b, u32 c);

void r_FUN_002e8070(u32* a0) asm("func_002e8070");

void r_FUN_002e8070(u32* a0) {
    register u32 t asm("$15");
    u32 b = a0[1];
    t = a0[0];
    asm volatile("" : "+r"(t));
    u32 c = a0[2];
    func_002e9cb8(t, b, c);
}
