#include "../common/types.h"

// FUN_00257970 (108 bytes). Loop of 24 calls to numeric 0x139d78 with a0 = *(u32*)(0x35F038)
// + offset + 0x87d0, offset stepping 408 per iteration. Returns the first nonzero result, else 0.
// a1..a3 pass through from entry (the callee's args are not set here), which plain C does not
// express, so this is whole-body noreorder asm with numeric jal targets.
u32 r_FUN_00257970(void) asm("func_00257970");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_00257970(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_00257970,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00257970\n"
    ".type func_00257970, @function\n"
    "func_00257970:\n"
    "addiu $29,$29,-48\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $18,16($29)\n"
    "daddu $16,$0,$0\n"
    "sd $19,24($29)\n"
    "daddu $17,$0,$0\n"
    "sd $31,32($29)\n"
    "ori $18,$0,0x87d0\n"
    "lui $19,0x36\n"
    "lw $4,-4040($19)\n"
    "1:\n"
    "addu $4,$4,$16\n"
    "addu $4,$4,$18\n"
    "jal 0x139d78\n"
    "addiu $16,$16,408\n"
    "bnez $2,2f\n"
    "addiu $17,$17,1\n"
    "slti $15,$17,24\n"
    "bnez $15,1b\n"
    "lw $4,-4040($19)\n"
    "2:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "ld $19,24($29)\n"
    "ld $31,32($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".set pop\n"
    ".size func_00257970, .-func_00257970\n"
    ".text\n");
