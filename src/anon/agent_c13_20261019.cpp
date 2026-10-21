#include "../common/types.h"

extern u8 D_00360000[];

// FUN_00253948 (44 bytes)
// Code: if a0 is not a multiple of 64, returns the next multiple of 64 above it:
//       v = a0 (or a0 + 63 when a0 is negative, via movn), then ((v >> 6) << 6) + 64.
//       If a0 is already a multiple of 64, returns a0 unchanged.
// Guess: rounds a size or offset up to a 64-byte boundary.
// Note: the object is built with -falign-functions=1 because the body is 44 bytes, not a
//       multiple of 8, and the original ends in jr ra with no padding.
s32 func_00253948(s32 a0) {
    s32 v = a0;
    if (a0 & 63) {
        s32 t5 = a0 + 63;
        if (a0 < 0) v = t5;
        v = ((v >> 6) << 6) + 64;
    }
    return v;
}

// FUN_00257ff8 (80 bytes)
// Code: m = halfword at D_00360000-4240 (the same flag mask as FUN_00257fa8). Scans bits
//       0..7 of m. For each set bit: if its index equals a0, return the count of set bits
//       below it; otherwise count it and keep going. Returns -1 if a0 is not a set bit.
// Guess: checks whether bit a0 is set in an 8-bit flag mask and returns its rank among the
//        set bits (the inverse of FUN_00257fa8, which maps rank to index).
s32 func_00257ff8(s32 a0) {
    s32 r = -1;
    u16 m = *(u16*)((u32)&D_00360000 - 4240u);
    s32 n = 0;
    for (s32 i = 0; i < 8; i++) {
        if ((m >> i) & 1) {
            if (i == a0) { r = n; break; }
            n++;
        }
    }
    return r;
}

// FUN_00258ce8 (88 bytes)
// Code: if a0 is NULL, writes three halfwords to the table at D_00360000-3928:
//       [0] = 0x9fcf, [1] = 0x9fd0, [2] = 0x9fd1. Otherwise copies three halfwords from a0
//       into the same table.
// Guess: loads a 3-entry halfword table, either from a default set or from a caller's
//        source. The defaults look like fixed IDs (negative as s16).
// Note: the register pins and the inline asm block reproduce the original's lui/addiu
//       placement and register choices. The asm block covers the null-path setup
//       (lui, two stores, the table address); the last store stays in C so gcc fills the jr
//       delay slot. The non-null path is plain C and uses the offset form of the address.
void func_00258ce8(u16* a0) {
    register s32 n asm("$13");
    u16* t;
    if (a0 == 0) {
        register u16* q asm("$12");
        register s32 v2 asm("$15");
        __asm__ volatile(
            "lui $13,0x36\n\t"
            "li $15,-24625\n\t"
            "sh $15,-3928($13)\n\t"
            "addiu $12,$13,-3928\n\t"
            "li $14,-24623\n\t"
            "li $15,-24624\n\t"
            "sh $14,4($12)\n\t"
            : "=r"(q), "=r"(v2) : : "$13", "$14", "memory");
        q[1] = v2;
    } else {
        t = (u16*)&D_00360000[-3928];
        n = 2;
        do {
            u16 v = *a0;
            n--;
            *t = v;
            a0++;
            t++;
        } while (n >= 0);
    }
}
