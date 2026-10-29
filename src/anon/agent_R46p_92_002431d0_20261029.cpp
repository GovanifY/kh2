#include "../common/types.h"

// Agent R46p_92 (2026-10-29): FUN_002431d0 (92 bytes, SLPM_666.75).
// idx = a0 * 8 + a1; base = jal 0x1058e8 (getSaveRam, mangled row); word = *(base + (idx >> 5) * 4 + 18904);
// returns whether bit (idx & 31) of that word is set.
// Matching: plain C reorders the s1 restore and the li/sllv pair. The whole body is one file-scope asm
// block with the original instruction order and a numeric jal target.
void r_FUN_002431d0(void) asm("func_002431d0");
#if 0
void r_FUN_002431d0(void) {
}
#endif

__asm__(
    ".section .text.func_002431d0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002431d0\n"
    ".type func_002431d0, @function\n"
    "func_002431d0:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "daddu $16,$4,$0\n"
    "daddu $17,$5,$0\n"
    "jal 0x1058e8\n"
    "sll $16,$16,3\n"
    "addu $16,$16,$17\n"
    "srl $14,$16,5\n"
    "ld $17,8($29)\n"
    "sll $14,$14,2\n"
    "ld $31,16($29)\n"
    "addu $2,$2,$14\n"
    "andi $16,$16,0x1f\n"
    "lw $2,18904($2)\n"
    "addiu $15,$0,1\n"
    "sllv $15,$15,$16\n"
    "and $2,$2,$15\n"
    "ld $16,0($29)\n"
    "sltu $2,$0,$2\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_002431d0, .-func_002431d0\n"
    ".text\n");
