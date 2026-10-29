#include "../common/types.h"

// Agent R46p_47 (2026-10-29): FUN_001c2c98 (76 bytes), SLPM_666.75.
// Calls the unnamed func at 0x1d7cd0 with a0 (move s0,a0 sits in the jal delay slot), then sets
// bit 0x200000 in the word at +1416 and stores 0x351468 at +0 and (word at +2748) | 4 back.
// The callee has no name row, so a numeric jal in whole-body asm is used.
void r_FUN_001c2c98(void) asm("func_001c2c98");
#if 0
void r_FUN_001c2c98(void) {
}
#endif

__asm__(
    ".section .text.func_001c2c98,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001c2c98\n"
    ".type func_001c2c98, @function\n"
    "func_001c2c98:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x1d7cd0\n"
    "daddu $16,$4,$0\n"
    "lw $13,1416($16)\n"
    "lui $15,0x20\n"
    "lw $14,2748($16)\n"
    "or $13,$13,$15\n"
    "ld $31,8($29)\n"
    "lui $15,0x35\n"
    "sw $13,1416($16)\n"
    "ori $14,$14,0x4\n"
    "addiu $15,$15,5224\n"
    "sw $15,0($16)\n"
    "sw $14,2748($16)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001c2c98, .-func_001c2c98\n"
    ".text\n");
