#include "../common/types.h"

// Zero one 16-byte vector at p (VU0: vf1 = vf0 - vf0, then sqc2).
static inline void h5_vzero(void* p) {
    __asm__ volatile(".set noreorder\n\tvsub.wxyz $vf1,$vf0,$vf0\n\tsqc2 $vf1,0(%0)\n\t.set reorder" : : "r"(p) : "memory");
}

// FUN_00178cf8 (48 bytes)
// Code: zeroes three 16-byte vectors: at a0+32, at (*(a0+2884))+2608, and at a0+16.
// Guess: resets the vector fields of an object and of its sub-object.
void func_00178cf8(u8* a0) {
    h5_vzero(a0 + 32);
    h5_vzero(*(u8**)(a0 + 2884) + 2608);
    h5_vzero(a0 + 16);
}

// FUN_00180dc0 (52 bytes)
// Code: scans 16 words starting at a0+332 for a1. Returns 1 if found, else 0.
// Guess: membership test over a fixed 16-entry id table.
s32 func_00180dc0(u8* a0, s32 a1) {
    s32* p = (s32*)(a0 + 332);
    s32 n = 0;
    do {
        if (*p == a1)
            return 1;
        p++;
        n++;
    } while (n < 16);
    return 0;
}

// FUN_001846a0 (84 bytes)
// Code: copies the 16-byte vector at a1 to a0+2176 unless they are the same address, then
//       normalizes that vector with VU0 (length via vsqrt, then divide by it). Returns the
//       length as a float in $f0. Also stores $f12 (not a parameter; the caller's float is
//       read from that register) at a0+2188.
// Guess: stores a direction vector at +2176 and its length at +2188.
f32 func_001846a0(u8* a0, u8* a1) {
    register f32 len asm("$f0");
    register f32 fv asm("$f12");
    u8* d = a0 + 2176;
    if (d != a1) {
        __asm__ volatile("lq $8,0(%0)\n\tsq $8,0(%1)" : : "r"(a1), "r"(d) : "$8", "memory");
    }
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "vmul.xyz $vf2,$vf1,$vf1\n\t"
        "vaddy.x $vf2,$vf2,$vf2y\n\t"
        "vaddz.x $vf2,$vf2,$vf2z\n\t"
        "vsqrt Q,$vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8,$22\n\t"
        "vaddq.x $vf2,$vf0,Q\n\t"
        "mtc1 $8,%0\n\t"
        "vnop\n\t"
        "vdiv Q,$vf0w,$vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1,$vf1,Q\n\t"
        "sqc2 $vf1,0(%1)"
        : "=f"(len)
        : "r"(d)
        : "$8", "memory");
    *(f32*)(a0 + 2188) = fv;
    return len;
}
