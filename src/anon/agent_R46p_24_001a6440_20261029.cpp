#include "../common/types.h"

// Agent R46p_24 (2026-10-29): FUN_001a6440 (76 bytes), SLPM_666.75.
// Code: frame of 16 bytes. Saves s0 then ra, s0 = a0, a0 = self->+4, and if (word at a0+1416) & 4 is
// set it calls func_00177998(a0) (numeric jal) and reloads a0 = *s0. Then it tail-jumps to 0x16cbc8
// with a1 = 21, a2 = 0, a3 = 0.
// Matching: the original uses beqzl (branch-likely), which gcc 3.2 does not emit. This is form (b):
// file-scope __asm__ whole body with numeric jal/j targets, so the .o matches byte for byte.
void r_FUN_001a6440(void) asm("func_001a6440");
#if 0
void r_FUN_001a6440(void) {
}
#endif

__asm__(
    ".section .text.func_001a6440,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001a6440\n"
    ".type func_001a6440, @function\n"
    "func_001a6440:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$4,$0\n"
    "lw $4,4($4)\n"
    "lw $15,1416($4)\n"
    "andi $15,$15,0x4\n"
    "beql $15,$0,1f\n"
    "lw $4,0($16)\n"
    "jal 0x177998\n"
    "nop\n"
    "lw $4,0($16)\n"
    "1:\n"
    "addiu $5,$0,21\n"
    "ld $31,8($29)\n"
    "daddu $6,$0,$0\n"
    "ld $16,0($29)\n"
    "daddu $7,$0,$0\n"
    "j 0x16cbc8\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001a6440, .-func_001a6440\n"
    ".text\n");
