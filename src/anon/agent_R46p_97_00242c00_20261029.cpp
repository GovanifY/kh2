#include "../common/types.h"

// FUN_00242c00 (108 bytes). Whole-body noreorder asm, top-level, so gcc emits no frame.
// Calls numeric 0x1058e8 (getSaveRam), updates the flag word at result+16800: bit 5 is
// replaced by (a0 & 0xff) == 0, then tail-style calls 0x242bd0 / 0x242b58 with a0.
// If both return 0, it tail-calls 0x242b88 with a0 = 1. Delay slots carry the andi, the
// sd/ld restores and the addiu sp, so the sequence is kept literally.
u32 r_FUN_00242c00(void) asm("func_00242c00");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_00242c00(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_00242c00,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00242c00\n"
    ".type func_00242c00, @function\n"
    "func_00242c00:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x1058e8\n"
    "andi $16,$4,0xff\n"
    "sltiu $16,$16,1\n"
    "addiu $2,$2,16800\n"
    "addiu $14,$0,-33\n"
    "lw $15,4($2)\n"
    "sll $16,$16,5\n"
    "and $15,$15,$14\n"
    "or $15,$15,$16\n"
    "jal 0x242bd0\n"
    "sw $15,4($2)\n"
    "bnez $2,3f\n"
    "ld $16,0($29)\n"
    "jal 0x242b58\n"
    "nop\n"
    "bnez $2,3f\n"
    "ld $16,0($29)\n"
    "addiu $4,$0,1\n"
    "ld $31,8($29)\n"
    "j 0x242b88\n"
    "addiu $29,$29,16\n"
    "3:\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00242c00, .-func_00242c00\n"
    ".text\n");
