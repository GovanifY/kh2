#include "../common/types.h"

// Agent R46p_65 (2026-10-29): FUN_001de8a8 (104 bytes), SLPM_666.75.
// Whole-body asm (form b). Saves a2/a3 and a0/a1, calls TASK_MANAGER::create_task (0x102788)
// twice with a3 set by lui+addiu, then stores 0x1e0000-6384 at +48 of the second call's result
// and returns that result. Callee is reached by numeric jal since its symbol is mangled.
void r_FUN_001de8a8(void) asm("func_001de8a8");
#if 0
void r_FUN_001de8a8(void) {
}
#endif

__asm__(
    ".section .text.func_001de8a8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001de8a8\n"
    ".type func_001de8a8, @function\n"
    "func_001de8a8:\n"
    "addiu $29,$29,-32\n"
    "sd $18,16($29)\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "daddu $18,$7,$0\n"
    "sd $31,24($29)\n"
    "lui $7,0x1e\n"
    "daddu $17,$4,$0\n"
    "daddu $16,$5,$0\n"
    "jal 0x102788\n"
    "addiu $7,$7,-6512\n"
    "lui $7,0x1e\n"
    "daddu $4,$17,$0\n"
    "daddu $5,$16,$0\n"
    "daddu $6,$18,$0\n"
    "jal 0x102788\n"
    "addiu $7,$7,-6448\n"
    "lui $15,0x1e\n"
    "ld $16,0($29)\n"
    "addiu $15,$15,-6384\n"
    "ld $17,8($29)\n"
    "sw $15,48($2)\n"
    "ld $18,16($29)\n"
    "ld $31,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001de8a8, .-func_001de8a8\n"
    ".text\n");
