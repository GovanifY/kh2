#include "../common/types.h"

// Data addresses used by the functions below. Declared as extern arrays so gcc
// emits paired HI16/LO16 relocations for the lui/addiu address build.
extern u8 D_00360000[];
extern u8 D_00370000[];

// FUN_002d8d40 (40 bytes)
// Code: loads a float constant k from D_00370000+23692. Stores (a0[472] + k) at *a1
// and (a0[468] - k) at *a2. Returns void.
// Guess: splits a pair of floats around a shared offset, two output slots.
// Notes: the address is built as a pointer and passed through an empty "+r" asm so that
// gcc keeps the addiu and does not fold 23692 into the lwc1 displacement.
void func_002d8d40(u8* a0, f32* a1, f32* a2) {
    u8* kp = &D_00370000[23692];
    asm("" : "+r"(kp));
    f32 k = *(f32*)kp;
    *a1 = *(f32*)(a0 + 472) + k;
    *a2 = *(f32*)(a0 + 468) - k;
}

// FUN_002ddbb8 (32 bytes)
// Code: p = word at a0+2808. If p is NULL, returns 0. Otherwise returns (halfword at p+18) & 1.
// Guess: reads a one-bit flag from an optional sub-object.
// Notes: the non-null path is the fall-through (beqz with a nop delay slot). Routing the
// halfword through a u32 local keeps the andi in the jr delay slot, with no extra andi.
s32 func_002ddbb8(u8* a0) {
    u8* p = *(u8**)(a0 + 2808);
    if (p != 0) {
        u32 v = *(u16*)(p + 18);
        return v & 1;
    }
    return 0;
}

// FUN_002dea00 (64 bytes)
// Code: stores the float argument b (f13) at +12, the word 30 at +4, the word -1 at +56,
// the word 256 at +8, and the float argument a (f12) at +20. Stores the vtable address
// 0x362d20 at +0. Loads a float constant from D_00370000+24112 and stores it at +16 (in the
// jr delay slot).
// Guess: constructor for an object with a vtable and a few initial fields.
// Notes:
//  - Register pins: 30 in t7 ($15), -1 in t6 ($14), 256 in t5 ($13), as in the original.
//  - The vtable address is split as a lui before the store to +8 and an addiu after it,
//    using %hi/%lo asm pieces (a single C expression gives lui + addiu 0 + addiu 11552).
//  - Empty memory barriers keep the store order.
void func_002dea00(u8* a0, f32 a, f32 b) {
    register u32 c30 asm("$15") = 30u;
    register s32 cm1 asm("$14") = -1;
    register u32 c256 asm("$13") = 256u;
    u32 vt;
    *(f32*)(a0 + 12) = b;
    *(u32*)(a0 + 4) = c30;
    asm volatile("" ::: "memory");
    *(s32*)(a0 + 56) = cm1;
    asm volatile("lui %0,%%hi(D_00360000+11552)" : "=r"(vt) :: "memory");
    *(u32*)(a0 + 8) = c256;
    asm volatile("addiu %0,%0,%%lo(D_00360000+11552)" : "+r"(vt) :: "memory");
    *(f32*)(a0 + 20) = a;
    asm volatile("" ::: "memory");
    *(u32*)a0 = vt;
    asm volatile("" ::: "memory");
    u8* fp = &D_00370000[24112];
    asm("" : "+r"(fp));
    *(f32*)(a0 + 16) = *(f32*)fp;
}
