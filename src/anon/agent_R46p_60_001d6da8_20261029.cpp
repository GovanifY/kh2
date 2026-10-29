#include "../common/types.h"

// Agent R46p_60 (2026-10-29): FUN_001d6da8 (96 bytes, SLPM_666.75).
// Code: frame of 32 bytes (s0, s1, ra). s0 = 0, s1 = arg0. Loop: s0 = FUN_001d6cc8(s0). If the result is
// non-zero, s0 = result, then calls FUN_001a3570(halfword at +2 of s0) and stores the halfword at +0 of s0
// into *s1 and advances s1 by 2 while the call result is positive; otherwise zero *s1 as a halfword and return.
// Matching: whole-body asm. The non-zero path shares the loop head through a bnez with a move in its
// delay slot, which plain C did not reproduce.
void r_FUN_001d6da8(void) asm("func_001d6da8");
#if 0
void r_FUN_001d6da8(void) {
}
#endif

__asm__(
    ".section .text.func_001d6da8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001d6da8\n"
    ".type func_001d6da8, @function\n"
    "func_001d6da8:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "daddu $16,$0,$0\n"
    "daddu $17,$4,$0\n"
    "1:\n"
    "jal 0x1d6cc8\n"
    "daddu $4,$16,$0\n"
    "bnez $2,3f\n"
    "daddu $16,$2,$0\n"
    "sh $0,0($17)\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    "3:\n"
    "jal 0x1a3570\n"
    "lhu $4,2($16)\n"
    "blez $2,1b\n"
    "nop\n"
    "lhu $15,0($16)\n"
    "sh $15,0($17)\n"
    "b 1b\n"
    "addiu $17,$17,2\n"
    ".set pop\n"
    ".size func_001d6da8, .-func_001d6da8\n"
    ".text\n");
