#include "../common/types.h"

// 128-bit integer; GCC emits lq/sq for plain assignments of this type.
typedef int u128 __attribute__((mode(TI)));

// FUN_001069b8 (24 bytes)
// Code: t5 = lui 0x340000 (absolute base), t7 = lui 0x340000 (second base). Loads the word at
// 0x33cc38 into t6, stores a0 at 0x33cc38, then stores the old word at 0x33cc3c in the jr delay
// slot. Guess: swaps a word with a new value and keeps the old one in a neighbouring word.
// The two bases are absolute literals (low halves are zero), so no relocations are needed and the
// displacements -13256 / -13252 come from the index. Pins t5=$13, t6=$14, t7=$15 with empty asm
// barriers so GCC emits the two lui in source order before the load.
void func_001069b8(u32 a0) {
    register u32* t5 asm("$13");
    register u32 t6 asm("$14");
    register u32* t7 asm("$15");
    t5 = (u32*)0x00340000;
    __asm__ volatile("" : "+r"(t5));
    t7 = (u32*)0x00340000;
    __asm__ volatile("" : "+r"(t7));
    t6 = t5[-3314];
    t5[-3314] = a0;
    t7[-3313] = t6;
}

// FUN_00107478 (28 bytes)
// Code: a0 += 96. If a1 == a0, return. Otherwise copy 16 bytes from a0 to a1 with lq/sq through t0.
// Guess: copies a 16-byte vector from a fixed offset (+96) of a source into a destination, skipping
// the copy when both point to the same place. Built with -falign-functions=1 (see Makefile), because
// the 28-byte function would otherwise get an 8-byte alignment nop.
// The 128-bit temporary is pinned to $8 (t0) so the register matches the original.
void func_00107478(u8* a0, u128* a1) {
    register u128 t asm("$8");
    a0 += 96;
    if (a1 == (u128*)a0) return;
    t = *(u128*)a0;
    *a1 = t;
}

// FUN_0010b550 (20 bytes)
// Code: t7 = -1. a0[0] = 0, a0[4..7] = t7 (word), then a0[1] = 0 in the jr delay slot.
// Guess: initializes a small header: two zero bytes and a word of all ones.
// t7 is pinned to $15 and the byte stores are split by empty memory barriers so the order
// (byte 0, word, byte 1 in the delay slot) matches. Built with -falign-functions=1 since 20 bytes
// is not a multiple of 8.
void func_0010b550(u8* a0) {
    register u32 t7 asm("$15");
    t7 = 0xffffffffu;
    __asm__ volatile("" : "+r"(t7));
    a0[0] = 0;
    __asm__ volatile("" ::: "memory");
    *(u32*)(a0 + 4) = t7;
    __asm__ volatile("" ::: "memory");
    a0[1] = 0;
}
