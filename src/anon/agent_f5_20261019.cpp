#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));

extern u32 D_0036c908[];

// FUN_00183768 (84 bytes)
// Code: p = a0 + 16. If p != a1, copy the 16-byte vector at a1 to p (lq/sq through $8).
// Load p into vf1, compute the length of its xyz part (vmul, vaddy, vaddz, vsqrt),
// divide vf1 by that length (vdiv/vmulq), and store vf1 back at p. Store the float
// argument f at a0+28. Returns the length as a float in $f0.
// Guess: normalize a 3D vector stored at +16 of an object and record a float (a scale
// or weight) at +28. The return value is the length before normalizing.
// Build: needs -falign-functions=1 (the 8-byte function padding adds a trailing nop
// to an 84-byte function).
f32 func_00183768(f32 f, u8* a0, u8* a1) {
    register u8* p asm("$15") = a0 + 16;
    register f32 len asm("$f0");
    if (p != a1) {
        __asm__ volatile(
            "lq $8,0(%1)\n\t"
            "sq $8,0(%0)\n\t"
            :
            : "r"(p), "r"(a1)
            : "$8", "memory");
    }
    __asm__ volatile(
        ".set noreorder\n\t"
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
        "sqc2 $vf1,0(%1)\n\t"
        ".set reorder\n\t"
        : "=f"(len)
        : "r"(p)
        : "$8", "memory");
    *(f32*)(a0 + 28) = f;
    return len;
}

// FUN_00186110 (56 bytes)
// Code: v = byte at +36 of a1. If v < 10, jump through the 10-entry table at 0x36c908.
// Table entries 0, 2, 3, 4, 5 go to "return 1"; 1, 6, 7, 8, 9 go to "return 0".
// Otherwise (v >= 10) return 0. The first argument is unused.
// Guess: a set-membership test on a small type code stored at +36 of an object.
s32 func_00186110(u32 a0, u8* a1) {
    u32 v = a1[36];
    static void* keep[] = { &&lab_one, &&lab_zero };
    if (v >= 10) goto lab_zero;
    goto *(void*)D_0036c908[v];
lab_one:
    return 1;
lab_zero:
    return 0;
}
