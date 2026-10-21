#include "../common/types.h"

// FUN_001e5fd8 (36 bytes)
// Code: sets bits 0x83 in the word at 0x10000010 (lw/ori/sw), then clears the word at
//       0x10000000 (lui t5 + sw $0).
// Guess: starts timer 0. 0x10000000 is the T0 counter and 0x10000010 is the T0 mode
//       register. The mode gets 0x83 (count enable plus clock select), and the counter
//       is reset to zero.
// Note: the zero store is an asm so GCC keeps it before the jr and leaves the nop in the
//       delay slot. The 36-byte size is not a multiple of 8, so this object is built with
//       -falign-functions=1 (see Makefile). Without it, the trailing padding nop shows up.
void func_001e5fd8(void) {
    register volatile u32* p asm("$15");
    register volatile u32* q asm("$13");
    __asm__ volatile("lui %0, 0x1000" : "=r"(p));
    __asm__ volatile("lui %0, 0x1000" : "=r"(q));
    __asm__ volatile("ori %0, %0, 0x10" : "+r"(p));
    *p = *p | 0x83u;
    __asm__ volatile("sw $0, 0(%0)\n\tnop" : : "r"(q) : "memory");
}

// FUN_001f0430 (44 bytes)
// Code: reads the float at +8 of arg0 and the float at +20 of arg0. Stores the first at
//       arg1 +4, arg0 (the pointer itself) at arg1 +0, and the second at arg1 +16. Then
//       writes 0.0f to arg1 +8, +24, +20 and +12.
// Guess: copies two float fields from a source object into a 28-byte record, storing the
//       source pointer in its first word and clearing the other fields.
// Note: the float zero is kept in $f0 from an asm mtc1 of $0, so the zero stores use swc1.
//       The x and y loads are pinned to $f1 and $f2. A memory barrier keeps the second
//       load before the pointer store.
void func_001f0430(u8* a0, u8* a1) {
    register f32 z asm("$f0");
    register f32 x asm("$f1");
    register f32 y asm("$f2");
    x = *(f32*)(a0 + 8);
    __asm__ volatile("mtc1 $0, %0" : "=f"(z));
    *(volatile f32*)(a1 + 4) = x;
    y = *(f32*)(a0 + 20);
    __asm__ volatile("" ::: "memory");
    *(u8* volatile*)(a1 + 0) = a0;
    *(volatile f32*)(a1 + 16) = y;
    *(volatile f32*)(a1 + 8) = z;
    *(volatile f32*)(a1 + 24) = z;
    *(volatile f32*)(a1 + 20) = z;
    *(volatile f32*)(a1 + 12) = z;
}

// FUN_00203a40 (68 bytes)
// Code: VU0 pseudo-random number. Sets t0 = -1 and moves it into vf2. Runs five
//       vrxor/vrnext.x pairs to advance the VU R register and produce a value in vf1.
//       Converts vf2 to float (vitof0.x), adds it into vf1 (vadd.x), moves the result
//       bits to t7 (qmfc2) and returns them as a float in $f0.
// Guess: a random float in [0, 1) (the VU0 random output is 1.x, minus the -1.0 seed).
//       It is the same routine as FUN_00207260 at another address.
// Note: the VU0 instructions are emitted as .word, since the assembler does not know them
//       in this build. The asm clobbers $8 (t0).
f32 func_00203a40(void) {
    register u32 r asm("$15");
    __asm__ volatile(
        "addi $8,$0,-1\n\t"
        ".word 0x48a81000\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4b02113c\n\t"
        ".word 0x4b020868\n\t"
        ".word 0x482f0800\n\t"
        : "=r"(r)
        :
        : "$8");
    union {
        u32 u;
        f32 f;
    } x;
    x.u = r;
    return x.f;
}
