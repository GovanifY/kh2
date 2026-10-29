#include "../common/types.h"

// Agent R46p_36 (2026-10-29): FUN_001b43e0 (80 bytes, SLPM_666.75).
// Reads the word at 0x01d48cb0. If nonzero, calls 0x1b5460 with it, then reloads the word and, if still
// nonzero, calls 0x1b4f40 with it and then calls 0x105110 (AREA::Free) with it.
// Whole-body asm: the callees 0x1b5460 and 0x1b4f40 have no functions.tsv row, so they are numeric jal
// targets. Plain C would need jalr through a function pointer.
void func_001b43e0(void) asm("func_001b43e0");
#if 0
void func_001b43e0(void) {
}
#endif

__asm__(
    ".section .text.func_001b43e0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001b43e0\n"
    ".type func_001b43e0, @function\n"
    "func_001b43e0:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lui $16,0x1d5\n"
    "lw $15,-29520($16)\n"
    "beq $15,$0,agent_R46p_36_001b43e0_L1\n"
    "daddu $4,$15,$0\n"
    "jal 0x1b5460\n"
    "nop\n"
    "lw $16,-29520($16)\n"
    "beq $16,$0,agent_R46p_36_001b43e0_L1\n"
    "daddu $4,$16,$0\n"
    "jal 0x1b4f40\n"
    "nop\n"
    "jal 0x105110\n"
    "daddu $4,$16,$0\n"
    "agent_R46p_36_001b43e0_L1:\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001b43e0, .-func_001b43e0\n"
    ".text\n");
