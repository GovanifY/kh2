#include "../common/types.h"

// Agent R46p_63 (2026-10-29): FUN_001dc790 (84 bytes), SLPM_666.75.
// Whole-body asm (form b). Callee 0x1dc738 has no functions.tsv row, so it is reached by numeric jal.
// The bnezl is kept as a branch-likely, which plain C does not emit.
u32 r_FUN_001dc790(void) asm("func_001dc790");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_001dc790(void) {
}
#endif

__asm__(
    ".section .text.func_001dc790,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001dc790\n"
    ".type func_001dc790, @function\n"
    "func_001dc790:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "daddu $16,$4,$0\n"
    "jal 0x1dc738\n"
    " daddu $17,$0,$0\n"
    "bnezl $2,2f\n"
    " addiu $17,$0,1\n"
    "lw $14,8($16)\n"
    "lui $15,0x20\n"
    "and $14,$14,$15\n"
    "beqz $14,3f\n"
    " daddu $2,$17,$0\n"
    "addiu $17,$0,1\n"
    "2: daddu $2,$17,$0\n"
    "3: ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    " addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001dc790, .-func_001dc790\n"
    ".text\n");
