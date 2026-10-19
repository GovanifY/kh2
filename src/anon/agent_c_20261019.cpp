#include "../common/types.h"

// Agent C: small leaf functions decompiled from SLPM_666.75.
// Each comment says what the code does, then gives a guess at its role.
// The guesses are unverified.

// FUN_00177a58 (28 bytes)
// Code: loads the byte at arg0+2820. If it is nonzero, stores the byte minus 1
// back to the same place. The store sits in a branch-likely delay slot, so it
// runs only on the taken path. Returns void.
// Guess: a saturating countdown byte, such as a timer or a remaining-hits counter.
void func_00177a58(u8* a0) {
    u8* p = a0 + 2820;
    if (*p) {
        *p = *p - 1;
    }
}

// FUN_001d1678 (28 bytes)
// Code: stores arg1 at arg0+16, 1 at arg0+12, and 0 at arg0+4, arg0+24 and
// arg0+40. Returns void.
// Guess: an init routine that sets a status word to 1, stores a parameter, and
// clears several fields of the object.
void func_001d1678(u8* a0, u32 a1) {
    *(u32*)(a0 + 16) = a1;
    *(u32*)(a0 + 12) = 1;
    *(u32*)(a0 + 4) = 0;
    *(u32*)(a0 + 24) = 0;
    *(u32*)(a0 + 40) = 0;
}

// FUN_001de4b0 (88 bytes)
// Code: walks a singly linked list that starts at arg0+12 and follows the link at
// +96. An entry matches when arg1 < 0 (any entry) or when the byte at entry+68
// plus 4 equals arg1. On a match: if arg2 is 0, the function returns entry+64.
// Otherwise it returns entry+64 if a flag is already set. If not, it sets the
// flag to (entry+64 == arg2) and keeps walking. Returns 0 when the list ends.
// Guess: a lookup by id in a list of objects, with a second check on a stored
// value.
u32 func_001de4b0(u8* a0, s32 a1, u32 a2) {
    u8* v0 = *(u8**)(a0 + 12);
    u32 t4 = 0;
    while (v0 != 0) {
        u8* next = *(u8**)(v0 + 96);
        if (a1 < 0 || ((u8*)*(u32*)(v0 + 68))[4] == a1) {
            if (a2 == 0) {
                return *(u32*)(v0 + 64);
            }
            if (t4 != 0) {
                return *(u32*)(v0 + 64);
            }
            t4 = ((*(u32*)(v0 + 64) ^ a2) == 0);
        }
        v0 = next;
    }
    return 0;
}

// FUN_00163268 (84 bytes)
// Code: VU0 vector math. Loads two 4-float vectors from arg0 and arg1, subtracts
// them, and stores the result through a stack temp. Squares the x, y and z
// components and adds them, then takes the square root (vsqrt). Stores the
// length as a float at arg2. Compares the length to the float at arg0+16 and
// returns 1 if length <= that value, else 0.
// Guess: a distance check between two points against a radius stored at +16 of
// the first object.
u32 func_00163268(u8* a0, u8* a1, f32* a2) {
    u32 tmp[4] __attribute__((aligned(16)));
    register u32 r asm("$2");
    __asm__ volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1,0(%2)\n\t"
        "lqc2 $vf2,0(%3)\n\t"
        "vsub.wxyz $vf1,$vf1,$vf2\n\t"
        "sqc2 $vf1,%0\n\t"
        "lqc2 $vf1,%0\n\t"
        "vmul.xyz $vf1,$vf1,$vf1\n\t"
        "vaddy.x $vf1,$vf1,$vf1y\n\t"
        "vaddz.x $vf1,$vf1,$vf1z\n\t"
        "vsqrt Q,$vf1x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8,$22\n\t"
        "mtc1 $8,$f1\n\t"
        "swc1 $f1,0(%4)\n\t"
        "lwc1 $f0,16(%2)\n\t"
        "c.le.s $f1,$f0\n\t"
        "bc1t 1f\n\t"
        "li $2,1\n\t"
        "move $2,$0\n\t"
        "1:\n\t"
        ".set reorder\n\t"
        : "=m"(tmp), "=r"(r)
        : "r"(a0), "r"(a1), "r"(a2)
        : "$8", "$f0", "$f1", "memory");
    return r;
}
