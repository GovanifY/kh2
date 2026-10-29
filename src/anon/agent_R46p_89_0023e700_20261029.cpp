#include "../common/types.h"

// Callee: func_001064a8 takes one u32 argument and returns a u32.
extern "C" u32 func_001064a8(u32);

// Float scale constant at 0x371560 (read as a single float).
extern f32 D_00371560[];

// FUN_0023e700 (56 bytes)
// Code: v = func_001064a8(20) + 10, converted to float and multiplied by the constant at 0x371560.
// The constant address is built with an empty "+r" barrier on the pointer so gcc emits lui/addiu.
f32 func_0023e700(void) {
    f32 *pc;
    u32 v = func_001064a8(20);
    f32 f = (f32)(s32)(v + 10);
    pc = (f32 *)((u32)&D_00371560[0]);
    __asm__("" : "+r"(pc));
    return f * *pc;
}
