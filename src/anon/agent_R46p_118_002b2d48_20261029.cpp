#include "../common/types.h"

// Agent R46p_118 (2026-10-29): FUN_002b2d48 (92 bytes, align flag), SLPM_666.75.
// s1 = 0; if (func_00139d78(*(0x35F634) + 19992)) s1 = 1;
// else if (func_00139d78(*(0x35F634) + 20400)) s1 = 1; return s1.
// Whole-body noreorder asm with a bnezl and numeric jal targets, as in the original.

u32 r_FUN_002b2d48(void) asm("func_002b2d48");
#if 0
u32 r_FUN_002b2d48(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_002b2d48,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002b2d48\n"
    ".type func_002b2d48, @function\n"
    "func_002b2d48:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "lui $16,0x36\n"
    "sd $31,16($29)\n"
    "lw $4,-2508($16)\n"
    "daddu $17,$0,$0\n"
    "jal 0x139d78\n"
    "addiu $4,$4,19992\n"
    "bnezl $2,4f\n"
    "addiu $17,$0,1\n"
    "lw $4,-2508($16)\n"
    "jal 0x139d78\n"
    "addiu $4,$4,20400\n"
    "beq $2,$0,5f\n"
    "daddu $2,$17,$0\n"
    "addiu $17,$0,1\n"
    "4:\n"
    "daddu $2,$17,$0\n"
    "5:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_002b2d48, .-func_002b2d48\n"
    ".text\n");
