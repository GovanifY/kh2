#include "../common/types.h"

// Agent R46k_0 (2026-10-23): FUN_00171a70 (88 bytes), SLPM_666.75.
// base = FUN_00177860(p[0][1]); bits = p[1]; p[0] = bit (bits & 31) of word (bits >> 5) at base.
// Matching: the whole function is one file-scope __asm__ block. Plain C (even with pinned
// registers) puts the ld ra restore after the srl, while the original has it between li and srl.
void r_FUN_00171a70(void) asm("func_00171a70");
#if 0
void r_FUN_00171a70(void) {
}
#endif

__asm__(
    ".section .text.func_00171a70,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00171a70\n"
    ".type func_00171a70, @function\n"
    "func_00171a70:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$4,$0\n"
    "lw $15,0($4)\n"
    "jal func_00177860\n"
    "lw $4,4($15)\n"
    "lw $15,4($16)\n"
    "addiu $13,$0,1\n"
    "ld $31,8($29)\n"
    "srl $14,$15,5\n"
    "andi $15,$15,0x1f\n"
    "sll $14,$14,2\n"
    "sllv $13,$13,$15\n"
    "addu $14,$14,$2\n"
    "lw $15,0($14)\n"
    "and $15,$15,$13\n"
    "sltu $15,$0,$15\n"
    "sw $15,0($16)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00171a70, .-func_00171a70\n"
    ".text\n");
