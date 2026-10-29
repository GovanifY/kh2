#include "../common/types.h"

// Agent R46p_61 (2026-10-29): FUN_001d5960 (76 bytes), SLPM_666.75.
// Whole-body asm. Calls the unregistered routine at 0x1d5868 (numeric jal). If it returns zero,
// calls func_001d58f0(this) and, if that is nonzero too, tail-jumps to func_001d5800(this).
// Otherwise returns. this is kept in s0 across the calls.
void r_FUN_001d5960(void) asm("func_001d5960");
#if 0
void r_FUN_001d5960(void) {
}
#endif

__asm__(
    ".section .text.func_001d5960,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001d5960\n"
    ".type func_001d5960, @function\n"
    "func_001d5960:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x1d5868\n"
    "daddu $16,$4,$0\n"
    "bnez $2,1f\n"
    "daddu $4,$16,$0\n"
    "jal 0x1d58f0\n"
    "nop\n"
    "beqz $2,1f\n"
    "daddu $4,$16,$0\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "j 0x1d5800\n"
    "addiu $29,$29,16\n"
    "1:\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001d5960, .-func_001d5960\n"
    ".text\n");
