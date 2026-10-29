#include "../common/types.h"

// Agent R46p_49 (2026-10-29): func_001ca950 (56 bytes), SLPM_666.75.
// Saves s0, s1, ra; s0 = a0; calls 0x1c6fa8 with the delay-slot move s1 = t1; then stores s1 to
// +84 and zero to +88 of the object at s0.
// The jal target has no functions.tsv row and the delay slot holds a move from t1, so this is
// form (b): whole-body asm with a numeric jal.
void r_FUN_001ca950(void) asm("func_001ca950");
#if 0
void r_FUN_001ca950(void) {
}
#endif

__asm__(
    ".section .text.func_001ca950,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001ca950\n"
    ".type func_001ca950, @function\n"
    "func_001ca950:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "daddu $16,$4,$0\n"
    "jal 0x1c6fa8\n"
    "daddu $17,$9,$0\n"
    "sw $17,84($16)\n"
    "sw $0,88($16)\n"
    "ld $17,8($29)\n"
    "ld $16,0($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001ca950, .-func_001ca950\n"
    ".text\n");
