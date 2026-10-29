#include "../common/types.h"

// Agent R46p_47 (2026-10-29): FUN_001c2ba8 (88 bytes), SLPM_666.75.
// Walks 8 words at 0x1d49530 (from the end, s1 = 7 down to 0). A non-zero word is passed to
// func_001dc9d0 (a0 = word); when that returns 0 the word is cleared. The clear sits in a
// branch-likely delay slot (beqzl), which gcc 3.2 does not emit, so this is a whole-body asm.
void r_FUN_001c2ba8(void) asm("func_001c2ba8");
#if 0
void r_FUN_001c2ba8(void) {
}
#endif

__asm__(
    ".section .text.func_001c2ba8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001c2ba8\n"
    ".type func_001c2ba8, @function\n"
    "func_001c2ba8:\n"
    "addiu $29,$29,-32\n"
    "lui $15,0x1d5\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "addiu $16,$15,-27344\n"
    "addiu $17,$0,7\n"
    "1:\n"
    "lw $15,0($16)\n"
    "beq $15,$0,2f\n"
    "daddu $4,$15,$0\n"
    "jal 0x1dc9d0\n"
    "nop\n"
    "beql $2,$0,2f\n"
    "sw $0,0($16)\n"
    "2:\n"
    "addiu $17,$17,-1\n"
    "bgez $17,1b\n"
    "addiu $16,$16,4\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001c2ba8, .-func_001c2ba8\n"
    ".text\n");
