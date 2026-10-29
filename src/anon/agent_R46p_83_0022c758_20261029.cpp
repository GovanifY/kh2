#include "../common/types.h"

// Agent R46p_83 (2026-10-29): FUN_0022c758 (100 bytes), SLPM_666.75.
// Loop calling func_001de4b0(*(word at 0x35de84), 0, r) with r starting at 0. A zero result returns 0;
// otherwise returns 1 when r equals the word at 0x35de88, else loops. Both globals are read through
// lui s0 / lui s1 bases (0x360000) with offsets -8568 and -8572.
// Whole-body asm: the original's loop-head branches (bnez out to a block after the epilogue, and a
// b back to the jal) do not come out of plain C. The jal targets func_001de4b0, which has a func_ row.

void r_FUN_0022c758(void) asm("func_0022c758");

void r_FUN_0022c758(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "daddu $2,$0,$0\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $31,16($29)\n\t"
        "lui $16,0x36\n\t"
        "lui $17,0x36\n\t"
        "lw $4,-8572($17)\n\t"
        "daddu $6,$2,$0\n"
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
        "lw $15,-8568($16)\n\t"
        "beq $15,$2,3b\n\t"
        " lw $4,-8572($17)\n\t"
        "b 1b\n\t"
        " daddu $6,$2,$0\n\t"
        ".set reorder"
        ::: "memory");
}
