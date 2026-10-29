#include "../common/types.h"

// Agent R46p_46 (2026-10-29): FUN_001bdff0 (108 bytes), SLPM_666.75.
// Saves s0, s1, s2, ra. s0 = 0x330000-17616+14064 (lui/addiu pair), s1 = 3, s2 = 2.
// Loop: calls FUN_001b8e88(lhu 8(s0)), then if the lhu 2(v0) word != s2 skips to the
// decrement; else calls FUN_001a67b0(lh 4(v0)) and stores v0 at 8(s0). s0 += 2 each pass.
// Form: whole-body asm. The loop head uses bnel (branch-likely), which gcc 3.2 does not emit.
void r_FUN_001bdff0(void) asm("func_001bdff0");
#if 0
void r_FUN_001bdff0(void) {
}
#endif

__asm__(
    ".section .text.func_001bdff0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001bdff0\n"
    ".type func_001bdff0, @function\n"
    "func_001bdff0:\n"
    "addiu $29,$29,-32\n"
    "lui $15,0x33\n"
    "sd $16,0($29)\n"
    "addiu $15,$15,-17616\n"
    "sd $17,8($29)\n"
    "sd $18,16($29)\n"
    "addiu $16,$15,14064\n"
    "sd $31,24($29)\n"
    "addiu $17,$0,3\n"
    "addiu $18,$0,2\n"
    "1:\n"
    "jal 0x1b8e88\n"
    "lhu $4,8($16)\n"
    "lhu $15,2($2)\n"
    "bnel $15,$18,2f\n"
    "addiu $17,$17,-1\n"
    "jal 0x1a67b0\n"
    "lh $4,4($2)\n"
    "sh $2,8($16)\n"
    "addiu $17,$17,-1\n"
    "2:\n"
    "bgez $17,1b\n"
    "addiu $16,$16,2\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "ld $31,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001bdff0, .-func_001bdff0\n"
    ".text\n");
