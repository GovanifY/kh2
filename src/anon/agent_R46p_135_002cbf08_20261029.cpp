#include "../common/types.h"

void r_func_002cbf08(void) asm("func_002cbf08");
#if 0
void r_func_002cbf08(void) {
}
#endif

// func_002cbf08 (100 bytes), SLPM_666.75. Whole-body asm, VU0 normalise of the vec3 at a0.
__asm__(
    ".section .text.func_002cbf08,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002cbf08\n"
    ".type func_002cbf08, @function\n"
    "func_002cbf08:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$4,$0\n"
    "jal 0x002cdb00\n"
    "lwc1 $f12,24($5)\n"
    "lqc2 $vf1,0($16)\n"
    "vmul.xyz $vf2,$vf1,$vf1\n"
    "vaddy.x $vf2,$vf2,$vf2y\n"
    "vaddz.x $vf2,$vf2,$vf2z\n"
    "vsqrt Q,$vf2x\n"
    "vwaitq\n"
    "cfc2.ni $8,$22\n"
    "vaddq.x $vf2,$vf0,Q\n"
    "mtc1 $8,$f0\n"
    "vnop\n"
    "vdiv Q,$vf0w,$vf2x\n"
    "vwaitq\n"
    "vmulq.xyz $vf1,$vf1,Q\n"
    "sqc2 $vf1,0($16)\n"
    "daddu $2,$16,$0\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002cbf08, .-func_002cbf08\n"
    ".text\n");
