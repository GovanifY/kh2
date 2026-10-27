#include "../common/types.h"

// FUN_00305df8 (40 bytes): frame of 16. If a0 == 1, calls FUN_0030f468(a1). Returns 0.
// Whole body is one noreorder asm block; sd ra sits in the bne delay slot as in the original.
extern "C" void func_0030f468(void);

u32 func_00305df8(u32 a0, u32 a1) __attribute__((noreturn));
u32 func_00305df8(u32 a0, u32 a1) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "addiu $2,$0,1\n\t"
        "bne $4,$2,1f\n\t"
        " sd $31,0($29)\n\t"
        "jal func_0030f468\n\t"
        " daddu $4,$5,$0\n"
        "1:\n\t"
        "ld $31,0($29)\n\t"
        "daddu $2,$0,$0\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
