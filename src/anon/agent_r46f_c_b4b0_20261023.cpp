#include "../common/types.h"

// Asm label alias: registers func_0014b4b0 with this file (no C definition is emitted).
u32 r_FUN_0014b4b0(void) asm("func_0014b4b0");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_0014b4b0(void) {
    return 0;
}
#endif

// FUN_0014b4b0 (100 bytes). Whole-body noreorder asm, top-level, so gcc emits no frame.
// Packs two 16-bit fields from a1 and a3 (a4 in t0) into 16.16-style words and tail-calls
// FUN_0014b5e8 with a0 unchanged. Instruction order copied from the original.
__asm__(
    ".section .text.func_0014b4b0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0014b4b0\n"
    ".type func_0014b4b0, @function\n"
    "func_0014b4b0:\n"
    "andi $7,$7,0xffff\n"
    "andi $8,$8,0xffff\n"
    "addiu $29,$29,-16\n"
    "andi $5,$5,0xffff\n"
    "andi $6,$6,0xffff\n"
    "sd $31,0($29)\n"
    "sll $7,$7,4\n"
    "sll $8,$8,4\n"
    "sll $5,$5,4\n"
    "ld $31,0($29)\n"
    "addiu $7,$7,8\n"
    "sll $6,$6,4\n"
    "addiu $8,$8,8\n"
    "addiu $5,$5,8\n"
    "daddu $7,$7,$0\n"
    "addiu $6,$6,8\n"
    "daddu $8,$8,$0\n"
    "dsll $7,$7,16\n"
    "dsll $8,$8,16\n"
    "daddu $5,$5,$0\n"
    "daddu $6,$6,$0\n"
    "or $5,$5,$7\n"
    "or $6,$6,$8\n"
    "j func_0014b5e8\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0014b4b0, .-func_0014b4b0\n"
    ".text\n");
