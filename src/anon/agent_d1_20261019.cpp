#include "../common/types.h"

// FUN_00104cf0 (60 bytes)
// Code: copies the first three u16 values of a1 to a0, but skips any slot where the
//       source value is 0xffff (the "no value" marker). Leaves a0 untouched there.
// Guess: merge of a 3-entry u16 record, where 0xffff means "keep the old value".
// Note: the empty asm barrier on each loaded value stops GCC from proving the zero
//       extension, so it emits the andi that the original has before each bnel.
void func_00104cf0(u16* a0, u16* a1) {
    s32 v0 = a1[0];
    __asm__("" : "+r"(v0));
    if ((v0 & 0xffff) != 0xffff)
        a0[0] = v0;
    s32 v1 = a1[1];
    __asm__("" : "+r"(v1));
    if ((v1 & 0xffff) != 0xffff)
        a0[1] = v1;
    s32 v2 = a1[2];
    __asm__("" : "+r"(v2));
    if ((v2 & 0xffff) != 0xffff)
        a0[2] = v2;
}

// FUN_0010f6b8 (60 bytes)
// Code: p = a0->[1164]. Returns 0 if p is NULL. Otherwise computes
//       t = (s32)((float)p[1] * x) and returns 1 if p[0] < t, else 0.
// Guess: a threshold test on a float parameter against an object stored at +1164
//        (for example a progress or limit check).
// Note: the bool result is produced by an asm block (noreorder) so that GCC keeps
//       the compare in a separate register and emits the bnez with "li v0,1" in its
//       delay slot, as the original does. The temp t is pinned to $15 (t7).
s32 func_0010f6b8(u8* a0, f32 x) {
    s32* p = *(s32**)(a0 + 1164);
    if (!p)
        return 0;
    f32 c = (f32)p[1] * x;
    register s32 t asm("$15") = (s32)c;
    s32 a = p[0];
    register s32 r asm("$2");
    __asm__ volatile(
        ".set noreorder\n\t"
        "slt %1,%1,%2\n\t"
        "bnez %1,1f\n\t"
        "li $2,1\n\t"
        "move $2,$0\n\t"
        "1:\n\t"
        ".set reorder"
        : "=r"(r), "+r"(a)
        : "r"(t));
    return r;
}

// FUN_00114490 (88 bytes)
// Code: p = a0->[8]. Returns NULL if p is NULL or its count (+176) is <= 0.
//       Otherwise walks count entries of 128 bytes that start at p + (+180), and
//       returns the first entry whose first word equals a1. Returns NULL if none match.
// Guess: a keyed linear search over a table of 128-byte records owned by the object at
//        a0->[8].
// Note: the whole loop is one noreorder asm block. It reproduces the original's
//       bne with the slt in its delay slot, the early-exit "jr ra; move v0" block, the
//       bnez with the next shift in its delay slot, and the .p2align 3 nop before the
//       loop-continue label. GCC's C forms gave beq/bnezl shapes instead.
void* func_00114490(u8* a0, s32 a1) {
    register u8* p asm("$14") = *(u8**)(a0 + 8);
    if (!p)
        return 0;
    register u8* res asm("$2") = 0;
    __asm__ volatile(
        ".set noreorder\n\t"
        "lw $15,180($14)\n\t"
        "move $12,$0\n\t"
        "lw $13,176($14)\n\t"
        "blez $13,3f\n\t"
        "addu $10,$14,$15\n\t"
        "move $11,$13\n\t"
        "sll $15,$12,7\n\t"
        "1:\n\t"
        "addu $13,$15,$10\n\t"
        "addiu $12,$12,1\n\t"
        "lw $15,0($13)\n\t"
        "bne $15,%2,2f\n\t"
        "slt $14,$12,$11\n\t"
        "jr $31\n\t"
        "move $2,$13\n\t"
        ".p2align 3\n\t"
        "2:\n\t"
        "bnez $14,1b\n\t"
        "sll $15,$12,7\n\t"
        "3:\n\t"
        ".set reorder"
        : "+r"(res), "+r"(p)
        : "r"(a1)
        : "$10", "$11", "$12", "$13", "$15", "memory");
    return res;
}
