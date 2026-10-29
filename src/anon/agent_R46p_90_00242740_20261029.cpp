#include "../common/types.h"

// Agent R46p_90: func_00242740 (76 bytes, SLPM_666.75).
// Whole-body asm. When a0 < 0: calls the IsExec callee (0x197920), then a0 = 1, or 2 when v0
// is zero (movz with t7 = 2). Then calls 0x2ba978 and 0x2ef7b8; if v0 is nonzero, restores ra
// and tail-jumps to 0x2bd680 from the delay-slot position. Otherwise returns.

void r_func_00242740(void) asm("func_00242740");

void r_func_00242740(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "bgez $4,1f\n\t"
        " nop\n\t"
        "jal 0x197920\n\t"
        " nop\n\t"
        "addiu $4,$0,1\n\t"
        "addiu $15,$0,2\n\t"
        "movz $4,$15,$2\n\t"
        "1:\n\t"
        "jal 0x2ba978\n\t"
        " nop\n\t"
        "jal 0x2ef7b8\n\t"
        " nop\n\t"
        "beqz $2,2f\n\t"
        " ld $31,0($29)\n\t"
        "j 0x2bd680\n\t"
        " addiu $29,$29,16\n\t"
        "2:\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
