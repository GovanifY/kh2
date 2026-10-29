#include "../common/types.h"

// Agent R46p_80 (2026-10-29): FUN_0021cda0 (44 bytes), SLPM_666.75.
// Sets a0 to a constant in the 0x33 page: 0x330000-20224 if a0 != 0, else 0x330000-22144, then
// tail-calls 0x1e72a8 with ra restored.
// Matching: the original uses bnezl (branch-likely), which gcc 3.2 does not emit. Whole body is
// one file-scope asm block with a numeric j tail to 0x1e72a8 (no registered row, so no named jal).
void r_FUN_0021cda0(void) asm("func_0021cda0");
#if 0
void r_FUN_0021cda0(void) {
}
#endif

__asm__(
    ".section .text.func_0021cda0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0021cda0\n"
    ".type func_0021cda0, @function\n"
    "func_0021cda0:\n"
    "addiu $29,$29,-16\n"
    "sd $31,0($29)\n"
    "bnezl $4,3f\n"
    "lui $4,0x33\n"
    "lui $4,0x33\n"
    "addiu $4,$4,-22144\n"
    "2:\n"
    "ld $31,0($29)\n"
    "j 0x1e72a8\n"
    "addiu $29,$29,16\n"
    "3:\n"
    "b 2b\n"
    "addiu $4,$4,-20224\n"
    ".set pop\n"
    ".size func_0021cda0, .-func_0021cda0\n"
    ".text\n");
