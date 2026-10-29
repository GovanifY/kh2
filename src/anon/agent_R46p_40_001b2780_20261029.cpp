#include "../common/types.h"

// Agent R46p_40 (2026-10-29): FUN_001b2780 (64 bytes), SLPM_666.75.
// Code: frame of 32 bytes. Saves s0 and ra, s0 = a1. Copies 16 bytes from a2 to the stack temp
// (lq/sq through t0), calls the callee at 0x17c4c8 with (s0, sp), then tail-calls the callee at
// 0x16bd60 with (s0, 20). The duplicated move a0,s0 is kept literally.
// Matching: whole-body noreorder asm. Numeric jal targets are used because 0x17c4c8 has no row.
void func_001b2780(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,16($29)\n\t"
        "sd $31,24($29)\n\t"
        "daddu $16,$5,$0\n\t"
        "lq $8,0($6)\n\t"
        "sq $8,0($29)\n\t"
        "daddu $5,$29,$0\n\t"
        "jal 0x17c4c8\n\t"
        " daddu $4,$16,$0\n\t"
        "daddu $4,$16,$0\n\t"
        "jal 0x16bd60\n\t"
        " addiu $5,$0,20\n\t"
        "ld $16,16($29)\n\t"
        "ld $31,24($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}
