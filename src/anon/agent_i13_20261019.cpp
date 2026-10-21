#include "../common/types.h"

// Table of 4-byte records {s16 key; s16 value} at 0x374A08. The list ends at the
// first record whose key is <= 0.
struct Rec0029e7b0 {
    s16 key;
    s16 val;
};
extern Rec0029e7b0 D_00374a08[];

// FUN_0029e7b0 (88 bytes)
// Code: if the first record's key is > 0, walks the records while the key is > 0 and
//       returns the value of the first record whose key equals arg0. Returns -1 if none.
// Guess: signed id -> value lookup in a small table, terminated by a non-positive key.
// Match notes: r = -1 is set before the table read so li v0,-1 comes right after lui.
//              The loop is a do/while with the value returned from inside the loop.
s32 func_0029e7b0(s32 a0) {
    s32 r = -1;
    s32 i = 0;
    if (D_00374a08[0].key > 0) {
        do {
            if (D_00374a08[i].key == a0) {
                r = D_00374a08[i].val;
                break;
            }
            i++;
        } while (D_00374a08[i].key > 0);
    }
    return r;
}

// Zero-terminated u16 list at 0x374AA0.
extern u16 D_00374aa0[];

// FUN_0029ec40 (88 bytes)
// Code: sets v0 = 0, then if the list is not empty, searches the zero-terminated u16
//       list at 0x374AA0 for arg0 and returns 1 if found, else 0.
// Guess: membership test in a 0-terminated id list (same family as FUN_0029ec98).
// Match notes: the same shape as the matched FUN_0029ec98 (agent_i_20261019.cpp).
s32 func_0029ec40(s32 a0) {
    s32 r = 0;
    s32 i = 0;
    if (D_00374aa0[0] != 0) {
        do {
            if (D_00374aa0[i] == a0) {
                r = 1;
                break;
            }
            i++;
        } while (D_00374aa0[i] != 0);
    }
    return r;
}

// Global pointer at 0x35F620. It points to a u32 bitmap; the bitmap starts at +316.
extern u8* D_0035f620;

// FUN_002ad338 (88 bytes)
// Code: sets v0 = 1, then checks bits 0..12 of the bitmap at (*0x35F620 + 316).
//       Bit i lives in word i>>5 at bit i&31. Any clear bit makes the result 0.
// Guess: "all of the first 13 flags are set" test on a status word.
// Match notes: i stays signed (slti compares signed), while the shifts use (u32)i.
//              r = 1 is set before the pointer load, and the bit mask is a pinned u32 one.
s32 func_002ad338(void) {
    s32 r = 1;
    s32 i = 0;
    u32 one = 1;
    u32* p = (u32*)(D_0035f620 + 316);
    do {
        u32 w = p[(u32)i >> 5];
        if (!(w & (one << ((u32)i & 31)))) {
            r = 0;
            break;
        }
        i++;
    } while (i < 13);
    return r;
}
