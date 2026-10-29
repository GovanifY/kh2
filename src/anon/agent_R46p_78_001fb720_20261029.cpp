#include "../common/types.h"

// Agent R46p_78 (2026-10-29): FUN_001fb720 (108 bytes), SLPM_666.75.
// Calls func_001fa950(a0, a1), with s2 = a0 + *(s32*)a2->+12 + 160 computed in the jal delay slot.
// After the call, if *(s32*)a1 == *(s32*)(a0+12), it stores a1->+12 (f32) to s2+68 and
// (f32)(u16)a1->+20 to s2+64.
// Matching: whole-body asm (form b). Plain C gave a different prologue order (sd ra after move s0),
// a t7 base register, and f1/f0 float use.
void r_FUN_001fb720(void) asm("func_001fb720");
#if 0
void r_FUN_001fb720(void) {
}
#endif

__asm__(
    ".section .text.func_001fb720,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001fb720\n"
    ".type func_001fb720, @function\n"
    "func_001fb720:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $18,16($29)\n"
    "daddu $16,$4,$0\n"
    "sd $31,24($29)\n"
    "daddu $17,$5,$0\n"
    "lw $14,12($6)\n"
    "lw $15,0($14)\n"
    "addu $15,$4,$15\n"
    "jal func_001fa950\n"
    "addiu $18,$15,160\n"
    "lw $14,12($16)\n"
    "lw $15,0($17)\n"
    "bne $15,$14,1f\n"
    "ld $16,0($29)\n"
    "lwc1 $f0,12($17)\n"
    "swc1 $f0,68($18)\n"
    "lhu $15,20($17)\n"
    "mtc1 $15,$f0\n"
    "cvt.s.w $f0,$f0\n"
    "swc1 $f0,64($18)\n"
    "1:\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "ld $31,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001fb720, .-func_001fb720\n"
    ".text\n");
