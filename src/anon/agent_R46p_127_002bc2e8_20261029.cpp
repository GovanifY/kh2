#include "../common/types.h"

// FUN_002bc2e8 (108 bytes)
// Code: r = FUN_002bc158(arg0, arg1, arg2). If r is zero, returns 0. Otherwise calls
// FUN_002bb310(r, arg0, arg1, arg2) and returns the word at +20 of r.
// Guess: a lookup that, when it finds a record, runs a helper on it and returns a field.
// Matching: whole body as one noreorder asm block. The original keeps arg1 in s0 and arg0 in s1,
// which plain C did not reproduce.

u32 func_002bc2e8(u32 a0, u32 a1, u32 a2) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-48\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $18,16($29)\n\t"
        "move $16,$5\n\t"
        "sd $19,24($29)\n\t"
        "move $17,$4\n\t"
        "sd $31,32($29)\n\t"
        "jal 0x2bc158\n\t"
        " move $18,$6\n\t"
        "move $19,$2\n\t"
        "move $4,$2\n\t"
        "move $5,$17\n\t"
        "move $6,$16\n\t"
        "move $7,$18\n\t"
        "beqz $19,.Lret_002bc2e8\n\t"
        " move $2,$0\n\t"
        "jal 0x2bb310\n\t"
        " nop\n\t"
        "lw $2,20($19)\n\t"
        ".Lret_002bc2e8:\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "ld $18,16($29)\n\t"
        "ld $19,24($29)\n\t"
        "ld $31,32($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,48\n\t"
        ".set reorder"
        ::: "memory");
    return 0;
}
