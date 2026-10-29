#include "../common/types.h"

// Agent R46p_118 (2026-10-29): FUN_002abdc8 (96 bytes), SLPM_666.75.
// base = func_002a9d68() + 320; for i in 0..3: if bit i of base[i>>5] is clear, set it.
// Whole-body noreorder asm with a do-while loop and a numeric jal, as in the original.

void r_FUN_002abdc8(void) asm("func_002abdc8");
#if 0
void r_FUN_002abdc8(void) {
    return;
}
#endif

__asm__(
    ".section .text.func_002abdc8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002abdc8\n"
    ".type func_002abdc8, @function\n"
    "func_002abdc8:\n"
    "addiu $29,$29,-16\n"
    "sd $31,0($29)\n"
    "jal 0x2a9d68\n"
    "nop\n"
    "addiu $2,$2,320\n"
    "daddu $11,$0,$0\n"
    "addiu $9,$0,1\n"
    "srl $15,$11,5\n"
    "1:\n"
    "andi $14,$11,0x1f\n"
    "sll $15,$15,2\n"
    "sllv $14,$9,$14\n"
    "addu $10,$15,$2\n"
    "addiu $11,$11,1\n"
    "lw $15,0($10)\n"
    "or $13,$15,$14\n"
    "and $15,$15,$14\n"
    "bne $15,$0,2f\n"
    "slti $12,$11,4\n"
    "sw $13,0($10)\n"
    "2:\n"
    "bne $12,$0,1b\n"
    "srl $15,$11,5\n"
    "ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002abdc8, .-func_002abdc8\n"
    ".text\n");
