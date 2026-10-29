#include "../common/types.h"

// Agent R46p_84 (2026-10-29): FUN_0021f5d8 (72 bytes, SLPM_666.75).
// Saves s0/ra, s0 = a0, loads a word from lui 0x1da and stores 2 at +168 of it, a0 += 64,
// jal 0x2f4000 (unnamed callee, delay slot is the sb), then stores the float at D_00370000+2924
// into +172 of s0.
// Matching: the callee has no functions.tsv row, so plain C would emit jalr through a pointer.
// Whole body is one file-scope asm block with the original instruction order (form b).
void r_FUN_0021f5d8(void) asm("func_0021f5d8");
#if 0
void r_FUN_0021f5d8(void) {
}
#endif

__asm__(
    ".section .text.func_0021f5d8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0021f5d8\n"
    ".type func_0021f5d8, @function\n"
    "func_0021f5d8:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x1da\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$4,$0\n"
    "lw $14,-6432($15)\n"
    "addiu $4,$4,64\n"
    "addiu $15,$0,2\n"
    "jal 0x2f4000\n"
    "sb $15,168($14)\n"
    "lui $15,0x37\n"
    "ld $31,8($29)\n"
    "addiu $15,$15,2924\n"
    "lwc1 $f0,0($15)\n"
    "swc1 $f0,172($16)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0021f5d8, .-func_0021f5d8\n"
    ".text\n");
