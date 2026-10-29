#include "../common/types.h"

// func_00259350 (104 bytes)
// Code: a chain of tests. Returns 1 if func_002538f8(a0) or func_00253928(a0) is nonzero.
// Otherwise returns 0 if isBackRead() (0x253918) is nonzero, else returns (func_002539e8(a0, 0) == 0).
// The callee 0x002539e8 has no functions.tsv row, so the whole body is one noreorder asm block
// with numeric jal targets. Saves are s0 then ra, as in the original.
void func_00259350(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "jal 0x2538f8\n\t"
        " daddu $16,$4,$0\n\t"
        "daddu $4,$16,$0\n\t"
        "bnez $2,3f\n\t"
        " addiu $15,$0,1\n\t"
        "jal 0x253928\n\t"
        " nop\n\t"
        "bnez $2,3f\n\t"
        " addiu $15,$0,1\n\t"
        "jal 0x253918\n\t"
        " nop\n\t"
        "daddu $5,$0,$0\n\t"
        "daddu $4,$16,$0\n\t"
        "bnez $2,4f\n\t"
        " daddu $15,$0,$0\n\t"
        "jal 0x2539e8\n\t"
        " nop\n\t"
        "sltiu $15,$2,1\n\t"
        "3:\n\t"
        "4:\n\t"
        "ld $16,0($29)\n\t"
        "daddu $2,$15,$0\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
