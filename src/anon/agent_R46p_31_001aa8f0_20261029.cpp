#include "../common/types.h"

// Agent R46p_31 (2026-10-29): FUN_001aa8f0 (76 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves ra. Loads two float fields from the object (f13 from +40, f12 from +36)
// and an unused word from +56, then calls FUN_001ab260 with a0 = *a0, a1 = a0 + 64, a2 = a1, a3 = a2, t0 = a3.
// Matching: whole-body noreorder asm with no C locals, so gcc emits no prologue. The asm keeps the
// original instruction order, with the t6/t7/t5/t4 temps in $14, $15, $13, $12.
// The callee has no functions.tsv row, so it is reached by a numeric jal target.

void func_001aa8f0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "daddu $14,$5,$0\n\t"
        "sd $31,0($29)\n\t"
        "daddu $15,$4,$0\n\t"
        "addiu $5,$4,64\n\t"
        "daddu $13,$6,$0\n\t"
        "lwc1 $f13,40($4)\n\t"
        "daddu $12,$7,$0\n\t"
        "daddu $9,$8,$0\n\t"
        "lw $10,56($15)\n\t"
        "lw $4,0($4)\n\t"
        "daddu $6,$14,$0\n\t"
        "lwc1 $f12,36($15)\n\t"
        "daddu $7,$13,$0\n\t"
        "jal 0x1ab260\n\t"
        " daddu $8,$12,$0\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
