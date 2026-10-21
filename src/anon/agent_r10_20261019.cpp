#include "../common/types.h"

extern u8 D_00360000;

// FUN_00292af0 (80 bytes)
// Code: count = s16 at 0x35f4e0, table = pointer at 0x35f4dc; entries have a 4-byte stride.
// Returns 1 if any entry's u16 at +0 equals a0, else 0.
// Note: the empty-looking asm is a real `move` (count copied from t7 to t4); r = 1; break
//       puts the match return on the bne fall-through. Needs -falign-functions=1.
u32 func_00292af0(u32 a0) {
    s32 i = 0;
    s32 t7 = *(s16*)(&D_00360000 - 2848);
    u32 r = 0;
    if (t7 > 0) {
        s32 n;
        asm("move %0,%1" : "=r"(n) : "r"(t7));
        u16* p = *(u16**)(&D_00360000 - 2852);
        do {
            if (*p == a0) { r = 1; break; }
            p += 2;
            i++;
        } while (i < n);
    }
    return r;
}

// FUN_00293148 (92 bytes)
// Code: count = s32 at 0x35f4d0, table = pointer at 0x35f4d4; 16-byte entries.
// Returns entry[3] of the first entry whose flag word [1] has bit 0 set and [0] == a0, else 0.
u32 func_00293148(u32 a0) {
    s32 t7 = *(s32*)(&D_00360000 - 2864);
    s32 i = 0;
    if (t7 > 0) {
        s32 n;
        asm("move %0,%1" : "=r"(n) : "r"(t7));
        u32* p = *(u32**)(&D_00360000 - 2860);
        do {
            u32 w = p[1];
            asm("" : "+r"(w));
            if ((u8)(w & 1)) {
                if (p[0] == a0) return p[3];
            }
            i++;
            p += 4;
        } while (i < n);
    }
    return 0;
}
