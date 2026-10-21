#include "../common/types.h"

// Agent F14: three leaf functions. Each one is a short C shape that gives the
// original instruction order. This object is built with -falign-functions=1 (see
// the Makefile), because FUN_00134db0 (28 bytes) and FUN_00135ff0 (44 bytes) are
// not multiples of 8 and end without padding.

// 16-byte vector copy. u128 makes the copy an lq/sq pair (t0 holds the value).
// The pointer is advanced by 16 before the compare, which gives the original's
// addiu, beq (nop in its delay slot), lq, sq order.
typedef int u128 __attribute__((mode(TI)));

// FUN_00134db0 (28 bytes)
// Code: a0 += 16; if (a1 != a0) copy 16 bytes from a0 to a1.
// Guess: copies one 16-byte record from the entry after a0 into a1.
// Matching: the temporary is pinned to t0 ($8), which gcc otherwise picks as t7.
void func_00134db0(u32 a0, u32 a1) {
    register u128 v asm("$8");
    a0 += 16;
    if (a1 != a0) {
        v = *(u128*)a0;
        *(u128*)a1 = v;
    }
}

// Global 16-byte record at 0x00347ce0. Declared as an array so gcc emits a
// HI16/LO16 pair (lui/addiu) instead of an immediate constant.
extern u128 D_00347ce0[];

// FUN_00135670 (32 bytes)
// Code: if (a0 != &D_00347ce0) copy the 16 bytes at that global to a0.
// Guess: stores a default 16-byte record into a caller buffer.
// Matching: the address goes through a pinned pointer (t7 = $15) with an empty
// "+r" barrier, so the lq uses t7 as its base register, as the original does.
void func_00135670(u32 a0) {
    register u128 v asm("$8");
    register u32 p asm("$15");
    p = (u32)D_00347ce0;
    __asm__ volatile("" : "+r"(p));
    if (a0 != p) {
        v = *(u128*)p;
        *(u128*)a0 = v;
    }
}

// FUN_00135ff0 (44 bytes)
// Code: clears the word at +12. Then 32 times it clears the words at +16 and +20
// and advances the pointer by 8. The loop counter runs from 31 down to 0.
// Guess: zeroes the header of a 32-entry table of 8-byte slots.
// Matching: the loop keeps its counter in t7 ($15). The two nops inside the
// loop are kept by gcc as well, so the loop shape matches with no asm.
void func_00135ff0(u32 a0) {
    register s32 n asm("$15");
    *(u32*)(a0 + 12) = 0;
    n = 31;
    do {
        *(u32*)(a0 + 16) = 0;
        n--;
        *(u32*)(a0 + 20) = 0;
        a0 += 8;
    } while (n >= 0);
}
