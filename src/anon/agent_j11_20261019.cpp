#include "../common/types.h"

// Data symbol used below. D_00361f60 is already in functions.tsv (u32 global, also declared in tiny.cpp).
extern u32 D_00361f60;

// FUN_002cf1f8 (76 bytes)
// Code: if the global word at D_00361f60 is zero, returns 1. Otherwise checks bit 27 (0x08000000) of the
//       word at +1416 of both arguments; if either is clear, returns 1. Otherwise returns 1 when the
//       words at +2804 of the two arguments are equal, else 0.
// Guess: a "same state" comparison between two objects, skipped when a global flag is clear.
// Matching: the early exits use `goto early`, which gives the original's shared `li v0,1` block at the
//       end. The lui 0x800 is hoisted by gcc into the delay slot of the first branch, as in the original.
u32 func_002cf1f8(u8* a0, u8* a1) {
    u32 r;
    if (D_00361f60 == 0) goto early;
    if ((*(u32*)(a0 + 1416) & 0x08000000) == 0) goto early;
    if ((*(u32*)(a1 + 1416) & 0x08000000) == 0) goto early;
    r = (*(u32*)(a0 + 2804) ^ *(u32*)(a1 + 2804)) == 0;
    return r;
early:
    return 1;
}

// FUN_002d5588 (44 bytes)
// Code: loads the pointer at +12 of a0, then the word at +4 of that object (x). Returns 1 when x is
//       0x37 or 0x38, else 0.
// Guess: a two-value test on a type or state field of a sub-object.
// Matching: both xori results are computed before the first branch, pinned to t6 (a) and t7 (b). The
//       `move v0,zero` sits in the beqz delay slot, and the li v0,1 block is the beqz target, as in
//       the original.
u32 func_002d5588(u8* a0) {
    s32 x = *(s32*)(*(u8**)(a0 + 12) + 4);
    register s32 a asm("$14");
    register s32 b asm("$15");
    a = x ^ 0x37;
    __asm__ volatile("" : "+r"(a));
    b = x ^ 0x38;
    u32 r = 0;
    if (b == 0) goto one;
    if (a != 0) goto done;
one:
    r = 1;
done:
    return r;
}

// FUN_002d5c20 (28 bytes)
// Code: sets the four floats at +0, +4, +8 and +12 of a0 to 0.0f, storing in the order +12, +0, +4, +8,
//       and returns a0.
// Guess: zeroes a 4-float vector (x, y, z, w) in place.
// Matching: the zero comes from `mtc1 $0` into $f0, so it is an explicit float register pinned to $f0.
//       The return value is pinned to v0 with an asm move that runs right after the mtc1, which places
//       the move in the original order. Empty memory barriers keep the store order. The last store
//       falls into the jr delay slot.
u8* func_002d5c20(u8* a0) {
    register f32 z asm("$f0");
    register u8* v asm("$2");
    __asm__ volatile("mtc1 $0,%0" : "=f"(z));
    __asm__ volatile("move %0,%1" : "=r"(v) : "r"(a0));
    *(f32*)(a0 + 12) = z;
    __asm__ volatile("" ::: "memory");
    *(f32*)(a0 + 0) = z;
    __asm__ volatile("" ::: "memory");
    *(f32*)(a0 + 4) = z;
    __asm__ volatile("" ::: "memory");
    *(f32*)(a0 + 8) = z;
    return v;
}
