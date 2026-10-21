#include "../common/types.h"

// Agent S23 (2026-10-21): FUN_0013d1d0 from SLPM_666.75, decompiled byte-exact.
// The guess is unverified. It is there to help place the function later.

// FUN_0013d1d0 (56 bytes)
// Code: p = word at +668 of a0. If p is null, return. f = word at +32 of p. If bit 8 of f is
// clear, return. Otherwise tail-call FUN_00139598(a0 + 260).
// Guess: a "flush this sub-object if its status bit is set" step on an object that holds a
// pointer at +668.
// Tricks: plain C. The nop before the shared return block (the label at +48 is 8-aligned)
// comes from -falign-labels=8, set per object in the Makefile.
u32 func_00139598(u32);

void func_0013d1d0(u32 a0) {
    u32 p = *(u32*)(a0 + 668);
    if (p == 0) {
        return;
    }
    u32 f = *(u32*)(p + 32);
    if ((f & 8) == 0) {
        return;
    }
    func_00139598(a0 + 260);
}
