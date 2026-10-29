#include "../common/types.h"

// Agent R46p_29 (2026-10-29): FUN_001abba8 (72 bytes), SLPM_666.75.
// Code: frame of 32 bytes, saves s0, s1, ra. Calls FUN_0023acd8(s0) with s0 = a0 + 20,
// then copies two words from the struct at s1 (offsets 16 and 12) into s0 offsets 332 and 328,
// and tail-jumps to FUN_0023ade0(s0).
// Matching: whole-body asm, because the callees have no functions.tsv row, so a named jal does not
// link, and the epilogue restores sit between the copies and the tail jump.
// Callees are reached by numeric jal/j targets. The symbol is bound with an asm label.

void r_FUN_001abba8(void) asm("func_001abba8");

void r_FUN_001abba8(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "addiu $16,$4,20\n\t"
        "sd $31,16($29)\n\t"
        "daddu $17,$4,$0\n\t"
        "jal 0x23acd8\n\t"
        "daddu $4,$16,$0\n\t"
        "lw $14,16($17)\n\t"
        "daddu $4,$16,$0\n\t"
        "lw $15,12($17)\n\t"
        "ld $31,16($29)\n\t"
        "sw $14,332($16)\n\t"
        "sw $15,328($16)\n\t"
        "ld $17,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "j 0x23ade0\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}
