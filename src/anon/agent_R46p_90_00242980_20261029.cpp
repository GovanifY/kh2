#include "../common/types.h"

// Agent R46p_90: func_00242980 (64 bytes, SLPM_666.75).
// Whole-body asm. Saves s0, s1, ra; calls the getSaveRam callee (0x1058e8, numeric jal)
// with the delay slot move s1,a1; loads two halfwords from the returned pointer (+16800, +16802)
// and stores them through a0 and a1. ld ra sits between the first lh/sw pair, so plain C
// does not reproduce the order.

void r_func_00242980(void) asm("func_00242980");

void r_func_00242980(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $31,16($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "jal 0x1058e8\n\t"
        " daddu $17,$5,$0\n\t"
        "lh $15,16800($2)\n\t"
        "ld $31,16($29)\n\t"
        "sw $15,0($16)\n\t"
        "lh $14,16802($2)\n\t"
        "ld $16,0($29)\n\t"
        "sw $14,0($17)\n\t"
        "ld $17,8($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}
