#include "../common/types.h"

// Agent R46p_9 (2026-10-29): func_001817f0 (100 bytes), SLPM_666.75.
// Loops over 14 twelve-byte records at 0x36c710 (end = base + 168). For each record whose first word
// equals a0, it calls func_0019ee80(word1, word2). Frame: 32 bytes, saves s0, s1, s2, ra.
// Plain C (do-while and for-loop variants) gave a different prologue order (lui before/after the saves)
// and a different loop shape (the pointer step is in both branch delay slots), so this is form (b):
// whole-body asm with the original instruction sequence. The jal target is numeric.
void r_FUN_001817f0(void) asm("func_001817f0");
#if 0
void r_FUN_001817f0(void) {
}
#endif

__asm__(
    ".section .text.func_001817f0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001817f0\n"
    ".type func_001817f0, @function\n"
    "func_001817f0:\n"
    "addiu $29,$29,-32\n"
    "lui $15,0x37\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $18,16($29)\n"
    "addiu $16,$15,-14576\n"
    "sd $31,24($29)\n"
    "daddu $17,$4,$0\n"
    "addiu $18,$16,168\n"
    "lw $15,0($16)\n"
    "1: bnel $15,$17,2f\n"
    " addiu $16,$16,12\n"
    "lw $4,4($16)\n"
    "jal 0x19ee80\n"
    " lw $5,8($16)\n"
    "addiu $16,$16,12\n"
    "2: slt $15,$16,$18\n"
    "bnezl $15,1b\n"
    " lw $15,0($16)\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "ld $31,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001817f0, .-func_001817f0\n"
    ".text\n");
