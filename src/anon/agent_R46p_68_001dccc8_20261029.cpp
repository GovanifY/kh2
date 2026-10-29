#include "../common/types.h"

// Agent R46p_68 (2026-10-29): FUN_001dccc8 (88 bytes), SLPM_666.75.
// Whole-body asm (form b). Callees 0x1e3468 and 0x143fc8 have no functions.tsv rows,
// so they are reached by numeric jal.
u32 r_FUN_001dccc8(void) asm("func_001dccc8");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_001dccc8(void) {
}
#endif

__asm__(
    ".section .text.func_001dccc8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001dccc8\n"
    ".type func_001dccc8, @function\n"
    "func_001dccc8:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x100\n"
    "sd $31,0($29)\n"
    "andi $5,$5,0xff\n"
    "daddu $13,$0,$0\n"
    "lw $14,8($4)\n"
    "and $14,$14,$15\n"
    "bnez $14,2f\n"
    " daddu $2,$0,$0\n"
    "beqz $5,2f\n"
    " daddu $2,$13,$0\n"
    "jal 0x1e3468\n"
    " lw $4,28($4)\n"
    "lui $4,0x35\n"
    "daddu $5,$2,$0\n"
    "jal 0x143fc8\n"
    " addiu $4,$4,11008\n"
    "daddu $13,$2,$0\n"
    "daddu $2,$13,$0\n"
    "2: ld $31,0($29)\n"
    "jr $31\n"
    " addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001dccc8, .-func_001dccc8\n"
    ".text\n");
