#include "../common/types.h"

// FUN_002ba7c8 (72 bytes)
// Code: loops while FUN_002ba200(p) is non-zero, calling FUN_00102448(p, 0) each time.
// Returns 0 when the first call returns zero.
// Guess: a poll loop that yields a task while a sound check is pending.
// Matching: the whole body is one noreorder asm block. Plain C reloads the argument before
// the first call (the original does not), so the loop shape differs. The original branches back
// to the first call without reloading $4, and the asm reproduces that exactly.
// The build truncates the gcc tail after the asm to the registered size (72).

u32 func_002ba7c8(u32 a0) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "move $16,$4\n\t"
        ".Lloop_002ba7c8:\n\t"
        "jal 0x2ba200\n\t"
        " nop\n\t"
        "move $4,$16\n\t"
        "bnez $2,.Lyield_002ba7c8\n\t"
        " move $5,$0\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".p2align 3\n\t"
        ".Lyield_002ba7c8:\n\t"
        "jal 0x102448\n\t"
        " nop\n\t"
        "b .Lloop_002ba7c8\n\t"
        " nop\n\t"
        ".set reorder"
        ::: "memory");
    return 0;
}
