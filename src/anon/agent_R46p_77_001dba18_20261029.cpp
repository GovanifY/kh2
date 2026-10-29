#include "../common/types.h"

// Agent R46p_77 (2026-10-29): FUN_001dba18 (108 bytes), SLPM_666.75.
// Code: frame of 32 bytes; saves s0, s1, ra. Loop: v0 = 0; s0 = 0x10000000; s1 = a0;
// calls func_001b9bc8(a0 = v0) via the ctarget_001b9bc8 row; if the result is non-zero,
// t6 = result, else t6 = 0 (the return block is the fall-through); the body walks
// the word at v0+1416 against s0 and the word at v0+8 against s1, branch-likely on the compare.
// Matching: whole-function file-scope __asm__ (form b) with local labels. A beql is not emitted
// by gcc 3.2, so plain C cannot reproduce the bnez/beql shape.
void r_FUN_001dba18(void) asm("func_001dba18");
#if 0
void r_FUN_001dba18(void) {
}
#endif

__asm__(
    ".section .text.func_001dba18,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001dba18\n"
    ".type func_001dba18, @function\n"
    "func_001dba18:\n"
    "addiu $29,$29,-32\n"
    "daddu $2,$0,$0\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "lui $16,0x1000\n"
    "daddu $17,$4,$0\n"
    "5:\n"
    "jal 0x1b9bc8\n"
    "daddu $4,$2,$0\n"
    "bnez $2,3f\n"
    "daddu $14,$2,$0\n"
    "daddu $14,$0,$0\n"
    "ld $16,0($29)\n"
    "6:\n"
    "daddu $2,$14,$0\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    "3:\n"
    "lw $15,1416($2)\n"
    "and $15,$15,$16\n"
    "beqz $15,5b\n"
    "nop\n"
    "lw $15,8($2)\n"
    "beql $15,$17,6b\n"
    "ld $16,0($29)\n"
    "b 5b\n"
    "nop\n"
    ".set pop\n"
    ".size func_001dba18, .-func_001dba18\n"
    ".text\n");
