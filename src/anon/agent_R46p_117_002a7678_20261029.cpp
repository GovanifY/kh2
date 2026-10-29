#include "../common/types.h"

// Agent R46p_117 (2026-10-29): FUN_002a7678 (92 bytes, align flag). Whole-body noreorder asm, same as R46p_115 002a9ce8.
// Calls func_00103570, func_001063c0(260), store result to 0x35F600 in a jal delay slot, func_001063c0(9040),
// func_00324448(result), then store s0 to 0x35F610. Numeric jal targets keep the .o identical.

u32 r_FUN_002a7678(void) asm("func_002a7678");
#if 0
u32 r_FUN_002a7678(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_002a7678,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002a7678\n"
    ".type func_002a7678, @function\n"
    "func_002a7678:\n"
    "addiu $29,$29,-16\n"
    "sd $31,8($29)\n"
    "sd $16,0($29)\n"
    "jal 0x103570\n"
    "nop\n"
    "daddu $5,$2,$0\n"
    "jal 0x1063c0\n"
    "addiu $4,$0,260\n"
    "lui $15,0x36\n"
    "jal 0x103570\n"
    "sw $2,-2560($15)\n"
    "daddu $5,$2,$0\n"
    "jal 0x1063c0\n"
    "addiu $4,$0,9040\n"
    "daddu $16,$2,$0\n"
    "jal 0x324448\n"
    "daddu $4,$2,$0\n"
    "lui $15,0x36\n"
    "ld $31,8($29)\n"
    "sw $16,-2556($15)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002a7678, .-func_002a7678\n"
    ".text\n");
