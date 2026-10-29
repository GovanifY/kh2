#include "../common/types.h"

// Agent R46p_62 (2026-10-29): FUN_001db250 (68 bytes), SLPM_666.75.
// Whole-body asm (form b). Loads a float from a0->+108->+32, subtracts it from a
// constant at 0x0036e7a0 (lui 0x37 + addiu -6240), calls 0x17d0e8 and then 0x19c778
// with sp as the second argument.
void r_FUN_001db250(void) asm("func_001db250");
#if 0
void r_FUN_001db250(void) {
}
#endif

__asm__(
    ".section .text.func_001db250,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001db250\n"
    ".type func_001db250, @function\n"
    "func_001db250:\n"
    "addiu $29,$29,-32\n"
    "sd $31,16($29)\n"
    "lw $15,108($4)\n"
    "lwc1 $f0,32($15)\n"
    "daddu $4,$29,$0\n"
    "lui $15,0x37\n"
    "addiu $15,$15,-6240\n"
    "lwc1 $f12,0($15)\n"
    "jal 0x17d0e8\n"
    "sub.s $f12,$f12,$f0\n"
    "lui $15,0x35\n"
    "daddu $5,$29,$0\n"
    "jal 0x19c778\n"
    "lw $4,-5816($15)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001db250, .-func_001db250\n"
    ".text\n");
