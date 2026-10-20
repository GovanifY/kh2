#include "../common/types.h"

// Batch 2026-10-19 E1: three leaf functions decompiled from SLPM_666.75.
// Each comment gives what the code does and a guess at its role.

typedef int u128 __attribute__((mode(TI)));

// FUN_001072d0 (48 bytes)
// Code: t = a0 + 80. If t != a1, copies 16 bytes (lq/sq) from a1 to t. Then a0 += 96.
//       If a0 != a2, copies 16 bytes from a2 to a0.
// Guess: writes two vector slots of an object, skipping self-copies. Same
//        family as FUN_00107300 and FUN_00107368.
// Note: the branch-likely shape comes from pinning t to $15 and an empty
//       memory-clobbering asm on the store address.
void func_001072d0(u8* a0, u8* a1, u8* a2) {
    register u8* d asm("$15") = a0 + 80;
    if (d != a1) {
        register u128 t asm("$8") = *(u128*)a1;
        __asm__ volatile("" : "+r"(d) :: "memory");
        *(u128*)d = t;
    }
    a0 += 96;
    if (a0 != a2) {
        register u128 t asm("$8") = *(u128*)a2;
        *(u128*)a0 = t;
    }
}

// FUN_00135c88 (60 bytes)
// Code: n = word at +12 of a0. Searches the n words starting at +16 for a1.
//       Returns the index of the first match, or -1 if there is none (or n <= 0).
// Guess: a find-index over a small ID table. The companion of FUN_00135cc8,
//        which uses the same layout.
// Note: the loop index is pinned to $13 and the loaded word to $15. The
//       next word is loaded in the delay slot of a branch-likely.
s32 func_00135c88(u8* a0, u32 a1) {
    register s32 n asm("$12") = *(s32*)(a0 + 12);
    register s32 i asm("$13") = 0;
    register u32 w asm("$15");
    register s32 r asm("$2");
    if (n > 0) {
        u8* p = a0 + 16;
        __asm__("" : "+r"(p));
        w = *(u32*)p;
        do {
            r = i;
            i++;
            p += 4;
            __asm__("" : "+r"(p));
            if (w == a1) return r;
            if (i >= n) break;
            w = *(u32*)p;
        } while (1);
    }
    r = -1;
    return r;
}

// FUN_0011bd70 (76 bytes)
// Code: reads nine floats at offsets 0..32 of a0 as a row-major 3x3 matrix
//       and returns its determinant in $f0. Uses the EE accumulator (mula.s,
//       msub.s, madd.s, msuba.s) for the products.
// Guess: a 3x3 determinant helper, such as a triple product of vectors.
// Note: the float registers are pinned to match the original allocation.
f32 func_0011bd70(f32* m) {
    register f32 a8 asm("$f1") = m[8];
    register f32 a4 asm("$f10") = m[4];
    register f32 a5 asm("$f5") = m[5];
    register f32 a7 asm("$f6") = m[7];
    register f32 a3 asm("$f4") = m[3];
    register f32 a6 asm("$f3") = m[6];
    register f32 a0 asm("$f7") = m[0];
    register f32 a1 asm("$f8") = m[1];
    register f32 a2 asm("$f0") = m[2];
    register f32 c0 asm("$f9");
    register f32 c1 asm("$f2");
    register f32 c2 asm("$f1");
    c0 = a4 * a8 - a5 * a7;
    c1 = a3 * a8 - a5 * a6;
    c2 = a3 * a7 - a4 * a6;
    return a0 * c0 - a1 * c1 + a2 * c2;
}
