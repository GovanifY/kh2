#include "../common/types.h"

extern u32 D_0035ec94;
extern u32 D_0035ecc0;
extern u32 D_0035ecc4;

// FUN_00242418 (92 bytes)
// Code: updates the CRC state word D_0035ecc4 over a0[0..a1-1]. For each byte b, with state c:
//       c = (c << 8) ^ table[(c >> 24) ^ b], using the table at D_0035ecc0 (a 256-entry u32
//       table). The state is reloaded and stored each pass. When a1 <= 0 the state is unchanged.
//       Returns the bitwise NOT of the final state.
// Guess: a table-driven CRC-32 (MSB-first table) with a running state. tiny.cpp sets the
//       state to -1 before use.
// Note: the state is reloaded from memory at the top of each pass and stored in the loop tail,
//       as in the original. The empty asm barrier is not needed because the table is read once,
//       before the loop.
u32 func_00242418(u8 *a0, s32 a1) {
    s32 n = a1 - 1;
    if (n >= 0) {
        u32 *T = (u32*)D_0035ecc0;
        do {
            u32 c = D_0035ecc4;
            u32 b = *a0;
            n--;
            c = (c << 8) ^ T[(c >> 24) ^ b];
            a0++;
            D_0035ecc4 = c;
        } while (n >= 0);
    }
    return ~D_0035ecc4;
}
