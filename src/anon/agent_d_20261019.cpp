#include "../common/types.h"

// FUN_00225298 (24 bytes)
// Code: Builds the address 0x01DAD910 via lui 0x1DB plus a -9968 offset. Stores
// 0xFFFFFFFF to that word, computes the pointer again (addiu) and stores
// 0xFFFFFFFF to the word at +4. Then returns.
// Guess: resets a pair of 32-bit sentinel/flag words (both set to -1) in an EE
// RAM status block.
void func_00225298(void) {
    u32 b;
    __asm__("lui %0, 0x1db" : "=r"(b));
    *(volatile u32*)(b - 9968) = 0xFFFFFFFFu;
    u32 q;
    __asm__ volatile("addiu %0, %1, -9968" : "=r"(q) : "r"(b));
    __asm__ volatile("" : : "r"(b));
    *(volatile u32*)(q + 4) = 0xFFFFFFFFu;
}

// FUN_00207260 (68 bytes)
// Code: VU0 pseudo-random number. Sets t0 = -1 and moves it into vf2. Runs five
// vrxor/vrnext.x pairs to advance the VU R register and produce a value in vf1.
// Converts vf2 to float (vitof0.x), adds it into vf1 (vadd.x), moves the result
// bits to t7 (qmfc2) and returns them as a float in $f0.
// Guess: returns a random float in the range of the -1 seed pattern, used by a
// random-number helper for effects or AI.
f32 func_00207260(void) {
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

// FUN_00101d38 (20 bytes)
// Code: Opens a 16-byte stack frame, saves and reloads ra (sd/ld at 0(sp)), then
// pops the frame and returns. No work is done otherwise.
// Guess: an empty stub or hook left over from a call site that was removed; the
// frame exists only to keep ra saved.
void func_00101d38(void) {
    __asm__ volatile("" ::: "$31");
    __builtin_return_address(0);
}
