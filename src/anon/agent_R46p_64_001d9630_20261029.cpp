#include "../common/types.h"

// FUN_001d9630 (88 bytes, SLPM_666.75). Whole-body noreorder asm (form b). Loops a1
// times over the u16 entries at a0: each nonzero entry is passed to FUN_001a3188(v, 100, 0)
// and then zeroed. FUN_001a3188 has no functions.tsv row, so it is reached by a numeric jal.
u32 r_FUN_001d9630(void) asm("func_001d9630");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_001d9630(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_001d9630,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001d9630\n"
    ".type func_001d9630, @function\n"
    "func_001d9630:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "blez $5,3f\n"
    "daddu $17,$4,$0\n"
    "daddu $16,$5,$0\n"
    "1:\n"
    "lhu $15,0($17)\n"
    "beq $15,$0,2f\n"
    "daddu $4,$15,$0\n"
    "addiu $5,$0,100\n"
    "jal 0x1a3188\n"
    "daddu $6,$0,$0\n"
    "sh $0,0($17)\n"
    "2:\n"
    "addiu $16,$16,-1\n"
    "bne $16,$0,1b\n"
    "addiu $17,$17,2\n"
    "3:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001d9630, .-func_001d9630\n"
    ".text\n");
