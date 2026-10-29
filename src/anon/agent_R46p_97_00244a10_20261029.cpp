#include "../common/types.h"

// FUN_00244a10 (80 bytes). Whole-body noreorder asm, top-level, so gcc emits no frame.
// Calls numeric 0x1d56c8 with a0 = 8; if the byte at the returned pointer is >= 2 it
// returns 1 (beqzl, branch-likely). Otherwise calls numeric 0x276c18 and returns 1 when
// that result is nonzero, else 0.
u32 r_FUN_00244a10(void) asm("func_00244a10");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_00244a10(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_00244a10,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00244a10\n"
    ".type func_00244a10, @function\n"
    "func_00244a10:\n"
    "addiu $29,$29,-16\n"
    "addiu $4,$0,8\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x1d56c8\n"
    "daddu $16,$0,$0\n"
    "lbu $15,0($2)\n"
    "sltiu $15,$15,2\n"
    "beqzl $15,3f\n"
    "addiu $16,$0,1\n"
    "jal 0x276c18\n"
    "nop\n"
    "beqz $2,2f\n"
    "daddu $2,$16,$0\n"
    "addiu $16,$0,1\n"
    "3:\n"
    "daddu $2,$16,$0\n"
    "2:\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00244a10, .-func_00244a10\n"
    ".text\n");
