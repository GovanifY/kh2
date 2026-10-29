#include "../common/types.h"

// FUN_00195c58 (40 bytes). Whole-body asm (form b): if the word at +1416 of arg1 has bit 0x80
// set, tail-calls func_00158f90 with the same arguments; otherwise returns. The lw sits before
// the ra save, which plain C does not reproduce.
void r_FUN_00195c58(void) asm("func_00195c58");
#if 0
void r_FUN_00195c58(void) {
}
#endif

__asm__(
    ".section .text.func_00195c58,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00195c58\n"
    ".type func_00195c58, @function\n"
    "func_00195c58:\n"
    "addiu $29,$29,-16\n"
    "lw $15,1416($5)\n"
    "sd $31,0($29)\n"
    "andi $15,$15,0x80\n"
    "beqz $15,1f\n"
    "ld $31,0($29)\n"
    "j 0x158f90\n"
    "addiu $29,$29,16\n"
    "1:\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00195c58, .-func_00195c58\n"
    ".text\n");
