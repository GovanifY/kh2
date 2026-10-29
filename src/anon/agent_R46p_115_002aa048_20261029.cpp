#include "../common/types.h"

// Agent R46p_115 (2026-10-29): FUN_002aa048 (80 bytes), SLPM_666.75.
// base = func_002a9d68(a0); word index a0 >> 5 (byte offset x4); bit a0 & 31.
// If the bit is clear, store word | bit back. The original has a beqzl whose delay slot is the
// store, which plain C did not produce (gcc gives bnez with the or in the delay slot), so this is
// a whole-body noreorder asm with numeric jal target.

u32 r_FUN_002aa048(void) asm("func_002aa048");
#if 0
u32 r_FUN_002aa048(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_002aa048,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002aa048\n"
    ".type func_002aa048, @function\n"
    "func_002aa048:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x2a9d68\n"
    "daddu $16,$4,$0\n"
    "srl $15,$16,5\n"
    "addiu $14,$0,1\n"
    "sll $15,$15,2\n"
    "andi $16,$16,0x1f\n"
    "addu $13,$15,$2\n"
    "sllv $14,$14,$16\n"
    "lw $15,0($13)\n"
    "or $12,$15,$14\n"
    "and $15,$15,$14\n"
    "beqzl $15,1f\n"
    "sw $12,0($13)\n"
    "1:\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002aa048, .-func_002aa048\n"
    ".text\n");
