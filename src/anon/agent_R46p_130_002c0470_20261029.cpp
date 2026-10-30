#include "../common/types.h"

// Agent R46p_130 (2026-10-29): FUN_002c0470 (84 bytes), SLPM_666.75.
// If FUN_00190140(a0 + 100) != 0: FUN_002c04c8(a0, a0+48, a0+64), FUN_002c6490(a0), return 1; else return 0.
// Matching: whole-body asm (form b). Size is 4 mod 8, so the Makefile needs -falign-functions=1 for this object.
void r_FUN_002c0470(void) asm("func_002c0470");
#if 0
void r_FUN_002c0470(void) {
}
#endif

__asm__(
    ".section .text.func_002c0470,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002c0470\n"
    ".type func_002c0470, @function\n"
    "func_002c0470:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$4,$0\n"
    "jal 0x190140\n"
    "addiu $4,$4,100\n"
    "addiu $5,$16,48\n"
    "addiu $6,$16,64\n"
    "daddu $4,$16,$0\n"
    "beq $2,$0,1f\n"
    "daddu $15,$0,$0\n"
    "jal 0x2c04c8\n"
    "nop\n"
    "jal 0x2c6490\n"
    "daddu $4,$16,$0\n"
    "addiu $15,$0,1\n"
    "1:\n"
    "ld $16,0($29)\n"
    "daddu $2,$15,$0\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002c0470, .-func_002c0470\n"
);
