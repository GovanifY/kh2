#include "../common/types.h"

extern f32 D_0036c4cc;

// FUN_00178570 (72 bytes)
// Zeroes the 16-byte vector at a0+16 (VU0: vf1 = vf0 - vf0, then sqc2). Then, when the float
// at +2620 of the sub-object at a0+2884 is positive and the float at +2612 is negative, copies
// the float constant D_0036c4cc into a0+20. The empty asm barrier on the constant's address
// keeps GCC from folding the low half into the lwc1 offset (the original uses lui + addiu).
void func_00178570(u8* a0) {
    __asm__ volatile(
        "vsub.wxyz $vf1,$vf0,$vf0\n\t"
        "sqc2 $vf1,0(%0)\n\t"
        :
        : "r"(a0 + 16)
        : "memory");
    u8* t = *(u8**)(a0 + 2884);
    if (0.0f < *(f32*)(t + 2620) && *(f32*)(t + 2612) < 0.0f) {
        f32* g = &D_0036c4cc;
        __asm__("" : "+r"(g));
        *(f32*)(a0 + 20) = *g;
    }
}

// FUN_00182838 (40 bytes)
// Fills a 3-word header: word 0 = a1, word 1 = 1 (or 3 when the low byte of a3 is non-zero),
// word 2 = a2.
void func_00182838(s32* a0, s32 a1, s32 a2, s32 a3) {
    a0[0] = a1;
    a0[1] = 1;
    a0[2] = a2;
    if ((u8)a3)
        a0[1] = 3;
}
