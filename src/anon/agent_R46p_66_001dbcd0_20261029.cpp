#include "../common/types.h"

// FUN_001dbcd0 (104 bytes). Calls FUN_0019ba60(word at 0x350000 - 5816); if the result is nonzero,
// calls FUN_0016c028 with the same argument and, unless the result equals the global at 0x1d5bab0,
// copies the 16 bytes at the result into that global. Then s = 0x350000 float at +10960 minus
// the float at +(-25072) from 0x350000, stored back.
// Matching: whole-body file-scope asm (form b). Numeric jal/beq targets; the delay-slot lui is kept.
void r_FUN_001dbcd0(void) asm("func_001dbcd0");
#if 0
void r_FUN_001dbcd0(void) {
}
#endif

__asm__(
    ".section .text.func_001dbcd0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001dbcd0\n"
    ".type func_001dbcd0, @function\n"
    "func_001dbcd0:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lui $16,0x35\n"
    "jal 0x19ba60\n"
    "lw $4,-5816($16)\n"
    "beqz $2,2f\n"
    "lui $14,0x35\n"
    "jal 0x16c028\n"
    "lw $4,-5816($16)\n"
    "lui $15,0x1d6\n"
    "addiu $15,$15,-17744\n"
    "beq $2,$15,2f\n"
    "lui $14,0x35\n"
    "lq $8,0($2)\n"
    "sq $8,0($15)\n"
    "lui $14,0x35\n"
    "2:\n"
    "ld $16,0($29)\n"
    "lui $15,0x35\n"
    "lwc1 $f0,10960($14)\n"
    "lwc1 $f1,-25072($15)\n"
    "ld $31,8($29)\n"
    "sub.s $f0,$f0,$f1\n"
    "swc1 $f0,10960($14)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001dbcd0, .-func_001dbcd0\n"
    ".text\n");
