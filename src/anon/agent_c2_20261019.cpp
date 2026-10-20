#include "../common/types.h"

// Agent C2 (kh2 decomp, 2026-10-19).

extern u32 D_003a99f0[];

// FUN_00148a68 (84 bytes)
// Code: idx = byte at a1+287. Scans the zero-terminated u32 table at 0x003a99f0 from idx
//       onward to the first zero slot, stores a1 there, then increments the word at a0+21372.
// Guess: appends a1 to a slot table indexed by a byte of a1 (a small "first free slot" registry).
// Note: the empty "+r" asm keeps the table base in one register (lui/addiu once).
void func_00148a68(u8* a0, u8* a1) {
    u32* b = D_003a99f0;
    __asm__("" : "+r"(b));
    u32 i = a1[287];
    while (b[i] != 0) i++;
    b[i] = (u32)a1;
    *(u32*)(a0 + 21372) += 1;
}

// FUN_00154288 (60 bytes)
// Code: returns 0 when a1 == 1, 2 when a1 == 2, and 3 for every other a1.
// Guess: small code-to-value mapping (a1 is a selector or type index).
// Note: a plain switch with an explicit case 0 reproduces the redundant beqz and the
//       out-of-line tail (beqzl delay slot) with no asm.
u32 func_00154288(u32 a0, s32 a1) {
    switch (a1) {
    case 0: return 3;
    case 1: return 0;
    case 2: return 2;
    default: return 3;
    }
}
