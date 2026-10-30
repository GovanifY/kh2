#include "../common/types.h"

// Agent R46p_128 (2026-10-29): FUN_002bc518 (108 bytes), SLPM_666.75.
// Walks the list at the global at 0x01e2aa80 (next pointer at +28, stops at null). Each object whose
// byte 49 is 3 gets func_002bbf68(obj, 1). Matching: whole-body asm (form b). The first load of the
// global is a bnezl/lw delay-slot pair plus a trailing nop before the loop label, which plain C did not reproduce.
void r_FUN_002bc518(void) asm("func_002bc518");
#if 0
void r_FUN_002bc518(void) {
}
#endif

__asm__(
    ".section .text.func_002bc518,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002bc518\n"
    ".type func_002bc518, @function\n"
    "func_002bc518:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $18,16($29)\n"
    "daddu $16,$0,$0\n"
    "sd $31,24($29)\n"
    "addiu $17,$0,3\n"
    "lui $18,0x1e3\n"
    "1:\n"
    "bnezl $16,2f\n"
    "lw $4,28($16)\n"
    "lw $4,-21888($18)\n"
    "2:\n"
    "bnez $4,3f\n"
    "daddu $16,$4,$0\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "ld $31,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    "nop\n"
    "3:\n"
    "lbu $15,49($4)\n"
    "bne $15,$17,1b\n"
    "nop\n"
    "jal func_002bbf68\n"
    "addiu $5,$0,1\n"
    "b 1b\n"
    "nop\n"
    ".set pop\n"
    ".size func_002bc518, .-func_002bc518\n"
    ".text\n");
