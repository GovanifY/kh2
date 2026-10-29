#include "../common/types.h"

// Agent R46p_99 (2026-10-29): func_00263c60 (92 bytes), SLPM_666.75.
// If func_00263cc0() returns zero, returns. Otherwise loads the s16 at 0x35f0d8 (t5) and the
// word at 0x35f0dc (t6). If word[388] of t6 differs from t5, calls func_00138c10(t6, t5),
// then sets word[392] of the reloaded pointer to -1.
// Callees have no function rows, so plain C would emit jalr. This is form (b): whole-body asm.
// The jal targets are numeric.
void r_FUN_00263c60(void) asm("func_00263c60");
#if 0
void r_FUN_00263c60(void) {
}
#endif

__asm__(
    ".section .text.func_00263c60,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00263c60\n"
    ".type func_00263c60, @function\n"
    "func_00263c60:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x263cc0\n"
    "nop\n"
    "beq $2,$0,2f\n"
    "lui $15,0x36\n"
    "lui $16,0x36\n"
    "lh $13,-3880($15)\n"
    "lw $14,-3876($16)\n"
    "daddu $5,$13,$0\n"
    "lw $15,388($14)\n"
    "beq $15,$13,2f\n"
    "daddu $4,$14,$0\n"
    "jal 0x138c10\n"
    "nop\n"
    "lw $14,-3876($16)\n"
    "addiu $15,$0,-1\n"
    "sw $15,392($14)\n"
    "2: ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00263c60, .-func_00263c60\n"
    ".text\n");
