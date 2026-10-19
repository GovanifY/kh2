#include "../common/types.h"

// FUN_002e9b10 (72 bytes)
// Code: byte counter with wrap. t = byte[4] + 1, stored to byte[4]. If (u8)t < s32 at
//       offset 0, return. Otherwise loop: v = t - byte[0] (reloaded each pass) until
//       (u8)v < s32 at offset 0, then store v to byte[4].
// Guess: the loop-carried value is t6 and the temp is t5. Plain C gave the swapped
//        allocation, so both are pinned with GCC local register variables (no asm).
void func_002e9b10(u8* a0) {
    register s32 v asm("$13");
    s32 d = a0[4];
    s32 s = *(s32*)a0;
    s32 t = d + 1;
    a0[4] = (u8)t;
    if (((u8)t) < s) return;
    for (;;) {
        v = t - a0[0];
        if (((u8)v) < s) { a0[4] = (u8)v; return; }
        t = v;
    }
}

// FUN_0028b120 (64 bytes)
// Code: numerator n = a3, or (s16)a0[0] + (s16)a0[18] when a3 < 0. *a1 = n % (s16)a0[24]
//       (checked division). Then *a2 = n / (s16)a0[24] with the divisor reloaded and no
//       zero check in the original.
// Guess: the second division is inline asm (div + mflo, no zero check), so the compiler
//        cannot add the trap. An empty asm memory barrier forces the divisor reload.
//        Register variables pin the divisor to t7 and the quotient to t6.
void func_0028b120(u8* a0, s32* a1, s32* a2, s32 a3) {
    s32 n = a3;
    if (n < 0) n = *(s16*)a0 + *(s16*)(a0 + 18);
    *a1 = n % *(s16*)(a0 + 24);
    asm volatile("" ::: "memory");
    register s32 d asm("$15");
    d = *(s16*)(a0 + 24);
    register s32 q asm("$14");
    asm volatile("div $0, %1, %2\n\tmflo %0" : "=r"(q) : "r"(n), "r"(d));
    *a2 = q;
}
