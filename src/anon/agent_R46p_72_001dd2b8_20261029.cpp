#include "../common/types.h"

// FUN_001dd2b8 (104 bytes)
// Code: if byte at 0x352af1 is nonzero, restore and return. Otherwise, if byte at
// 0x352af0 is zero, return. Otherwise call 0x106a18(0), save its result in s0,
// call 0x106a60(0), then tail-call 0x1dd320(retval_of_second, 1).
// Guess: conditional two-step query followed by a tail call into the next function.
// Whole-body asm: the epilogue ld ra/ld s0 interleave with the tail call and the
// branch-delay slots, which plain C did not reproduce.
void func_001dd2b8(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x35\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "lbu $14,10993($15)\n\t"
        "bnez $14,1f\n\t"
        "ld $16,0($29)\n\t"
        "lui $15,0x35\n\t"
        "lbu $14,10992($15)\n\t"
        "beqz $14,2f\n\t"
        "ld $31,8($29)\n\t"
        "jal 0x106a18\n\t"
        "daddu $4,$0,$0\n\t"
        "daddu $16,$2,$0\n\t"
        "jal 0x106a60\n\t"
        "daddu $4,$0,$0\n\t"
        "daddu $4,$16,$0\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "daddu $5,$2,$0\n\t"
        "addiu $6,$0,1\n\t"
        "j 0x1dd320\n\t"
        "addiu $29,$29,16\n\t"
        "1:\n\t"
        "ld $31,8($29)\n\t"
        "2:\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder\n\t"
        : : : "memory");
}
