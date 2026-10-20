#include "../common/types.h"

// Batch 2026-10-19 R2: three leaf functions from SLPM_666.75, matched byte for byte
// (relocated immediates in the original are symbol references, so they are not compared
// by value here; the full link check confirms them).

typedef int u128 __attribute__((mode(TI)));

extern u8 D_00350000[];
extern u8 D_01d44400[];
extern u8 D_01d44440[];

// FUN_001b1fc8 (40 bytes)
// Code: if the word at D_00350000+3864 is zero, returns 1 when the word at
// D_00350000+3868 equals a0, else 0. Otherwise returns 0.
// Guess: a guard flag check plus an id compare on a state word.
// Written with one result variable so the function has a single exit (the
// original fills v0 with zero in the branch delay slot).
u32 func_001b1fc8(u32 a0) {
    u32 r = 0;
    if (*(u32*)&D_00350000[3864] == 0) {
        r = *(u32*)&D_00350000[3868] == a0;
    }
    return r;
}

// FUN_001b1ff0 (56 bytes)
// Code: if a0 == -1 returns NULL. Otherwise stores 2 at D_00350000+3864, increments the
// word at D_01d44400, and returns the address D_01d44440.
// Guess: a "start a request" call that counts requests and returns a status block.
// The original keeps the counter address (lui 0x1d4) and the status address as two
// separate lui/addiu pairs; two extern arrays give that shape.
u8* func_001b1ff0(s32 a0) {
    u8* r = 0;
    if (a0 != -1) {
        *(u32*)&D_00350000[3864] = 2;
        *(u32*)D_01d44400 += 1;
        r = D_01d44440;
    }
    return r;
}

// FUN_001b2520 (84 bytes)
// Code: a0 is a ring buffer header: word 0 = capacity, word 4 = high-water mark,
// word 8 = cursor, word 20 = pointer to 16-byte entries. Copies the 16-byte vector at
// a1 into the current entry unless it is already there. Then the high-water mark becomes
// max(mark, cursor+1), and the cursor becomes (cursor+1) % capacity.
// Guess: appends a record to a fixed ring of 16-byte entries.
// The copy uses lq/sq with $8 (t0), pinned by the inline block. The memory clobber makes
// the cursor reload after the copy, as the original does. Object needs -falign-functions=1
// because the size (84) is not a multiple of 8.
void func_001b2520(u8* a0, u8* a1) {
    s32 cur = *(s32*)(a0 + 8);
    u8* p = (u8*)(*(u32*)(a0 + 20)) + (cur << 4);
    if (p != a1) {
        __asm__ volatile("lq $8,0(%0)\n\tsq $8,0(%1)" : : "r"(a1), "r"(p) : "$8", "memory");
        cur = *(s32*)(a0 + 8);
    }
    s32 cap = *(s32*)a0;
    s32 n = cur + 1;
    s32 hi = *(s32*)(a0 + 4);
    *(s32*)(a0 + 4) = (n < hi) ? hi : n;
    *(s32*)(a0 + 8) = n % cap;
}
