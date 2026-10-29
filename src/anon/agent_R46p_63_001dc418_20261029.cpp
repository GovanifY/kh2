#include "../common/types.h"

// Agent R46p_63 (2026-10-29): FUN_001dc418 (108 bytes), SLPM_666.75.
// Whole-body asm (form b). Callees 0x1e2c00, 0x1e6c00 and 0x1dc4b8 have no functions.tsv rows,
// so they are reached by numeric jal/j.
u32 r_FUN_001dc418(void) asm("func_001dc418");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_001dc418(void) {
}
#endif

__asm__(
    ".section .text.func_001dc418,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001dc418\n"
    ".type func_001dc418, @function\n"
    "func_001dc418:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x35\n"
    "sd $16,0($29)\n"
    "addiu $15,$15,11080\n"
    "sd $31,8($29)\n"
    "sw $15,0($4)\n"
    "daddu $16,$4,$0\n"
    "lw $14,28($4)\n"
    "beqz $14,1f\n"
    " daddu $4,$14,$0\n"
    "jal 0x1e2c00\n"
    " nop\n"
    "jal 0x1e6c00\n"
    " lw $4,28($16)\n"
    "1: lui $4,0x35\n"
    "daddu $5,$16,$0\n"
    "jal 0x321c50\n"
    " addiu $4,$4,10976\n"
    "lui $14,0x35\n"
    "ld $31,8($29)\n"
    "lw $15,10984($14)\n"
    "daddu $4,$16,$0\n"
    "ld $16,0($29)\n"
    "addiu $15,$15,-1\n"
    "sw $15,10984($14)\n"
    "j 0x1dc4b8\n"
    " addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001dc418, .-func_001dc418\n"
    ".text\n");
