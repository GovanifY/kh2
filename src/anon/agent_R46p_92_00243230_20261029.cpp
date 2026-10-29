#include "../common/types.h"

// Agent R46p_92 (2026-10-29): FUN_00243230 (104 bytes, SLPM_666.75).
// idx = a0 * 8 + a1; p = jal 0x1058e8 result + 18904 + (idx >> 5) * 4; bit = 1 << (idx & 31);
// if the word at p has no bit set, store the word with the bit set (beql in the original).
// Matching: gcc 3.2 has no branch-likely, so the whole body is one file-scope asm block with the
// original instruction order and a numeric jal target.
void r_FUN_00243230(void) asm("func_00243230");
#if 0
void r_FUN_00243230(void) {
}
#endif

__asm__(
    ".section .text.func_00243230,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00243230\n"
    ".type func_00243230, @function\n"
    "func_00243230:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "daddu $16,$4,$0\n"
    "sd $31,16($29)\n"
    "daddu $17,$5,$0\n"
    "jal 0x1058e8\n"
    "sll $16,$16,3\n"
    "addu $16,$16,$17\n"
    "srl $13,$16,5\n"
    "addiu $2,$2,18904\n"
    "sll $13,$13,2\n"
    "andi $16,$16,0x1f\n"
    "addu $13,$13,$2\n"
    "addiu $14,$0,1\n"
    "lw $15,0($13)\n"
    "sllv $14,$14,$16\n"
    "or $12,$15,$14\n"
    "and $15,$15,$14\n"
    "beql $15,$0,agent_R46p_92_00243230_L54\n"
    "sw $12,0($13)\n"
    "agent_R46p_92_00243230_L54:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_00243230, .-func_00243230\n"
    ".text\n");
