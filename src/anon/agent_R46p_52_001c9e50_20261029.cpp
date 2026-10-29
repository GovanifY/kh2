#include "../common/types.h"

// Agent R46p_52 (2026-10-29): FUN_001c9e50 (80 bytes), SLPM_666.75.
// Code: frame of 16 bytes (s0, ra). s0 = a0. Loop: if YS::EVENT::IsExec(a0) != 0 go to the yield block;
// if func_0017a6c8(s0) != 0 go to the yield block; otherwise return. The yield block calls
// Tz::TaskYield with a1 = 0 in the delay slot and branches back to the IsExec call (a0 as it was left).
// Matching: whole-body asm. The loop reuses a0 without a move, so plain C cannot reproduce the branch
// layout. The callees are reached by numeric jal targets.
void r_FUN_001c9e50(void) asm("func_001c9e50");
#if 0
void r_FUN_001c9e50(void) {
}
#endif

__asm__(
    ".section .text.func_001c9e50,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001c9e50\n"
    ".type func_001c9e50, @function\n"
    "func_001c9e50:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$4,$0\n"
    "3:\n"
    "jal 0x197920\n"
    "nop\n"
    "bnez $2,1f\n"
    "daddu $4,$16,$0\n"
    "jal 0x17a6c8\n"
    "nop\n"
    "bnez $2,1f\n"
    "daddu $4,$16,$0\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "1:\n"
    "jal 0x102448\n"
    "daddu $5,$0,$0\n"
    "b 3b\n"
    "nop\n"
    ".set pop\n"
    ".size func_001c9e50, .-func_001c9e50\n"
    ".text\n");
