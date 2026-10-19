#include "../common/types.h"

extern u8 D_00360000;

// FUN_00230878 (76 bytes)
// Code: key = the signed 16-bit value at +4 of arg0. Walks a 64-entry table of
// 8-byte records whose base pointer is the global at 0x35dce8. For each record
// whose first word is non-null, it compares the signed 16-bit value at +4 of
// that word with the key. On the first match it stores arg0 into the record at
// +4 and returns. If nothing matches, it returns without storing.
// Guess: registers an object in a fixed-size lookup table, keyed by a 16-bit
// ID. It replaces the reference in the first slot whose owner has the same ID.
// The table pointer is read at the top of each pass, which gives the original
// branch-likely. The object is built with -falign-jumps=1 (see the Makefile).
void func_00230878(u8* a0) {
    register s32 key asm("$10") = *(s16*)(a0 + 4);
    register s32 i asm("$12") = 0;
    do {
        u8* tbl = *(u8**)((u32)&D_00360000 - 8984u);
        register u32 sh asm("$15") = (u32)i << 3;
        u8* e = (u8*)(sh + (u32)tbl);
        i++;
        u8* p = *(u8**)e;
        if (p != 0) {
            if (*(s16*)(p + 4) == key) {
                *(u8**)(e + 4) = a0;
                return;
            }
        }
    } while (i < 64);
}
