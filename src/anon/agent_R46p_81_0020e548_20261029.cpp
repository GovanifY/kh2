#include "../common/types.h"

// Asm label alias: registers func_0020e548 with this file (no C definition is emitted).
void r_FUN_0020e548(void) asm("func_0020e548");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_0020e548(void) {
}
#endif

// FUN_0020e548 (68 bytes). Top-level asm, so gcc emits no prologue or epilogue.
// Loads the word at a0+4. If it is zero, it calls FUN_002fe0a0 with a0 = 0x370000 + 1864 and
// FUN_002fd348 with a0 = 1 (both delay slots fall through). Then it loads a2 = u16 at a0+0
// and a1 = u8 at a0+9 and tail-jumps to FUN_0020e2e8 with a3 = the original a1.
// The bnez delay slot holds the move a0,t7, which the fall-through lui overwrites on the zero path.
__asm__(
    ".section .text.func_0020e548,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0020e548\n"
    ".type func_0020e548, @function\n"
    "func_0020e548:\n"
    "addiu $29,$29,-16\n"
    "daddu $14,$4,$0\n"
    "sd $31,0($29)\n"
    "daddu $7,$5,$0\n"
    "lw $15,4($4)\n"
    "bnez $15,1f\n"
    "daddu $4,$15,$0\n"
    "lui $4,0x37\n"
    "jal 0x2fe0a0\n"
    "addiu $4,$4,1864\n"
    "jal 0x2fd348\n"
    "addiu $4,$0,1\n"
    "1:\n"
    "lhu $6,0($14)\n"
    "lbu $5,9($14)\n"
    "ld $31,0($29)\n"
    "j 0x20e2e8\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0020e548, .-func_0020e548\n"
    ".text\n");
