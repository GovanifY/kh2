#include "../common/types.h"

// Agent R46p_79 (2026-10-29): FUN_001db950 (84 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves s0 and ra. Calls the unregistered 0x1c23a8 with
// a0..a2 unchanged, a3 = 0, t0 = 0, t1 = 96 (sixth argument in the jal delay slot),
// and t2 = the original a3 (copied before the call). Then sets bit 0x1000 in the word
// at +1416, clears the word at +2552, and stores 0x350000 + 10872 at +0.
// Matching: whole-function file-scope __asm__ (form b) with a numeric jal, since the
// callee has no functions.tsv row. Plain C cannot place the t2 copy and li t1 in these slots.
void r_FUN_001db950(void) asm("func_001db950");
#if 0
void r_FUN_001db950(void) {
}
#endif

__asm__(
    ".section .text.func_001db950,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001db950\n"
    ".type func_001db950, @function\n"
    "func_001db950:\n"
    "addiu $29,$29,-16\n"
    "daddu $10,$7,$0\n"
    "sd $16,0($29)\n"
    "daddu $7,$0,$0\n"
    "sd $31,8($29)\n"
    "daddu $8,$0,$0\n"
    "daddu $16,$4,$0\n"
    "jal 0x1c23a8\n"
    "addiu $9,$0,96\n"
    "lw $13,1416($16)\n"
    "lui $14,0x1000\n"
    "lui $15,0x35\n"
    "sw $0,2552($16)\n"
    "or $13,$13,$14\n"
    "ld $31,8($29)\n"
    "addiu $15,$15,10872\n"
    "sw $13,1416($16)\n"
    "sw $15,0($16)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001db950, .-func_001db950\n"
    ".text\n");
