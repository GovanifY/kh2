#include "../common/types.h"

// Agent R46p_52 (2026-10-29): FUN_001c10f8 (52 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves ra. a1 = the pointer at 0x1d49508, a2 = the word at a1 + 4,
// a1 += 8, a3 = 64, t0 = 0x320898 (fifth argument), then jal 0x2fd248 (no functions.tsv row).
// Matching: whole-body asm with the lui t7 before the sd ra, which plain C does not emit.
// The callee is reached by a numeric jal; the delay slot holds addiu a1,a1,8.
void r_FUN_001c10f8(void) asm("func_001c10f8");
#if 0
void r_FUN_001c10f8(void) {
}
#endif

__asm__(
    ".section .text.func_001c10f8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001c10f8\n"
    ".type func_001c10f8, @function\n"
    "func_001c10f8:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x1d5\n"
    "sd $31,0($29)\n"
    "lui $8,0x32\n"
    "lw $5,-27384($15)\n"
    "addiu $8,$8,2200\n"
    "addiu $7,$0,64\n"
    "lw $6,4($5)\n"
    "jal 0x2fd248\n"
    "addiu $5,$5,8\n"
    "ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001c10f8, .-func_001c10f8\n"
    ".text\n");
