#include "../common/types.h"

// Agent R46p_130 (2026-10-29): FUN_002bfd48 (72 bytes), SLPM_666.75.
// FUN_002be340(a1); while (FUN_002be4a0() != 0) FUN_00102448(*(a0), 0); return 0.
// Matching: whole-body asm (form b). FUN_002be4a0 and FUN_00102448 are numeric jals (their registry names are not func_ rows).
void r_FUN_002bfd48(void) asm("func_002bfd48");
#if 0
void r_FUN_002bfd48(void) {
}
#endif

__asm__(
    ".section .text.func_002bfd48,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002bfd48\n"
    ".type func_002bfd48, @function\n"
    "func_002bfd48:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$4,$0\n"
    "jal func_002be340\n"
    "daddu $4,$5,$0\n"
    "1:\n"
    "jal 0x2be4a0\n"
    "nop\n"
    "bne $2,$0,2f\n"
    "daddu $5,$0,$0\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "2:\n"
    "jal 0x102448\n"
    "lw $4,0($16)\n"
    "beq $0,$0,1b\n"
    "nop\n"
    ".set pop\n"
    ".size func_002bfd48, .-func_002bfd48\n"
);
