#include "../common/types.h"

// Asm label alias: registers func_002278e0 with this file (no C definition is emitted).
void r_FUN_002278e0(void) asm("func_002278e0");
#if 0
void r_FUN_002278e0(void) {
}
#endif

// FUN_002278e0 (80 bytes). Top-level asm, whole body. If the word at D_00360000-8976 is zero, returns.
// Else saves a0 in s0, calls FUN_00225fa0(&D_00360000-9472, a0->24) and tail-jumps to FUN_00227930 with a0 = s0.
__asm__(
    ".section .text.func_002278e0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002278e0\n"
    ".type func_002278e0, @function\n"
    "func_002278e0:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x36\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lw $14,-8976($15)\n"
    "beqz $14,agent_r46p82_b_ret\n"
    "daddu $16,$4,$0\n"
    "lw $5,24($4)\n"
    "lui $4,0x36\n"
    "jal 0x225fa0\n"
    "addiu $4,$4,-9472\n"
    "daddu $4,$16,$0\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "j 0x227930\n"
    "addiu $29,$29,16\n"
    "agent_r46p82_b_ret: ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002278e0, .-func_002278e0\n"
    ".text\n");
