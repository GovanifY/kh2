#include "../common/types.h"

// Agent K11: three leaf functions from SLPM_666.75 (002df160, 002e3260, 002e3f58).
// Object needs -falign-functions=1 (see Makefile) because 002e3260 is 92 bytes.

// Empty asm that stops gcc reordering memory operations across it.
#define K11_BAR() __asm__ volatile("" ::: "memory")

// FUN_002df160 (40 bytes)
// Code: zeroes the u32 at +32, loads the floats at +24 and +32 (the +32 load sees the
// zero just stored), stores f0 to +36 and +28, f1 to +44 and +40, and zeroes the bytes
// at +48 and +49. Guess: resets a small struct field block and copies two floats.
// Each store is separated by a memory barrier so gcc keeps the original sequence.
void func_002df160(u32 a0) {
    u8* p = (u8*)a0;
    *(u32*)(p + 32) = 0;
    K11_BAR();
    f32 f0 = *(f32*)(p + 24);
    f32 f1 = *(f32*)(p + 32);
    K11_BAR();
    *(f32*)(p + 36) = f0;
    K11_BAR();
    *(f32*)(p + 44) = f1;
    K11_BAR();
    *(u8*)(p + 48) = 0;
    K11_BAR();
    *(u8*)(p + 49) = 0;
    K11_BAR();
    *(f32*)(p + 28) = f0;
    K11_BAR();
    *(f32*)(p + 40) = f1;
}

// FUN_002e3260 (92 bytes)
// Code: count = word at +8 of arg0. Iterator p starts at arg0+16 with 32-byte entries.
// If count <= 0 returns 0. Otherwise loops: returns p if a1 == 0; returns p if the word
// at p is 0; if (word & 0xffff0000) == (a1 & 0xffff0000) and the halfword at p+4 == a2,
// returns p. Advances p by 32 for i < count, else returns 0.
// Guess: search over a table of 32-byte records keyed by the upper half of a word.
// Shape: the registers are pinned to the original ones (cnt t3, mask t2, key t4, i t5,
// p v0). The count and pointer are set before the branch, and an empty volatile asm after
// the count check stops gcc from hoisting the mask setup above the branch.
u32 func_002e3260(u32 a0, u32 a1, u32 a2) {
    register s32 cnt asm("$11");
    register u8* p asm("$2");
    register u32 mask asm("$10");
    register u32 key asm("$12");
    register s32 i asm("$13");
    cnt = *(s32*)(a0 + 8);
    p = (u8*)a0 + 16;
    i = 0;
    if (cnt <= 0) {
        p = 0;
        goto done;
    }
    __asm__ volatile("" : "+r"(p), "+r"(cnt), "+r"(i));
    mask = 0xffff0000u;
    key = a1 & mask;
    do {
        if (a1 == 0) goto done;
        u32 w = *(u32*)p;
        if (w == 0) goto done;
        if ((w & mask) == key) {
            if (*(u16*)(p + 4) == a2) goto done;
        }
        i++;
        p += 32;
    } while (i < cnt);
    p = 0;
done:
    __asm__ volatile("" : "+r"(p));
    return (u32)p;
}

// FUN_002e3f58 (32 bytes)
// Code: zeroes the words at +0, +4 and +8 of arg0, then stores the float constant at
// SLPM address 0x375f74 to +12. Guess: resets a small 16-byte record and fills in a
// default float.
// The constant address is built as one lui/addiu pair using %hi/%lo asm, so the gcc
// output has no separate addiu of zero. The stores sit between the two halves to match.
extern u8 D_00370000[];
void func_002e3f58(u32 a0) {
    u32* w = (u32*)a0;
    u8* q;
    __asm__ volatile("lui %0,%%hi(D_00370000+0x5f74)" : "=r"(q));
    w[0] = 0;
    K11_BAR();
    __asm__ volatile("addiu %0,%0,%%lo(D_00370000+0x5f74)" : "+r"(q));
    w[1] = 0;
    K11_BAR();
    f32 f = *(f32*)q;
    K11_BAR();
    w[2] = 0;
    K11_BAR();
    *(f32*)(w + 3) = f;
}
