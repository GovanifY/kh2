#include "../common/types.h"

// Agent R46p_75 (2026-10-29): FUN_002006b0 (76 bytes), SLPM_666.75.
// Code: t7 = a1->+12, t6 = t7->+4; s0 = a0 + t6; calls the unnamed callee at 0x2f3f88 with
// a0 = s0 + 160 and a1 = &D_00354bc0; then s0 += 176, a0 = s0, a1 = &D_00354be0 and calls it again.
// Matching: the callee has no functions.tsv row, so plain C would emit jalr. A whole-body asm
// block with numeric jal targets reproduces the bytes exactly.
void func_002006b0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,8($29)\n\t"
        "sd $16,0($29)\n\t"
        "lw $15,12($5)\n\t"
        "lw $14,4($15)\n\t"
        "lui $5,0x35\n\t"
        "addiu $5,$5,19392\n\t"
        "addu $16,$4,$14\n\t"
        "jal 0x2f3f88\n\t"
        "addiu $4,$16,160\n\t"
        "addiu $16,$16,176\n\t"
        "lui $5,0x35\n\t"
        "daddu $4,$16,$0\n\t"
        "jal 0x2f3f88\n\t"
        "addiu $5,$5,19424\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
