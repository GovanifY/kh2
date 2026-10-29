#include "../common/types.h"

// Agent R46p_94 (2026-10-29): FUN_00233ac0 (92 bytes, SLPM_666.75).
// Converts a0 to float (halving with the low bit folded in when a0 < 0), divides by the float
// constant at 0x3713b0, and tail-returns through a jal to the unnamed callee 0x313bc0.
// Whole-body asm form (b): the callee has no func_ row, so plain C cannot emit the numeric jal,
// and the two nops between lwc1 and div.s are kept as literal words.
void r_FUN_00233ac0(void) asm("func_00233ac0");
#if 0
void r_FUN_00233ac0(void) {
}
#endif

__asm__(
    ".section .text.func_00233ac0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00233ac0\n"
    ".type func_00233ac0, @function\n"
    "func_00233ac0:\n"
    "addiu $29,$29,-16\n"
    "srl $15,$4,1\n"
    "andi $14,$4,1\n"
    "sd $31,0($29)\n"
    "bltz $4,agent_R46p_94_00233ac0_LNEG\n"
    "or $14,$14,$15\n"
    "mtc1 $4,$f0\n"
    "cvt.s.w $f0,$f0\n"
    "agent_R46p_94_00233ac0_LDIV:\n"
    "lui $15,0x37\n"
    "addiu $15,$15,5040\n"
    "lwc1 $f12,0($15)\n"
    "nop\n"
    "nop\n"
    "div.s $f12,$f0,$f12\n"
    "jal 0x313bc0\n"
    "nop\n"
    "ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "agent_R46p_94_00233ac0_LNEG:\n"
    "mtc1 $14,$f0\n"
    "cvt.s.w $f0,$f0\n"
    "b agent_R46p_94_00233ac0_LDIV\n"
    "add.s $f0,$f0,$f0\n"
    ".set pop\n"
    ".size func_00233ac0, .-func_00233ac0\n"
    ".text\n");
