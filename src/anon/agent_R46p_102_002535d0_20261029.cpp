#include "../common/types.h"

// Agent R46p_102: func_002535d0 (104 bytes), SLPM_666.75.
// s0 = -1. If the signed byte at 0x3726c8 is negative, skip to the call. Otherwise scan bytes
// from 0x3726c8 for one equal to a0; a match sets s0 = 2 before the call. The scan stops at
// the first negative byte. Calls 0x102fa0 with a0; if it returns nonzero, s0 = 2 (movn).
// Whole-body asm (form b): the loop uses a branch-likely-free layout with numeric labels.
void r_FUN_002535d0(void) asm("func_002535d0");
#if 0
void r_FUN_002535d0(void) {
}
#endif

__asm__(
    ".section .text.func_002535d0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002535d0\n"
    ".type func_002535d0, @function\n"
    "func_002535d0:\n"
    "addiu $29,$29,-16\n"
    "lui $14,0x37\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lb $15,9928($14)\n"
    "bltz $15,1f\n"
    "addiu $16,$0,-1\n"
    "addiu $14,$14,9928\n"
    "2: lb $15,0($14)\n"
    "bne $4,$15,4f\n"
    "addiu $14,$14,1\n"
    "addiu $16,$0,2\n"
    "1: jal 0x102fa0\n"
    "nop\n"
    "addiu $15,$0,2\n"
    "ld $31,8($29)\n"
    "movn $16,$15,$2\n"
    "daddu $2,$16,$0\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "4: lb $15,0($14)\n"
    "bgez $15,2b\n"
    "nop\n"
    "beq $0,$0,1b\n"
    "nop\n"
    ".set pop\n"
    ".size func_002535d0, .-func_002535d0\n"
    ".text\n");
