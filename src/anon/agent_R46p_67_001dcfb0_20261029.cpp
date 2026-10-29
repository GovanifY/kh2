#include "../common/types.h"

// Asm label alias: registers func_001dcfb0 with this file (no C definition is emitted).
void r_FUN_001dcfb0(void) asm("func_001dcfb0");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_001dcfb0(void) {
}
#endif

// FUN_001dcfb0 (60 bytes). Whole-body noreorder asm, top-level, so gcc emits no frame.
// Walks the list headed by the word at 0x352ae0: calls 0x1dc878 on each node, with the
// next pointer (word at +40) loaded in the jal delay slot. s0 holds the cursor.
__asm__(
    ".section .text.func_001dcfb0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001dcfb0\n"
    ".type func_001dcfb0, @function\n"
    "func_001dcfb0:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x35\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lw $4,10976($15)\n"
    "beq $4,$0,2f\n"
    "ld $16,0($29)\n"
    "1:\n"
    "jal 0x1dc878\n"
    "lw $16,40($4)\n"
    "bne $16,$0,1b\n"
    "daddu $4,$16,$0\n"
    "ld $16,0($29)\n"
    "2:\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001dcfb0, .-func_001dcfb0\n"
    ".text\n");
