#include "../common/types.h"

extern u8 D_00360000[];

// FUN_002908a8 (68 bytes)
// Code: clears the pointer fields at +4, +8 (u32) and +16 (u8) of the object. Then, for
// i = 0 .. count-1 (count at +12), it writes 0 to the u32 slot at (base + 4*i), where base
// is the pointer at +20 (reloaded each pass).
// Guess: resets a list object and zeroes its pointer table.
// Register notes: the offset is pinned to $14 (t6) so the addu puts the sum in t6 and the
// store uses it. i = 0 is hoisted above the count test so it fills the blez delay slot.
void func_002908a8(u32 a0) {
    register u32 q asm("$14");
    u8* p = (u8*)a0;
    *(u32*)(p + 4) = 0;
    *(u8*)(p + 16) = 0;
    *(u32*)(p + 8) = 0;
    s32 n = *(s32*)(p + 12);
    s32 i = 0;
    if (n > 0) {
        do {
            s32 base = *(s32*)(p + 20);
            q = (u32)(i << 2);
            q = q + (u32)base;
            *(u32*)q = 0;
            i = i + 1;
            n = *(s32*)(p + 12);
        } while (i < n);
    }
}
