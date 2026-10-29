#include "../common/types.h"

// Agent R46p_34 (2026-10-29): FUN_001b1360 (108 bytes), SLPM_666.75.
// Code: frame of 32 bytes, saves s0, s1, s2, ra. Loop: calls FUN_001b9bc8(v0), starting from a0 = 0, and
// stops with 0 when the result is 0. Otherwise it reads the word at +1188 and compares it with 2 (loop
// again on a mismatch); when equal to s1 the word at +1232 is compared and stored with s2 on a match.
// Matching: whole-body noreorder asm (gcc 3.2 emits no branch-likely). Numeric labels: 2 = loop head,
// 3 = the non-null path. The bnezl/beql delay slots carry the loads and the store.

void func_001b1360(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "daddu $2,$0,$0\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $18,16($29)\n\t"
        "addiu $16,$0,2\n\t"
        "sd $31,24($29)\n\t"
        "daddu $17,$4,$0\n\t"
        "daddu $18,$5,$0\n\t"
        "2:\n\t"
        "jal 0x1b9bc8\n\t"
        " daddu $4,$2,$0\n\t"
        "bnezl $2,3f\n\t"
        " lw $15,1188($2)\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "ld $18,16($29)\n\t"
        "ld $31,24($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        "nop\n\t"
        "3:\n\t"
        "bne $15,$16,2b\n\t"
        " nop\n\t"
        "lw $15,1232($2)\n\t"
        "beql $15,$17,2b\n\t"
        " sw $18,1232($2)\n\t"
        "b 2b\n\t"
        " nop\n\t"
        ".set reorder"
        ::: "memory");
}
