#include "../common/types.h"

// Batch G14 (2026-10-20): three leaf functions decompiled from SLPM_666.75.
// Each comment says what the code does, then gives a guess at its role.
// Object note: built with -falign-functions=1 (per-object flag in the Makefile),
// because the original functions are 28 and 24 bytes with no padding after them.

extern u8 D_00350000[];
extern u8 D_001c6460[];
extern u32 D_01d49320;

// FUN_001aeae0 (28 bytes)
// Code: zeroes three 32-bit words at 0x350cc8, 0x350ccc and 0x350cd0. Each
//       store uses its own lui, and the stores run in the order cc8, cd0, ccc.
// Guess: resets three state words in the same 0x350000 block, as in the sibling
//        FUN_001c8de0. The lui pattern shows three separate symbol accesses.
// Matching: separate &D_00350000[offset] accesses let GCC emit one lui per store.
void func_001aeae0(void) {
    *(u32*)&D_00350000[3272] = 0;
    *(u32*)&D_00350000[3280] = 0;
    *(u32*)&D_00350000[3276] = 0;
}

// FUN_001bbb08 (28 bytes)
// Code: p = the word at D_01d49320. Returns 0 if p is null, else the word at p.
// Guess: a "read through a global pointer, if set" accessor.
// Matching: plain C. GCC puts the move v0,zero in the beqz delay slot.
u32 func_001bbb08(void) {
    u32 p = D_01d49320;
    u32 v = 0;
    if (p) v = *(u32*)p;
    return v;
}

// FUN_001c6748 (24 bytes)
// Code: stores the byte 2 at arg0+80 and the address 0x001c6460 (FUN_001c6460) at
//       arg0+84.
// Guess: sets a type code and a function pointer on an object. The address
//        0x1c6460 is the start of an asm-only function, so it is named as data here.
// Matching: the address is taken with &D_001c6460[0] so GCC emits lui + addiu with
//           paired relocations, as in the original.
void func_001c6748(u8* a0) {
    *(u8*)(a0 + 80) = 2;
    *(u32*)(a0 + 84) = (u32)&D_001c6460[0];
}
