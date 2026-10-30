#include "../common/types.h"

// FUN_002bbd58 (72 bytes)
// Code: reads the byte at +49 of arg0. If it is 5, tail-calls FUN_002bbbc8(arg0).
// If it is 6, tail-calls FUN_002bbc90(arg0). Otherwise calls FUN_002bb9b8(arg0) (not a tail call)
// and returns its result.
// Guess: a dispatcher on a type byte stored in an object at +49.
// Matching: a switch with default break, and an empty "+r" asm on the default result so gcc
// keeps the non-tail call with its nop delay slot.

u32 func_002bbbc8(u8*);
u32 func_002bbc90(u8*);
u32 func_002bb9b8(u8*);

u32 func_002bbd58(u8* a0) {
    switch (a0[49]) {
    case 5:
        return func_002bbbc8(a0);
    case 6:
        return func_002bbc90(a0);
    default:
        break;
    }
    u32 r = func_002bb9b8(a0);
    __asm__ volatile("" : "+r"(r));
    return r;
}
