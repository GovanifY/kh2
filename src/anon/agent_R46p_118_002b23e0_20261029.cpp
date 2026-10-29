#include "../common/types.h"

// Agent R46p_118 (2026-10-29): FUN_002b23e0 (72 bytes), SLPM_666.75.
// x = a0; if (x < 0) func_00276608(28) as the new x; r = func_002b2338(x);
// return *(u32*)(0x35F630 table) + r * 36.
// Whole-body noreorder asm with numeric jal targets, because no callee has a usable named label.

u32 r_FUN_002b23e0(s32 a0) asm("func_002b23e0");
#if 0
u32 r_FUN_002b23e0(s32 a0) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_002b23e0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002b23e0\n"
    ".type func_002b23e0, @function\n"
    "func_002b23e0:\n"
    "addiu $29,$29,-16\n"
    "daddu $2,$4,$0\n"
    "sd $31,0($29)\n"
    "bgez $2,1f\n"
    "addiu $4,$0,28\n"
    "jal 0x276608\n"
    "nop\n"
    "1:\n"
    "jal 0x2b2338\n"
    "daddu $4,$2,$0\n"
    "daddu $13,$2,$0\n"
    "ld $31,0($29)\n"
    "addiu $14,$0,36\n"
    "lui $15,0x36\n"
    "mult $13,$13,$14\n"
    "lw $2,-2512($15)\n"
    "addu $2,$2,$13\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002b23e0, .-func_002b23e0\n"
    ".text\n");
