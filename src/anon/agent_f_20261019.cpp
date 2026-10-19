#include "../common/types.h"

// FUN_00113808 (64 bytes)
// Code: o = word at +8 of a0; if null return 0. If a1 < 0 or a1 >= word at o+168 return
//       0. Else return word at o+172 plus a1*32.
// Guess: bounds-checked element lookup in a table of 32-byte entries.
u8* func_00113808(u8* a0, s32 a1) {
    u8* o = *(u8**)(a0 + 8);
    if (!o) return 0;
    if (a1 < 0 || a1 >= *(s32*)(o + 168)) return 0;
    return (u8*)(o + *(s32*)(o + 172)) + a1 * 32;
}
