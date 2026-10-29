#include "../common/types.h"

// func_002827f0 (104 bytes)
// Saves s0..s2 and ra, calls func_00281f70(a0) with s2 = a0, then loads word 4104(s2).
// If it is zero, tail-jumps to 0x00282858 with (a0 = s2, a1 = a1 saved in s0, a2 = a2 saved in s1).
// Otherwise tail-jumps to 0x00282B00 with the same arguments.
// Both tail jumps are numeric and the epilogue restores interleave with them, so this is whole-body asm.
void func_002827f0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $18,16($29)\n\t"
        "daddu $16,$5,$0\n\t"
        "sd $31,24($29)\n\t"
        "daddu $17,$6,$0\n\t"
        "jal 0x281f70\n\t"
        " daddu $18,$4,$0\n\t"
        "lw $15,4104($18)\n\t"
        "daddu $4,$18,$0\n\t"
        "daddu $5,$16,$0\n\t"
        "bnez $15,5f\n\t"
        " daddu $6,$17,$0\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "ld $18,16($29)\n\t"
        "ld $31,24($29)\n\t"
        "j 0x282858\n\t"
        " addiu $29,$29,32\n\t"
        "5:\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "ld $18,16($29)\n\t"
        "ld $31,24($29)\n\t"
        "j 0x282b00\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}
