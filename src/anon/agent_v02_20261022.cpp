#include "../common/types.h"

// Agent V02 (2026-10-22): FUN_0015a118 (SLPM_666.75, 60 bytes).
// Code: f = FUN_0015a098(a0) (float result in $f0). f += the float global at
// 0x34aa44 (loaded into $f1 after the call, so the add is f0 = f0 + f1). Then
// tail-free call FUN_0017ce10(f) with f in $f12 and stores its result at a0+80.
// Guess: a float field at +80 is refreshed from a 0x34aa44 offset value after a
// clamp-like helper; FUN_0015a098 returns the base value.
// Matching: the callee float result is pinned to $f1 for the global load and
// the sum is passed to the helper via a $f12 pin, which gives add.s $f0,$f0,$f1
// followed by mov.s $f12,$f0 in the delay slot of the second jal.
// Build flag: -falign-functions=1 (60 bytes is not a multiple of 8).
extern "C" f32 func_0015a098(u32);
extern "C" f32 func_0017ce10(f32);
extern f32 D_0034aa44;

void func_0015a118(u8* a0) {
    f32 f0 = func_0015a098((u32)a0);
    register f32 k asm("$f1") = D_0034aa44;
    f0 = f0 + k;
    register f32 arg asm("$f12") = f0;
    f0 = func_0017ce10(arg);
    *(f32*)(a0 + 80) = f0;
}
