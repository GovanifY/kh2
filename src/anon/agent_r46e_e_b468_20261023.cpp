#include "../common/types.h"

// Asm label alias: registers func_0014b468 with this file (no C definition is emitted).
u32 r_FUN_0014b468(void) asm("func_0014b468");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_0014b468(void) {
    return 0;
}
#endif

// FUN_0014b468 (72 bytes). Top-level asm, so gcc emits no prologue or epilogue. The body is the
// original instruction sequence, and the tail jump to FUN_0014b5e8 uses the delay slot to free the
// 16-byte slot. The section name matches the .text.<symbol> pattern used by the linker script.
__asm__(
    ".section .text.func_0014b468,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0014b468\n"
    ".type func_0014b468, @function\n"
    "func_0014b468:\n"
    "andi $6,$6,0xffff\n"
    "andi $15,$5,0xffff\n"
    "sll $6,$6,4\n"
    "addiu $29,$29,-16\n"
    "sll $15,$15,4\n"
    "sd $31,0($29)\n"
    "addiu $6,$6,8\n"
    "addiu $15,$15,8\n"
    "daddu $6,$6,$0\n"
    "ld $31,0($29)\n"
    "dsll $6,$6,16\n"
    "daddu $15,$15,$0\n"
    "or $15,$15,$6\n"
    "lui $5,0x8\n"
    "ori $5,$5,0x8\n"
    "daddu $6,$15,$0\n"
    "j func_0014b5e8\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0014b468, .-func_0014b468\n"
    ".text\n");
