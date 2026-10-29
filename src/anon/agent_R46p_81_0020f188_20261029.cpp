#include "../common/types.h"

// Asm label alias: registers func_0020f188 with this file (no C definition is emitted).
void r_FUN_0020f188(void) asm("func_0020f188");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_0020f188(void) {
}
#endif

// FUN_0020f188 (88 bytes). Top-level asm, so gcc emits no prologue or epilogue.
// Reads two 64-bit words at 0x01da8bb0 + 64 and + 72 (base 0x01db0000 - 29776). It stores them
// at s0 - 26304 + 32 and + 40, where s0 = 0x00360000 - 26304. Then it calls FUN_002f25a0 with
// a0 = a1 = 0 and FUN_002f3918 with a0 = the word at 0x00360000 - 28216 and a1 = s0.
// The callees have no func_ rows, so both calls are numeric jal in the asm.
__asm__(
    ".section .text.func_0020f188,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0020f188\n"
    ".type func_0020f188, @function\n"
    "func_0020f188:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x1db\n"
    "sd $31,8($29)\n"
    "addiu $15,$15,-29776\n"
    "sd $16,0($29)\n"
    "daddu $4,$0,$0\n"
    "daddu $5,$0,$0\n"
    "ld $13,72($15)\n"
    "lui $16,0x36\n"
    "ld $14,64($15)\n"
    "addiu $16,$16,-26304\n"
    "sd $13,40($16)\n"
    "jal 0x2f25a0\n"
    "sd $14,32($16)\n"
    "lui $15,0x36\n"
    "daddu $5,$16,$0\n"
    "jal 0x2f3918\n"
    "lw $4,-28216($15)\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0020f188, .-func_0020f188\n"
    ".text\n");
