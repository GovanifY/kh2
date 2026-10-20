#include "../common/types.h"

// FUN_0010f6b8 (60 bytes)
// Code: p = a0->[1164]. Returns 0 if p is NULL. Otherwise computes
//       t = (s32)((float)p[1] * x) and returns 1 if p[0] < t, else 0.
// Guess: a threshold test on a float parameter against an object stored at +1164
//        (for example a progress or limit check).
// Note: the result is set to 1 before a branch on the compare, so the original's
//       bnez has "li v0,1" in its delay slot and "move v0,zero" on the fall-through.
//       The compare is kept as a value by an empty volatile barrier. The converted
//       int is pinned to $15 (t7) to match the mfc1 destination.
s32 func_0010f6b8(u8* a0, f32 x) {
    register s32 t asm("$15");
    s32* p = *(s32**)(a0 + 1164);
    s32 r = 0;
    s32 a;
    s32 cond;
    if (!p)
        return r;
    t = (s32)((f32)p[1] * x);
    a = p[0];
    cond = a < t;
    __asm__ volatile("" : "+r"(cond));
    r = 1;
    if (cond)
        goto done;
    r = 0;
    __asm__("" : "+r"(r));
done:
    return r;
}

// FUN_0010f6f8 (76 bytes)
// Code: returns 0 if (a0->+2040 & 4). Otherwise p = a0->+1164; returns 0 if p is NULL.
//       Else returns (p->+384 < (int)((float)p->+388 * a1)). The +388 field is read as an
//       int and converted to float, and the product is truncated back to int.
// Guess: a range or threshold test on an object's state, with the float scaled by a1.
// Note: same tail as FUN_0010f6b8. The result is set to 1 before the branch and reset to 0
//       on the fall-through, and the converted value is pinned to $15 (t7).
s32 func_0010f6f8(u8* a0, f32 a1) {
    register s32 t asm("$15");
    s32 r = 0;
    s32 cond;
    u8* p;
    s32 a;
    if (*(u32*)(a0 + 2040) & 4)
        return r;
    p = *(u8**)(a0 + 1164);
    if (!p)
        return r;
    t = (s32)((f32)*(s32*)(p + 388) * a1);
    a = *(s32*)(p + 384);
    cond = a < t;
    __asm__ volatile("" : "+r"(cond));
    r = 1;
    if (cond)
        goto done;
    r = 0;
    __asm__("" : "+r"(r));
done:
    return r;
}
