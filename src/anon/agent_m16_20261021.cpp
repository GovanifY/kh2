#include "../common/types.h"

// Callees. func_0016a070 and func_0010cc80 are called with the object as the only argument.
extern "C" u32 func_0010cc80(void*);
extern "C" u32 func_0016a070(void*);
extern "C" s32 func_001a35f8(u32, u32);
extern "C" u32 func_001064a8(u32);

// Float constant used by FUN_0010f660 (read as a single float at 0x36a52c).
extern f32 D_0036a52c[];

// FUN_0010f600 (72 bytes)
// Code: p = a0->+12. If p is non-null and p->+4 is zero and (a0->+352 & 4) is set,
//       returns (func_0010cc80(a0) != 0). Otherwise returns 0.
// Guess: a gated query on an object's sub-record, with a flag bit at +352.
// Note: the call result is turned into 0 or 1 with a plain != 0, which gives sltu v0,zero,v0.
s32 func_0010f600(u8* a0) {
    s32 r = 0;
    u32* sub = *(u32**)(a0 + 12);
    if (sub) {
        if (sub[1] == 0) {
            if (*(u32*)(a0 + 352) & 4) {
                r = func_0010cc80(a0) != 0;
            }
        }
    }
    return r;
}

// FUN_0010f660 (84 bytes)
// Code: v = func_001064a8(20001). Converts the unsigned v to a float and multiplies it by the
//       constant at 0x36a52c. If v is negative (as signed), the value is (v>>1)|(v&1), converted,
//       and doubled. This is the usual unsigned-to-float conversion with rounding preserved.
// Guess: a random float in [0, 1) or similar scale from a 20001-range generator.
// Note: the neg path is placed out of line with a goto so it becomes the bltz target, and the
//       constant address is built with an empty "+r" barrier so gcc emits lui/addiu, not lui/lwc1.
//       hi and h are pinned to $15 (t7) and $14 (t6) to match the original's register use.
f32 func_0010f660(void) {
    register s32 hi asm("$15");
    register s32 h asm("$14");
    f32 f1;
    f32* pc;
    u32 v = func_001064a8(20001);
    hi = (s32)(v >> 1);
    h = (s32)(v & 1) | hi;
    if ((s32)v < 0) goto neg;
    f1 = (f32)(s32)v;
common:
    pc = (f32*)((u32)&D_0036a52c[0]);
    __asm__("" : "+r"(pc));
    return f1 * *pc;
neg:
    f1 = (f32)h;
    f1 = f1 + f1;
    goto common;
}

// FUN_0010f748 (104 bytes)
// Code: p = a0->+12. Returns 0 unless p is non-null and p->+4 is 0 or 31. Then, if (a0->+352 & 4),
//       x = func_0016a070(a0) and returns (func_001a35f8(a1, x) > 0) (signed compare).
// Guess: a state check on an object's sub-record (type 0 or 31) that asks a helper about a1.
// Note: early returns keep the original's branch and delay-slot shapes. Ordering in the 0x10f740s
//       stubs is the same as the original and needs no pins.
s32 func_0010f748(u8* a0, s32 a1) {
    if (*(u32*)(a0 + 12) == 0) return 0;
    {
        s32 k = *(s32*)(*(u32*)(a0 + 12) + 4);
        if (k != 0 && k != 31) return 0;
    }
    if (!(*(u32*)(a0 + 352) & 4)) return 0;
    {
        s32 x = (s32)func_0016a070(a0);
        return func_001a35f8(a1, x) > 0;
    }
}
