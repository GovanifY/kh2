#include "../common/types.h"

// Agent R46p_56 (2026-10-29): FUN_001d22a8 (52 bytes), SLPM_666.75.
// Whole-body asm. Sets a1 = *(0x1d6xxx) and a2 = a1[1], a3 = 16, a0 = 0x321688 (5th
// argument in t0), then jal 0x2fd248 (no functions.tsv row, so a numeric target) with a1 += 8 in
// the delay slot.
void r_FUN_001d22a8(void) asm("func_001d22a8");
#if 0
void r_FUN_001d22a8(void) {
}
#endif

__asm__(
    ".section .text.func_001d22a8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001d22a8\n"
    ".type func_001d22a8, @function\n"
    "func_001d22a8:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x1d6\n"
    "sd $31,0($29)\n"
    "lui $8,0x32\n"
    "lw $5,-17920($15)\n"
    "addiu $8,$8,5768\n"
    "addiu $7,$0,16\n"
    "lw $6,4($5)\n"
    "jal 0x2fd248\n"
    "addiu $5,$5,8\n"
    "ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001d22a8, .-func_001d22a8\n"
    ".text\n");
