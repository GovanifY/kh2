#include "../common/types.h"

// Agent R46p_115 (2026-10-29): FUN_002a9ce8 (68 bytes, align flag), SLPM_666.75.
// r = func_00103570(); s = func_001063c0(2408, r); func_00319a60(s); store s to 0x35F610.
// Plain C let gcc move the s0 save into the jal delay slot, so this is a whole-body noreorder asm
// with numeric jal targets, as in the original.

u32 r_FUN_002a9ce8(void) asm("func_002a9ce8");
#if 0
u32 r_FUN_002a9ce8(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_002a9ce8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002a9ce8\n"
    ".type func_002a9ce8, @function\n"
    "func_002a9ce8:\n"
    "addiu $29,$29,-16\n"
    "sd $31,8($29)\n"
    "sd $16,0($29)\n"
    "jal 0x103570\n"
    "nop\n"
    "daddu $5,$2,$0\n"
    "jal 0x1063c0\n"
    "addiu $4,$0,2408\n"
    "daddu $16,$2,$0\n"
    "jal 0x319a60\n"
    "daddu $4,$2,$0\n"
    "lui $15,0x36\n"
    "ld $31,8($29)\n"
    "sw $16,-2544($15)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002a9ce8, .-func_002a9ce8\n"
    ".text\n");
