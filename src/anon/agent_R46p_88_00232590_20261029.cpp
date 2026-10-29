#include "../common/types.h"

// FUN_00232590 (92 bytes)
// Code: frame of 16 bytes, saves s0 and ra. Sets s0 = 0x360000 and stores zero to the byte
// at s0-7335. Calls the unnamed function at 0x2283e0; if it returns 0, returns (beqzl).
// Otherwise calls 0x227120(), then 0x2ff538(v0, 0x370000+4848, 12). If that returns
// non-zero, returns (bnezl). Otherwise stores 1 to the byte at s0-7335 and returns.
// Whole body is one noreorder asm block: gcc does not emit the branch-likely forms.
void func_00232590(void) __attribute__((noreturn));
void func_00232590(void) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "lui $16,0x36\n\t"
        "jal 0x2283e0\n\t"
        " sb $0,-7335($16)\n\t"
        "beqzl $2,1f\n\t"
        " ld $16,0($29)\n\t"
        "jal 0x227120\n\t"
        " nop\n\t"
        "lui $5,0x37\n\t"
        "daddu $4,$2,$0\n\t"
        "addiu $5,$5,4848\n\t"
        "jal 0x2ff538\n\t"
        " addiu $6,$0,12\n\t"
        "bnezl $2,1f\n\t"
        " ld $16,0($29)\n\t"
        "addiu $15,$0,1\n\t"
        "sb $15,-7335($16)\n\t"
        "ld $16,0($29)\n\t"
        "1:\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
