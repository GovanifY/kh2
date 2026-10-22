#include "../common/types.h"

// Agent V01 (2026-10-22): FUN_00159f90, FUN_0015a118, FUN_0015aa98 (SLPM_666.75).
// Each comment says what the code does, then the matching notes.

// Callees.
extern "C" f32 func_0015a098(u32);      // returns a float in $f0 (address only, FUN_0015a098)
extern "C" f32 func_0017ce10(f32);      // YS::MATH::FixRadian(float), float in and out
extern "C" void func_001391c8(u32, u32, u32);  // dk::Obj2D::create

extern u8 D_00350000[];   // base for the float global at 0x34aa44 (D_0034aa44)
extern u8 D_00370000[];   // read-only float table, offsets -19584 and -19580 used

// FUN_00159f90 (64 bytes).
// Code: clears the float global at 0x34aa44. If bit 2 of a1 is set, loads the float at
// 0x36b380 into the global. Otherwise, if bit 3 of a1 is set, loads the float at 0x36b384.
// Otherwise the global stays 0. Returns 1 in every case.
// Matching: the zero store is written as an asm sw with a %lo(D_0034aa44) reloc so it can
// sit in the beqz delay slot. The lui of the global base is a volatile asm, and the andi
// pair is placed after it. The two table pointers are asm lui/addiu pairs pinned to $15,
// and the shared lwc1 and swc1 tail is one block. Needs no per-object flags.
u32 func_00159f90(u32 a0, u32 a1) {
    (void)a0;
    register u8* b asm("$14");
    register u32 t7 asm("$15");
    register u8* p asm("$15");
    register f32 v asm("$f0");
    asm volatile("lui %0,%%hi(D_0034aa44)" : "=r"(b));
    t7 = a1 & 8u;
    a1 = a1 & 4u;
    asm volatile("sw $0,%%lo(D_0034aa44)(%0)" : : "r"(b) : "memory");
    if (a1 == 0u) goto other;
    asm volatile("lui %0,%%hi(D_00370000-19584)\n\taddiu %0,%0,%%lo(D_00370000-19584)" : "=r"(p));
    goto load;
other:
    if (t7 == 0u) return 1;
    asm volatile("lui %0,%%hi(D_00370000-19580)\n\taddiu %0,%0,%%lo(D_00370000-19580)" : "=r"(p));
load:
    asm volatile("" : : "r"(p));
    v = *(f32*)p;
    asm volatile("swc1 %1,%%lo(D_0034aa44)(%0)" : : "r"(b), "f"(v) : "memory");
    return 1;
}

