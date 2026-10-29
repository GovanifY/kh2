#include "../common/types.h"

// Asm label alias: registers func_001db198 with this file (no C definition is emitted).
s32 r_FUN_001db198(void) asm("func_001db198");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
s32 r_FUN_001db198(void) {
    return 0;
}
#endif

// FUN_001db198 (104 bytes). Whole-body noreorder asm, top-level, so gcc emits no frame.
// a1 == 0 returns 1; a1 < 0 or a1 >= 3 returns 0. Otherwise calls FUN_001db200(a0, a1);
// if that is nonzero, returns (FUN_001db250(a0) != 0). a0 is kept in s0, the result in s1.
__asm__(
    ".section .text.func_001db198,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001db198\n"
    ".type func_001db198, @function\n"
    "func_001db198:\n"
    "addiu $29,$29,-32\n"
    "addiu $2,$0,1\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "beq $5,$0,4f\n"
    "daddu $16,$4,$0\n"
    "bltz $5,3f\n"
    "slti $15,$5,3\n"
    "beq $15,$0,4f\n"
    "daddu $2,$0,$0\n"
    "jal 0x1db200\n"
    "daddu $17,$0,$0\n"
    "beq $2,$0,5f\n"
    "daddu $4,$16,$0\n"
    "jal 0x1db250\n"
    "nop\n"
    "sltu $17,$0,$2\n"
    "5:\n"
    "daddu $2,$17,$0\n"
    "4:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    "3:\n"
    "b 4b\n"
    "daddu $2,$0,$0\n"
    ".set pop\n"
    ".size func_001db198, .-func_001db198\n"
    ".text\n");
