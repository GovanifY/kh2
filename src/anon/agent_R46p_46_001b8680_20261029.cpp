#include "../common/types.h"

// Agent R46p_46 (2026-10-29): FUN_001b8680 (92 bytes), SLPM_666.75.
// Decrements the counter word at 0x1d5 lui + -29496 + 192, reads the entry at +160 + index * 20
// (mult by 20 written as the raw R5900 3-operand word), then calls FUN_001b8450(entry) and returns entry.
// Form: whole-body asm. The prologue stores ra before s0 and the arguments are moved in the
// original order (move a2,a1 before move a1,a0). The mult is the raw .word 0x020e8018 (mult s0,s0,t6).
void r_FUN_001b8680(void) asm("func_001b8680");
#if 0
void r_FUN_001b8680(void) {
}
#endif

__asm__(
    ".section .text.func_001b8680,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001b8680\n"
    ".type func_001b8680, @function\n"
    "func_001b8680:\n"
    "addiu $29,$29,-16\n"
    "lui $13,0x1d5\n"
    "sd $31,8($29)\n"
    "addiu $13,$13,-29496\n"
    "sd $16,0($29)\n"
    "daddu $6,$5,$0\n"
    "daddu $5,$4,$0\n"
    "lw $14,192($13)\n"
    "addiu $14,$14,-1\n"
    "sll $15,$14,2\n"
    "sw $14,192($13)\n"
    "addu $15,$15,$13\n"
    "lw $16,160($15)\n"
    "addiu $14,$0,20\n"
    ".word 0x020e8018\n"
    "addu $16,$16,$13\n"
    "jal 0x1b8450\n"
    "daddu $4,$16,$0\n"
    "daddu $2,$16,$0\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001b8680, .-func_001b8680\n"
    ".text\n");
