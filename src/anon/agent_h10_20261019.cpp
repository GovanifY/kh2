#include "../common/types.h"

// Global words written by FUN_001c8a90: D_01d49960 (+0 and +4) and D_01d49968.
extern u32 D_01d49960[];
extern u32 D_01d49968[];

// FUN_001c8a90 (28 bytes)
// Code: zeroes three words in a global block: the words at 0x01d49960, 0x01d49964 and the
// word at 0x01d49968. The body is one inline-asm block in the original order (lui t7 for the
// first address, addiu t6 = t7 + low half, lui t7 for the last address, sw at +4 of t6, then
// the last sw in the jr delay slot). Paired %hi/%lo relocations come from the asm itself.
// Guess: reset of a small state block.
void func_001c8a90(void) {
    __asm__ volatile(
        "lui $15,%%hi(D_01d49960)\n\t"
        "sw $0,%%lo(D_01d49960)($15)\n\t"
        "addiu $14,$15,%%lo(D_01d49960)\n\t"
        "lui $15,%%hi(D_01d49968)\n\t"
        "sw $0,4($14)\n\t"
        "sw $0,%%lo(D_01d49968)($15)"
        :
        :
        : "$14", "$15", "memory");
}

// FUN_00222730 (28 bytes)
// Code: VU0 subtraction of the xyz parts. Loads vf1 from a1, vf2 from a2 and vf3 from a0,
// then vsub.xyz vf3 = vf1 - vf2 (w keeps the value loaded from a0) and stores vf3 back to a0.
// The whole body is one asm block. The trailing nop fills the jr delay slot that gcc emits
// after the block, so sqc2 stays before jr as in the original.
// Guess: a[0] = b - c for the xyz part of a vec4.
void func_00222730(u8* a0, u8* a1, u8* a2) {
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "lqc2 $vf2,0(%2)\n\t"
        "lqc2 $vf3,0(%0)\n\t"
        "vsub.xyz $vf3,$vf1,$vf2\n\t"
        "sqc2 $vf3,0(%0)\n\t"
        "nop"
        :
        : "r"(a0), "r"(a1), "r"(a2)
        : "memory");
}

// FUN_00222750 (28 bytes)
// Code: same as FUN_00222730 with vadd.xyz instead of vsub.xyz: a[0] = b + c for xyz.
// Guess: vec4 add (the other half of the pair).
void func_00222750(u8* a0, u8* a1, u8* a2) {
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "lqc2 $vf2,0(%2)\n\t"
        "lqc2 $vf3,0(%0)\n\t"
        "vadd.xyz $vf3,$vf1,$vf2\n\t"
        "sqc2 $vf3,0(%0)\n\t"
        "nop"
        :
        : "r"(a0), "r"(a1), "r"(a2)
        : "memory");
}
