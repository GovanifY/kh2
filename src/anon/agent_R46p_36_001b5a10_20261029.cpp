#include "../common/types.h"

// Agent R46p_36 (2026-10-29): FUN_001b5a10 (80 bytes, SLPM_666.75).
// Returns 0 if the word at 0x01d48cb0 is null. Otherwise calls 0x1b5cb8 (LIMIT_TABLE::is_kh1) with that
// pointer. If it returns nonzero, returns *(p + 12) + 128. If it returns zero, returns p + 24, reading the
// pointer register from before the call (t7 is not reloaded on that path).
// Whole-body asm: the t7 reuse after the call is not expressible in plain C, and the callee 0x1b5cb8
// is reached by a numeric jal.
void func_001b5a10(void) asm("func_001b5a10");
#if 0
void func_001b5a10(void) {
}
#endif

__asm__(
    ".section .text.func_001b5a10,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001b5a10\n"
    ".type func_001b5a10, @function\n"
    "func_001b5a10:\n"
    "addiu $29,$29,-16\n"
    "daddu $2,$0,$0\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lui $16,0x1d5\n"
    "lw $15,-29520($16)\n"
    "beq $15,$0,agent_R46p_36_001b5a10_L1\n"
    "daddu $4,$15,$0\n"
    "jal 0x1b5cb8\n"
    "nop\n"
    "beq $2,$0,agent_R46p_36_001b5a10_L2\n"
    "lw $15,-29520($16)\n"
    "lw $14,12($15)\n"
    "addiu $2,$14,128\n"
    "agent_R46p_36_001b5a10_L1:\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "agent_R46p_36_001b5a10_L2:\n"
    "beq $0,$0,agent_R46p_36_001b5a10_L1\n"
    "addiu $2,$15,24\n"
    ".set pop\n"
    ".size func_001b5a10, .-func_001b5a10\n"
    ".text\n");
