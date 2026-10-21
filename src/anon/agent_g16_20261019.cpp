#include "../common/types.h"

// Three VU0 vector routines. Each is a short VU0 sequence: lqc2 loads, one vector op, sqc2 store.
// There is no C logic, so each body is inline asm with arguments pinned to $4..$6 (a0..a2).
// The final sqc2 sits inside .set noreorder/.set reorder so the assembler does not move it into
// the jr ra delay slot. The compiler then adds its own jr ra / nop epilogue.

// FUN_002226a0 (24 bytes)
// Code: loads the vector at a0 (vf1) and the vector at a1 (vf2), copies only x and y from vf2
//       into vf1, then stores vf31 back to a0 (the original stores vf31, not vf1, so it is kept).
// Guess: an xy-only copy helper whose store is a leftover of a VU0 macro.
void func_002226a0(u8* a0, u8* a1) {
    register u8* p0 asm("$4") = a0;
    register u8* p1 asm("$5") = a1;
    __asm__ volatile(
        "lqc2 $vf1,0(%0)\n\t"
        "lqc2 $vf2,0(%1)\n\t"
        "vmove.xy $vf1,$vf2\n\t"
        ".set noreorder\n\t"
        "sqc2 $vf31,0(%0)\n\t"
        ".set reorder"
        : : "r"(p0), "r"(p1) : "memory");
}

// FUN_002226b8 (24 bytes)
// Code: same as FUN_002226a0 but copies x, y and z from the vector at a1 into vf1, then stores
//       vf1 back to a0.
// Guess: an xyz copy into a 3-float vector field (w is left alone).
void func_002226b8(u8* a0, u8* a1) {
    register u8* p0 asm("$4") = a0;
    register u8* p1 asm("$5") = a1;
    __asm__ volatile(
        "lqc2 $vf1,0(%0)\n\t"
        "lqc2 $vf2,0(%1)\n\t"
        "vmove.xyz $vf1,$vf2\n\t"
        ".set noreorder\n\t"
        "sqc2 $vf1,0(%0)\n\t"
        ".set reorder"
        : : "r"(p0), "r"(p1) : "memory");
}

// FUN_00222710 (28 bytes)
// Code: loads vectors a1 (vf1), a2 (vf2) and a0 (vf3), computes vf3.xy = vf1.xy + vf2.xy,
//       and stores vf3 to a0. The z and w lanes of vf3 come from the old contents of a0.
// Guess: adds the xy parts of two vectors into a destination vector (a0 = a1 + a2, xy only).
// Build: 28 bytes is not a multiple of 8, so this object uses -falign-functions=1 (see Makefile).
void func_00222710(u8* a0, u8* a1, u8* a2) {
    register u8* p0 asm("$4") = a0;
    register u8* p1 asm("$5") = a1;
    register u8* p2 asm("$6") = a2;
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "lqc2 $vf2,0(%2)\n\t"
        "lqc2 $vf3,0(%0)\n\t"
        "vadd.xy $vf3,$vf1,$vf2\n\t"
        ".set noreorder\n\t"
        "sqc2 $vf3,0(%0)\n\t"
        ".set reorder"
        : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
