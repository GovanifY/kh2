#include "../common/types.h"

// 128-bit value as one lq/sq pair (GCC mode TI).
typedef int u128 __attribute__((mode(TI)));

extern u8 D_0034a9a0[];
extern u8 D_004f3800[];
extern f32 D_004f5268[];
extern f32 D_004f526c[];
extern f32 D_004f5270[];

// FUN_00158920 (32 bytes)
// Code: d = &D_0034a9a0; if (a0 != d) { copy 16 bytes from a0 to d }. Returns nothing.
// Guess: copies a 16-byte vector into a fixed global slot unless it is already there.
// Note: d is pinned to $15 (t7). The copy is one lq/sq pair in asm with temp $8 (t0),
//       because gcc picks t6 for the temp otherwise. The branch stays in C, so the
//       beq and its nop delay slot come from gcc.
void func_00158920(u128* a0) {
    register u128* d asm("$15") = (u128*)D_0034a9a0;
    asm("" : "+r"(d));
    if (a0 != d) {
        asm volatile("lq $8, 0(%0)\n\tsq $8, 0(%1)" : : "r"(a0), "r"(d) : "$8", "memory");
    }
}

// FUN_0015cea0 (24 bytes)
// Code: copies the 16-byte vector at D_004f3800 to a0, then returns a0.
// Guess: loads a fixed 16-byte constant into the caller's vector (returns the destination).
// Note: the lq/sq pair is in asm with temp $8 (t0), so the sq sits before jr ra and
//       move v0,a0 lands in the delay slot. Source address is an address-barrier
//       variable, so gcc emits lui + addiu as in the original.
u128* func_0015cea0(u128* a0) {
    u128* s = (u128*)D_004f3800;
    asm("" : "+r"(s));
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(a0), "r"(s) : "$8", "memory");
    return a0;
}

// FUN_00167638 (28 bytes)
// Code: stores f12, f13 and f14 to three consecutive float globals at 0x4f5268, 0x4f526c,
//       0x4f5270 (the last store in the jr delay slot).
// Guess: writes three float parameters to a fixed three-float state block.
// Note: three separate extern arrays make gcc emit one lui per store, as the original does.
void func_00167638(f32 a, f32 b, f32 c) {
    D_004f5268[0] = a;
    D_004f526c[0] = b;
    D_004f5270[0] = c;
}
