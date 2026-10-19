#include "../common/types.h"

// Agent A: small leaf functions decompiled from SLPM_666.75.
// Each comment says what the code does, then gives a guess at its role.
// The guesses are unverified. They're there to help place the function later.

extern u8 D_00350000;
extern u8 D_00360000;

// FUN_001ddc08 (60 bytes)
// Code: loads a pointer from 0x352AE0 (D_00350000 + 10976). While the pointer
// is non-null, ORs 0x04000000 into the word at node+8, then follows the pointer
// at node+40 to the next node. Returns void.
// Guess: sets one flag bit on every node of a linked list whose head is kept in
// a global. The bit may mean "dirty" or "visible".
void func_001ddc08(void) {
    u32 p = *(u32*)((u32)&D_00350000 + 10976u);
    while (p != 0) {
        *(u32*)(p + 8) |= 0x04000000u;
        p = *(u32*)(p + 40);
    }
}

// FUN_001db850 (56 bytes)
// Code: n = a0->s32 at +24. Loops i from 0 while i < n (n is re-read each pass):
// writes i into element i of the s32 array whose pointer is at a0+16. The array
// pointer is re-read on each pass too. After the loop, stores n into a0+8.
// Guess: fills an index table of the object's count. The count is also copied
// into a0+8 as a cached size.
void func_001db850(u8* a0) {
    s32 i = 0;
    while (i < *(s32*)(a0 + 24)) {
        *(s32*)(*(u32*)(a0 + 16) + i * 4) = i;
        i++;
    }
    *(s32*)(a0 + 8) = *(s32*)(a0 + 24);
}

// FUN_0027ae78 (92 bytes)
// Code: loads a pointer from 0x35F230 (D_00350000 + 62000) and reads the s16 at
// that pointer (h). Loops i from 0 to 7, skipping i == 6. Bits of h are tested
// from bit 0 upward. When bit i is set, if a0 == count the function returns i,
// otherwise count is incremented. If the loop finishes, returns 8.
// Guess: finds the index of the (a0+1)th set bit in an 8-bit mask, where bit 6
// is reserved. The mask is probably a per-slot flag halfword.
s32 func_0027ae78(s32 a0) {
    s16* p = *(s16**)((u32)&D_00350000 + 62000u);
    s32 count = 0;
    s32 i;
    for (i = 0; i < 8; i++) {
        u8 f;
        if (i == 6) {
            continue;
        }
        f = !((*p >> i) & 1);
        if (f) {
            continue;
        }
        if (a0 == count) {
            return i;
        }
        count++;
    }
    return i;
}

// FUN_002eac70 (36 bytes)
// Code: stores the four float arguments f12..f15 into the 0x36xxxx region at
// offsets 13376, 13384, 13388 and 13392 (0x363440, 0x363448, 0x36344C, 0x363450).
// Guess: stores four float parameters into a global settings block. The gap
// between the first two offsets suggests a struct with padding or a vec4 layout.
void func_002eac70(f32 a0, f32 a1, f32 a2, f32 a3) {
    *(f32*)((u32)&D_00360000 + 13376u) = a0;
    *(f32*)((u32)&D_00360000 + 13384u) = a1;
    *(f32*)((u32)&D_00360000 + 13388u) = a2;
    *(f32*)((u32)&D_00360000 + 13392u) = a3;
}
