#include "../common/types.h"

// FUN_0022cf18 (68 bytes)
// Code: frame of 16 bytes, saves s0 and ra. Saves a0 in s0, calls the unnamed
// function at 0x2f1670 with a0 = 0x1DAD990. If it returns non-zero, restores and returns.
// Otherwise tail-calls 0x1024a8 with a0 = the saved pointer.
// Whole body is one noreorder asm block (the jal target has no function row).
void func_0022cf18(u32 a0) __attribute__((noreturn));
void func_0022cf18(u32 a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "lui $4,0x1db\n\t"
        "jal 0x2f1670\n\t"
        " addiu $4,$4,-9840\n\t"
        "bnez $2,1f\n\t"
        " daddu $4,$16,$0\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,8($29)\n\t"
        "j 0x1024a8\n\t"
        " addiu $29,$29,16\n\t"
        "1:\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
