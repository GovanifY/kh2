#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));

extern u32 D_0036c908[];

// FUN_00183768 (84 bytes)
// Code: p = a0 + 16. If p != a1, copy the 16-byte vector at a1 to p (lq/sq through $8).
// Load p into vf1, compute the length of its xyz part (vmul, vaddy, vaddz, vsqrt),
// divide vf1 by that length (vdiv/vmulq), and store vf1 back at p. Store the float
// argument f at a0+28. Returns the length as a float in $f0.
// Guess: normalize a 3D vector stored at +16 of an object and record a float (a scale
// or weight) at +28. The return value is the length before normalizing.
// Build: needs -falign-functions=1 (the 8-byte function padding adds a trailing nop
// to an 84-byte function).
f32 func_00183768(f32 f, u8* a0, u8* a1) {
    register u8* p asm("$15") = a0 + 16;
    register f32 len asm("$f0");
    if (p != a1) {
        __asm__ volatile(
            "lq $8,0(%1)\n\t"
            "sq $8,0(%0)\n\t"
            :
            : "r"(p), "r"(a1)
            : "$8", "memory");
    }
    __asm__ volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1,0(%1)\n\t"
        "vmul.xyz $vf2,$vf1,$vf1\n\t"
        "vaddy.x $vf2,$vf2,$vf2y\n\t"
        "vaddz.x $vf2,$vf2,$vf2z\n\t"
        "vsqrt Q,$vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8,$22\n\t"
        "vaddq.x $vf2,$vf0,Q\n\t"
        "mtc1 $8,%0\n\t"
        "vnop\n\t"
        "vdiv Q,$vf0w,$vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1,$vf1,Q\n\t"
        "sqc2 $vf1,0(%1)\n\t"
        ".set reorder\n\t"
        : "=f"(len)
        : "r"(p)
        : "$8", "memory");
    *(f32*)(a0 + 28) = f;
    return len;
}

// FUN_00186110 (56 bytes)
// Code: v = byte at +36 of a1. If v < 10, jump through the 10-entry table at 0x36c908.
// Table entries 0, 2, 3, 4, 5 go to "return 1"; 1, 6, 7, 8, 9 go to "return 0".
// Otherwise (v >= 10) return 0. The first argument is unused.
// Guess: a set-membership test on a small type code stored at +36 of an object.
s32 func_00186110(u32 a0, u8* a1) {
    u32 v = a1[36];
    static void* keep[] = { &&lab_one, &&lab_zero };
    if (v >= 10) goto lab_zero;
    goto *(void*)D_0036c908[v];
lab_one:
    return 1;
lab_zero:
    return 0;
}

// FUN_0018a1b8 (96 bytes)
// Code: count = *(u32*)a0. The scan start is a2 + 20 when a2 is non-null, else a0 + 64.
// The end is a0 + 64 + count * 20. Walks 20-byte records (cursor in $6). A record
// matches when bit (byte at +4 of the record) is set in the mask a1 (1 << byte, AND
// with a1). Returns the first matching record, or 0.
// Guess: find the next record after a2 in an array of 20-byte entries whose type
// bit is in a filter mask.
// The body is one noreorder asm block, because GCC never reproduced the delay-slot
// fills (the cursor move in the beqz slot, the lbu in the bnezl slot).
u8* func_0018a1b8(u8* a0, u32 a1, u8* a2) {
    register u8* p0 asm("$4") = a0;
    register u32 p1 asm("$5") = a1;
    register u8* p2 asm("$6") = a2;
    register u8* out asm("$2");
    __asm__ volatile(
        ".set noreorder\n\t"
        "lw $14,0($4)\n\t"
        "li $15,20\n\t"
        "addiu $12,$4,64\n\t"
        "addiu $13,$6,20\n\t"
        "mult $14,$14,$15\n\t"
        "movn $12,$13,$6\n\t"
        "addu $4,$4,$14\n\t"
        "addiu $4,$4,64\n\t"
        "sltu $15,$12,$4\n\t"
        "beqz $15,2f\n\t"
        "move $6,$12\n\t"
        "li $13,1\n\t"
        "lbu $15,4($6)\n\t"
        "1:\n\t"
        "move $2,$6\n\t"
        "addiu $6,$6,20\n\t"
        "sllv $15,$13,$15\n\t"
        "and $15,$5,$15\n\t"
        "bnez $15,3f\n\t"
        "sltu $14,$6,$4\n\t"
        "bnezl $14,1b\n\t"
        "lbu $15,4($6)\n\t"
        "2:\n\t"
        "move $2,$0\n\t"
        "3:\n\t"
        ".set reorder\n\t"
        : "+r"(p0), "+r"(p2), "=r"(out)
        : "r"(p1)
        : "$12", "$13", "$14", "$15", "memory");
    return out;
}
