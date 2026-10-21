#include "../common/types.h"

extern u8 D_00360000[];

// FUN_00232e60 (60 bytes)
// Code: reads the table pointer stored at D_00360000 - 8968, then scans 64 records of 64 bytes.
//       Returns the first record whose first word is -1, or 0 if none matches.
// Guess: a free-slot finder over a fixed 64-entry object pool.
u8* func_00232e60(void) {
    u8* p = *(u8**)&D_00360000[-8968];
    s32 i;
    for (i = 0; i < 64; i++) {
        if (*(s32*)p == -1)
            return p;
        p += 64;
    }
    return 0;
}

// FUN_00236d60 (52 bytes)
// Code: clears a 1536-byte array of 24-byte records starting at D_00360000 - 7104. Each record
//       gets a zero byte at +0 and a zero word at +4. The compare is signed (slt), and the loop
//       tail carries the next byte store in the back-branch delay slot.
// Guess: resets a table of 64 small slots at startup.
void func_00236d60(void) {
    u8* p = &D_00360000[-7104];
    u8* end = p + 1536;
    do {
        p[0] = 0;
        *(u32*)(p + 4) = 0;
        p += 24;
    } while ((s32)p < (s32)end);
}

// FUN_00237540 (52 bytes)
// Code: a1 indexes a table of 4-byte entries at +12 of a0. Its first halfword plus a2 selects
//       a 20-byte record in the block at +8. The function adds a3 to the record's first word and
//       stores the result at its +8 word.
// Guess: updates one field of a record selected by a table lookup.
// Note: the index is pinned to a1 ($5) and the table address is added straight into it, so the
//       address goes straight into a1 as the original does (the plain form computes into t7 and
//       then moves it).
void func_00237540(u8* a0, u32 a1, s32 a2, u32 a3) {
    register u32 i asm("$5") = a1 << 2;
    u32 tb = (u32)*(u8**)(a0 + 12);
    i += tb;
    u16 v = *(u16*)i;
    u8* rec = *(u8**)(a0 + 8) + 20 * ((s32)v + a2);
    *(u32*)(rec + 8) = *(u32*)rec + a3;
}
