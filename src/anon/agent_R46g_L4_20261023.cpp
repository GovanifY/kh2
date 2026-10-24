#include "../common/types.h"

// Asm label aliases: each registers func_<addr> with this file (no C definition is emitted).
void r_FUN_00180408(void) asm("func_00180408");
void r_FUN_00180c88(void) asm("func_00180c88");
void r_FUN_00180ef0(void) asm("func_00180ef0");
#if 0
void r_FUN_00180408(void) {
}
void r_FUN_00180c88(void) {
}
void r_FUN_00180ef0(void) {
}
#endif

// FUN_00180408 (64 bytes). Top-level asm, whole body. If a1 is zero, returns 0. Else calls
// FUN_00168b38(a1, 9, 0); returns word +8 of the result, or 0 if it is null.
__asm__(
    ".section .text.func_00180408,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00180408\n"
    ".type func_00180408, @function\n"
    "func_00180408:\n"
    "addiu $29,$29,-16\n"
    "daddu $15,$5,$0\n"
    "daddu $4,$5,$0\n"
    "sd $31,0($29)\n"
    "beqz $15,agent_r46g_l4_a_zero\n"
    "addiu $5,$0,9\n"
    "jal 0x168b38\n"
    "daddu $6,$0,$0\n"
    "beqzl $2,agent_r46g_l4_a_join\n"
    "daddu $2,$0,$0\n"
    "lw $2,8($2)\n"
    "agent_r46g_l4_a_join: ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "agent_r46g_l4_a_zero: b agent_r46g_l4_a_join\n"
    "daddu $2,$0,$0\n"
    ".set pop\n"
    ".size func_00180408, .-func_00180408\n"
    ".text\n");

// FUN_00180c88 (72 bytes). Top-level asm, whole body. Tail-calls FUN_0017f488 with f13 = 0.0 when
// word +256 of a0 is zero, else tail-calls FUN_001802d8 with fields of a0 (+252, +256, +240, +8).
__asm__(
    ".section .text.func_00180c88,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00180c88\n"
    ".type func_00180c88, @function\n"
    "func_00180c88:\n"
    "addiu $29,$29,-16\n"
    "daddu $15,$4,$0\n"
    "sd $31,0($29)\n"
    "lw $14,256($4)\n"
    "bnez $14,agent_r46g_l4_b_nz\n"
    "daddu $8,$5,$0\n"
    "mtc1 $0,$f13\n"
    "ld $31,0($29)\n"
    "j 0x17f488\n"
    "addiu $29,$29,16\n"
    "agent_r46g_l4_b_nz: lw $7,8($4)\n"
    "daddu $5,$14,$0\n"
    "lw $6,240($15)\n"
    "daddu $9,$0,$0\n"
    "lw $4,252($4)\n"
    "ld $31,0($29)\n"
    "j 0x1802d8\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00180c88, .-func_00180c88\n"
    ".text\n");

// FUN_00180ef0 (56 bytes). Top-level asm, whole body. Walks a linked list from the head at +396
// of a0 (the link of each node is the word at +44), sets bit 0x02000000 in word +8 of each node,
// and clears the head (+396) and +400 at the end.
__asm__(
    ".section .text.func_00180ef0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00180ef0\n"
    ".type func_00180ef0, @function\n"
    "func_00180ef0:\n"
    "daddu $13,$0,$0\n"
    "lui $12,0x200\n"
    "agent_r46g_l4_w1: bnezl $13,agent_r46g_l4_w2\n"
    "lw $14,44($13)\n"
    "lw $14,396($4)\n"
    "agent_r46g_l4_w2: bnez $14,agent_r46g_l4_w3\n"
    "daddu $13,$14,$0\n"
    "sw $0,396($4)\n"
    "jr $31\n"
    "sw $0,400($4)\n"
    "agent_r46g_l4_w3: lw $15,8($14)\n"
    "or $15,$15,$12\n"
    "b agent_r46g_l4_w1\n"
    "sw $15,8($14)\n"
    ".set pop\n"
    ".size func_00180ef0, .-func_00180ef0\n"
    ".text\n");
