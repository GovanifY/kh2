#include "../common/types.h"

// Agent S27 (2026-10-21): three functions from SLPM_666.75, decompiled byte-exact.
// Each comment says what the code does, then gives a guess at its role.
// The guesses are unverified.

extern "C" u32 func_00141080(f32);
u32 func_001ad990(u32, f32, f32, f32);
extern "C" u32 func_00141778(u32, u32);
extern "C" u32 func_00147050(u32, u32, u32, u32, u32);
extern u8 D_00350000[];
extern u8 D_00370000[];

// FUN_00141010 (96 bytes)
// Code: r = FUN_00141080(a), passing the float through (a is also kept in $f20 for later).
// If r is 0, return 0. Otherwise let obj = D_00350000 - 30960. If the word at obj+68 is
// null, return r. Else call FUN_001ad990(p + 2100, 0.0f, float constant at D_00370000 -
// 20864, a), clear the word at obj+64, and return the callee's result.
// Guess: a timed reset of an object's pending value, called once per frame with a float.
// Tricks: `q` is pinned to $4 and computed before the null test, so the addiu fills the
// beqz delay slot. The float regs are pinned ($f12, $f13, $f14) and the constant address
// goes through an empty "+r" barrier so gcc emits lui+addiu. A barrier after the first
// float move keeps the mov.s before the constant load.
u32 func_00141010(f32 a) {
    u32 r;
    u8* obj;
    register u32 p asm("$14");
    register u32 q asm("$4");
    register f32 z asm("$f12");
    register f32 fa asm("$f14");
    register f32 cst asm("$f13");
    u8* kp;
    r = func_00141080(a);
    if (r == 0) goto done;
    obj = &D_00350000[-30960];
    p = *(u32*)(obj + 68);
    q = p + 2100;
    if (p == 0) goto done;
    fa = a;
    asm volatile("" : "+f"(fa));
    kp = &D_00370000[-20864];
    asm volatile("" : "+r"(kp));
    z = 0.0f;
    asm volatile("" : "+f"(z));
    cst = *(f32*)kp;
    r = func_001ad990(q, z, cst, fa);
    *(u32*)(obj + 64) = 0;
done:
    return r;
}

// FUN_00143348 (76 bytes)
// Code: calls FUN_00147050(word at D_00350000 - 30720, 0, obj, 0, &tmp), where tmp is a
// zeroed 4-byte local. Then stores the return value as a halfword at obj+280, and the halfword
// that the callee wrote to tmp at obj+282.
// Guess: a query that fills two 16-bit result fields of an object from a global handle.
// Tricks: the local is a u32 zeroed up front and read back as a u16 (big-endian, so the
// halfword written by the callee is the high one). The global is loaded through a symbol so
// gcc folds the -30720 offset into lw.
void func_00143348(u8* a0) {
    u32 tmp = 0;
    u32 r;
    r = func_00147050(*(u32*)&D_00350000[-30720], 0, (u32)a0, 0, (u32)&tmp);
    *(u16*)(a0 + 280) = (u16)r;
    *(u16*)(a0 + 282) = *(u16*)&tmp;
}

// FUN_00143448 (36 bytes)
// Code: return FUN_00141778(word at D_00350000 - 30716, (u16)arg0). This is a real call (not a
// tail jump), so it keeps its own frame and restores ra after the call.
// Guess: a lookup that takes a 16-bit id and a fixed global handle.
// Tricks: the empty "+r" barrier on the return value stops gcc from making a sibling `j`.
u32 func_00143448(u32 a0) {
    u32 r = func_00141778(*(u32*)&D_00350000[-30716], (u16)a0);
    asm volatile("" : "+r"(r));
    return r;
}
