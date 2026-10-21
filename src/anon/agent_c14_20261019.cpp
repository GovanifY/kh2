#include "../common/types.h"

// ---------------------------------------------------------------------------
// FUN_00259510 (96 bytes)
// Code: key/value table of 4-byte records {s16 key, s16 val} at 0x372C30, ended by
//       key == -1. Returns val of the first record whose key equals a0; otherwise 11.
// Guess: id -> value lookup (same family as FUN_00259460, which uses 6-byte records).
// Note: r is pinned to $2 so `li v0,11` is emitted before the table loads, and
//       the loop is a do-while with the tail test on the next record's key.
struct E259510 { s16 key, val; };
extern E259510 D_00372c30[];

s32 func_00259510(s32 a0) {
    register s32 r asm("$2") = 11;
    s32 i = 0;
    if (D_00372c30[0].key != -1) {
        for (;;) {
            if (D_00372c30[i].key == a0) { r = D_00372c30[i].val; break; }
            i++;
            if (D_00372c30[i].key == -1) break;
        }
    }
    return r;
}

// ---------------------------------------------------------------------------
// FUN_002670A0 (88 bytes)
// Code: m = halfword at +28 of the object pointed to by the global at 0x35F0E4.
//       Walks bits 0..9 of m. For each set bit, if the running count equals a0
//       return the bit index, else count++. Returns -1 if none matches.
// Guess: index of the a0-th set flag among ten flag bits (sibling of FUN_00257FA8,
//        which handles eight bits).
// Note: r is pinned to $2 so `li v0,-1` runs first and stays live across the loop.
//       The loop shape (bnel on the count, bnezl loop tail) comes from the
//       for-loop with an early break.
extern u8 D_00360000[];

s32 func_002670a0(s32 a0) {
    register s32 r asm("$2") = -1;
    s32 n = 0, b;
    for (b = 0; b < 10; b++) {
        if (((*(u16*)(*(u8**)&D_00360000[-3868] + 28)) >> b) & 1) {
            if (n == a0) { r = b; break; }
            n++;
        }
    }
    return r;
}

// ---------------------------------------------------------------------------
// FUN_002670F8 (88 bytes)
// Code: same flag word as FUN_002670A0. For each set bit b (0..9), if b equals a0
//       return the count of set bits below it, else count++. Returns -1 if a0 is not
//       a set bit.
// Guess: the rank of a flag among the set flags (inverse of FUN_002670A0).
// Note: r pinned to $2 as above; the comparison is on the bit index, not the count.
s32 func_002670f8(s32 a0) {
    register s32 r asm("$2") = -1;
    s32 n = 0, b;
    for (b = 0; b < 10; b++) {
        if (((*(u16*)(*(u8**)&D_00360000[-3868] + 28)) >> b) & 1) {
            if (b == a0) { r = n; break; }
            n++;
        }
    }
    return r;
}
