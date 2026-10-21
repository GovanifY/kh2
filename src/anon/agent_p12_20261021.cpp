#include "../common/types.h"

// Callees.
// func_0011ac10 is the start of FUN_0011ac10 (1064 bytes, not yet decompiled). Called with the
// object pointer; the return value is unused.
// func_00106a60 is registered; called with 1, returns a pointer to a record.
// _ZN2kn6Friend13getPartyCharaEi (0x00111e38) takes an int in a0 and returns a word.
// _ZN2YS3OBJ7set_dirERKN2kn7FVectorE (0x0016aef0) takes this and a pointer to a 4-float vector.
extern "C" void func_0011ac10(u32 a0);
extern "C" u32 func_00106a60(u32 a0);
u32 Friend_getPartyChara(u32 a0) asm("_ZN2kn6Friend13getPartyCharaEi");
void OBJ_set_dir(u32 self, u32 vec) asm("_ZN2YS3OBJ7set_dirERKN2kn7FVectorE");

// FUN_0011b038 (108 bytes; the object is built with -falign-functions=1 because the size is not a
// multiple of 8 and the default alignment adds a trailing nop).
// Code: s1 = getPartyChara(0); func_0011ac10(a0); p = func_00106a60(1);
// builds a 4-float vector on the stack {p->f24, 0.0, p->f56, 0.0} and calls set_dir(s1, &vec).
// Guess: copies two floats from a record into a vector and applies it to a party member object.
// Tricks: f2/f1/f0 and $4/$5 are pinned so the loads, the mtc1 zero and the argument moves keep
// the original order; an empty asm "+f" after the first load keeps lwc1 f2 ahead of lwc1 f1; an
// asm "memory" barrier makes the last store (vec[1]) the call delay slot.
void func_0011b038(u32 a0) {
    u32 s1 = Friend_getPartyChara(0);
    func_0011ac10(a0);
    u8* p = (u8*)func_00106a60(1);
    register f32 z asm("$f2") = *(f32*)(p + 56);
    asm volatile("" : "+f"(z));
    register u32 self asm("$4") = s1;
    asm volatile("" : "+r"(self));
    register f32 x asm("$f1") = *(f32*)(p + 24);
    f32 vec[4];
    register u32 pv asm("$5") = (u32)vec;
    asm volatile("" : "+r"(pv));
    register f32 zero asm("$f0");
    asm volatile("mtc1 $0,%0" : "=f"(zero));
    vec[0] = x;
    vec[2] = z;
    vec[3] = zero;
    asm volatile("" ::: "memory");
    vec[1] = zero;
    OBJ_set_dir(self, pv);
}

// FUN_0011c798 (48 bytes)
// Code: p = a0->+20; calls the virtual slot at byte offset 52 of p's vtable as
// f(p, a0->+260, a1) and returns its result (no return-value move, v0 passes through).
// Guess: forwards an argument through a virtual method of a sub-object.
// Tricks: the object, vtable and function pointer are pinned to t5, t6 and t7 to match the original.
u32 func_0011c798(u32 a0, u32 a1) {
    register u8* p asm("$13") = *(u8**)(a0 + 20);
    register void** vt asm("$14") = *(void***)p;
    register u32 (*fn)(u8*, u32, u32) asm("$15") = (u32 (*)(u8*, u32, u32))vt[13];
    return fn(p, *(u32*)(a0 + 260), a1);
}

// FUN_0011c7c8 (48 bytes)
// Same shape as FUN_0011c798, but the virtual slot is at byte offset 60 (vtable index 15).
u32 func_0011c7c8(u32 a0, u32 a1) {
    register u8* p asm("$13") = *(u8**)(a0 + 20);
    register void** vt asm("$14") = *(void***)p;
    register u32 (*fn)(u8*, u32, u32) asm("$15") = (u32 (*)(u8*, u32, u32))vt[15];
    return fn(p, *(u32*)(a0 + 260), a1);
}
