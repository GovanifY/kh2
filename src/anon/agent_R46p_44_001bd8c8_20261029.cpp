#include "../common/types.h"

// Agent R46p_44 (2026-10-29): FUN_001bd8c8 (80 bytes, SLPM_666.75).
// Whole-body asm (form b). Plain C put the prologue saves, the lhu delay slot and the second call's
// argument moves in the wrong order, and the second call became a tail jump.
// Code: base = *(*(a0 + 2240)); off = *(base + 108) * 12; r = call(lhu(base + off + 14)) through the
// mangled u_call4 at 001b8e88 (numeric jal); then func_001bd918(a0, r, 0) (numeric jal, not a tail).
void func_001bd8c8(void) asm("func_001bd8c8");
#if 0
void func_001bd8c8(void) {
}
#endif

__asm__(
    ".section .text.func_001bd8c8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001bd8c8\n"
    ".type func_001bd8c8, @function\n"
    "func_001bd8c8:\n"
    "addiu $29,$29,-16\n"
    "sd $31,8($29)\n"
    "sd $16,0($29)\n"
    "lw $14,2240($4)\n"
    "daddu $16,$4,$0\n"
    "lw $13,0($14)\n"
    "lw $15,108($13)\n"
    "addiu $14,$0,12\n"
    ".word 0x01ee7818\n"
    "addu $13,$13,$15\n"
    "jal 0x1b8e88\n"
    "lhu $4,14($13)\n"
    "daddu $4,$16,$0\n"
    "daddu $5,$2,$0\n"
    "jal 0x1bd918\n"
    "daddu $6,$0,$0\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001bd8c8, .-func_001bd8c8\n"
);
