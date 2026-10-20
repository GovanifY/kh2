#include "../common/types.h"

extern u32 D_01d48cb0;

// VU0 helper for func_001b7958: vf1 = *p + *q (vadd.wxyz), stored back to *p.
// Keeps the original order: lqc2 vf1, lqc2 vf2, vadd, sqc2.
static inline void r3_vadd_store(u8* p, u8* q) {
    __asm__ volatile(
        "lqc2 $vf1,0(%0)\n\t"
        "lqc2 $vf2,0(%1)\n\t"
        "vadd.wxyz $vf1,$vf1,$vf2\n\t"
        "sqc2 $vf1,0(%0)"
        : : "r"(p), "r"(q) : "memory");
}

// FUN_001b5af0 (48 bytes)
// Code: p = global at 0x01d48cb0. If p is NULL, returns 0. If the word at p+64 has bit 2
//       set, returns 0. Otherwise returns the u16 at (*p)+40.
// Guess: query a u16 field of the object pointed to by a global, gated by a flag.
// Matching notes: the goto order (good path after the shared "return 0") makes GCC emit the
//       branch-likely beqzl with the word load in its delay slot.
u32 func_001b5af0(void) {
    u32 p = D_01d48cb0;
    if (p == 0) goto ret0;
    if ((*(u32*)(p + 64) & 4) == 0) goto good;
ret0:
    return 0;
good:
    return *(u16*)(*(u32*)p + 40);
}

// FUN_001b6d88 (72 bytes)
// Code: if a1 == 3 and the byte at a0 is >= 3, stores (byte + 1) at a0 and returns.
//       Otherwise stores the low byte of a1 at a0, and if a1 == 2 clears bit 0 of the byte at a0+3.
// Guess: a small state machine on a status byte with a 2-value sub-state.
// Matching notes: the asm barrier on the loaded byte keeps the andi 0xff that GCC would
//       otherwise drop (lbu already zero-extends).
void func_001b6d88(u8* a0, u32 a1) {
    u32 t;
    if (a1 != 3) goto Lb;
    t = *a0;
    __asm__ volatile("" : "+r"(t));
    if ((t & 0xff) < 3) goto Lb;
    *a0 = (u8)(t + 1);
    return;
Lb:
    *a0 = (u8)a1;
    if (a1 == 2) a0[3] &= 0xfe;
}

// FUN_001b7958 (60 bytes)
// Code: n = word at a0. For i in 0..n-1, the 16-byte vector at a0+32+32*i gets the
//       vector at a1 added (VU0 vadd.wxyz). Returns nothing.
// Guess: adds a vector offset to each entry of an array of 32-byte entries at a0+32.
// Matching notes: the loop re-reads the count after each store (the memory clobber forces it),
//       and the pointer is advanced in the delay slot of the loop branch.
void func_001b7958(u8* a0, u8* a1) {
    s32 i = 0;
    if (*(s32*)a0 <= 0) return;
    u8* p = a0 + 32;
    do {
        r3_vadd_store(p, a1);
        i++;
        p += 32;
    } while (i < *(s32*)a0);
}
