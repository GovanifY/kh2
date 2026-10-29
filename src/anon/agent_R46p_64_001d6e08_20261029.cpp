#include "../common/types.h"

// FUN_001d6e08 (84 bytes, SLPM_666.75). Whole-body noreorder asm (form b): the loop
// ends in bgezl, which gcc 3.2 does not emit. Loops twice over the words at a0+4,
// calling FUN_0016ed50(word, -1, 30) for each nonzero word.
u32 r_FUN_001d6e08(void) asm("func_001d6e08");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_001d6e08(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_001d6e08,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001d6e08\n"
    ".type func_001d6e08, @function\n"
    "func_001d6e08:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "addiu $16,$4,4\n"
    "addiu $17,$0,1\n"
    "lw $15,0($16)\n"
    "1:\n"
    "addiu $16,$16,4\n"
    "beq $15,$0,2f\n"
    "daddu $4,$15,$0\n"
    "addiu $5,$0,-1\n"
    "jal 0x16ed50\n"
    "addiu $6,$0,30\n"
    "2:\n"
    "addiu $17,$17,-1\n"
    "bgezl $17,1b\n"
    "lw $15,0($16)\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001d6e08, .-func_001d6e08\n"
    ".text\n");
