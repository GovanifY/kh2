#include "../common/types.h"

// FUN_002376d8 (68 bytes)
// Code: if a1 (signed) < word at +60 of a0, stores a1 at +104, takes the table
// entry at (base = word at +12) + a1*4, and writes two results into a0: +20 gets
// (word at +8) + 20 * halfword[entry+0], and +24 gets halfword[entry+2].
// Guess: a selector that looks up a 20-byte-stride record for index a1 and caches it.
// Register pins and asm barriers fix the load and store order seen in the original.
void func_002376d8(u8* a0, s32 a1) {
    register u32 t4 asm("$12");
    register u32 t5 asm("$13");
    register u32 t6 asm("$14");
    register u32 t7 asm("$15");
    t7 = *(u32*)(a0 + 60);
    if (a1 < (s32)t7) {
        t6 = (u32)a1 << 2;
        t4 = *(u32*)(a0 + 12);
        __asm__ volatile("" : "+r"(t4) : : "memory");
        *(s32*)(a0 + 104) = a1;
        __asm__ volatile("addu %0,%0,%1" : "+r"(t4) : "r"(t6));
        t5 = *(u32*)(a0 + 8);
        __asm__ volatile("" : "+r"(t5) : : "memory");
        t7 = *(u16*)(t4 + 0);
        t6 = 20;
        t7 = t7 * t6;
        __asm__ volatile("addu %0,%0,%1" : "+r"(t5) : "r"(t7));
        *(u32*)(a0 + 20) = t5;
        __asm__ volatile("" : : : "memory");
        t7 = *(u16*)(t4 + 2);
        *(u32*)(a0 + 24) = t7;
    }
}

// FUN_00239e60 (88 bytes)
// Code: stores the three floats a1, a2, a3 at a0+0x134, +0x138, +0x13c. Then it
// compares each one with the float constant at D_003714bc (lui/addiu pair in asm).
// If all three equal that constant, the flag is 0; otherwise it is 1. The flag is
// shifted to bit 1 and merged into the word at +0xb8 (bit 1 cleared, then set from the flag).
// Guess: updates a "all three values are zero" status bit from a 3-float setter.
// Build: the lui/addiu pair and the store ordering come from inline asm and memory barriers.
void func_00239e60(u8* a0, f32 a1, f32 a2, f32 a3) {
    register u32 t5 asm("$13");
    register u32 t6 asm("$14");
    register u32 t7 asm("$15");
    register f32* zp asm("$15");
    __asm__ volatile("lui %0,%%hi(D_003714bc)" : "=r"(zp));
    *(f32*)(a0 + 0x134) = a1;
    __asm__ volatile("addiu %0,%0,%%lo(D_003714bc)" : "+r"(zp));
    *(f32*)(a0 + 0x138) = a2;
    f32 z = *zp;
    __asm__ volatile("" ::: "memory");
    t5 = 0;
    __asm__ volatile("" : "+r"(t5));
    *(f32*)(a0 + 0x13c) = a3;
    if (a1 != z) t5 = 1;
    else if (a2 != z) t5 = 1;
    else if (a3 != z) t5 = 1;
    t7 = *(u32*)(a0 + 0xb8);
    t6 = (u32)-3;
    t5 = t5 << 1;
    t7 = (t7 & t6) | t5;
    *(u32*)(a0 + 0xb8) = t7;
}

// FUN_00239eb8 (92 bytes)
// Code: stores a1 at a0+0x134, then checks a1, the float at +0x138 and the float at
// +0x13c against the constant at D_003714c0. The flag is 0 only when all three equal it.
// The flag goes to bit 1 of the word at +0xb8, the same as FUN_00239e60.
// Guess: the one-argument form of the same "all zero" status update.
// Build: the goto shape gives the original branch-likely pattern (bc1fl / bc1tl with
// delay-slot loads). The li of -3 is kept after the load of +0xb8 via a barrier.
void func_00239eb8(u8* a0, f32 a1) {
    register u32 t5 asm("$13");
    register u32 t6 asm("$14");
    register u32 t7 asm("$15");
    register f32* zp asm("$15");
    __asm__ volatile("lui %0,%%hi(D_003714c0)" : "=r"(zp));
    *(f32*)(a0 + 0x134) = a1;
    __asm__ volatile("addiu %0,%0,%%lo(D_003714c0)" : "+r"(zp));
    f32 z = *zp;
    __asm__ volatile("" ::: "memory");
    if (a1 != z) goto Lone;
    t5 = 0;
    if (*(f32*)(a0 + 0x138) != z) goto Lone;
    if (*(f32*)(a0 + 0x13c) == z) goto Lset;
Lone:
    t5 = 1;
Lset:
    t7 = *(u32*)(a0 + 0xb8);
    __asm__ volatile("" ::: "memory");
    t6 = (u32)-3;
    __asm__ volatile("" : "+r"(t6));
    t5 = t5 << 1;
    t7 = (t7 & t6) | t5;
    *(u32*)(a0 + 0xb8) = t7;
}
