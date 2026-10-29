#include "../common/types.h"

// FUN_001e2c00 (92 bytes, 23 instructions, non-leaf). If a0 is zero, calls FUN_002fdfc8 twice with
// constants from 0x370000 (the second with a3 = 357 in a2) and executes break; otherwise calls
// FUN_001e7cc0(s0) with s0 = a0. Whole-body file-scope asm: the prologue saves s0 before ra and
// the bnez delay slot holds move s0,a0, which plain C does not reproduce. Needs -falign-functions=1
// (92 bytes).
void r_func_001e2c00(void) asm("func_001e2c00");
#if 0
void r_func_001e2c00(void) {
}
#endif

__asm__(
    ".section .text.func_001e2c00,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001e2c00\n"
    ".type func_001e2c00, @function\n"
    "func_001e2c00:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "bnez $4,1f\n"
    "daddu $16,$4,$0\n"
    "lui $4,0x37\n"
    "lui $5,0x37\n"
    "addiu $4,$4,-5768\n"
    "jal 0x2fdfc8\n"
    "addiu $5,$5,-5696\n"
    "lui $5,0x37\n"
    "lui $4,0x37\n"
    "addiu $5,$5,-5680\n"
    "addiu $6,$0,357\n"
    "jal 0x2fdfc8\n"
    "addiu $4,$4,-5736\n"
    "break\n"
    "1:\n"
    "jal 0x1e7cc0\n"
    "daddu $4,$16,$0\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001e2c00, .-func_001e2c00\n"
    ".text\n");
