#include "../common/types.h"

// Agent R46p_61 (2026-10-29): FUN_001d6538 (60 bytes), SLPM_666.75.
// Whole-body asm. Calls the unregistered routine at 0x1ce378 (numeric jal) with this in s0,
// then stores the vtable-style words 0x1d6xxx at +2552 and 0x35xxxx at +0.
void r_FUN_001d6538(void) asm("func_001d6538");
#if 0
void r_FUN_001d6538(void) {
}
#endif

__asm__(
    ".section .text.func_001d6538,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001d6538\n"
    ".type func_001d6538, @function\n"
    "func_001d6538:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x1ce378\n"
    "daddu $16,$4,$0\n"
    "lui $15,0x1d6\n"
    "ld $31,8($29)\n"
    "lui $14,0x35\n"
    "addiu $15,$15,-17800\n"
    "addiu $14,$14,10112\n"
    "sw $15,2552($16)\n"
    "sw $14,0($16)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001d6538, .-func_001d6538\n"
    ".text\n");
