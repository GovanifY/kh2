#include "../common/types.h"

extern u32 D_004f63a8[];
extern u32 D_0034dca0;
extern u32 D_0034dcb8;

// FUN_0016f930 (64 bytes)
// Code: linear search of the two-word table at 0x4f63a8 for a0. Returns 2410 + 10*i
//       for the first match at index i (0 or 1), else 2400.
// Guess: maps one of two known ids to a fixed code, with a default for unknown ids.
s32 func_0016f930(u32 a0) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (D_004f63a8[i] == a0) return 2410 + 10 * i;
    }
    return 2400;
}

// FUN_00170ee8 (76 bytes)
// Code: when a1 == 0xffff and a0 == 1, zeroes the two words at 0x34dca0 and 0x34dca4.
//       Then, under the same test, zeroes the two words at 0x34dcb8 and 0x34dcbc.
// Guess: reset of two 8-byte state blocks, triggered by a "clear" request from a0/a1.
// Notes: the lui (0x350000) is pinned to a register, and the addiu for the second
//        address is pinned with an empty asm, so the register use and the store order
//        match. The two if blocks are separated by a memory barrier (kept as two
//        sequential ifs). The first block's barrier sits after the stores.
void func_00170ee8(s32 a0, s32 a1) {
    if (a1 == 0xffff) {
        if (a0 == 1) {
            u8* h = (u8*)0x350000;
            __asm__("" : "+r"(h));
            u8* q = h - 9056;
            __asm__ volatile("" : "+r"(q) : : "memory");
            *(u32*)(h - 9056) = 0;
            *(u32*)(q + 4) = 0;
            __asm__ volatile("" ::: "memory");
        }
    }
    if (a1 == 0xffff) {
        if (a0 == 1) {
            u8* h = (u8*)0x350000;
            __asm__("" : "+r"(h));
            u8* q = h - 9032;
            __asm__ volatile("" : "+r"(q) : : "memory");
            *(u32*)(h - 9032) = 0;
            *(u32*)(q + 4) = 0;
        }
    }
}

// FUN_00179c80 (52 bytes)
// Code: returns 1 when the word at +2896 of a0 is 7 and the word at +340 is 203 or 204,
//       else 0. The loaded value is pinned to $4 (a0), as the original reuses it.
// Guess: a state predicate on a sub-object, keyed by a type 7 and one of two codes.
// Notes: goto-based shape gives the original beq/bne structure with a shared return.
s32 func_00179c80(u8* p) {
    register s32 r asm("$2");
    r = 0;
    if (*(s32*)(p + 2896) == 7) {
        register s32 v asm("$4");
        v = *(s32*)(p + 340);
        if (v == 203) goto yes;
        if (v == 204) goto yes;
        return r;
yes:
        r = 1;
    }
    return r;
}
