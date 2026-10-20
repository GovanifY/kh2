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
