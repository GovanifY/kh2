#include "../common/types.h"

// Agent R46p_78 (2026-10-29): FUN_001fbab8 (100 bytes), SLPM_666.75.
// Same frame shape as FUN_001fb8b8: sp+0 = a0, sp+4 = word at a0+36, sp+8 = constant pointer
// (lui 0x1da, addiu -5952), sp+12 = float at a0+32, sp+16 = truncated float at a0+40 (cvt.w.s),
// sp+18 = halfword at a0+44, sp+20 = a0+16. Calls numeric jal 0x21fe40 with a0 = sp, a1 = 0.
// Matching: whole-body asm (form b) with literal immediates and a numeric jal.
void r_FUN_001fbab8(void) asm("func_001fbab8");
#if 0
void r_FUN_001fbab8(void) {
}
#endif

__asm__(
    ".section .text.func_001fbab8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001fbab8\n"
    ".type func_001fbab8, @function\n"
    "func_001fbab8:\n"
    "addiu $29,$29,-48\n"
    "daddu $14,$4,$0\n"
    "sd $31,32($29)\n"
    "addiu $11,$4,16\n"
    "daddu $5,$0,$0\n"
    "lwc1 $f0,40($4)\n"
    "lw $15,36($4)\n"
    "cvt.w.s $f1,$f0\n"
    "lhu $13,44($4)\n"
    "mfc1 $12,$f1\n"
    "lwc1 $f1,32($4)\n"
    "sw $15,4($29)\n"
    "daddu $4,$29,$0\n"
    "swc1 $f1,12($29)\n"
    "lui $15,0x1da\n"
    "sh $12,16($29)\n"
    "addiu $15,$15,-5952\n"
    "sh $13,18($29)\n"
    "sw $15,8($29)\n"
    "sw $11,20($29)\n"
    "jal 0x21fe40\n"
    "sw $14,0($29)\n"
    "ld $31,32($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".set pop\n"
    ".size func_001fbab8, .-func_001fbab8\n"
    ".text\n");
