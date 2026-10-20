#include "../common/types.h"

extern u8 D_00350000;

// FUN_0019d380 (52 bytes)
// Code: p = the pointer at D_00350000+1092. If p->+32 is zero, return 0. If p->+4 != a0
//       or p->+36 != a1, return 0. Otherwise return p->+32.
// Guess: lookup of the cached entry for a pair of ids.
// asm use: none. The ternary form gives beqzl/bnel with move v0,zero in the delay
//          slots, where an if-return form gives movz.
u32 func_0019d380(u32 a0, u32 a1) {
    u32* p = *(u32**)(&D_00350000 + 1092);
    u32 v = p[8];
    return (v == 0 || p[1] != a0 || p[9] != a1) ? 0 : v;
}

// FUN_0019f5d8 (56 bytes)
// Code: scan 8 records of 12 bytes starting at a0 (do-while, end = a0 + 96). Return the
//       first record with word +0 == a1 and word +4 == a2, else 0.
// Guess: search a small table of (id, id) pairs.
// Pointers are s32 so the loop test uses signed slt, as the original does.
u32 func_0019f5d8(u32 a0, u32 a1, u32 a2) {
    s32 p = a0;
    s32 end = a0 + 96;
    do {
        if (*(u32*)p == a1 && *(u32*)(p + 4) == a2) return p;
        p += 12;
    } while (p < end);
    return 0;
}

// FUN_0019f740 (80 bytes)
// Code: scan the same 8 records (do-while). A record matches when word +0 == a1 and
//       word +4 is -1 or a2. For a match, return 1 if byte +8 is zero. Otherwise keep
//       scanning. Return 0 if nothing qualifies.
// Guess: search for an entry with a wildcard (-1) key and a zero flag byte.
// asm use: register pin on -1 in $13 (t5) so the li is scheduled first, as in the original.
u32 func_0019f740(u32 a0, u32 a1, u32 a2) {
    register s32 m1 asm("$13") = -1;
    s32 p = a0;
    s32 end = a0 + 96;
    do {
        if (*(u32*)p == a1 && (*(s32*)(p + 4) == m1 || *(u32*)(p + 4) == a2)) {
            if (*(u8*)(p + 8) == 0) return 1;
        }
        p += 12;
    } while (p < end);
    return 0;
}
