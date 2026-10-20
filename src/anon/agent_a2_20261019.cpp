#include "../common/types.h"

// Agent A2 leaf functions (kh2 decomp, 2026-10-19). Each is checked against SLPM_666.75.

// FUN_0013a178 (96 bytes)
// Code: loads a 4x4 matrix (4 rows at a1) and a point at a0, computes M*p with VU0 (vmulax,
//       vmadday, vmaddaz, vmaddw), divides by w (vdiv/vwaitq/vmulq), converts to integers
//       (vftoi0) and stores the 4 ints at the fixed scratch vector 0x003b8b40. Then x -= 1792
//       and y -= 1840 on that vector, and returns its address.
// Guess: projects a point to biased integer screen coordinates in a fixed scratch vector.
// Note: the VU0 sequence is one asm block in the original order. C does the scalar tail.
u32* func_0013a178(u8* a0, u8* a1) {
    extern u32 D_003b8b40[];
    u32* p = D_003b8b40;
    __asm__ volatile(
        "lqc2 $vf4,0(%1)\n\t"
        "lqc2 $vf5,16(%1)\n\t"
        "lqc2 $vf6,32(%1)\n\t"
        "lqc2 $vf7,48(%1)\n\t"
        "lqc2 $vf8,0(%0)\n\t"
        "vmulax.wxyz ACC,$vf4,$vf8x\n\t"
        "vmadday.wxyz ACC,$vf5,$vf8y\n\t"
        "vmaddaz.wxyz ACC,$vf6,$vf8z\n\t"
        "vmaddw.wxyz $vf12,$vf7,$vf8w\n\t"
        "vdiv Q,$vf0w,$vf12w\n\t"
        "vwaitq\n\t"
        "vmulq.wxyz $vf12,$vf12,Q\n\t"
        "vftoi0.wxyz $vf13,$vf12\n\t"
        "sqc2 $vf13,0(%2)\n\t"
        :
        : "r"(a0), "r"(a1), "r"(p)
        : "memory");
    p[0] = p[0] - 1792;
    p[1] = p[1] - 1840;
    return p;
}
