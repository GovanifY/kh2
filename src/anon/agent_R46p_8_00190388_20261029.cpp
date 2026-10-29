#include "../common/types.h"

// Agent R46p_8 (2026-10-29): FUN_00190388 (72 bytes, SLPM_666.75). Whole-body asm (form b).
// Plain C matched the body but not the epilogue order: the original copies the 16 bytes
// (sq) before it sets v0 and reloads ra, and the prologue puts sd ra after move s1,a0.
// Calls func_001902a8(arg1, sp) with a 16-byte frame local at sp+0 whose word 3 is zeroed.
// Copies the 16 bytes at sp+16 to arg0 and returns arg0 in v0.

void r_FUN_00190388(void) asm("func_00190388");
#if 0
void r_FUN_00190388(void) {
}
#endif

__asm__(
    ".section .text.func_00190388,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00190388\n"
    ".type func_00190388, @function\n"
    "func_00190388:\n"
    "addiu $29,$29,-64\n"
    "sd $17,40($29)\n"
    "sd $16,32($29)\n"
    "move $17,$4\n"
    "sd $31,48($29)\n"
    "move $4,$5\n"
    "sw $0,12($29)\n"
    "move $5,$29\n"
    "jal func_001902a8\n"
    "addiu $16,$29,16\n"
    "lq $8,0($16)\n"
    "sq $8,0($17)\n"
    "move $2,$17\n"
    "ld $16,32($29)\n"
    "ld $17,40($29)\n"
    "ld $31,48($29)\n"
    "jr $31\n"
    "addiu $29,$29,64\n"
    ".set pop\n"
    ".size func_00190388, .-func_00190388\n"
    ".text\n");
