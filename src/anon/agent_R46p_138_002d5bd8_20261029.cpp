#include "../common/types.h"

// FUN_002d5bd8 (68 bytes): reads the word at +4 of the record at +12 of arg0.
// Returns 1 when that word is 0x37 or 0x38; otherwise tail-returns func_00179b68(arg0).
// Matching: the whole function is one file-scope __asm__ block (the branch and delay-slot
// shape of the original is not produced from C).
void r_FUN_002d5bd8(void) asm("func_002d5bd8");
#if 0
void r_FUN_002d5bd8(void) {
}
#endif

__asm__(
    ".section .text.func_002d5bd8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002d5bd8\n"
    ".type func_002d5bd8, @function\n"
    "func_002d5bd8:\n"
    "addiu $29,$29,-16\n"
    "sd $31,0($29)\n"
    "lw $13,12($4)\n"
    "lw $14,4($13)\n"
    "xori $15,$14,0x37\n"
    "xori $14,$14,0x38\n"
    "beqz $14,1f\n"
    "addiu $2,$0,1\n"
    "bnez $15,2f\n"
    "nop\n"
    "1:\n"
    "ld $31,0($29)\n"
    "3:\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "2:\n"
    "jal func_00179b68\n"
    "nop\n"
    "b 3b\n"
    "ld $31,0($29)\n"
    ".set pop\n"
    ".size func_002d5bd8, .-func_002d5bd8\n"
    ".text\n");
