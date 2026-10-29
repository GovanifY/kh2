#include "../common/types.h"

// Agent R46p_85 (2026-10-29): FUN_00232348 (80 bytes, SLPM_666.75).
// Calls the unnamed 0x105c30 (REGION::Get) and compares its result with 8. If it differs, uses a
// branch-likely to jump to a tail that loads a word from 0x340000-13580 and returns it. Otherwise
// calls 0x242e48. Then returns 0x370000+4816 if that call returns non-zero, else the word at
// 0x340000-13584.
// Matching: gcc 3.2 has no branch-likely, so the whole body is one file-scope asm block with the
// original instruction order and numeric jal targets.
void r_FUN_00232348(void) asm("func_00232348");
#if 0
void r_FUN_00232348(void) {
}
#endif

__asm__(
    ".section .text.func_00232348,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00232348\n"
    ".type func_00232348, @function\n"
    "func_00232348:\n"
    "addiu $29,$29,-16\n"
    "sd $31,0($29)\n"
    "jal 0x105c30\n"
    "nop\n"
    "addiu $15,$0,8\n"
    "bnel $2,$15,agent_R46p_85_00232348_L48\n"
    "lui $15,0x34\n"
    "jal 0x242e48\n"
    "nop\n"
    "lui $15,0x37\n"
    "bne $2,$0,agent_R46p_85_00232348_L38\n"
    "addiu $15,$15,4816\n"
    "lui $15,0x34\n"
    "lw $15,-13584($15)\n"
    "agent_R46p_85_00232348_L38:\n"
    "ld $31,0($29)\n"
    "daddu $2,$15,$0\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "agent_R46p_85_00232348_L48:\n"
    "b agent_R46p_85_00232348_L38\n"
    "lw $15,-13580($15)\n"
    ".set pop\n"
    ".size func_00232348, .-func_00232348\n"
    ".text\n");
