#include "../common/types.h"

// Asm label alias: registers func_00226e60 with this file (no C definition is emitted).
void r_FUN_00226e60(void) asm("func_00226e60");
#if 0
void r_FUN_00226e60(void) {
}
#endif

// FUN_00226e60 (64 bytes). Top-level asm, whole body. Calls FUN_00197920(a0 & 0xff); if it returns
// zero, returns 0 (branch-likely path). Otherwise stores the masked byte at D_00360000-8692 and tail-jumps
// to FUN_00226dc8 with the stack popped.
__asm__(
    ".section .text.func_00226e60,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00226e60\n"
    ".type func_00226e60, @function\n"
    "func_00226e60:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x197920\n"
    "andi $16,$4,0xff\n"
    "beqzl $2,agent_r46p82_a_zero\n"
    "ld $16,0($29)\n"
    "lui $15,0x36\n"
    "ld $31,8($29)\n"
    "sb $16,-8692($15)\n"
    "ld $16,0($29)\n"
    "j 0x226dc8\n"
    "addiu $29,$29,16\n"
    "agent_r46p82_a_zero: ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00226e60, .-func_00226e60\n"
    ".text\n");
