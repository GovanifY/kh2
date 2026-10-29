#include "../common/types.h"

// FUN_00195558 (80 bytes). Whole-body asm (form b): calls the unregistered-by-name routine at
// 0x195430 on arg0, then arg0 + 520, while the pointer is below arg0 + 2080 (signed), then stores
// zero at arg0 + 2084. The callee has only a mangled registry name, so the jal is numeric.
void r_FUN_00195558(void) asm("func_00195558");
#if 0
void r_FUN_00195558(void) {
}
#endif

__asm__(
    ".section .text.func_00195558,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00195558\n"
    ".type func_00195558, @function\n"
    "func_00195558:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $18,16($29)\n"
    "daddu $16,$4,$0\n"
    "sd $31,24($29)\n"
    "daddu $17,$4,$0\n"
    "addiu $18,$4,2080\n"
    "1:\n"
    "jal 0x195430\n"
    "daddu $4,$16,$0\n"
    "addiu $16,$16,520\n"
    "slt $15,$16,$18\n"
    "bnez $15,1b\n"
    "ld $31,24($29)\n"
    "sw $0,2084($17)\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_00195558, .-func_00195558\n"
    ".text\n");
