#include "../common/types.h"

// Agent R46p_53 (2026-10-29): func_001ce248 (88 bytes), SLPM_666.75.
// Builds a word from the bytes at a1[0..3] with lb/sll/or in the original order, calls
// func_00168b88(word at 0x352134, a0, that word, 0) and returns the word at result + 8.
// Plain C (three attempts with a signed-byte OR expression) gave the wrong load order or
// operand grouping, so this is form (b): whole-body asm with numeric jal target.
void r_FUN_001ce248(void) asm("func_001ce248");
#if 0
void r_FUN_001ce248(void) {
}
#endif

__asm__(
    ".section .text.func_001ce248,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001ce248\n"
    ".type func_001ce248, @function\n"
    "func_001ce248:\n"
    "addiu $29,$29,-16\n"
    "daddu $15,$5,$0\n"
    "sd $31,0($29)\n"
    "daddu $7,$0,$0\n"
    "lb $12,1($5)\n"
    "lb $13,3($15)\n"
    "lb $14,2($15)\n"
    "daddu $5,$4,$0\n"
    "lb $6,0($15)\n"
    "sll $12,$12,8\n"
    "sll $13,$13,24\n"
    "sll $14,$14,16\n"
    "lui $15,0x35\n"
    "or $6,$6,$13\n"
    "or $14,$14,$12\n"
    "lw $4,8500($15)\n"
    "jal 0x168b88\n"
    "or $6,$6,$14\n"
    "lw $2,8($2)\n"
    "ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001ce248, .-func_001ce248\n"
    ".text\n");
