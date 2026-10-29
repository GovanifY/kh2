#include "../common/types.h"

// Agent R46p_96: FUN_00240a08 (100 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves s0 then ra. s0 = a0, or if a0 is zero, the word at D_00360000 - 4976.
// Calls 0x2409b8(s0); if the result differs from word +8 of s0, returns 0. Calls 0x105870(0); if the
// result differs from word +0, returns 0. Otherwise returns (word +4 == 0x3a).
// Matching: whole-body asm (form b). gcc returns through a0 in the delay slots and cannot reproduce it.
// Callees use numeric jal targets, so no symbol is needed at link time.
void r46p96_FUN_00240a08(void) asm("func_00240a08");
#if 0
void r46p96_FUN_00240a08(void) {
}
#endif

__asm__(
    ".section .text.func_00240a08,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00240a08\n"
    ".type func_00240a08, @function\n"
    "func_00240a08:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "bne $4,$0,1f\n"
    "daddu $16,$4,$0\n"
    "lui $15,0x36\n"
    "lw $16,-4976($15)\n"
    "1:\n"
    "jal 0x2409b8\n"
    "daddu $4,$16,$0\n"
    "lw $15,8($16)\n"
    "bne $2,$15,9f\n"
    "daddu $4,$0,$0\n"
    "jal 0x105870\n"
    "nop\n"
    "lw $15,0($16)\n"
    "bne $15,$2,9f\n"
    "daddu $4,$0,$0\n"
    "lw $15,4($16)\n"
    "xori $15,$15,0x3a\n"
    "sltiu $4,$15,1\n"
    "9:\n"
    "ld $16,0($29)\n"
    "daddu $2,$4,$0\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00240a08, .-func_00240a08\n"
    ".text\n");
