#include "../common/types.h"

// Agent L11: leaf functions decompiled from SLPM_666.75.
// The pins (register asm) and empty asm barriers are there to get the same
// register use and instruction order as the original. They do not change behaviour.

extern u32 D_0033cae8[];

// FUN_002eff58 (56 bytes)
// Code: loads two floats at +272 and +276 of arg0, adds them, multiplies by a
// float constant at 0x376224 (D_00370000 + 25124), then returns 1 if the result is
// <= the float at +28 of arg0, else 0.
// Guess: a threshold test on a pair of values scaled by a constant.
int func_002eff58(u8* a0) {
    register float fa asm("$f1");
    register float fb asm("$f2");
    register float fc asm("$f3");
    // The base address is written as a literal 0x370000 so that the compiler
    // emits lui plus one addiu, as the original does.
    fa = *(float*)(a0 + 272);
    __asm__ volatile("" ::: "memory");
    u8* base = (u8*)0x00370000u;
    __asm__ volatile("" : "+r"(base));
    fb = *(float*)(a0 + 276);
    __asm__ volatile("" ::: "memory");
    float* kp = (float*)(base + 25124);
    __asm__ volatile("" : "+r"(kp));
    float fk = *kp;
    __asm__ volatile("" : "+f"(fk));
    fa = fa + fb;
    fc = *(float*)(a0 + 28);
    __asm__ volatile("" ::: "memory");
    fa = fa * fk;
    return fa <= fc;
}

// FUN_002f1ae0 (48 bytes)
// Code: index = arg0 >> 5. Loads the word at D_0033CAE8 + index*4, then returns 1
// if bit (arg0 & 31) of that word is set, else 0.
// Guess: a bitset lookup. The table at 0x33CAE8 holds 32 flags per word.
u32 func_002f1ae0(u32 a0) {
    register u32 idx asm("$14");
    idx = a0 >> 5;
    __asm__ volatile("" : "+r"(idx));
    u32 base = (u32)D_0033cae8;
    __asm__ volatile("" : "+r"(base));
    idx = idx << 2;
    __asm__ volatile("" : "+r"(idx));
    idx = idx + base;
    __asm__ volatile("" : "+r"(idx));
    u32 sh = a0 & 31;
    __asm__ volatile("" : "+r"(sh));
    u32 w = *(u32*)idx;
    __asm__ volatile("" : "+r"(w));
    u32 bit = 1u << sh;
    __asm__ volatile("" : "+r"(bit));
    return (w & bit) != 0;
}
