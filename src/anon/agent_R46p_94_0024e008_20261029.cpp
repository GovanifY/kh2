#include "../common/types.h"

// Agent R46p_94 (2026-10-29): FUN_0024e008 (80 bytes, SLPM_666.75).
// Calls func_0024dfe0(a0), then returns 6*a0 plus 0x370000+8544, or +8568 when the word at
// 0x360000-4620 is non-zero. The R5900 3-operand mult is a raw .word (mult t5,s0,t5).
// Whole-body asm form (b): plain C cannot emit the 3-operand mult.
void r_FUN_0024e008(void) asm("func_0024e008");
#if 0
void r_FUN_0024e008(void) {
}
#endif

__asm__(
    ".section .text.func_0024e008,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0024e008\n"
    ".type func_0024e008, @function\n"
    "func_0024e008:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x24dfe0\n"
    "daddu $16,$4,$0\n"
    "addiu $13,$0,6\n"
    "lui $14,0x36\n"
    ".word 0x020d6818\n"
    "lw $12,-4620($14)\n"
    "lui $15,0x37\n"
    "addiu $15,$15,8544\n"
    "beq $12,$0,agent_R46p_94_0024e008_L1\n"
    "addu $2,$13,$15\n"
    "lui $15,0x37\n"
    "addiu $15,$15,8568\n"
    "addu $2,$13,$15\n"
    "agent_R46p_94_0024e008_L1:\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0024e008, .-func_0024e008\n"
    ".text\n");
