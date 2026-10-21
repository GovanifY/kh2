#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));

// Agent L13: three VU0 / MMI leaf routines from SLPM_666.75.
// Each body is one asm block with the arguments pinned to a0..a2 ($4..$6) and f12 ($f12).
// Where the original ends with "jr ra" followed by a store in the delay slot, the asm
// block ends with that store, and gcc puts it in the jr ra delay slot (no extra nop).

// FUN_002f3dd8 (68 bytes)
// Code: loads four quadwords from a1 (t0..t3), interleaves their 32-bit words with
//       pextlw/pextuw, recombines the 64-bit halves with pcpyld/pcpyud, and stores the
//       four results to a0. The last store (sq t3, 48(a0)) is in C so it fills the jr
//       delay slot.
// Guess: a 4x4 transpose of 32-bit words, from a1 into a0.
void func_002f3dd8(u8* a0, u8* a1) {
    register u8* p0 asm("$4") = a0;
    register u8* p1 asm("$5") = a1;
    register u128 t3 asm("$11");
    __asm__ volatile(
        "lq $8,0(%2)\n\t"
        "lq $9,16(%2)\n\t"
        "lq $10,32(%2)\n\t"
        "lq $11,48(%2)\n\t"
        "pextlw $12,$9,$8\n\t"
        "pextuw $13,$9,$8\n\t"
        "pextlw $14,$11,$10\n\t"
        "pextuw $15,$11,$10\n\t"
        "pcpyld $8,$14,$12\n\t"
        "pcpyud $9,$12,$14\n\t"
        "pcpyld $10,$15,$13\n\t"
        "pcpyud $11,$13,$15\n\t"
        "sq $8,0(%1)\n\t"
        "sq $9,16(%1)\n\t"
        "sq $10,32(%1)\n\t"
        : "=r"(t3)
        : "r"(p0), "r"(p1)
        : "$8", "$9", "$10", "$12", "$13", "$14", "$15", "memory");
    *(u128*)(p0 + 48) = t3;
}

// FUN_002f3e90 (32 bytes)
// Code: loads the vec4 at a1 into vf4. Moves the float argument (f12) into vf5.x, takes
//       Q = 1 / vf5.x (vdiv, then vwaitq), multiplies all four lanes of vf4 by Q, and stores
//       vf4 to a0. The sqc2 sits in the jr ra delay slot, as in the original.
// Guess: divide a vec4 by a scalar (a0 = a1 / x).
void func_002f3e90(u8* a0, u8* a1, f32 x) {
    register u8* p0 asm("$4") = a0;
    register u8* p1 asm("$5") = a1;
    register f32 fx asm("$f12") = x;
    __asm__ volatile(
        "lqc2 $vf4,0(%1)\n\t"
        "mfc1 $8,$f12\n\t"
        "qmtc2 $8,$vf5\n\t"
        "vdiv Q,$vf0w,$vf5x\n\t"
        "vwaitq\n\t"
        "vmulq.wxyz $vf4,$vf4,Q\n\t"
        "sqc2 $vf4,0(%0)"
        : : "r"(p0), "r"(p1), "f"(fx) : "memory", "$8");
}

// FUN_002f3ed0 (40 bytes)
// Code: loads the vec4 at a1 (vf4) and the vec4 at a2 (vf5). Moves the float argument into
//       vf6.x = t. Computes vf8.x = 1 - t (vf7 = 1 via vf0.w, then subtract). ACC = vf4 * t,
//       then vf9 = ACC + vf5 * (1 - t). Stores vf9 to a0. The sqc2 sits in the jr delay slot.
// Guess: linear interpolation between a1 and a2 with weight t: a0 = a1 * t + a2 * (1 - t).
void func_002f3ed0(u8* a0, u8* a1, u8* a2, f32 x) {
    register u8* p0 asm("$4") = a0;
    register u8* p1 asm("$5") = a1;
    register u8* p2 asm("$6") = a2;
    register f32 fx asm("$f12") = x;
    __asm__ volatile(
        "lqc2 $vf4,0(%1)\n\t"
        "lqc2 $vf5,0(%2)\n\t"
        "mfc1 $8,$f12\n\t"
        "qmtc2 $8,$vf6\n\t"
        "vaddw.x $vf7,$vf0,$vf0w\n\t"
        "vsub.x $vf8,$vf7,$vf6\n\t"
        "vmulax.wxyz ACC,$vf4,$vf6x\n\t"
        "vmaddx.wxyz $vf9,$vf5,$vf8x\n\t"
        "sqc2 $vf9,0(%0)"
        : : "r"(p0), "r"(p1), "r"(p2), "f"(fx) : "memory", "$8");
}
