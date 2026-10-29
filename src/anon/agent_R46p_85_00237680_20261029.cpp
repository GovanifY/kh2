#include "../common/types.h"

// Agent R46p_85 (2026-10-29): FUN_00237680 (88 bytes, SLPM_666.75).
// Prologue opens a 16-byte frame, reloads ra, and jumps to the body at +0x18. The body
// compares the word at arg0+104 with arg1. If equal, it returns. Otherwise it stores arg1 there,
// and sets arg0+20 from the halfword at (arg0+12)+arg1*4 times 20 plus arg0+8, and arg0+24 from
// the next halfword.
// Matching: the stub and the raw mult (.word 0x01ee7818, mult $15,$15,$14) need whole-body asm.
// Plain C is not used.
void r_FUN_00237680(void) asm("func_00237680");
#if 0
void r_FUN_00237680(void) {
}
#endif

__asm__(
    ".section .text.func_00237680,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00237680\n"
    ".type func_00237680, @function\n"
    "func_00237680:\n"
    "addiu $29,$29,-16\n"
    "sd $31,0($29)\n"
    "ld $31,0($29)\n"
    "j agent_R46p_85_00237680_L18\n"
    "addiu $29,$29,16\n"
    "nop\n"
    "agent_R46p_85_00237680_L18:\n"
    "lw $15,104($4)\n"
    "beq $15,$5,agent_R46p_85_00237680_L50\n"
    "sll $14,$5,2\n"
    "lw $12,12($4)\n"
    "sw $5,104($4)\n"
    "addu $12,$12,$14\n"
    "lw $13,8($4)\n"
    "lhu $15,0($12)\n"
    "addiu $14,$0,20\n"
    ".word 0x01ee7818\n"
    "addu $13,$13,$15\n"
    "sw $13,20($4)\n"
    "lhu $15,2($12)\n"
    "sw $15,24($4)\n"
    "agent_R46p_85_00237680_L50:\n"
    "jr $31\n"
    "nop\n"
    ".set pop\n"
    ".size func_00237680, .-func_00237680\n"
    ".text\n");
