#include "../common/types.h"

// Scratch-free, pinned-register matches for three leaves. The base of the
// halfword table at 0x32FAFE is a real symbol (D_0032fafe) so gcc emits the
// lui/addiu pair with HI16/LO16 relocations, which link to the original
// lui 0x33 + addiu -1282 encoding.
extern u16 D_0032fafe[];

// FUN_001d97f0 (48 bytes)
// Code: q = D_0032fafe + a0 (halfwords). If q[3] (u16) < 999, q[3] += 1.
// Guess: a saturating counter in a fixed table (entry 3 of row a0).
void func_001d97f0(u32 a0) {
    // Pin the loaded value to t6 and the incremented value to t7 so the
    // compare sees the andi-masked load, as in the original.
    register u32 v asm("$14");
    register u32 n asm("$15");
    u16* q = D_0032fafe + a0;
    v = q[3];
    n = v + 1;
    __asm__ volatile("" : "+r"(v));
    if ((u16)v < 999) q[3] = (u16)n;
}

// FUN_001d9820 (48 bytes)
// Code: same as FUN_001d97f0 but on q[9] (byte offset +18 from the row base).
// Guess: a second saturating counter in the same table.
void func_001d9820(u32 a0) {
    register u32 v asm("$14");
    register u32 n asm("$15");
    u16* q = D_0032fafe + a0;
    v = q[9];
    n = v + 1;
    __asm__ volatile("" : "+r"(v));
    if ((u16)v < 999) q[9] = (u16)n;
}

// FUN_001d9c68 (52 bytes)
// Code: checks the first 5 bytes at a0. Returns 1 if all five equal 1,
// otherwise 0 (the loop exits early on the first byte that is not 1).
// Guess: a 5-byte signature or flag-set check.
u32 func_001d9c68(u8* a0) {
    register u8* p asm("$14");
    register u32 c asm("$15");
    s32 i = 0;
    u32 v0 = 0;
    do {
        p = a0 + i;
        c = *p;
        i++;
        if (c != 1) return 0;
    } while (i < 5);
    v0 = 1;
    return v0;
}
