#include "../common/types.h"

// FUN_00104cf0 (60 bytes)
// Code: copies the first three u16 values of a1 to a0, but skips any slot where the
//       source value is 0xffff (the "no value" marker). Leaves a0 untouched there.
// Guess: merge of a 3-entry u16 record, where 0xffff means "keep the old value".
// Note: the empty asm barrier on each loaded value stops GCC from proving the zero
//       extension, so it emits the andi that the original has before each bnel.
void func_00104cf0(u16* a0, u16* a1) {
    s32 v0 = a1[0];
    __asm__("" : "+r"(v0));
    if ((v0 & 0xffff) != 0xffff)
        a0[0] = v0;
    s32 v1 = a1[1];
    __asm__("" : "+r"(v1));
    if ((v1 & 0xffff) != 0xffff)
        a0[1] = v1;
    s32 v2 = a1[2];
    __asm__("" : "+r"(v2));
    if ((v2 & 0xffff) != 0xffff)
        a0[2] = v2;
}

// FUN_0010f6b8 (60 bytes)
// Code: p = a0->[1164]. Returns 0 if p is NULL. Otherwise computes
//       t = (s32)((float)p[1] * x) and returns 1 if p[0] < t, else 0.
// Guess: a threshold test on a float parameter against an object stored at +1164
//        (for example a progress or limit check).
// Note: the bool result is produced by an asm block (noreorder) so that GCC keeps
//       the compare in a separate register and emits the bnez with "li v0,1" in its
//       delay slot, as the original does. The temp t is pinned to $15 (t7).
s32 func_0010f6b8(u8* a0, f32 x) {
    s32* p = *(s32**)(a0 + 1164);
    if (!p)
        return 0;
    f32 c = (f32)p[1] * x;
    register s32 t asm("$15") = (s32)c;
    s32 a = p[0];
    register s32 r asm("$2");
    __asm__ volatile(
        ".set noreorder\n\t"
        "slt %1,%1,%2\n\t"
        "bnez %1,1f\n\t"
        "li $2,1\n\t"
        "move $2,$0\n\t"
        "1:\n\t"
        ".set reorder"
        : "=r"(r), "+r"(a)
        : "r"(t));
    return r;
}
