#include "../common/types.h"

// Agent R46p_40 (2026-10-29): FUN_001b6d00 (64 bytes), SLPM_666.75.
// Code: frame of 16 bytes. Saves s0 and ra. s0 = 0x350000. If the word at s0+4484 is nonzero,
// calls the callee at 0x102670 with (word at 0x35 0x0f8c+24 ..., word at 0x350000 + 4628);
// the beqzl delay slot (ld s0) only runs when the branch is taken. Then clears the word at s0+4484.
// Matching: whole-body noreorder asm. The branch-likely (beqzl) is not emitted by gcc 3.2.
void func_001b6d00(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "lui $16,0x35\n\t"
        "lw $15,4484($16)\n\t"
        "beqzl $15,1f\n\t"
        " ld $16,0($29)\n\t"
        "lw $5,24($15)\n\t"
        "lui $15,0x35\n\t"
        "jal 0x102670\n\t"
        " lw $4,4628($15)\n\t"
        "sw $0,4484($16)\n\t"
        "ld $16,0($29)\n\t"
        "1:\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
