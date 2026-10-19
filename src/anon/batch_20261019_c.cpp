#include "../common/types.h"

// Batch 2026-10-19 C: small functions decompiled from SLPM_666.75.
// Each comment says what the code does, then gives a guess at its role.
// The guesses are unverified. They're there to help place the function later.

extern u8 D_00350000;
extern u8 D_00360000;

// Callees that already have registry names use the existing symbol.
extern "C" u32 func_0023aa18(u32) asm("_ZN2YI8SEQUENCE9GetParamXEv");
extern "C" u32 func_0023aa38(u32) asm("_ZN2YI8SEQUENCE9GetParamYEv");
extern "C" void func_00105110(u32) asm("_ZN4AREA4FreeEPv");
void func_0019f9a8(u32);
void func_001c0248(u32);
void func_00319fb0(u32);
void func_002cff98(u32);

// FUN_0028eab8 (68 bytes)
// Code: s0 = arg1 + 24. Stores GetParamX(s0) at arg0+36, then GetParamY(s0)
// at arg0+40.
// Guess: copies two parameters from a sub-object at +24 of arg1 into fields of
// arg0. The sub-object is probably a SEQUENCE, judging by the callee names.
void func_0028eab8(u8* a0, u8* a1) {
    u8* s0 = a1 + 24;
    *(u32*)(a0 + 36) = func_0023aa18((u32)s0);
    *(u32*)(a0 + 40) = func_0023aa38((u32)s0);
}

// FUN_001c8de0 (28 bytes)
// Code: writes zero to three 32-bit globals at 0x351ec8, 0x351ec0 and 0x351eb8.
// Guess: resets three state words in one block, in a single init routine.
void func_001c8de0(void) {
    *(u32*)((u32)&D_00350000 + 7864u) = 0;
    *(u32*)((u32)&D_00350000 + 7872u) = 0;
    *(u32*)((u32)&D_00350000 + 7880u) = 0;
}

// FUN_002ddb80 (52 bytes)
// Code: stores the vtable address 0x362b68 at arg0, calls FUN_002cff98(arg0),
// then tail-calls AREA::Free(arg0).
// Guess: the destructor of a C++ class that has a vtable at offset 0. It runs
// a base step, then frees the object.
void func_002ddb80(u8* a0) {
    *(u32*)a0 = (u32)&D_00360000 + 11112u;
    func_002cff98((u32)a0);
    return func_00105110((u32)a0);
}
