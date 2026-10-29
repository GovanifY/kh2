#include "../common/types.h"

// Agent R46p_30 (2026-10-29): FUN_001ae620 (48 bytes), SLPM_666.75.
// Loop: while (func_002f71b0(1)) func_001ae678(); then return.
// Whole-body asm (form b): the prologue saves ra before the first call, and the
// loop back-edge is a b to the jal, which plain C does not reproduce.
// The callee 0x2f71b0 has no functions.tsv row, so it is a numeric jal.
void r_FUN_001ae620(void) asm("func_001ae620");
#if 0
void r_FUN_001ae620(void) {
}
#endif

__asm__(
    ".section .text.func_001ae620,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001ae620\n"
    ".type func_001ae620, @function\n"
    "func_001ae620:\n"
    "addiu $29,$29,-16\n"
    "sd $31,0($29)\n"
    "1:\n"
    "jal 0x2f71b0\n"
    "addiu $4,$0,1\n"
    "bnez $2,2f\n"
    "ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "2:\n"
    "jal 0x1ae678\n"
    "nop\n"
    "b 1b\n"
    "nop\n"
    ".set pop\n"
    ".size func_001ae620, .-func_001ae620\n"
    ".text\n");
