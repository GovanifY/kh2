#include "../common/types.h"

// Agent R46p_73 (2026-10-29): FUN_001e7810 (104 bytes), SLPM_666.75.
// Loops i from 0 while i < arg0->count (+100). For each arg0->table[i] (table at +120), calls the
// function pointer at +16 of that entry if it is non-null, passing arg0 as the argument.
// Matching: whole body as one file-scope asm block. The loop ends with a bnezl whose delay slot is the
// loop-head lw, which gcc 3.2 does not emit, so the original order is written out directly.
void r_FUN_001e7810(void) asm("func_001e7810");
#if 0
void r_FUN_001e7810(void) {
}
#endif

__asm__(
    ".section .text.func_001e7810,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001e7810\n"
    ".type func_001e7810, @function\n"
    "func_001e7810:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "daddu $16,$0,$0\n"
    "lw $12,100($4)\n"
    "blez $12,4f\n"
    "daddu $17,$4,$0\n"
    "lw $15,120($17)\n"
    "2:\n"
    "sll $14,$16,2\n"
    "addu $14,$14,$15\n"
    "lw $13,0($14)\n"
    "lw $15,16($13)\n"
    "beq $15,$0,3f\n"
    "addiu $16,$16,1\n"
    "jalr $15\n"
    "daddu $4,$17,$0\n"
    "lw $12,100($17)\n"
    "3:\n"
    "slt $15,$16,$12\n"
    "bnezl $15,2b\n"
    "lw $15,120($17)\n"
    "4:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001e7810, .-func_001e7810\n"
    ".text\n");
