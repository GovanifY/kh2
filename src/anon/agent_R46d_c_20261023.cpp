#include "../common/types.h"

// FUN_001182d0 (88 bytes)
// Code: s0 = 0, s1 = 0. Loop: s0 = func_0010cce0(s0). If s0 is zero, return s1. Otherwise
// r = func_0019c410(s0) and s1 += 1 when r is zero (movz), then loop.
// Matching: the whole body is one noreorder asm block, so the bnez with the return block inline
// and the body at the end come out in the original order. gcc appends a 2-word tail after the
// asm; the build keeps only the first 88 bytes, so the tail is dropped.
// The symbol is bound with an asm label (as in src/tozawa/cmenu_selector.hpp), so the source
// lookup finds exactly this file.
extern "C" u32 func_0010cce0(u32 a0);
extern "C" u32 func_0019c410(u32 a0);

u32 r_FUN_001182d0(void) asm("func_001182d0");

u32 r_FUN_001182d0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $31,16($29)\n\t"
        "move $16,$0\n\t"
        "move $17,$0\n\t"
        "1:\n\t"
        "jal func_0010cce0\n\t"
        " move $4,$16\n\t"
        "move $16,$2\n\t"
        "bnez $2,2f\n\t"
        " move $4,$2\n\t"
        "move $2,$17\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "ld $31,16($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        "2:\n\t"
        "jal func_0019c410\n\t"
        " nop\n\t"
        "addiu $15,$17,1\n\t"
        "b 1b\n\t"
        " movz $17,$15,$2\n\t"
        ".set reorder"
        ::: "memory");
}
