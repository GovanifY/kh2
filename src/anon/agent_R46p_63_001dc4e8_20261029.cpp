#include "../common/types.h"

// Agent R46p_63 (2026-10-29): FUN_001dc4e8 (88 bytes), SLPM_666.75.
// Whole-body asm (form b). Callee 0x1dc018 has no functions.tsv row, so it is reached by numeric jal.
u32 r_FUN_001dc4e8(void) asm("func_001dc4e8");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_001dc4e8(void) {
}
#endif

__asm__(
    ".section .text.func_001dc4e8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001dc4e8\n"
    ".type func_001dc4e8, @function\n"
    "func_001dc4e8:\n"
    "addiu $29,$29,-32\n"
    "daddu $15,$6,$0\n"
    "sd $17,8($29)\n"
    "addiu $6,$4,20\n"
    "sd $16,0($29)\n"
    "daddu $17,$7,$0\n"
    "sd $31,16($29)\n"
    "addiu $7,$4,24\n"
    "daddu $16,$4,$0\n"
    "daddu $4,$5,$0\n"
    "jal 0x1dc018\n"
    " daddu $5,$15,$0\n"
    "beqz $2,1f\n"
    " daddu $15,$0,$0\n"
    "sw $17,16($16)\n"
    "addiu $15,$0,1\n"
    "1: ld $16,0($29)\n"
    "daddu $2,$15,$0\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    " addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001dc4e8, .-func_001dc4e8\n"
    ".text\n");
