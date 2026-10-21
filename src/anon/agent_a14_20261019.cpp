#include "../common/types.h"

extern u8 D_00360000[];

// FUN_00230838 (60 bytes)
// Code: walks a 64-entry table of 8-byte records whose base pointer is the global at
//       0x35dce8. On the first record whose first word is zero, stores arg0 there and
//       returns. Returns without storing when the table is full.
// Guess: registers an object in the first free slot of a fixed-size table.
// Note: same loop shape as FUN_00230878 (batch_20261019_g.cpp). The table pointer is
//       read at the top of each pass so gcc puts it in the branch-likely delay slot.
//       The object is built with -falign-jumps=1 (see the Makefile line for this file).
void func_00230838(u8* a0) {
    register s32 i asm("$12") = 0;
    do {
        u8* tbl = *(u8**)((u32)&D_00360000[0] - 8984u);
        register u32 sh asm("$15") = (u32)i << 3;
        u8* e = (u8*)(sh + (u32)tbl);
        i++;
        if (*(u32*)e == 0) {
            *(u8**)e = a0;
            return;
        }
    } while (i < 64);
}

// FUN_002314c0 (60 bytes)
// Code: copies six floats from arg0 into the global block at 0x35db20. Destination
//       offsets are 0, 4, 8, 16, 20, 24. Offset 12 is skipped.
// Guess: copies a 6-float transform or vector block into a fixed global, with one
//        component left alone (for example a 3-element vector followed by a 3-element
//        vector, skipping the padding float).
// Note: the float temporaries are pinned to $f1 and $f0 in the same alternating order
//       as the original. The lui is one asm block so the first store uses -9440($14).
void func_002314c0(f32* a0) {
    register f32 x1 asm("$f1");
    register f32 x0 asm("$f0");
    register u8* p asm("$14");
    register f32* q asm("$15");
    x1 = a0[0];
    __asm__ volatile("lui %0,0x36" : "=r"(p));
    *(f32*)(p - 9440) = x1;
    q = (f32*)(p - 9440);
    __asm__ volatile("" : "+r"(q));
    x0 = a0[1];
    q[1] = x0;
    x1 = a0[2];
    q[2] = x1;
    x0 = a0[3];
    q[4] = x0;
    x1 = a0[4];
    q[5] = x1;
    x0 = a0[5];
    q[6] = x0;
}

// FUN_00232110 (60 bytes)
// Code: sets the byte at 0x35de14 to 1. Reads the signed halfword at +6 of arg0.
//       If it is 0, clears the byte at 0x35de15 and returns. If it is 1, stores 1 there.
//       Any other value returns with only the first byte set.
// Guess: a state flag set at entry, plus a second flag that mirrors a mode field of
//        an object (0, 1, or other).
// Note: the empty memory-clobber asm on the fall-through return path keeps gcc from
//       reordering the return into the branch shape, which gives the original beql.
void func_00232110(u8* a0) {
    *(u8*)((u32)&D_00360000[0] - 8684u) = 1;
    s32 v = *(s16*)(a0 + 6);
    if (v == 0) goto zero;
    if (v == 1) goto one;
    __asm__ volatile("" ::: "memory");
    return;
one:
    *(u8*)((u32)&D_00360000[0] - 8683u) = (u8)v;
    return;
zero:
    *(u8*)((u32)&D_00360000[0] - 8683u) = 0;
}
