#include "../common/types.h"

// Agent R46p_27 (2026-10-29): FUN_001a60c8 (80 bytes), SLPM_666.75.
// Code: frame of 32 bytes, saves s0, s1, ra. Loops six times: s0 = i, calls FUN_001a6658(i) and
// stores the result at D_00350828 + 44 * i (s1 walks the table). Then tail-jumps to FUN_001bdff0.
// Matching: the whole function is one noreorder asm block with no C locals, so gcc emits no
// prologue. The asm writes the original words in the original order; the loop body is the
// jal with the move in its delay slot, and the bnez targets that jal (numeric label 1).
// The 8 bytes of gcc's trailing jr ra; nop fall past the 80-byte boundary.
// The symbol is bound with an asm label so the source lookup finds this file.

void r_FUN_001a60c8(void) asm("func_001a60c8");

void r_FUN_001a60c8(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "lui $15,0x35\n\t"
        "sd $16,0($29)\n\t"
        "addiu $15,$15,2048\n\t"
        "sd $17,8($29)\n\t"
        "sd $31,16($29)\n\t"
        "daddu $16,$0,$0\n\t"
        "addiu $17,$15,40\n\t"
        "1:\n\t"
        "jal 0x1a6658\n\t"
        " daddu $4,$16,$0\n\t"
        "addiu $16,$16,1\n\t"
        "sw $2,0($17)\n\t"
        "slti $15,$16,6\n\t"
        "bnez $15,1b\n\t"
        " addiu $17,$17,44\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "ld $31,16($29)\n\t"
        "j 0x1bdff0\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}
