#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));
extern u8 D_004f0000;

// FUN_0016d888 (72 bytes)
// Code: a0 points at two vector pointers {va, vb}. Computes the VU0 cross product va x vb
//       into a stack temporary, copies it to the static vector at 0x004f62a0 (skipped if the
//       temporary is that address), and stores the static vector's address back to a0[0].
// Guess: a "result = a x b" operator that returns its result through a shared static
//        vector (self-assignment guard in the vector copy).
// Note: VU0 part and the 16-byte copy are inline asm; g is pinned to $15 to match.
void func_0016d888(u32* a0) {
    u128 tmp;
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "lqc2 $vf2,0(%2)\n\t"
        "vsub.wxyz $vf3,$vf0,$vf0\n\t"
        "vopmula.xyz ACC,$vf1,$vf2\n\t"
        "vopmsub.xyz $vf3,$vf2,$vf1\n\t"
        "sqc2 $vf3,0(%3)\n\t"
        : "=m"(tmp)
        : "r"(a0[0]), "r"(a0[1]), "r"(&tmp));
    register u128* g asm("$15") = (u128*)(&D_004f0000 + 25248);
    __asm__("" : "+r"(g));
    if (&tmp != g)
        __asm__ volatile("lq $8,0(%1)\n\tsq $8,0(%0)" ::"r"(g), "r"(&tmp) : "$8", "memory");
    a0[0] = (u32)g;
}

// FUN_0017d930 (52 bytes)
// Code: counts the decimal digits of a0 (0 when a0 <= 0).
s32 func_0017d930(s32 a0) {
    s32 c = 0;
    s32 t = 1;
    if (a0 > 0) {
        do {
            t *= 10;
            c++;
        } while (a0 >= t);
    }
    return c;
}

