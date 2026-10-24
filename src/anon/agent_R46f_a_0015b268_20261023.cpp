#include "../common/types.h"

// Agent R46f_a (2026-10-23): FUN_0015b268 (100 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves s0 then ra. s0 = 0x350000. If the word at s0 - 21864 is zero, calls
// func_0015ad80(obj, a0, a1) with obj = word at s0 - 21860, bumps the counter, returns. Otherwise
// stores a1 (float) at obj + 436 and tail-calls func_0015aea8(obj).
// Matching: one file-scope __asm__ block. The else tail restores s0, then ra, as in the original.
void r_FUN_0015b268(void) asm("func_0015b268");
#if 0
void r_FUN_0015b268(void) {
}
#endif

__asm__(
    ".section .text.func_0015b268,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0015b268\n"
    ".type func_0015b268, @function\n"
    "func_0015b268:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lui $16,0x35\n"
    "lw $15,-21864($16)\n"
    "bnez $15,2f\n"
    "daddu $5,$4,$0\n"
    "lui $15,0x35\n"
    "jal func_0015ad80\n"
    "lw $4,-21860($15)\n"
    "lw $15,-21864($16)\n"
    "ld $31,8($29)\n"
    "addiu $15,$15,1\n"
    "sw $15,-21864($16)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "2:\n"
    "lui $14,0x35\n"
    "ld $16,0($29)\n"
    "lw $15,-21860($14)\n"
    "ld $31,8($29)\n"
    "swc1 $f12,436($15)\n"
    "lw $4,-21860($14)\n"
    "j func_0015aea8\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0015b268, .-func_0015b268\n"
    ".text\n");
