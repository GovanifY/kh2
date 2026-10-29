#include "../common/types.h"

// FUN_0019d4f8 (80 bytes, not 32: the tail at 0x19d518 is inside this function).
// Clears the words at +8 and +4 of a0, then falls into a block that saves s0 and ra,
// calls 0x1bc688(a0 + 36), and tail-jumps to 0x190128(a0 + 12) with the frame restored.
// Whole-body asm in a noreturn function; callees have no functions.tsv row, so jal/j are numeric.
void func_0019d4f8(u32 a0) __attribute__((noreturn));
void func_0019d4f8(u32 a0) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sw $0,8($4)\n\t"
        "sd $31,0($29)\n\t"
        "sw $0,4($4)\n\t"
        "ld $31,0($29)\n\t"
        "j 1f\n\t"
        "addiu $29,$29,16\n\t"
        "nop\n\t"
        "1:\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "addiu $4,$4,36\n\t"
        "jal 0x1bc688\n\t"
        "addiu $16,$16,12\n\t"
        "daddu $4,$16,$0\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "j 0x190128\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
