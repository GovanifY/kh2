#include "../common/types.h"

void r_func_002cba50(void) asm("func_002cba50");
#if 0
void r_func_002cba50(void) {
}
#endif

// Agent R46p_135 (2026-10-29): func_002cba50 (56 bytes), SLPM_666.75.
// Loads a float constant from 0x0037589c, calls FUN_002cba88(a0, f12 = float at a1+36, f13 = constant),
// and returns a0. Whole-body asm: the C scheduler puts the constant load and the saves in another order.
__asm__(
    ".section .text.func_002cba50,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002cba50\n"
    ".type func_002cba50, @function\n"
    "func_002cba50:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x37\n"
    "sd $16,0($29)\n"
    "addiu $15,$15,22684\n"
    "sd $31,8($29)\n"
    "lwc1 $f13,0($15)\n"
    "daddu $16,$4,$0\n"
    "jal 0x002cba88\n"
    "lwc1 $f12,36($5)\n"
    "daddu $2,$16,$0\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002cba50, .-func_002cba50\n"
    ".text\n");
