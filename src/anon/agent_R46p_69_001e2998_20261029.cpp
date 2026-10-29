#include "../common/types.h"

// FUN_001e2998 (72 bytes, 18 instructions, non-leaf). Loads the word at 0x352bd0 through s1 = 0x350000.
// If it is non-zero, calls FUN_001e2898(p) (numeric jal, nop in the delay slot) and then
// AREA::Free(p) (numeric jal to 0x105110). Clears the word in both paths; the beqz delay slot
// holds move a0,s0. Whole-body file-scope asm: gcc's C prologue puts lui and sd ra in the wrong
// order, and the beqz with the sw in the target block needs the explicit form.
void r_func_001e2998(void) asm("func_001e2998");
#if 0
void r_func_001e2998(void) {
}
#endif

__asm__(
    ".section .text.func_001e2998,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001e2998\n"
    ".type func_001e2998, @function\n"
    "func_001e2998:\n"
    "addiu $29,$29,-32\n"
    "sd $17,8($29)\n"
    "sd $16,0($29)\n"
    "lui $17,0x35\n"
    "sd $31,16($29)\n"
    "lw $16,11216($17)\n"
    "beqz $16,1f\n"
    "daddu $4,$16,$0\n"
    "jal 0x1e2898\n"
    "nop\n"
    "jal 0x105110\n"
    "daddu $4,$16,$0\n"
    "1:\n"
    "sw $0,11216($17)\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001e2998, .-func_001e2998\n"
    ".text\n");
