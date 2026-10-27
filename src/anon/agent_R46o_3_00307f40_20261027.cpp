#include "../common/types.h"

// FUN_00307f40 (40 bytes): frame of 16. move a0,a2; if a0 != 0 calls FUN_00306e80(a0). Returns 1.
// Whole body is one noreorder asm block.
extern "C" void func_00306e80(void);

u32 func_00307f40(u32 a0, u32 a1, u32 a2) __attribute__((noreturn));
u32 func_00307f40(u32 a0, u32 a1, u32 a2) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "daddu $4,$6,$0\n\t"
        "beqz $4,1f\n\t"
        " sd $31,0($29)\n\t"
        "jal func_00306e80\n\t"
        " nop\n"
        "1:\n\t"
        "ld $31,0($29)\n\t"
        "addiu $2,$0,1\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
