#include "../common/types.h"

void r_func_002cd3e0(void) asm("func_002cd3e0");
#if 0
void r_func_002cd3e0(void) {
}
#endif

// func_002cd3e0 (68 bytes), SLPM_666.75. Whole-body asm.
__asm__(
    ".section .text.func_002cd3e0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002cd3e0\n"
    ".type func_002cd3e0, @function\n"
    "func_002cd3e0:\n"
    "addiu $29,$29,-48\n"
    "sd $17,24($29)\n"
    "sd $16,16($29)\n"
    "sd $31,32($29)\n"
    "daddu $17,$4,$0\n"
    "jal 0x0016c028\n"
    "daddu $4,$5,$0\n"
    "lq $8,0($2)\n"
    "sq $8,0($29)\n"
    "daddu $4,$17,$0\n"
    "jal 0x002cd428\n"
    "daddu $5,$29,$0\n"
    "ld $16,16($29)\n"
    "ld $17,24($29)\n"
    "ld $31,32($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".set pop\n"
    ".size func_002cd3e0, .-func_002cd3e0\n"
    ".text\n");
