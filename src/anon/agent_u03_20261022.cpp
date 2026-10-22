#include "../common/types.h"

// FUN_00155658 (100 bytes)
// Code: reads the float from FUN_00166d38(a0->52) and keeps it in f20. Then
// calls FUN_00166d10(a0->36, (a0->52->1164)->4) for a float, and calls
// FUN_00154cd0(a0, 1, that float). Finally tail-calls FUN_00154cd0(a0, 2, f20).
// Guess: two per-channel updates of a float from an object's sub-record.
// The two loads through a0->52 are pinned to t7/t6 so the register encoding
// matches the original (gcc otherwise picks t6 then t7).
f32 func_00166d38(u32);
f32 func_00166d10(u32, u32);
void func_00154cd0(u32, u32, f32);

void func_00155658(u32 a0) {
    u32 s0 = a0;
    f32 f20 = func_00166d38(*(u32*)(a0 + 52));
    register u32 t7 asm("$15") = *(u32*)(s0 + 52);
    register u32 t6 asm("$14") = *(u32*)(t7 + 1164);
    f32 f0 = func_00166d10(*(u32*)(s0 + 36), *(u32*)(t6 + 4));
    func_00154cd0(s0, 1, f0);
    return func_00154cd0(s0, 2, f20);
}

// FUN_00157160 (92 bytes)
// Code: p = FUN_0017df58(0). If p is non-null and (p->1416 & 0x00400000) is
// set, calls FUN_001574a0(a0->4) and tail-calls FUN_001024a8(a0). Otherwise
// returns.
// Guess: a flag-gated cleanup for an object owned through a global lookup.
// The mask is kept in t6 (lui) and the field load in t7, as in the original.
u32 func_0017df58(u32);
void func_001574a0(u32);
void func_001024a8(u32);

void func_00157160(u32 a0) {
    u32 s0 = a0;
    u32 p = func_0017df58(0);
    if (p == 0) {
        return;
    }
    register u32 t6 asm("$14") = 0x00400000;
    register u32 t7 asm("$15") = *(u32*)(p + 1416);
    t7 = t7 & t6;
    if (t7 == 0) {
        return;
    }
    func_001574a0(*(u32*)(s0 + 4));
    return func_001024a8(s0);
}

// FUN_00157990 (108 bytes)
// Code: p = a0->52. cur = a0->40 and v = *(p->1164) (both signed words).
// If cur != v: a0->36 = max(cur, v) (cur < v stores v, otherwise cur), then
// a0->40 = v. Then calls FUN_00138c10(a0 + 7528, 126) and tail-calls
// FUN_00138c10(a0 + 8764, 127). If cur == v, returns.
// Guess: a "latest value" update that refreshes two sub-systems.
// The volatile-free barrier after the cur < v store stops gcc from merging the
// two stores into a movn; it is an empty asm with a memory clobber and emits
// no instruction. p is pinned to t6, the chained load to t7, and cur to t5.
void func_00138c10(u32, u32);

void func_00157990(u32 a0) {
    u32 s0 = a0;
    register u32 p asm("$14") = *(u32*)(a0 + 52);
    register u32 q asm("$15") = *(u32*)(p + 1164);
    register s32 cur asm("$13") = *(s32*)(a0 + 40);
    register s32 v asm("$15") = *(s32*)q;
    if (cur != v) {
        if (cur < v) {
            *(s32*)(a0 + 36) = v;
            asm volatile("" ::: "memory");
        } else {
            *(s32*)(a0 + 36) = cur;
        }
        *(s32*)(s0 + 40) = v;
        func_00138c10(s0 + 7528, 126);
        return func_00138c10(s0 + 8764, 127);
    }
}
