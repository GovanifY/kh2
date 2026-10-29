#include "../common/types.h"

// Agent R46p_96: FUN_00241608 (100 bytes), SLPM_666.75.
// Code: frame of 32 bytes, saves s0, s1, ra. s0 = a1, s1 = a2, then calls 0x2416d8 (a0 unchanged, a1 = s0, a2 = s1).
// Result goes to a3. t6 = the word at D_00360000 - 4972. If s0 is zero, a1 = the word at D_00360000 - 4984.
// If a2 is zero, a2 = the word at D_00360000 - 4976. Then a0 = byte at t6 (delay slot), and tail j 0x2346f0.
// Matching: whole-body asm (form b). Byte-identical to the other body at 0x241608 apart from the tail target.
void r46p96_FUN_00241608(void) asm("func_00241608");
#if 0
void r46p96_FUN_00241608(void) {
}
#endif

__asm__(
    ".section .text.func_00241608,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00241608\n"
    ".type func_00241608, @function\n"
    "func_00241608:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "daddu $16,$5,$0\n"
    "jal 0x2416d8\n"
    "daddu $17,$6,$0\n"
    "lui $15,0x36\n"
    "daddu $7,$2,$0\n"
    "lw $14,-4972($15)\n"
    "daddu $8,$0,$0\n"
    "daddu $5,$16,$0\n"
    "bne $16,$0,1f\n"
    "daddu $6,$17,$0\n"
    "lui $15,0x36\n"
    "lw $5,-4984($15)\n"
    "1:\n"
    "bne $6,$0,2f\n"
    "lb $4,0($14)\n"
    "lui $15,0x36\n"
    "lw $6,-4976($15)\n"
    "2:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "j 0x2346f0\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_00241608, .-func_00241608\n"
    ".text\n");
