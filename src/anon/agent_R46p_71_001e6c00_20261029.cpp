#include "../common/types.h"

// Agent R46p_71 (2026-10-29): FUN_001e6c00 (60 bytes), SLPM_666.75.
// Code: frame of 16 bytes. Calls func_002fde18(a0, 171, 336) (mangled wtarget row), saves the
// original a0 in s0, then calls numeric 0x1e7798(word at 0x1da0000 - 6428, s0) and returns.
// Matching: whole-body asm (form b). Numeric jal targets; the second callee has no row.
void r_FUN_001e6c00(void) asm("func_001e6c00");
#if 0
void r_FUN_001e6c00(void) {
}
#endif

__asm__(
    ".section .text.func_001e6c00,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001e6c00\n"
    ".type func_001e6c00, @function\n"
    "func_001e6c00:\n"
    "addiu $29,$29,-16\n"
    "addiu $6,$0,336\n"
    "sd $16,0($29)\n"
    "addiu $5,$0,171\n"
    "sd $31,8($29)\n"
    "jal 0x2fde18\n"
    "daddu $16,$4,$0\n"
    "lui $15,0x1da\n"
    "daddu $5,$16,$0\n"
    "jal 0x1e7798\n"
    "lw $4,-6428($15)\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001e6c00, .-func_001e6c00\n"
    ".text\n");
