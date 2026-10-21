#include "../common/types.h"

// Agent L12 leaves (kh2 decomp, 2026-10-20). VU0 leaf functions written as inline asm in the
// original order. The sqc2 is a separate asm statement, so gcc places it in the jr delay slot.
// Object flag: -falign-functions=1 (the 28- and 60-byte bodies get no trailing alignment nop).

// FUN_002f3d50 (28 bytes)
// Code: loads the vec4 at a1 into vf4 and at a2 into vf5, computes the cross product with
//       vopmula/vopmsub into vf6, clears w with vsub.w, and stores vf6 to a0 in the jr delay slot.
// Guess: writes the cross product a1 x a2 (xyz, w = 0) to a0.
void func_002f3d50(u8* a0, u8* a1, u8* a2) {
    __asm__ volatile(
        "lqc2 $vf4,0(%1)\n\t"
        "lqc2 $vf5,0(%2)\n\t"
        "vopmula.xyz ACC,$vf4,$vf5\n\t"
        "vopmsub.xyz $vf6,$vf5,$vf4\n\t"
        "vsub.w $vf6,$vf6,$vf6\n\t"
        :
        : "r"(a0), "r"(a1), "r"(a2)
        : "memory");
    __asm__ volatile("sqc2 $vf6,0(%0)" : : "r"(a0) : "memory");
}

// FUN_002f3d70 (36 bytes)
// Code: loads the vec4 at a0 and a1, multiplies xyz, sums y and z into x (vaddy/vaddz),
//       then moves the x lane to $f0 through v0.
// Guess: dot product of the xyz parts of two vectors, returned as a float.
f32 func_002f3d70(u8* a0, u8* a1) {
    register f32 r asm("$f0");
    __asm__ volatile(
        "lqc2 $vf4,0(%1)\n\t"
        "lqc2 $vf5,0(%2)\n\t"
        "vmul.xyz $vf5,$vf4,$vf5\n\t"
        "vaddy.x $vf5,$vf5,$vf5y\n\t"
        "vaddz.x $vf5,$vf5,$vf5z\n\t"
        "qmfc2 $2,$vf5\n\t"
        "mtc1 $2,%0\n\t"
        : "=f"(r)
        : "r"(a0), "r"(a1)
        : "$2", "memory");
    return r;
}

// FUN_002f3d98 (60 bytes)
// Code: loads the vec4 at a1 into vf4, computes its squared length (vmul.xyz, vaddy, vaddz),
//       takes vsqrt and reciprocal (vdiv) through Q, multiplies xyz by the reciprocal, and
//       stores the normalized vector (w = 0) to a0 in the jr delay slot.
// Guess: normalizes the xyz part of a1 into a0.
void func_002f3d98(u8* a0, u8* a1) {
    __asm__ volatile(
        "lqc2 $vf4,0(%1)\n\t"
        "vmul.xyz $vf5,$vf4,$vf4\n\t"
        "vaddy.x $vf5,$vf5,$vf5y\n\t"
        "vaddz.x $vf5,$vf5,$vf5z\n\t"
        "vsqrt Q,$vf5x\n\t"
        "vwaitq\n\t"
        "vaddq.x $vf5,$vf0,Q\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vdiv Q,$vf0w,$vf5x\n\t"
        "vsub.wxyz $vf6,$vf0,$vf0\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf6,$vf4,Q\n\t"
        :
        : "r"(a0), "r"(a1)
        : "memory");
    __asm__ volatile("sqc2 $vf6,0(%0)" : : "r"(a0) : "memory");
}
