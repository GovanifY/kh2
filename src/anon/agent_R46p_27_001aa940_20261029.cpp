#include "../common/types.h"

// Agent R46p_27 (2026-10-29): FUN_001aa940 (64 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves ra. Passes a shifted argument set to FUN_001ab598:
// a0 = *a0, a1 = a0 + 64 (original a0), a2 = a1, a3 = a2, t0 = a3, t1 = t0.
// Tail-free: it calls FUN_001ab598 with the call's delay slot moving t0, then restores ra and returns.
// Matching: the whole function is one noreorder asm block with no C locals, so gcc emits no
// prologue. The asm writes the moves in the original order; the t6/t7/t5 temps sit in $14, $15, $13.
// Callees without a functions.tsv row are reached by a numeric jal target.
// The symbol is bound with an asm label so the source lookup finds this file.

void r_FUN_001aa940(void) asm("func_001aa940");

void r_FUN_001aa940(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "daddu $14,$6,$0\n\t"
        "sd $31,0($29)\n\t"
        "daddu $15,$4,$0\n\t"
        "daddu $13,$7,$0\n\t"
        "daddu $9,$8,$0\n\t"
        "addiu $15,$15,64\n\t"
        "lw $4,0($4)\n\t"
        "daddu $6,$5,$0\n\t"
        "daddu $7,$14,$0\n\t"
        "daddu $5,$15,$0\n\t"
        "jal 0x1ab598\n\t"
        " daddu $8,$13,$0\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
