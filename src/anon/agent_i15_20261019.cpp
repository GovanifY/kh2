#include "../common/types.h"

// Built at -O0 (see the per-object Makefile line for this file). The three
// functions below were compiled that way in the original: every argument is
// spilled to a frame addressed through s8, and the result goes through t7.

// FUN_002b81ec (40 bytes)
// Code: frame, spill a0, return 0. The 8-word frame has s8 saved; no ra.
// Guess: a stub that accepts an argument and returns 0 (a no-op hook).
u32 func_002b81ec(u32 a0) {
    (void)a0;
    return 0u;
}

// FUN_002b8214 (40 bytes)
// Same body as FUN_002b81ec, at the next address.
u32 func_002b8214(u32 a0) {
    (void)a0;
    return 0u;
}

// FUN_002b8984 (96 bytes)
// Code: stores a1 at a0 + 0x48000 + 0x1c and a2 at a0 + 0x48000 + 0x20, then returns 0.
// Guess: writes two words into a fixed-offset block of an object.
// Trick: `register char* p asm("$14")` keeps the base pointer in t6 and
// lets gcc fold the +0x1c/+0x20 into the store offset. Without the register
// variable gcc folds the constants into the lui/ori pair instead.
u32 func_002b8984(u32 a0, u32 a1, u32 a2) {
    register char* p asm("$14");
    p = (char*)a0 + 0x48000;
    *(u32*)(p + 0x1c) = a1;
    p = (char*)a0 + 0x48000;
    *(u32*)(p + 0x20) = a2;
    return 0u;
}
