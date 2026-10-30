#include "../common/types.h"

// Agent R46p_130 (2026-10-29): FUN_002bef78 (48 bytes), SLPM_666.75.
// Forwards (a1, a2) to vtable slot 4 (offset 16) of the object at a0->field36 and returns its result.
// Matching: whole-body asm (form b). The -O0 home-slot stores of the arguments are kept verbatim.
void r_FUN_002bef78(void) asm("func_002bef78");
#if 0
void r_FUN_002bef78(void) {
}
#endif

__asm__(
    ".section .text.func_002bef78,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002bef78\n"
    ".type func_002bef78, @function\n"
    "func_002bef78:\n"
    "addiu $29,$29,-48\n"
    "sd $31,32($29)\n"
    "sd $5,0($29)\n"
    "sw $6,16($29)\n"
    "lw $4,36($4)\n"
    "lw $14,0($4)\n"
    "lw $15,16($14)\n"
    "jalr $15\n"
    "nop\n"
    "ld $31,32($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".set pop\n"
    ".size func_002bef78, .-func_002bef78\n"
);
