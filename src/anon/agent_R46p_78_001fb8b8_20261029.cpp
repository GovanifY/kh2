#include "../common/types.h"

// Agent R46p_78 (2026-10-29): FUN_001fb8b8 (108 bytes), SLPM_666.75.
// Builds a 48-byte frame: copies a0 to t6, then fills sp+0..sp+20 with a0, the word at a0+36,
// a constant pointer (lui 0x1da, addiu -5952), the truncated floats at a0+40/a0+44 (sh at sp+16/18),
// the float at a0+32 (swc1 sp+12), and a0+16 at sp+20. Calls func_0021fbd8(sp) (numeric jal 0x21fbd8).
// Matching: whole-body asm (form b) with literal lui/addiu immediates and a numeric jal.
void r_FUN_001fb8b8(void) asm("func_001fb8b8");
#if 0
void r_FUN_001fb8b8(void) {
}
#endif

__asm__(
    ".section .text.func_001fb8b8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001fb8b8\n"
    ".type func_001fb8b8, @function\n"
    "func_001fb8b8:\n"
    "addiu $29,$29,-48\n"
    "daddu $14,$4,$0\n"
    "sd $31,32($29)\n"
    "addiu $11,$4,16\n"
    "daddu $5,$0,$0\n"
    "lwc1 $f0,40($4)\n"
    "lwc1 $f1,44($4)\n"
    "cvt.w.s $f2,$f0\n"
    "lw $15,36($4)\n"
    "cvt.w.s $f0,$f1\n"
    "mfc1 $12,$f2\n"
    "mfc1 $13,$f0\n"
    "lwc1 $f0,32($4)\n"
    "sw $15,4($29)\n"
    "daddu $4,$29,$0\n"
    "swc1 $f0,12($29)\n"
    "lui $15,0x1da\n"
    "sh $12,16($29)\n"
    "addiu $15,$15,-5952\n"
    "sh $13,18($29)\n"
    "sw $15,8($29)\n"
    "sw $11,20($29)\n"
    "jal 0x21fbd8\n"
    "sw $14,0($29)\n"
    "ld $31,32($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".set pop\n"
    ".size func_001fb8b8, .-func_001fb8b8\n"
    ".text\n");
