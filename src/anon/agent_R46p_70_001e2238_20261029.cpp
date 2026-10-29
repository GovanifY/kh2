#include "../common/types.h"

// Agent R46p_70 (2026-10-29): FUN_001e2238 (96 bytes), SLPM_666.75.
// Code: frame of 32 bytes. Saves s0, s1, s2, ra. s0 = a0. If word at a0 + 3532 > 0, loop:
// s2 = count, s1 = byte offset starting at 0. Each step calls FUN_001e1728(*(s0 + 3528) + s1),
// then s2 += 1, s1 += 48, and repeats while s2 < *(s0 + 3532).
// Matching: the callee FUN_001e1728 has no func_ row, so the jal is numeric, and the loop tail uses
// a bnez with a delay-slot addiu. Whole body is one top-level asm in .text.func_001e2238.
void r_FUN_001e2238(void) asm("func_001e2238");
#if 0
void r_FUN_001e2238(void) {
}
#endif

__asm__(
    ".section .text.func_001e2238,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001e2238\n"
    ".type func_001e2238, @function\n"
    "func_001e2238:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $18,16($29)\n"
    "sd $17,8($29)\n"
    "daddu $16,$4,$0\n"
    "sd $31,24($29)\n"
    "lw $15,3532($4)\n"
    "blez $15,.L_func_001e2238_end\n"
    "daddu $18,$0,$0\n"
    "daddu $17,$0,$0\n"
    ".L_func_001e2238_loop:\n"
    "lw $4,3528($16)\n"
    "addiu $18,$18,1\n"
    "jal 0x1e1728\n"
    "addu $4,$4,$17\n"
    "lw $15,3532($16)\n"
    "slt $15,$18,$15\n"
    "bnez $15,.L_func_001e2238_loop\n"
    "addiu $17,$17,48\n"
    ".L_func_001e2238_end:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "ld $31,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001e2238, .-func_001e2238\n"
    ".text\n");
