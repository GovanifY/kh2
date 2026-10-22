#include "../common/types.h"

// Agent W02 (2026-10-22): FUN_001659b8, FUN_001675b0, FUN_00167b60 (SLPM_666.75).
// Each comment says what the code does, then how it matches.

// Callees and data (declared so the registry aliases resolve).
extern "C" void func_001656d0(u32, u32, u32);   // (ptr, a, b) worker, not in C
extern "C" void func_00167638(f32, f32, f32);   // stores three float params to globals (cxx)
extern "C" void func_00167b98(void);            // no-arg helper, not in C
extern "C" void func_00167c30(void);            // no-arg helper, not in C
extern "C" void func_001678f0(u32);            // one-arg helper, not in C
extern "C" u32 func_00102788(u32, u32, u32, u32); // registration call, tail target
extern "C" u32 func_00167618(u32, u32, u32, u32); // registered cxx function, used as an address

// Data bases. Each access is written as base[-offset] so gcc emits lui plus a
// negative lw/lwc1 offset, as the original does.
extern u32 D_0034c7a0;
extern u8 D_00330000[];
extern u8 D_00350000[];
extern u8 D_00370000[];

// FUN_001659b8 (88 bytes).
// Code: s0 = word at 0x34c7a0 (a pool object). Decrements the word at s0+1280 and stores it.
// Uses the new count t as an index: t15 = word at s0+1024+4*t, then s0 += t15 << 4.
// Calls func_001656d0(s0, a0, a1), then returns the new s0.
// Guess: pops one entry from a free list and hands it to an init routine.
u32 func_001659b8(u32 a0, u32 a1) {
    register u32 r15 asm("$15");   // t7: the count, then the loaded entry index
    register u32 r14 asm("$14");   // t6: the table address
    u32 s0 = D_0034c7a0;
    r15 = *(u32*)(s0 + 1280) - 1;
    *(u32*)(s0 + 1280) = r15;
    r14 = (r15 << 2);
    r14 = r14 + s0;
    r15 = *(u32*)(r14 + 1024);
    s0 = s0 + (r15 << 4);
    func_001656d0(s0, a0, a1);
    return s0;
}

// FUN_001675b0 (104 bytes).
// Code: loads three floats from 0x36b610, 0x36b614, 0x36b618 into f12, f13, f14, and calls
// func_00167638 with them. Then calls func_00167b98 and func_00167c30. Last, tail-calls
// func_00102788(word at 0x32b91c, 0, 0x1adb0, func_00167618).
// Guess: a setup step that registers a handler with a float triple, then a fixed record.
u32 func_001675b0() {
    register u8* p asm("$15");
    p = &D_00370000[-18928];
    __asm__("" : "+r"(p));
    f32 f12 = *(f32*)p;
    __asm__ volatile("lui %0,%%hi(D_00370000-18924)" : "=r"(p));
    __asm__ volatile("addiu %0,%0,%%lo(D_00370000-18924)" : "+r"(p));
    f32 f13 = *(f32*)p;
    __asm__ volatile("lui %0,%%hi(D_00370000-18920)" : "=r"(p));
    __asm__ volatile("addiu %0,%0,%%lo(D_00370000-18920)" : "+r"(p));
    f32 f14 = *(f32*)p;
    func_00167638(f12, f13, f14);
    func_00167b98();
    func_00167c30();
    return func_00102788(*(u32*)&D_00330000[-18148], 0, 0x0001adb0u, (u32)func_00167618);
}

// FUN_00167b60 (56 bytes).
// Code: s0 = 0x34d3c0 (D_00350000 - 11328). Calls func_001678f0(s0), then s0 += 384 and calls
// func_001678f0(s0) again. Returns nothing.
// Guess: runs one helper on two adjacent 384-byte records.
void func_00167b60() {
    u8* s = &D_00350000[-11328];
    func_001678f0((u32)s);
    s += 384;
    func_001678f0((u32)s);
    __asm__ volatile("" ::: "memory");
}
