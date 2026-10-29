#include "../common/types.h"

// Agent R46p_45 (2026-10-29): FUN_001b1e80 (100 bytes, SLPM_666.75). Retry of the R46p_39 draft.
// If arg0 is -1, or equals the word at D_00350000+3868, return. Otherwise call 0x102818 with
// (word at D_00330000-18148, 0, 0x55730, 0x1b1ee8, 4096), store the result at D_01d50000-29628,
// and store arg0 at +4 of the result.
// Whole-body asm: the callee 0x102818 has a layout row but no functions.tsv row, so it is a numeric
// jal target. The lui of 0x35/0x33/0x1d5 and the lui a2 / lw order are written out in the asm.
void func_001b1e80(u32 a0) asm("func_001b1e80");
#if 0
void func_001b1e80(u32 a0) {
}
#endif

__asm__(
    ".section .text.func_001b1e80,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001b1e80\n"
    ".type func_001b1e80, @function\n"
    "func_001b1e80:\n"
    "addiu $29,$29,-16\n"
    "addiu $15,$0,-1\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "beq $4,$15,agent_R46p_45_001b1e80_L1\n"
    "daddu $16,$4,$0\n"
    "lui $15,0x35\n"
    "lw $14,3868($15)\n"
    "beq $4,$14,agent_R46p_45_001b1e80_L1\n"
    "lui $15,0x33\n"
    "lui $6,0x5\n"
    "lw $4,-18148($15)\n"
    "lui $7,0x1b\n"
    "addiu $7,$7,7912\n"
    "daddu $5,$0,$0\n"
    "ori $6,$6,0x5730\n"
    "jal 0x102818\n"
    "addiu $8,$0,4096\n"
    "lui $15,0x1d5\n"
    "sw $2,-29628($15)\n"
    "sw $16,4($2)\n"
    "agent_R46p_45_001b1e80_L1:\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001b1e80, .-func_001b1e80\n"
    ".text\n");
