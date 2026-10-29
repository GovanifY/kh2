#include "../common/types.h"

// Agent R46p_83 (2026-10-29): FUN_0022e0a8 (100 bytes), SLPM_666.75.
// Loop over a callee at p+16: r = func_001de4b0(p+16, 0, r), starting from r = 0. A zero result
// returns 0; otherwise returns 1 when the word at p+12 equals r, and loops again if it does not.
// Plain C gives beqz/bne with the return block inline. The original branches out of line: bnez to a
// block after the epilogue that loops back to the jal, so this is a whole-body asm block.
// The jal targets func_001de4b0, which has a func_ row.

void r_FUN_0022e0a8(void) asm("func_0022e0a8");

void r_FUN_0022e0a8(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "daddu $2,$0,$0\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $31,16($29)\n\t"
        "addiu $16,$4,16\n\t"
        "daddu $17,$4,$0\n\t"
        "daddu $6,$2,$0\n\t"
        "daddu $4,$16,$0\n"
        "1:\n\t"
        "jal func_001de4b0\n\t"
        " daddu $5,$0,$0\n\t"
        "bnez $2,2f\n\t"
        " addiu $14,$0,1\n\t"
        "daddu $14,$0,$0\n"
        "3:\n\t"
        "ld $16,0($29)\n\t"
        "daddu $2,$14,$0\n\t"
        "ld $17,8($29)\n\t"
        "ld $31,16($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n"
        "2:\n\t"
        "lw $15,12($17)\n\t"
        "beq $15,$2,3b\n\t"
        " daddu $6,$2,$0\n\t"
        "b 1b\n\t"
        " daddu $4,$16,$0\n\t"
        ".set reorder"
        ::: "memory");
}
