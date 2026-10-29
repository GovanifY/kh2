#include "../common/types.h"

// Agent R46p_118 (2026-10-29): FUN_002944f8 (84 bytes, align flag), SLPM_666.75.
// sb 0 to 0x35F600 and 0x35F601; r = func_00103570(); s = func_001063c0(28, r);
// func_0023f800(s); store s to 0x35F5FC.
// Whole-body noreorder asm with numeric jal targets, because the byte stores sit before the
// s0 save and no callee has a usable named row.

void r_FUN_002944f8(void) asm("func_002944f8");
#if 0
void r_FUN_002944f8(void) {
    return;
}
#endif

__asm__(
    ".section .text.func_002944f8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002944f8\n"
    ".type func_002944f8, @function\n"
    "func_002944f8:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x36\n"
    "lui $14,0x36\n"
    "sd $31,8($29)\n"
    "sb $0,-2688($15)\n"
    "sb $0,-2687($14)\n"
    "sd $16,0($29)\n"
    "jal 0x103570\n"
    "nop\n"
    "daddu $5,$2,$0\n"
    "jal 0x1063c0\n"
    "addiu $4,$0,28\n"
    "daddu $16,$2,$0\n"
    "jal 0x23f800\n"
    "daddu $4,$2,$0\n"
    "lui $15,0x36\n"
    "ld $31,8($29)\n"
    "sw $16,-2692($15)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002944f8, .-func_002944f8\n"
    ".text\n");
