#include "../common/types.h"

// Agent R46p_87 (2026-10-29): FUN_0023fcd0 (96 bytes), SLPM_666.75.
// Reads a counter at 0x36 base -5140 and a table pointer at 0x36 base -5136, indexes 8-byte entries,
// calls FUN_002fdd68(entry[0], entry[1]) through a numeric jal (no functions.tsv row for the callee),
// then decrements the counter and stores entry word 0 at -5144 of the 0x360000 base.
// Whole-body asm: the callee has no func_ row and plain C would emit jalr. The jal delay slot holds the a2 load.
// Size is a multiple of 8, so no align flag.

void r_FUN_0023fcd0(void) asm("func_0023fcd0");

void r_FUN_0023fcd0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "lui $14,0x36\n\t"
        "sd $17,8($29)\n\t"
        "sd $31,16($29)\n\t"
        "sd $16,0($29)\n\t"
        "lui $17,0x36\n\t"
        "lw $15,-5140($17)\n\t"
        "lw $16,-5136($14)\n\t"
        "sll $15,$15,3\n\t"
        "addu $16,$16,$15\n\t"
        "lw $5,-8($16)\n\t"
        "jal 0x2fdd68\n\t"
        " lw $6,-4($16)\n\t"
        "lw $14,-5140($17)\n\t"
        "lui $15,0x36\n\t"
        "lw $13,-8($16)\n\t"
        "addiu $14,$14,-1\n\t"
        "ld $31,16($29)\n\t"
        "sw $14,-5140($17)\n\t"
        "sw $13,-5144($15)\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}
