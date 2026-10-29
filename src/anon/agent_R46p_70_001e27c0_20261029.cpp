#include "../common/types.h"

// Agent R46p_70 (2026-10-29): FUN_001e27c0 (52 bytes), SLPM_666.75.
// Code: frame of 16 bytes. Clears the words at a0 + 3520, +3524, +3532, +3536, +3556, +3564,
// sets the word at a0 + 3584 to -1, then tail-jumps to FUN_001e17b8 (no callable row, so numeric j).
// Matching: the tail j sits before the frame pop's delay slot, so the whole body is one
// top-level asm in .text.func_001e27c0 with a numeric j. Same bytes as FUN_001e2788.
void r_FUN_001e27c0(void) asm("func_001e27c0");
#if 0
void r_FUN_001e27c0(void) {
}
#endif

__asm__(
    ".section .text.func_001e27c0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001e27c0\n"
    ".type func_001e27c0, @function\n"
    "func_001e27c0:\n"
    "addiu $29,$29,-16\n"
    "sw $0,3520($4)\n"
    "sd $31,0($29)\n"
    "addiu $14,$0,-1\n"
    "sw $14,3584($4)\n"
    "sw $0,3524($4)\n"
    "sw $0,3532($4)\n"
    "sw $0,3536($4)\n"
    "sw $0,3556($4)\n"
    "sw $0,3564($4)\n"
    "ld $31,0($29)\n"
    "j 0x1e17b8\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001e27c0, .-func_001e27c0\n"
    ".text\n");
