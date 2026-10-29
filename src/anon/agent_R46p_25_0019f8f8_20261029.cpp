#include "../common/types.h"

// Agent R46p_25 (2026-10-29): FUN_0019f8f8 (84 bytes), SLPM_666.75.
// Frame of 16 bytes. Saves s0, ra. s0 = a0; stores a1 at s0+0 and clears s0+4 in the jal delay slot
// of the call to 0x1c0150(a0 + 72). Then s0 += 12, and an 8-iteration loop clears one word at s0 and
// advances s0 by 8. The callee has no functions.tsv row, so the jal is a numeric target and the
// whole body is file-scope asm (form b). Plain C cannot place the zero store in that jal delay slot.
void r_FUN_0019f8f8(void) asm("func_0019f8f8");
#if 0
void r_FUN_0019f8f8(void) {
}
#endif

__asm__(
    ".section .text.func_0019f8f8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0019f8f8\n"
    ".type func_0019f8f8, @function\n"
    "func_0019f8f8:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$4,$0\n"
    "sw $5,0($16)\n"
    "addiu $4,$4,72\n"
    "jal 0x1c0150\n"
    "sw $0,4($16)\n"
    "addiu $16,$16,12\n"
    "addiu $15,$0,7\n"
    "1:\n"
    "sw $0,0($16)\n"
    "addiu $15,$15,-1\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "bgez $15,1b\n"
    "addiu $16,$16,8\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0019f8f8, .-func_0019f8f8\n"
    ".text\n");
