#include "../common/types.h"

// Asm label alias: registers func_00225aa8 with this file (no C definition is emitted).
void r_FUN_00225aa8(void) asm("func_00225aa8");
#if 0
void r_FUN_00225aa8(void) {
}
#endif

// FUN_00225aa8 (84 bytes). Top-level asm, whole body. Returns 1 if the byte at D_00360000-9492 is set,
// or if the byte at D_00360000-9491 is clear and FUN_00225a68() returns nonzero; otherwise returns 0.
__asm__(
    ".section .text.func_00225aa8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00225aa8\n"
    ".type func_00225aa8, @function\n"
    "func_00225aa8:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x36\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lbu $14,-9492($15)\n"
    "bnez $14,agent_r46p82_c_li\n"
    "daddu $16,$0,$0\n"
    "lui $15,0x36\n"
    "lbu $14,-9491($15)\n"
    "bnezl $14,agent_r46p82_c_mov\n"
    "addiu $16,$0,1\n"
    "jal 0x225a68\n"
    "nop\n"
    "beqz $2,agent_r46p82_c_ret\n"
    "daddu $2,$16,$0\n"
    "agent_r46p82_c_li: addiu $16,$0,1\n"
    "agent_r46p82_c_mov: daddu $2,$16,$0\n"
    "agent_r46p82_c_ret: ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00225aa8, .-func_00225aa8\n"
    ".text\n");
