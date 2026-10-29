#include "../common/types.h"

// Agent R46p_80 (2026-10-29): FUN_001eaee0 (108 bytes), SLPM_666.75.
// Reads a pointer at a2+12, adds the word it points to into a0, calls the unnamed 0x2f4000 with
// (D_01da (-6424) + 16) in a0, then copies three floats from the object into the four-byte
// slots at +64, +68 and +72 of the global object at D_01d9e6e8.
// Matching: the callee has no functions.tsv row, so plain C would emit jalr. The whole body is a
// file-scope asm block with a numeric jal and the addiu in the delay slot.
void r_FUN_001eaee0(void) asm("func_001eaee0");
#if 0
void r_FUN_001eaee0(void) {
}
#endif

__asm__(
    ".section .text.func_001eaee0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001eaee0\n"
    ".type func_001eaee0, @function\n"
    "func_001eaee0:\n"
    "addiu $29,$29,-32\n"
    "lw $14,12($6)\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "daddu $16,$4,$0\n"
    "lui $17,0x1da\n"
    "lw $15,0($14)\n"
    "lw $4,-6424($17)\n"
    "addu $16,$16,$15\n"
    "jal 0x2f4000\n"
    "addiu $4,$4,16\n"
    "lwc1 $f0,160($16)\n"
    "addiu $13,$16,160\n"
    "lw $15,-6424($17)\n"
    "ld $16,0($29)\n"
    "swc1 $f0,64($15)\n"
    "ld $31,16($29)\n"
    "lw $14,-6424($17)\n"
    "lwc1 $f0,4($13)\n"
    "swc1 $f0,68($14)\n"
    "lw $15,-6424($17)\n"
    "lwc1 $f0,8($13)\n"
    "ld $17,8($29)\n"
    "swc1 $f0,72($15)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001eaee0, .-func_001eaee0\n"
    ".text\n");
