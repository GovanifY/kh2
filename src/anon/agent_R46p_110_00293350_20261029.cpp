#include "../common/types.h"

// FUN_00293350 (104 bytes). Calls numeric 0x103eb0 (getMenuMode-style, no args change) and
// keeps its result pointer in v0. Then calls numeric 0x102818 with a0 = *(v0+4), a1 = 0,
// a2 = 0x222e0, a3 = 0x2933b8, t0 = 4096, and stores the three saved args at v0+4, v0+8, v0+12.
// Callee 0x102818 has no functions.tsv row, so this is whole-body noreorder asm with numeric jal.
void r_FUN_00293350(u32 a0, u32 a1, u32 a2) asm("func_00293350");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_00293350(u32 a0, u32 a1, u32 a2) {
}
#endif

__asm__(
    ".section .text.func_00293350,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00293350\n"
    ".type func_00293350, @function\n"
    "func_00293350:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $18,16($29)\n"
    "daddu $16,$6,$0\n"
    "sd $31,24($29)\n"
    "daddu $17,$4,$0\n"
    "jal 0x103eb0\n"
    "daddu $18,$5,$0\n"
    "lw $4,4($2)\n"
    "lui $6,2\n"
    "lui $7,0x29\n"
    "daddu $5,$0,$0\n"
    "addiu $7,$7,13240\n"
    "ori $6,$6,0x22e0\n"
    "jal 0x102818\n"
    "addiu $8,$0,4096\n"
    "sw $16,12($2)\n"
    "sw $17,4($2)\n"
    "sw $18,8($2)\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "ld $31,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_00293350, .-func_00293350\n"
    ".text\n");
