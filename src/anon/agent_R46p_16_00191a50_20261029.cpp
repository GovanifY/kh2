#include "../common/types.h"

// Agent R46p_16 (2026-10-29): func_00191a50 (104 bytes), SLPM_666.75.
// Code: w = word at D_00350000 - 3520. If (w & 0x100) or (w & 0x2), returns 1. Otherwise returns 1
// when func_00197920(a0) is non-zero, or when func_001c8db8(D_00350000 + 7880, 0, a2, a3) is non-zero,
// and 0 otherwise. Saves s0 and ra in a 16-byte frame.
// Guess: a status check on a flag word with two follow-up probes.
// Matching: plain C gave the wrong branch shapes (the bnezl with li in its delay slot, and the shared
// li s0,1 / move v0,s0 tail). Form (b): whole-body asm with the original sequence, numeric jal targets.

void r_func_00191a50(void) asm("func_00191a50");
#if 0
void r_func_00191a50(void) {
}
#endif

__asm__(
    ".section .text.func_00191a50,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00191a50\n"
    ".type func_00191a50, @function\n"
    "func_00191a50:\n"
    "addiu $29,$29,-16\n"
    "lui $14,0x35\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lw $15,-3520($14)\n"
    "andi $14,$15,0x2\n"
    "andi $15,$15,0x100\n"
    "bnez $15,1f\n"
    "daddu $16,$0,$0\n"
    "bnezl $14,2f\n"
    "addiu $16,$0,1\n"
    "jal 0x197920\n"
    "nop\n"
    "bnez $2,1f\n"
    "daddu $5,$0,$0\n"
    "lui $4,0x35\n"
    "jal 0x1c8db8\n"
    "addiu $4,$4,7880\n"
    "beqz $2,3f\n"
    "daddu $2,$16,$0\n"
    "1:\n"
    "addiu $16,$0,1\n"
    "2:\n"
    "daddu $2,$16,$0\n"
    "3:\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00191a50, .-func_00191a50\n"
    ".text\n");
