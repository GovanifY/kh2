#include "../common/types.h"

// Agent R46p_79 (2026-10-29): FUN_0020e138 (40 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves ra. Calls the function at 0x2fea18 (no row; numeric jal),
// copies v0 to t7, then a VU0 qmtc2 t7,vf31 and vrxor (raw encodings) and returns.
// Matching: whole-function file-scope __asm__ (form b). The two VU0 ops are written as
// raw .word values, since gas does not take these mnemonics.
void r_FUN_0020e138(void) asm("func_0020e138");
#if 0
void r_FUN_0020e138(void) {
}
#endif

__asm__(
    ".section .text.func_0020e138,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0020e138\n"
    ".type func_0020e138, @function\n"
    "func_0020e138:\n"
    "addiu $29,$29,-16\n"
    "sd $31,0($29)\n"
    "jal 0x2fea18\n"
    "nop\n"
    "daddu $15,$2,$0\n"
    ".word 0x48aff800\n"
    ".word 0x4a00fc3f\n"
    "ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0020e138, .-func_0020e138\n"
    ".text\n");
