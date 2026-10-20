// Decompiled leaf functions from the 2026-10-19 batch K2: FUN_0018e108, FUN_0018f0b0, FUN_00192450.
//
// Shared technique: a u128 typedef (mode TI) gives plain 128-bit assignments as lq/sq.
// Empty asm barriers ("+r") stop GCC from folding a symbol address into the load/store
// offset, which keeps the original lui/addiu/lq/sq sequence and register choice.

typedef int u128 __attribute__((mode(TI)));
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern u8 D_00350000[];
extern f32 D_0036ccd8[];
extern u8 D_01c60000[];

// FUN_0018e108 (56 bytes)
// Code: if a0 is not the 16-byte slot at D_00350000-4368, copy the 16 bytes at a0 there.
//       Then the same for a1 with the slot at D_00350000-4352 (self-copies are skipped).
// Guess: copies two 16-byte vectors into a pair of fixed global slots.
// Matching: each slot address is recomputed with lui/addiu, and each value uses register $8 (t0).
void func_0018e108(u8* a0, u8* a1) {
    register u8* d asm("$15");
    d = &D_00350000[-4368];
    __asm__ volatile("" : "+r"(d));
    if (a0 != d) {
        register u128 t asm("$8") = *(u128*)a0;
        *(u128*)d = t;
    }
    d = &D_00350000[-4352];
    __asm__ volatile("" : "+r"(d));
    if (a1 != d) {
        register u128 t asm("$8") = *(u128*)a1;
        *(u128*)d = t;
    }
}

// FUN_0018f0b0 (80 bytes)
// Code: if a1 == 0xffff and a0 == 1, load the float at D_0036ccd8 and store it at D_01c60000+3280.
//       Then, if the same two conditions hold, zero the two words at D_01c60000+3288 and +3292.
// Guess: a one-shot reset of a float and two words when a particular mode is selected.
void func_0018f0b0(int a0, int a1) {
    if (a1 == 0xffff && a0 == 1) {
        f32* s = &D_0036ccd8[0];
        __asm__ volatile("" : "+r"(s));
        f32 v = *s;
        // Base pinned to $15 with no barrier: GCC emits lui + swc1 3280(t7), no addiu.
        register u8* d asm("$15") = &D_01c60000[0];
        *(f32*)(d + 3280) = v;
    }
    if (a1 == 0xffff && a0 == 1) {
        u32* q = (u32*)&D_01c60000[3288];
        __asm__ volatile("" : "+r"(q));
        ((u32*)&D_01c60000[0])[822] = 0;
        q[1] = 0;
    }
}

// FUN_00192450 (72 bytes)
// Code: c = a0[a1]. If c >= 32, return c-32. Otherwise let t = (u8)(c-25). If t >= 7,
//       return -1. Otherwise return ((c-25) << 8) + a0[a1+1] + 224.
// Guess: a two-byte character-class decoder (the two-byte form uses a second byte).
// Matching: the first address is pinned to $15 (t7); the second is computed as a1+a0 after an
//           a0 barrier so GCC does not reuse the first sum; sh is pinned to $14 (t6); the second
//           byte is loaded into $13 (t5) to match the original's register use.
s32 func_00192450(u8* a0, u32 a1) {
    register u8* q asm("$15") = (u8*)((u32)a0 + (u32)a1);
    __asm__ volatile("" : "+r"(q));
    u32 c = q[0];
    s32 r = (s32)(c - 32);
    if (c < 32) {
        s32 t = (s32)(c - 25);
        if ((u8)t < 7) {
            register s32 sh asm("$14") = t << 8;
            __asm__ volatile("" : "+r"(sh));
            __asm__ volatile("" : "+r"(a0));
            register u8* p asm("$15") = (u8*)((u32)a1 + (u32)a0);
            __asm__ volatile("" : "+r"(p));
            register s32 b asm("$13") = p[1];
            r = sh + b + 224;
        } else
            r = -1;
    }
    return r;
}
