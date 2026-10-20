#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));
extern u8 D_004f0000;

// FUN_00162b68 (68 bytes)
// Code: dot = a0.xyz . a1.xyz (VU0) + float at a1+12; *a2 = dot; return a0->f[4] < dot.
// Guess: signed distance of a point against a plane (a1 = normal + d) compared with a
//        radius stored at +16 of a0 (sphere/plane overlap test); also writes the distance.
// Note: whole-function inline asm (VU0 macro instructions have no C equivalent here).
s32 func_00162b68(void* a0, void* a1, f32* a2) {
    register s32 r asm("$2");
    __asm__ volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1,0(%1)\n\t"
        "lqc2 $vf2,0(%2)\n\t"
        "vmul.xyz $vf1,$vf1,$vf2\n\t"
        "vaddy.x $vf1,$vf1,$vf1y\n\t"
        "vaddz.x $vf1,$vf1,$vf1z\n\t"
        "qmfc2 $8,$vf1\n\t"
        "mtc1 $8,$f1\n\t"
        "lwc1 $f0,12(%2)\n\t"
        "add.s $f1,$f1,$f0\n\t"
        "swc1 $f1,0(%3)\n\t"
        "lwc1 $f0,16(%1)\n\t"
        "c.lt.s $f0,$f1\n\t"
        "bc1t 1f\n\t"
        "move %0,$0\n\t"
        "li %0,1\n\t"
        "1:\n\t"
        ".set reorder\n\t"
        : "=r"(r)
        : "r"(a0), "r"(a1), "r"(a2)
        : "$8", "$f0", "$f1", "memory");
    return r;
}

// FUN_0016d888 (72 bytes)
// Code: a0 points at two vector pointers {va, vb}. Computes the VU0 cross product va x vb
//       into a stack temporary, copies it to the static vector at 0x004f62a0 (skipped if the
//       temporary is that address), and stores the static vector's address back to a0[0].
// Guess: a "result = a x b" operator that returns its result through a shared static
//        vector (self-assignment guard in the vector copy).
// Note: VU0 part and the 16-byte copy are inline asm; g is pinned to $15 to match.
void func_0016d888(u32* a0) {
    u128 tmp;
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "lqc2 $vf2,0(%2)\n\t"
        "vsub.wxyz $vf3,$vf0,$vf0\n\t"
        "vopmula.xyz ACC,$vf1,$vf2\n\t"
        "vopmsub.xyz $vf3,$vf2,$vf1\n\t"
        "sqc2 $vf3,0(%3)\n\t"
        : "=m"(tmp)
        : "r"(a0[0]), "r"(a0[1]), "r"(&tmp));
    register u128* g asm("$15") = (u128*)(&D_004f0000 + 25248);
    __asm__("" : "+r"(g));
    if (&tmp != g)
        __asm__ volatile("lq $8,0(%1)\n\tsq $8,0(%0)" ::"r"(g), "r"(&tmp) : "$8", "memory");
    a0[0] = (u32)g;
}

// FUN_0017d930 (52 bytes)
// Code: counts the decimal digits of a0 (0 when a0 <= 0).
s32 func_0017d930(s32 a0) {
    s32 c = 0;
    s32 t = 1;
    if (a0 > 0) {
        do {
            t *= 10;
            c++;
        } while (a0 >= t);
    }
    return c;
}

// FUN_0018a100 (96 bytes)
// Code: a0 = list header: count at +0, 20-byte entries from +64. Searches from a2+20
//       (or the list start when a2 is NULL) for an entry whose byte 4 equals a1
//       (a1 == 22 matches the first entry visited). Returns the entry or NULL.
// Guess: "find next entry of type a1" iterator over an array of 20-byte records.
// Note: whole-function inline asm (C gives the same loop, but GCC fills the first delay
//       slot differently: beqzl+move v0,zero instead of beqz+move v0,t4).
u8* func_0018a100(u8* a0, s32 a1, u8* a2) {
    register u8* r asm("$2");
    __asm__ volatile(
        ".set noreorder\n\t"
        "lw $14,0(%1)\n\t"
        "li $15,20\n\t"
        "addiu $12,%1,64\n\t"
        "addiu $13,%3,20\n\t"
        "mult $14,$14,$15\n\t"
        "movn $12,$13,%3\n\t"
        "addu %1,%1,$14\n\t"
        "addiu %1,%1,64\n\t"
        "sltu $15,$12,%1\n\t"
        "beqz $15,3f\n\t"
        "move %0,$12\n\t"
        "li $14,22\n\t"
        "1:\n\t"
        "beq %2,$14,4f\n\t"
        "nop\n\t"
        "lbu $15,4(%0)\n\t"
        "beq $15,%2,4f\n\t"
        "nop\n\t"
        "addiu %0,%0,20\n\t"
        "sltu $15,%0,%1\n\t"
        "bnez $15,1b\n\t"
        "nop\n\t"
        "3:\n\t"
        "move %0,$0\n\t"
        "4:\n\t"
        ".set reorder\n\t"
        : "=&r"(r), "+r"(a0)
        : "r"(a1), "r"(a2)
        : "$12", "$13", "$14", "$15", "memory");
    return r;
}
