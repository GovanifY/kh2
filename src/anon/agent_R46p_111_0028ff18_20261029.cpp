#include "../common/types.h"

// Agent R46p_111 (2026-10-29): FUN_0028ff18 (80 bytes, SLPM_666.75). Whole-body asm (form b).
// Calls 0x290060(a0). o = *p, v = s16 at p+12. If o->+388 != v: call 0x138c10(o, v), then (*p)->+392 = -1.
// Plain C gives the right shape but puts o/v/cmp in t5/t6/t7; the reference uses t7/t5/t6.
void r_FUN_0028ff18(void) asm("func_0028ff18");
#if 0
void r_FUN_0028ff18(void) {
}
#endif

__asm__(
    ".section .text.func_0028ff18,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0028ff18\n"
    ".type func_0028ff18, @function\n"
    "func_0028ff18:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x290060\n"
    "daddu $16,$4,$0\n"
    "lw $15,0($16)\n"
    "lh $13,12($16)\n"
    "lw $14,388($15)\n"
    "daddu $4,$15,$0\n"
    "beq $14,$13,2f\n"
    "daddu $5,$13,$0\n"
    "jal 0x138c10\n"
    "nop\n"
    "lw $14,0($16)\n"
    "addiu $15,$0,-1\n"
    "sw $15,392($14)\n"
    "2:\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0028ff18, .-func_0028ff18\n"
    ".text\n");
