#include "../common/types.h"

// Asm label alias: registers func_001bdcd0 with this file (no C definition is emitted).
u32 r_FUN_001bdcd0(void) asm("func_001bdcd0");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_001bdcd0(void) {
    return 0;
}
#endif

// FUN_001bdcd0 (80 bytes). Top-level asm: both callees (0x001819c0, 0x001bd590) have no
// functions.tsv row, so they are numeric jal targets. The shared return label is reached by a
// beqz whose delay slot already holds the result move.
__asm__(
    ".section .text.func_001bdcd0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001bdcd0\n"
    ".type func_001bdcd0, @function\n"
    "func_001bdcd0:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "daddu $16,$4,$0\n"
    "jal 0x1819c0\n"
    "daddu $17,$0,$0\n"
    "beqz $2,1f\n"
    "daddu $4,$16,$0\n"
    "jal 0x1bd590\n"
    "nop\n"
    "beqz $2,2f\n"
    "daddu $2,$17,$0\n"
    "1:\n"
    "addiu $17,$0,1\n"
    "daddu $2,$17,$0\n"
    "2:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001bdcd0, .-func_001bdcd0\n"
    ".text\n");
