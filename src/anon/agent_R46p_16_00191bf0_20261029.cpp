#include "../common/types.h"

// Agent R46p_16 (2026-10-29): func_00191bf0 (48 bytes), SLPM_666.75.
// Code: keeps the float argument in f0, stores it as a word at D_01c60000 + 6504, then loads the
// float at (word at D_00350000 + 8496) + 80, multiplies it by the argument and tail-jumps to
// func_00191c30 with the product in f12.
// Guess: a scale-and-forward step on a float state value.
// Matching: plain C gives a different frame (no ra save around the store). Form (b): whole-body asm
// with the original sequence and a numeric tail j. The 16-byte frame is kept for the ra save.

void r_func_00191bf0(void) asm("func_00191bf0");
#if 0
void r_func_00191bf0(void) {
}
#endif

__asm__(
    ".section .text.func_00191bf0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00191bf0\n"
    ".type func_00191bf0, @function\n"
    "func_00191bf0:\n"
    "mov.s $f0,$f12\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x35\n"
    "sd $31,0($29)\n"
    "lui $14,0x1c6\n"
    "lw $13,8496($15)\n"
    "swc1 $f12,6504($14)\n"
    "ld $31,0($29)\n"
    "lwc1 $f12,80($13)\n"
    "mul.s $f12,$f12,$f0\n"
    "j 0x191c30\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00191bf0, .-func_00191bf0\n"
    ".text\n");
