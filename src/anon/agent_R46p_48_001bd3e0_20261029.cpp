#include "../common/types.h"

// Asm label alias: registers func_001bd3e0 with this file (no C definition is emitted).
u32 r_FUN_001bd3e0(void) asm("func_001bd3e0");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_001bd3e0(void) {
    return 0;
}
#endif

// FUN_001bd3e0 (52 bytes). Top-level asm: the tail jump to 0x001bd418 is a numeric j with its
// addiu in the delay slot, which C cannot emit. The bnez delay slot holds the ld ra restore.
__asm__(
    ".section .text.func_001bd3e0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001bd3e0\n"
    ".type func_001bd3e0, @function\n"
    "func_001bd3e0:\n"
    "addiu $29,$29,-16\n"
    "lui $14,0x200\n"
    "sd $31,0($29)\n"
    "lw $13,2528($4)\n"
    "lw $15,1416($13)\n"
    "and $15,$15,$14\n"
    "bnez $15,1f\n"
    "ld $31,0($29)\n"
    "j 0x1bd418\n"
    "addiu $29,$29,16\n"
    "1:\n"
    "daddu $2,$0,$0\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001bd3e0, .-func_001bd3e0\n"
    ".text\n");
