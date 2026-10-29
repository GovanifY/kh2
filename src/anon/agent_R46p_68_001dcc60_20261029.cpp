#include "../common/types.h"

// Agent R46p_68 (2026-10-29): FUN_001dcc60 (104 bytes), SLPM_666.75.
// Whole-body asm (form b): a beql on $s0 needs branch-likely, which gcc 3.2 does not emit.
// Callees 0x1dcd38 and 0x1c8ab0 are reached by numeric jal.
u32 r_FUN_001dcc60(void) asm("func_001dcc60");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_001dcc60(void) {
}
#endif

__asm__(
    ".section .text.func_001dcc60,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001dcc60\n"
    ".type func_001dcc60, @function\n"
    "func_001dcc60:\n"
    "addiu $29,$29,-32\n"
    "sd $17,8($29)\n"
    "sd $16,0($29)\n"
    "sd $18,16($29)\n"
    "daddu $17,$4,$0\n"
    "sd $31,24($29)\n"
    "addiu $16,$0,1\n"
    "jal 0x1dcd38\n"
    " daddu $18,$0,$0\n"
    "beql $2,$16,4f\n"
    " lw $15,8($17)\n"
    "jal 0x1c8ab0\n"
    " nop\n"
    "beq $2,$16,5f\n"
    " daddu $2,$18,$0\n"
    "lw $15,8($17)\n"
    "4: lui $14,0x80\n"
    "and $15,$15,$14\n"
    "sltiu $18,$15,1\n"
    "daddu $2,$18,$0\n"
    "5: ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "ld $31,24($29)\n"
    "jr $31\n"
    " addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001dcc60, .-func_001dcc60\n"
    ".text\n");
