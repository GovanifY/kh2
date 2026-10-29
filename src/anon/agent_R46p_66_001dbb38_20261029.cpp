#include "../common/types.h"

// FUN_001dbb38 (92 bytes). Loop: s0 = FUN_00185da8(s0); if s0 == 0 return; if FUN_0019c410(s0) == 0
// repeat; otherwise call the vtable slot at +32 of the object s0 with s0 as the argument.
// Matching: whole-body file-scope asm (form b). Plain C gives the wrong block layout: the original's
// bnez goes to an out-of-line block and the return falls through.
void r_FUN_001dbb38(void) asm("func_001dbb38");
#if 0
void r_FUN_001dbb38(void) {
}
#endif

__asm__(
    ".section .text.func_001dbb38,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001dbb38\n"
    ".type func_001dbb38, @function\n"
    "func_001dbb38:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$0,$0\n"
    "1:\n"
    "jal 0x185da8\n"
    "daddu $4,$16,$0\n"
    "daddu $16,$2,$0\n"
    "bnez $2,2f\n"
    "daddu $4,$2,$0\n"
    "ld $16,0($29)\n"
    "3:\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "2:\n"
    "jal 0x19c410\n"
    "nop\n"
    "beqz $2,1b\n"
    "nop\n"
    "lw $14,0($16)\n"
    "lw $15,32($14)\n"
    "jalr $15\n"
    "daddu $4,$16,$0\n"
    "b 3b\n"
    "ld $16,0($29)\n"
    ".set pop\n"
    ".size func_001dbb38, .-func_001dbb38\n"
    ".text\n");
