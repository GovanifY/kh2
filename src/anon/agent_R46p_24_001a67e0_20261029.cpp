#include "../common/types.h"

// Agent R46p_24 (2026-10-29): FUN_001a67e0 (108 bytes), SLPM_666.75.
// Code: frame of 16 bytes. Saves s0 then ra. If a0 is null it skips to the epilogue. Otherwise it walks
// the list head at 0x1c7cb20 (lui 0x1c7, offset -13536) via the word at +12 of each node until it
// reaches s0 again. If the walk finds no match, it calls func_001a5d48(s0) and func_00105110(s0),
// both as numeric jal targets, then restores ra and returns.
// Matching: the original uses beqzl (branch-likely), which gcc 3.2 does not emit. This is form (b):
// file-scope __asm__ whole body with numeric jal targets and local numeric labels.
void r_FUN_001a67e0(void) asm("func_001a67e0");
#if 0
void r_FUN_001a67e0(void) {
}
#endif

__asm__(
    ".section .text.func_001a67e0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001a67e0\n"
    ".type func_001a67e0, @function\n"
    "func_001a67e0:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "beq $4,$0,4f\n"
    "daddu $16,$4,$0\n"
    "lui $15,0x1c7\n"
    "daddu $14,$0,$0\n"
    "lw $13,-13536($15)\n"
    "1:\n"
    "beq $14,$0,2f\n"
    "daddu $15,$13,$0\n"
    "lw $15,12($14)\n"
    "2:\n"
    "bne $15,$0,6f\n"
    "daddu $14,$15,$0\n"
    "3:\n"
    "beql $16,$0,5f\n"
    "ld $16,0($29)\n"
    "jal 0x1a5d48\n"
    "daddu $4,$16,$0\n"
    "jal 0x105110\n"
    "daddu $4,$16,$0\n"
    "4:\n"
    "ld $16,0($29)\n"
    "5:\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "6:\n"
    "bne $15,$16,1b\n"
    "nop\n"
    "beq $0,$0,3b\n"
    "nop\n"
    ".set pop\n"
    ".size func_001a67e0, .-func_001a67e0\n"
    ".text\n");
