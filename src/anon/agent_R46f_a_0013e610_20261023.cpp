#include "../common/types.h"

// Agent R46f_a (2026-10-23): FUN_0013e610 (100 bytes), SLPM_666.75.
// Code: frame of 16 bytes. Saves ra, then a1 = a0, then s0. s0 = the word at 0x350000 - 31068.
// Decrements the word at s0 + 8100, picks the record at s0 + 8064 + (new count * 4), and
// s0 += record * 896. Calls func_0013e2d8(s0, a1, word at 0x350000 - 31072 + 32), then returns s0 in v0.
// Matching: the whole function is one file-scope __asm__ block, so gcc emits no prologue of its
// own. The prologue writes ra before a1/s0 as in the original; the asm carries the exact words.
void r_FUN_0013e610(void) asm("func_0013e610");
#if 0
void r_FUN_0013e610(void) {
}
#endif

__asm__(
    ".section .text.func_0013e610,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0013e610\n"
    ".type func_0013e610, @function\n"
    "func_0013e610:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x35\n"
    "sd $31,8($29)\n"
    "daddu $5,$4,$0\n"
    "sd $16,0($29)\n"
    "lw $16,-31068($15)\n"
    "lw $14,8100($16)\n"
    "addiu $14,$14,-1\n"
    "sll $15,$14,2\n"
    "sw $14,8100($16)\n"
    "addu $15,$15,$16\n"
    "lw $13,8064($15)\n"
    "lui $14,0x35\n"
    "lw $6,-31072($14)\n"
    "addiu $15,$0,896\n"
    "mult $13,$13,$15\n"
    "addiu $6,$6,32\n"
    "addu $16,$16,$13\n"
    "jal func_0013e2d8\n"
    "daddu $4,$16,$0\n"
    "daddu $2,$16,$0\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0013e610, .-func_0013e610\n"
    ".text\n");
