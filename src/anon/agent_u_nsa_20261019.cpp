#include "../common/types.h"

extern u8 D_01c60000;

// FUN_00196328 (96 bytes)
// Code: a0[0..2] = 0xff; the three halfwords at a0+4, +6, +8 = 0xffff; then
//       a0[i] = table[a1*4 + i] for i = 0..2, where table is the pointer stored at
//       D_01c60000+6916 (reloaded for each byte). Returns a0.
// Guess: fills an RGB colour (plus default halfword fields) from a palette indexed by a1.
// Note: this object is built with -fno-strict-aliasing (per-object Makefile flag). With
//       type-based aliasing GCC hoists the table-pointer load above the halfword stores;
//       the original keeps it after them. `u16 v` makes the constant load as `ori 0xffff`.
#define TB (*(u32*)(&D_01c60000 + 6916))
u8* func_00196328(u8* a0, s32 a1) {
    u16 v = 0xffff;
    u16* h = (u16*)(a0 + 4);
    a0[0] = v;
    a0[1] = v;
    a0[2] = v;
    h[0] = v;
    h[1] = v;
    h[2] = v;
    u32 o = a1 << 2;
    a0[0] = *(u8*)(o + TB);
    a0[1] = *(u8*)(o + 1 + TB);
    a0[2] = *(u8*)(o + 2 + TB);
    return a0;
}
