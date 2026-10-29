#include "../common/types.h"

// FUN_0022d1d8 (96 bytes)
// Code: frame of 16 bytes, saves s0 and ra. Calls the unnamed function at 0x2282f0 with
// a0 = halfword at a0+4. If it returns non-zero, returns early. Otherwise calls 0x227ca8
// with a0 = a0+8, then loads bytes at offsets 6, 7, 12, 13, 14 and tail-calls 0x15c958.
// Whole body is one noreorder asm block (the jal targets have no function rows).
void func_0022d1d8(u32 a0) __attribute__((noreturn));
void func_0022d1d8(u32 a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "jal 0x2282f0\n\t"
        " lh $4,4($4)\n\t"
        "bnez $2,1f\n\t"
        " addiu $4,$16,8\n\t"
        "jal 0x227ca8\n\t"
        " nop\n\t"
        "lbu $9,7($16)\n\t"
        "daddu $4,$2,$0\n\t"
        "lbu $5,12($16)\n\t"
        "lbu $6,13($16)\n\t"
        "lbu $7,14($16)\n\t"
        "lbu $8,6($16)\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "j 0x15c958\n\t"
        " addiu $29,$29,16\n\t"
        "1:\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
