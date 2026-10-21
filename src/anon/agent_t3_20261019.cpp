#include "../common/types.h"

// Data block that func_001c10c8 clears. The address is 0x01d49388 (the lui/addiu pair
// in the original is 0x1d5 / -27768). Declared as an extern array so gcc emits
// R_MIPS_HI16/LO16 relocations against the symbol.
extern u8 D_01d49388[];

// FUN_001c0a80 (44 bytes)
// Code: zeroes the 19 bytes at a0[0..18] with a byte loop. The loop uses a
// "bnezl" with the next address computed in the delay slot, and two nops sit
// between slti and the branch.
// Guess: clears a 19-byte field of a struct.
// Note: 44 bytes is not a multiple of 8, so this object needs -falign-functions=1
// (set in the Makefile line below). Without it gcc pads the function to 48 bytes.
void func_001c0a80(u8* a0) {
    for (s32 i = 0; i < 19; i++)
        a0[i] = 0;
}

// FUN_001c10c8 (48 bytes)
// Code: stores a zero halfword at D_01d49388, then 64 bytes later, six times in
// total (a countdown from 5 to 0 that runs until it goes negative). The loop test
// is bgez on the counter, with three nops before the branch.
// Guess: clears the first halfword of six 64-byte records in a table.
// Note: the do/while with i-- and a pointer step of 64 in the loop body gives this
// shape directly. No barriers or register pins are needed.
void func_001c10c8(void) {
    u8* p = D_01d49388;
    s32 i = 5;
    do {
        *(u16*)p = 0;
        i--;
        p += 64;
    } while (i >= 0);
}
