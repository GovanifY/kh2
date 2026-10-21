#include "../common/types.h"

u32 func_00139d78(u32 a0);
void func_00138c10(u32 a0, u32 a1);
void func_00139510(u32 a0);
void func_0013e2d8(u32 a0, u32 a1, u32 a2);
void func_0013e610(u32 a0);
extern u8 D_00350000[];

// Agent S24 (2026-10-21): three functions from SLPM_666.75, one of them not byte-exact yet.
// Each comment says what the code does, then gives a guess at its role.
// The guesses are unverified.

// FUN_0013e4b8 (104 bytes)
// Code: s0 = a0, s1 = a0 + 448. If func_00139d78(a0) is zero, return. Otherwise call
// func_00138c10(s0, s0->+388 - 1). Then if func_00139d78(s1) is zero, return. Otherwise
// tail-call func_00139510(s1).
// Guess: a two-step "try, then update, then finish" routine on an object and its sub-object at +448.
// Tricks: the first call takes a0 directly, which keeps the original argument order.
// The asm barrier on s0 stops GCC from computing s1 from the copy, so the addiu uses a0 in the
// jal delay slot, as in the original.
void func_0013e4b8(u32 a0) {
    u32 s1 = a0 + 448;
    u32 s0 = a0;
    asm volatile("" : "+r"(s0));
    if (func_00139d78(a0) == 0) {
        return;
    }
    func_00138c10(s0, *(u32*)(s0 + 388) - 1);
    if (func_00139d78(s1) == 0) {
        return;
    }
    func_00139510(s1);
}

// FUN_0013e5a8 (100 bytes; this object is built with -falign-functions=1 because 100 is not a
// multiple of 8)
// Code: s0 = a0, s1 = a0 + 448. If func_00139d78(a0) is non-zero, call the virtual slot at +20
// of the object at s0. If func_00139d78(s1) is non-zero, call func_00139510(s1). Then tail-call
// func_0013e610(*(s0 + 436)).
// Guess: a "run the object's step, then the sub-object's step, then queue the next item" routine.
// Tricks: as in FUN_0013e4b8, the barrier on s0 keeps s1 computed from a0. The final tail call
// is a void call, so GCC emits a direct `j`.
void func_0013e5a8(u32 a0) {
    u32 s1 = a0 + 448;
    u32 s0 = a0;
    asm volatile("" : "+r"(s0));
    if (func_00139d78(a0) != 0) {
        ((void (*)(u32))(*(u32*)(*(u32*)s0 + 20)))(s0);
    }
    if (func_00139d78(s1) != 0) {
        func_00139510(s1);
    }
    func_0013e610(*(u32*)(s0 + 436));
}

