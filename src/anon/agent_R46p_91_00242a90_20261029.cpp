#include "../common/types.h"

// FUN_00242a90 (88 bytes): same shape as FUN_00242df0. s0 = a0; p = getSaveRam() + 16800;
// t = (a0 == 0) ? 0 : (a0 == 2 ? 2 : 1); word at p+4 becomes (word & ~6) | (t << 1).
// getSaveRam has a mangled registry row (_Z10getSaveRamv), so it is called through an asm label.
extern "C" u8 *call_getSaveRam(void) asm("_Z10getSaveRamv");

void func_00242a90(u32 a0) {
    u32 s0 = a0;
    u32 *p = (u32 *)(call_getSaveRam() + 16800);
    u32 t = 0;
    if (s0 != 0) {
        t = 2;
        u32 t6 = s0 ^ 2;
        if (t6 != 0) {
            t = 1;
        }
    }
    u32 w = p[1];
    w &= 0xFFFFFFF9u;
    w |= t << 1;
    p[1] = w;
}
