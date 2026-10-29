#include "../common/types.h"

// Agent R46p_60 (2026-10-29): FUN_001d6d00 (88 bytes, SLPM_666.75).
// Code: frame of 16 bytes (s0, ra). Walks a list with FUN_001d6cc8, passing each result back in. A
// non-null node whose halfword at +0 equals arg0 gives ((node - word at 0x01d60000-17768) - 8) >> 6, plus 1.
// Otherwise returns 0. The epilogue is shared by both exits, and the found block sits after it, so the
// branch-likely and the delay-slot layout are not reachable from plain C. Matching: whole-body asm.
void r_FUN_001d6d00(void) asm("func_001d6d00");
#if 0
void r_FUN_001d6d00(void) {
}
#endif

__asm__(
    ".section .text.func_001d6d00,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001d6d00\n"
    ".type func_001d6d00, @function\n"
    "func_001d6d00:\n"
    "addiu $29,$29,-16\n"
    "daddu $2,$0,$0\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$4,$0\n"
    "1:\n"
    "jal 0x1d6cc8\n"
    "daddu $4,$2,$0\n"
    "bnezl $2,3f\n"
    "lhu $15,0($2)\n"
    "daddu $2,$0,$0\n"
    "2:\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "3:\n"
    "bne $15,$16,1b\n"
    "lui $14,0x1d6\n"
    "lw $15,-17768($14)\n"
    "subu $15,$2,$15\n"
    "addiu $15,$15,-8\n"
    "sra $15,$15,6\n"
    "b 2b\n"
    "addiu $2,$15,1\n"
    ".set pop\n"
    ".size func_001d6d00, .-func_001d6d00\n"
    ".text\n");
