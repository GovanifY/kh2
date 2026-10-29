#include "../common/types.h"

// Agent R46p_118 (2026-10-29): FUN_002b1aa0 (80 bytes), SLPM_666.75.
// w = *(u32*)func_002b23e0(-1); if (w & 0x04000000) return 20690;
// if (w & 0x10000000) return *(u32*)(0x370000 + 19620); else return *(u32*)(0x370000 + 19624).
// Whole-body noreorder asm with a numeric jal, because the callee has no usable named label.

u32 r_FUN_002b1aa0(void) asm("func_002b1aa0");
#if 0
u32 r_FUN_002b1aa0(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_002b1aa0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002b1aa0\n"
    ".type func_002b1aa0, @function\n"
    "func_002b1aa0:\n"
    "addiu $29,$29,-16\n"
    "sd $31,0($29)\n"
    "jal 0x2b23e0\n"
    "addiu $4,$0,-1\n"
    "lw $13,0($2)\n"
    "lui $14,0x1000\n"
    "lui $15,0x400\n"
    "and $14,$13,$14\n"
    "and $13,$13,$15\n"
    "bne $13,$0,3f\n"
    "addiu $2,$0,20690\n"
    "beq $14,$0,4f\n"
    "lui $15,0x37\n"
    "lw $2,19620($15)\n"
    "3:\n"
    "ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "4:\n"
    "lui $15,0x37\n"
    "beq $0,$0,3b\n"
    "lw $2,19624($15)\n"
    ".set pop\n"
    ".size func_002b1aa0, .-func_002b1aa0\n"
    ".text\n");
