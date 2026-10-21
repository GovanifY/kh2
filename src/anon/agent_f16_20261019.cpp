#include "../common/types.h"

// Agent F16: three small leaf functions decompiled from SLPM_666.75.
// Each comment says what the code does. Guesses about the role are unverified.

extern u8 D_00350000[];
extern u8 D_00370000[];

// FUN_0014ca20 (20 bytes).
// Code: loads the word at D_00350000-25096 as the return value, then stores
// zero to the word at D_00350000-25092. The two lui's and the store-in-delay-slot
// shape come out of plain C with the two offsets folded into lw/sw immediates.
// Guess: takes a pending value out of a two-word slot in the global block and
// clears it.
u32 func_0014ca20(void) {
    u32 v = *(u32*)&D_00350000[-25096];
    *(u32*)&D_00350000[-25092] = 0;
    return v;
}

// FUN_0014ce60 (24 bytes).
// Code: loads a float from the address D_00370000-20244 (an addiu, not folded
// into the lwc1) and stores it at D_00350000-25076 (folded into the swc1).
// The address is pinned to t7 ($15), and an empty "+r" asm keeps it as a
// separate value so gcc emits lui/addiu/lwc1 and reuses t7 for the store base.
// Guess: copies one float from a constant-table entry into a global.
void func_0014ce60(void) {
    register u32 pa asm("$15");
    pa = (u32)&D_00370000[-20244];
    __asm__("" : "+r"(pa));
    *(f32*)&D_00350000[-25076] = *(f32*)pa;
}

// FUN_00152598 (28 bytes).
// Code: t = (a1 << 3) + a3. Returns the word at t+4 when a2 is non-zero, and
// the word at t+0 otherwise. The pinned temp is $15 (t7), and the empty "+r"
// asm between the steps keeps gcc from folding the shift into the address add.
// The "if (a2 == 0) return p[0]" form gives the bnez fallthrough shape.
// Guess: picks one half of an 8-byte entry in a table indexed by a1, with a
// base in a3 and a selector in a2.
u32 func_00152598(u32 a0, u32 a1, u32 a2, u32 a3) {
    register u32 t asm("$15");
    t = a1 << 3;
    __asm__("" : "+r"(t));
    t = t + a3;
    __asm__("" : "+r"(t));
    if (a2 == 0) {
        return ((u32*)t)[0];
    }
    return ((u32*)t)[1];
}
