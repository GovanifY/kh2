#include "../common/types.h"

// Agent S25 (2026-10-21): three functions from SLPM_666.75.
// Each comment says what the code does, then gives a guess at its role.
// The guesses are unverified.

// Callees.
u32 func_00139d78(u32);
void func_00138c10(u32, u32);
u32 func_00139510(u32);
u32 func_00102788(u32, u32, u32, u32);
f32 func_0017ce10(f32);
u32 func_0013ef90(u32);

extern u8 D_00330000;
extern u8 D_00350000;

// FUN_0013efe8 (56 bytes).
// Code: clears one byte at 0x348700 (D_00350000 - 30976). Then tail-calls
// func_00102788(word at 0x32B96C, 0, 0x493E0, func_0013EF90), with the callee address in a3.
// Guess: a reset of one flag byte, then a registration call with a fixed record and a handler.
u32 func_0013efe8(void) {
    *(u8*)((u32)&D_00350000 - 30976u) = 0;
    return func_00102788(*(u32*)((u32)&D_00330000 - 18068u), 0, 0x000493E0u, (u32)func_0013ef90);
}

// FUN_0013f608 (60 bytes).
// Code: f = word(a0+52) as a float. Store f at a0+164. Store the float at a0+48 into a0+160.
// Then call func_0017ce10(f) and store its result (in $f0) at a0+164.
// Guess: a float helper that filters a value at +48 through a routine and keeps the result at +164.
void func_0013f608(u32 a0) {
    u8* p = (u8*)a0;
    f32 f = *(f32*)(p + 52);
    *(f32*)(p + 164) = f;
    *(f32*)(p + 160) = *(f32*)(p + 48);
    *(f32*)(p + 164) = func_0017ce10(f);
}
