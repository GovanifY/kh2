#include "../common/types.h"

// Asm label alias: registers func_0013f828 with this file (no C definition is emitted).
u32 r_FUN_0013f828(void) asm("func_0013f828");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_0013f828(void) {
    return 0;
}
#endif

// FUN_0013f828 (92 bytes). Top-level asm, so gcc emits no frame. The body keeps the original order:
// frame save of s1, s0, ra; s1 = a0; call FUN_0016c028(a0->+68) with s0 = s1 + 128; if the result
// differs from s0, copy 16 bytes with lq/sq; then float-subtract a constant from +132 and restore.
__asm__(
    ".section .text.func_0013f828,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0013f828\n"
    ".type func_0013f828, @function\n"
    "func_0013f828:\n"
    "addiu $29,$29,-32\n"
    "sd $17,8($29)\n"
    "sd $16,0($29)\n"
    "sd $31,16($29)\n"
    "daddu $17,$4,$0\n"
    "addiu $16,$17,128\n"
    "jal func_0016c028\n"
    "lw $4,68($4)\n"
    "beq $16,$2,2f\n"
    "lui $15,0x37\n"
    "lq $8,0($2)\n"
    "sq $8,0($16)\n"
    "lui $15,0x37\n"
    "2:\n"
    "lwc1 $f0,132($17)\n"
    "addiu $15,$15,-21064\n"
    "ld $16,0($29)\n"
    "lwc1 $f1,0($15)\n"
    "ld $31,16($29)\n"
    "sub.s $f0,$f0,$f1\n"
    "swc1 $f0,132($17)\n"
    "ld $17,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_0013f828, .-func_0013f828\n"
    ".text\n");
