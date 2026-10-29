#include "../common/types.h"

// Asm label alias: registers func_001bded8 with this file (no C definition is emitted).
u32 r_FUN_001bded8(void) asm("func_001bded8");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_001bded8(void) {
    return 0;
}
#endif

// FUN_001bded8 (96 bytes). Top-level asm: the callees 0x001bd370, 0x001bc720, 0x001bd3a0,
// 0x001bdf68, 0x001bdff0 and 0x001d6da8 are numeric jal targets, and the jal delay slots hold
// the a0 moves and the nop. The stores after the last call stay after it.
__asm__(
    ".section .text.func_001bded8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001bded8\n"
    ".type func_001bded8, @function\n"
    "func_001bded8:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x1bd370\n"
    "daddu $16,$4,$0\n"
    "jal 0x1bc720\n"
    "addiu $4,$16,36\n"
    "jal 0x1bc720\n"
    "addiu $4,$16,732\n"
    "sw $0,2528($16)\n"
    "jal 0x1bd3a0\n"
    "daddu $4,$16,$0\n"
    "jal 0x1bdf68\n"
    "daddu $4,$16,$0\n"
    "jal 0x1bdff0\n"
    "nop\n"
    "jal 0x1d6da8\n"
    "addiu $4,$16,2642\n"
    "sw $0,2736($16)\n"
    "sw $0,2728($16)\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001bded8, .-func_001bded8\n"
    ".text\n");
