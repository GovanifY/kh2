#include "../common/types.h"

// Agent L10: three leaf functions from the 0x002e.... range. Each one is written with
// register pins and empty memory or value barriers so gcc keeps the original store and
// branch order. Object flags: -falign-functions=1 (see Makefile), because two bodies are
// not a multiple of 8 bytes and gcc would otherwise pad them.

// Table base for the lui/addiu pairs below. Only the symbol is needed here.
extern u8 D_00360000[];

#define L10_MB() __asm__ volatile("" ::: "memory")

// FUN_002eb068 (44 bytes)
// Code: reads the word at +12 of arg0 (a pointer), then the word at +4 of that object.
// Returns 1 when the word is 0x33 or 0x3d, otherwise 0. The compiler emits the two xori
// values and the beqz/bnez pair; the move v0,zero sits in the beqz delay slot.
// Guess: a two-value type check on a state word in a sub-object.
u32 func_002eb068(u32* a0) {
    register u32 p asm("$14");
    register u32 t asm("$15");
    register u32 c0 asm("$14");
    register u32 c1 asm("$15");
    u32 v;
    p = a0[3];
    t = ((u32*)p)[1];
    c0 = t ^ 0x33;
    // Barrier: keeps xori t6 ahead of xori t7, as in the original.
    __asm__ volatile("" : "+r"(c0));
    c1 = t ^ 0x3d;
    v = 0;
    if (c1 == 0) goto one;
    if (c0 != 0) goto done;
one:
    v = 1;
done:
    return v;
}

// FUN_002edf28 (64 bytes)
// Code: initialises an object at arg0 with a vtable pointer (lui/addiu of D_00360000
// + 14304), zeroes words 1..5 and 7, and writes 0x80 to byte 24 and bytes 25..27.
// Guess: a constructor for a small object with a vtable and a four-byte array that
// defaults to 128.
// Build: lui and addiu are separate asm pieces with the store to word 1 in between.
void func_002edf28(u32* a0) {
    register u32 vt asm("$15");
    register u8* t7 asm("$15");
    register u32 b asm("$14");
    __asm__ volatile("lui %0,%%hi(D_00360000+14304)" : "=r"(vt));
    L10_MB();
    a0[1] = 0;
    L10_MB();
    __asm__ volatile("addiu %0,%0,%%lo(D_00360000+14304)" : "+r"(vt));
    a0[3] = 0;
    L10_MB();
    a0[0] = vt;
    L10_MB();
    b = 128;
    __asm__ volatile("" : "+r"(b));
    a0[2] = 0;
    L10_MB();
    a0[4] = 0;
    L10_MB();
    t7 = (u8*)a0 + 24;
    __asm__ volatile("" : "+r"(t7));
    a0[5] = 0;
    L10_MB();
    ((volatile u8*)a0)[24] = (u8)b;
    ((volatile u8*)t7)[3] = (u8)b;
    ((volatile u8*)t7)[1] = (u8)b;
    ((volatile u8*)t7)[2] = (u8)b;
    a0[7] = 0;
}

// FUN_002ee730 (68 bytes)
// Code: initialises an object at arg0 with a second vtable (D_00360000 + 14408) and
// sets word 6 to 0x222e0, word 5 to 2, byte 8 to 77, word 10 to 4096 and words 1, 7,
// 8, 9 to zero.
// Guess: a constructor for another small object with a vtable and a few fixed
// parameters.
// Build: the lui/addiu of the vtable are split as in FUN_002edf28. The constants are
// pinned to registers so gcc emits them in the original order, and the last store sits
// in the jr delay slot.
void func_002ee730(u32* a0) {
    register u32 vt asm("$15");
    register u32 b asm("$14");
    register u32 c asm("$13");
    register u32 two asm("$15");
    register u32 four asm("$15");
    __asm__ volatile("lui %0,%%hi(D_00360000+14408)" : "=r"(vt));
    L10_MB();
    a0[1] = 0;
    L10_MB();
    __asm__ volatile("addiu %0,%0,%%lo(D_00360000+14408)" : "+r"(vt));
    a0[7] = 0;
    L10_MB();
    a0[0] = vt;
    L10_MB();
    c = 0x000222e0u;
    __asm__ volatile("" : "+r"(c));
    a0[8] = 0;
    L10_MB();
    two = 2;
    __asm__ volatile("" : "+r"(two));
    a0[6] = c;
    L10_MB();
    a0[5] = two;
    L10_MB();
    b = 77;
    __asm__ volatile("" : "+r"(b));
    ((volatile u8*)a0)[8] = (u8)b;
    L10_MB();
    four = 4096;
    __asm__ volatile("" : "+r"(four));
    a0[9] = 0;
    L10_MB();
    a0[10] = four;
}
