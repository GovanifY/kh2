#include "../common/types.h"

// Agent R46p_68 (2026-10-29): FUN_001e0230 (108 bytes), SLPM_666.75.
// Whole-body asm (form b): a bnezl loop head with a branch-likely delay lw needs asm.
// Callee 0x1e01e8 has a func_ row but is reached by numeric jal.
u32 r_FUN_001e0230(void) asm("func_001e0230");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_001e0230(void) {
}
#endif

__asm__(
    ".section .text.func_001e0230,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001e0230\n"
    ".type func_001e0230, @function\n"
    "func_001e0230:\n"
    "addiu $29,$29,-48\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $18,16($29)\n"
    "daddu $16,$0,$0\n"
    "sd $19,24($29)\n"
    "daddu $17,$5,$0\n"
    "sd $31,32($29)\n"
    "daddu $18,$4,$0\n"
    "lui $19,0x1da\n"
    "3: bnezl $16,6f\n"
    " lw $4,20($16)\n"
    "lw $4,-7352($19)\n"
    "6: bnez $4,7f\n"
    " daddu $16,$4,$0\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "ld $19,24($29)\n"
    "ld $31,32($29)\n"
    "jr $31\n"
    " addiu $29,$29,48\n"
    "7: daddu $5,$18,$0\n"
    "jal 0x1e01e8\n"
    " daddu $6,$17,$0\n"
    "beq $0,$0,3b\n"
    " nop\n"
    ".set pop\n"
    ".size func_001e0230, .-func_001e0230\n"
    ".text\n");
