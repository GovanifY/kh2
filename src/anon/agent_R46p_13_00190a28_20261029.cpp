#include "../common/types.h"

// Agent R46p_13 (2026-10-29): FUN_00190a28 (84 bytes, SLPM_666.75).
// Code: frame of 16. Sets v0 = 0. If the word at a1+264 has bit 0x800 clear, saves a0 in s0
// and calls 0x1cd7a8(0x01c60d10, a1), keeping the result in v0. If v0 is still 0, loads the
// word at 0x34e948. Then restores s0/ra and tail-calls 0x190878(s0, v0, 0).
// Matching: whole-body asm. The move s0,a0 sits in the bnez delay slot, the beqz/bnez join
// keeps a single move a0,s0 on both paths, and the tail is a numeric j. Plain C duplicated
// the a0 move on the fall-through path (21 bytes off), and a named tail to the mangled row
// for 0x190878 did not encode the j. Form (b): top-level asm in .text.func_00190a28.

void r_FUN_00190a28(void) asm("func_00190a28");
#if 0
void r_FUN_00190a28(void) {
}
#endif

__asm__(
    ".section .text.func_00190a28,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00190a28\n"
    ".type func_00190a28, @function\n"
    "func_00190a28:\n"
    "addiu $29,$29,-16\n"
    "daddu $2,$0,$0\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lw $15,264($5)\n"
    "andi $15,$15,0x800\n"
    "bne $15,$0,agent_R46p_13_00190a28_L1\n"
    "daddu $16,$4,$0\n"
    "lui $4,0x1c6\n"
    "jal 0x1cd7a8\n"
    "addiu $4,$4,3344\n"
    "agent_R46p_13_00190a28_L1:\n"
    "bne $2,$0,agent_R46p_13_00190a28_L2\n"
    "daddu $4,$16,$0\n"
    "lui $15,0x35\n"
    "lw $2,-5816($15)\n"
    "agent_R46p_13_00190a28_L2:\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "daddu $5,$2,$0\n"
    "daddu $6,$0,$0\n"
    "j 0x190878\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00190a28, .-func_00190a28\n"
    ".text\n");
