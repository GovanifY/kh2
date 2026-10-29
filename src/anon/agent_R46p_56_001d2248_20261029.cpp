#include "../common/types.h"

// Agent R46p_56 (2026-10-29): FUN_001d2248 (80 bytes), SLPM_666.75.
// Whole-body asm (beqzl and bnezl branch-likely forms, which gcc 3.2 does not emit).
// If word +56 < a1, stores a1 at +56 and calls the check_warning routine (func_001d17b0), then
// if word +28 is nonzero and below word +56, sets word +28 to word +56.
void r_FUN_001d2248(void) asm("func_001d2248");
#if 0
void r_FUN_001d2248(void) {
}
#endif

__asm__(
    ".section .text.func_001d2248,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001d2248\n"
    ".type func_001d2248, @function\n"
    "func_001d2248:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lw $15,56($4)\n"
    "slt $15,$15,$5\n"
    "beqz $15,1f\n"
    "daddu $16,$4,$0\n"
    "jal 0x1d17b0\n"
    "sw $5,56($16)\n"
    "lw $15,28($16)\n"
    "beqzl $15,2f\n"
    "ld $16,0($29)\n"
    "lw $14,56($16)\n"
    "slt $15,$15,$14\n"
    "bnezl $15,1f\n"
    "sw $14,28($16)\n"
    "1:\n"
    "ld $16,0($29)\n"
    "2:\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001d2248, .-func_001d2248\n"
    ".text\n");
