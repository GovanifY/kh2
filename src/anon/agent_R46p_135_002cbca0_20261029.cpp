#include "../common/types.h"

void r_func_002cbca0(void) asm("func_002cbca0");
#if 0
void r_func_002cbca0(void) {
}
#endif

// func_002cbca0 (76 bytes), SLPM_666.75. Whole-body asm.
__asm__(
    ".section .text.func_002cbca0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002cbca0\n"
    ".type func_002cbca0, @function\n"
    "func_002cbca0:\n"
    "addiu $29,$29,-32\n"
    "lui $15,0x37\n"
    "sd $16,0($29)\n"
    "addiu $15,$15,22700\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "daddu $16,$5,$0\n"
    "lwc1 $f13,0($15)\n"
    "daddu $17,$4,$0\n"
    "jal 0x002cba88\n"
    "lwc1 $f12,36($5)\n"
    "lwc1 $f0,20($16)\n"
    "daddu $2,$17,$0\n"
    "ld $31,16($29)\n"
    "swc1 $f0,12($17)\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_002cbca0, .-func_002cbca0\n"
    ".text\n");
