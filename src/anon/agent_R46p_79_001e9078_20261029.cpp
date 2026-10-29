#include "../common/types.h"

// Agent R46p_79 (2026-10-29): FUN_001e9078 (92 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves ra only. Stores a1->4 at a0 + (word at (a2->12)) + 160,
// then, if the word at 0x1da0000-5472 is non-zero, loads the pointer table entry
// t5 + a0->8->14 (byte) * 4; if that entry is non-zero, calls it through jalr with
// a0 unchanged and a1 = a1->4 (the load sits in the jalr delay slot).
// Matching: whole-function file-scope __asm__ (form b) with numeric jalr; plain C
// would reuse the a1->4 value and not reproduce the delay-slot reload.
void r_FUN_001e9078(void) asm("func_001e9078");
#if 0
void r_FUN_001e9078(void) {
}
#endif

__asm__(
    ".section .text.func_001e9078,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001e9078\n"
    ".type func_001e9078, @function\n"
    "func_001e9078:\n"
    "addiu $29,$29,-16\n"
    "lw $14,12($6)\n"
    "sd $31,0($29)\n"
    "lw $15,0($14)\n"
    "lw $13,4($5)\n"
    "addu $15,$4,$15\n"
    "lui $14,0x1da\n"
    "sw $13,160($15)\n"
    "lw $13,-5472($14)\n"
    "beq $13,$0,1f\n"
    "ld $31,0($29)\n"
    "lw $14,8($4)\n"
    "lbu $15,14($14)\n"
    "sll $15,$15,2\n"
    "addu $15,$15,$13\n"
    "lw $15,0($15)\n"
    "beq $15,$0,1f\n"
    "nop\n"
    "jalr $15\n"
    "lw $5,4($5)\n"
    "ld $31,0($29)\n"
    "1:\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001e9078, .-func_001e9078\n"
    ".text\n");
