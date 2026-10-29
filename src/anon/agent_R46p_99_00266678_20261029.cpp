#include "../common/types.h"

// Agent R46p_99 (2026-10-29): func_00266678 (48 bytes), SLPM_666.75.
// If a1 == 23, calls func_002657a8(). Then calls func_00266988() and tail-jumps to
// func_002666a8() with the frame restored in the j delay slot.
// Plain C cannot keep the tail-call register state, so this is form (b): whole-body asm.
// The jal/j targets are numeric.
void r_FUN_00266678(void) asm("func_00266678");
#if 0
void r_FUN_00266678(void) {
}
#endif

__asm__(
    ".section .text.func_00266678,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00266678\n"
    ".type func_00266678, @function\n"
    "func_00266678:\n"
    "addiu $29,$29,-16\n"
    "addiu $15,$0,23\n"
    "sd $31,0($29)\n"
    "bne $5,$15,1f\n"
    "nop\n"
    "jal 0x2657a8\n"
    "nop\n"
    "1: jal 0x266988\n"
    "nop\n"
    "ld $31,0($29)\n"
    "j 0x2666a8\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00266678, .-func_00266678\n"
    ".text\n");
