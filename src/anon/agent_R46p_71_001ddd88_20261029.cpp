#include "../common/types.h"

// Agent R46p_71 (2026-10-29): FUN_001ddd88 (72 bytes), SLPM_666.75.
// Code: frame of 16 bytes. Saves a1 = a0, then s0 = a0, ra. Calls func_00321cb0 with
// a0 = 0x1da0000 - 7352 and the original a0 in a1. If the result is zero it restores and
// returns; otherwise it restores and tail-jumps to 0x1dde40 with a0 = s0 (numeric j, no row).
// Matching: whole-body asm (form b). The prologue writes a1 before s0 as in the original.
void r_FUN_001ddd88(void) asm("func_001ddd88");
#if 0
void r_FUN_001ddd88(void) {
}
#endif

__asm__(
    ".section .text.func_001ddd88,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001ddd88\n"
    ".type func_001ddd88, @function\n"
    "func_001ddd88:\n"
    "addiu $29,$29,-16\n"
    "daddu $5,$4,$0\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$4,$0\n"
    "lui $4,0x1da\n"
    "jal 0x321cb0\n"
    "addiu $4,$4,-7352\n"
    "beqz $2,0f\n"
    "daddu $4,$16,$0\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "j 0x1dde40\n"
    "addiu $29,$29,16\n"
    "0:\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001ddd88, .-func_001ddd88\n"
    ".text\n");
