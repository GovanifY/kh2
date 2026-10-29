#include "../common/types.h"

// Agent R46p_84 (2026-10-29): FUN_0022dd40 (64 bytes, SLPM_666.75).
// ra saved to 0(sp), calls unnamed 0x2282f0(lh a0,4(a0)) with the lh in the jal delay slot.
// If the result is nonzero, returns. Otherwise tail-calls 0x102c18(1, 0x17318, 0x22dc30)
// with a1 built as lui 1 + ori 0x7318.
// Matching: the callee has no functions.tsv row, and the tail call needs a restore before the j,
// so plain C does not give this order. Whole body is one file-scope asm block (form b).
void r_FUN_0022dd40(void) asm("func_0022dd40");
#if 0
void r_FUN_0022dd40(void) {
}
#endif

__asm__(
    ".section .text.func_0022dd40,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0022dd40\n"
    ".type func_0022dd40, @function\n"
    "func_0022dd40:\n"
    "addiu $29,$29,-16\n"
    "sd $31,0($29)\n"
    "jal 0x2282f0\n"
    "lh $4,4($4)\n"
    "lui $5,0x1\n"
    "lui $6,0x23\n"
    "addiu $4,$0,1\n"
    "addiu $6,$6,-9168\n"
    "bnez $2,agent_R46p_84_0022dd40_L1\n"
    "ori $5,$5,0x7318\n"
    "ld $31,0($29)\n"
    "j 0x102c18\n"
    "addiu $29,$29,16\n"
    "agent_R46p_84_0022dd40_L1:\n"
    "ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0022dd40, .-func_0022dd40\n"
    ".text\n");
