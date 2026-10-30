#include "../common/types.h"

// Agent R46p_128 (2026-10-29): FUN_002be4b0 (108 bytes), SLPM_666.75.
// r = func_00105c30(a0). If r == 8, a2 = 0x00375000, else a2 = word at 0x0033caf4. Then
// s0 = a0 + 64, func_002fee78(s0, 0x00374fe8, a2, word at old a0), func_00170518(s0, -200, 0),
// and a tail call to func_00170888(0).
// Matching: whole-body asm (form b). Branch-likely-free code, but the r == 8 arm is placed after the tail.
void r_FUN_002be4b0(void) asm("func_002be4b0");
#if 0
void r_FUN_002be4b0(void) {
}
#endif

__asm__(
    ".section .text.func_002be4b0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002be4b0\n"
    ".type func_002be4b0, @function\n"
    "func_002be4b0:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal func_00105c30\n"
    "daddu $16,$4,$0\n"
    "addiu $15,$0,8\n"
    "beq $2,$15,1f\n"
    "lui $15,0x34\n"
    "lw $6,-13580($15)\n"
    "2:\n"
    "lw $7,0($16)\n"
    "lui $5,0x37\n"
    "addiu $5,$5,20456\n"
    "addiu $16,$16,64\n"
    "jal func_002fee78\n"
    "daddu $4,$16,$0\n"
    "daddu $4,$16,$0\n"
    "addiu $5,$0,-200\n"
    "jal func_00170518\n"
    "daddu $6,$0,$0\n"
    "ld $16,0($29)\n"
    "daddu $4,$0,$0\n"
    "ld $31,8($29)\n"
    "j func_00170888\n"
    "addiu $29,$29,16\n"
    "1:\n"
    "lui $15,0x37\n"
    "b 2b\n"
    "addiu $6,$15,20480\n"
    ".set pop\n"
    ".size func_002be4b0, .-func_002be4b0\n"
    ".text\n");
