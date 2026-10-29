#include "../common/types.h"

// Agent R46p_29 (2026-10-29): FUN_001abd30 (96 bytes), SLPM_666.75.
// Code: frame of 32 bytes, saves s0, s1, ra. Zeroes the word at a0, then calls FUN_00239700(a0+4),
// FUN_001abb28(a0+348), FUN_001ab810(), and FUN_001ab800() (result into s0), and tail-jumps to
// FUN_00239988(a0+4, s0, v0).
// Matching: whole-body asm. The callees have no functions.tsv row, so a named jal does not link.
// The body is identical to FUN_001abd30 at 0x001abd90 (same bytes, separate object).

void r_FUN_001abd30(void) asm("func_001abd30");

void r_FUN_001abd30(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sw $0,0($4)\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $31,16($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "addiu $17,$4,4\n\t"
        "addiu $16,$16,348\n\t"
        "jal 0x239700\n\t"
        "daddu $4,$17,$0\n\t"
        "jal 0x1abb28\n\t"
        "daddu $4,$16,$0\n\t"
        "jal 0x1ab810\n\t"
        "nop\n\t"
        "jal 0x1ab800\n\t"
        "daddu $16,$2,$0\n\t"
        "daddu $4,$17,$0\n\t"
        "ld $31,16($29)\n\t"
        "daddu $5,$16,$0\n\t"
        "ld $17,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "daddu $6,$2,$0\n\t"
        "j 0x239988\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}
