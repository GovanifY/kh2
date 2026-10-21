#include "../common/types.h"

// Agent S35 (2026-10-21): two functions from SLPM_666.75 (FUN_0014f578, FUN_00152ab8).
// Each comment says what the code does, then gives a guess at its role.
// FUN_001535b0 is not matched and is not included here (see the report).

// Callees.
extern "C" u32 func_00150bc0(u32);
extern "C" u32 func_00150940(u32, u32);
extern "C" u32 func_001507b8(u32);
extern "C" u32 func_00152508(u32, u32, u32, u32, u32, u32, u32, u32);

extern u8 D_00350000;

// FUN_0014f578 (88 bytes).
// Code: calls func_00150bc0(word at D_00350000 - 23508). If it returns non-zero, tail-calls
// func_00150940(the same word, a0). Otherwise tail-calls func_001507b8(the same word).
// Guess: a dispatch on a state word, with the argument passed on in one branch only.
// Matching: the base 0x350000 is pinned to $16 (s0) and kept opaque with an empty "+r" asm, so gcc
// emits one lui and folds -23508 into each lw. The argument is copied to $17 (s1) by a volatile asm move.
u32 func_0014f578(u32 a0) {
    register u32 base asm("$16") = 0x00350000u;
    register u32 arg asm("$17");
    asm volatile("" : "+r"(base));
    asm volatile("move %0,%1" : "=r"(arg) : "r"(a0));
    if (func_00150bc0(*(u32*)(base - 23508u)))
        return func_00150940(*(u32*)(base - 23508u), arg);
    return func_001507b8(*(u32*)(base - 23508u));
}

// FUN_00152ab8 (48 bytes).
// Code: stores a4 at a0+440, a6 at a0+448, a5 at a0+444 and a2 at a0+436. Then tail-calls
// func_00152508(a0, 108, a2, a3, a7, a5, a6, a7).
// Guess: a setup that records four fields, then starts a helper with a fixed size of 108.
// Matching: the stores and register moves are volatile asm in the original order, so gcc keeps
// the frame setup first. The first store is plain C. The t0 and a1 call arguments are pinned
// to $8 and $5 by asm, and the copy of a0 is pinned to $15 (t7) for the last store.
u32 func_00152ab8(u8* a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    register u8* p asm("$15");
    register u32 r5 asm("$8");
    register u32 r2 asm("$5");
    *(u32*)(a0 + 440) = a4;
    asm volatile("move %0,%1" : "=r"(p) : "r"(a0));
    asm volatile("sw %0,448(%1)" :: "r"(a6), "r"(a0) : "memory");
    asm volatile("move %0,%1" : "=r"(r5) : "r"(a7));
    asm volatile("sw %0,444(%1)" :: "r"(a5), "r"(a0) : "memory");
    asm volatile("li %0,108" : "=r"(r2));
    asm volatile("sw %0,436(%1)" :: "r"(a2), "r"(p) : "memory");
    return func_00152508((u32)a0, r2, a2, a3, r5, a5, a6, a7);
}
