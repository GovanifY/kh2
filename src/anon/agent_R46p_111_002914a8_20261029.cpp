#include "../common/types.h"

// Agent R46p_111 (2026-10-29): FUN_002914a8 (104 bytes, SLPM_666.75). Whole-body asm (form b).
// Calls 0x1a80c8(a1) and sets s0 = 0. If the byte at 0x370000+17544 is negative (bltzl), returns s0.
// Otherwise walks a zero-terminated byte string at that base and compares it with byte 2 of a0 (passed through s0).
// Branch-likely and the backward loop need raw asm; plain C does not reproduce the layout.
void r_FUN_002914a8(void) asm("func_002914a8");
#if 0
void r_FUN_002914a8(void) {
}
#endif

__asm__(
    ".section .text.func_002914a8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002914a8\n"
    ".type func_002914a8, @function\n"
    "func_002914a8:\n"
    "addiu $29,$29,-16\n"
    "daddu $4,$5,$0\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x1a80c8\n"
    "daddu $16,$0,$0\n"
    "lui $14,0x37\n"
    "lb $15,17544($14)\n"
    "bltzl $15,3f\n"
    "daddu $2,$16,$0\n"
    "lbu $2,2($2)\n"
    "addiu $14,$14,17544\n"
    "1:\n"
    "lb $15,0($14)\n"
    "bne $2,$15,4f\n"
    "addiu $14,$14,1\n"
    "addiu $16,$0,1\n"
    "daddu $2,$16,$0\n"
    "3:\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "4:\n"
    "lb $15,0($14)\n"
    "bgez $15,1b\n"
    "nop\n"
    "b 3b\n"
    "daddu $2,$16,$0\n"
    ".set pop\n"
    ".size func_002914a8, .-func_002914a8\n"
    ".text\n");
