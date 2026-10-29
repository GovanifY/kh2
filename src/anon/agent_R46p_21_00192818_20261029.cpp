#include "../common/types.h"

// Agent R46p_21 (2026-10-29): FUN_00192818 (80 bytes), SLPM_666.75. Retry of the R46p_14 leaf.
// Copies the six-word record at a2 to a 24-byte stack temporary with the original load order
// (words 5,1,2,3,4,0) and store order (sp words 2,0,1,3,4,5), then calls func_00192800(a0, a1, sp, a3)
// with jal and returns. Plain C copies give the 0..5 order, so this is whole-body asm.

void r_FUN_00192818(void) asm("func_00192818");
#if 0
void r_FUN_00192818(void) {
}
#endif

__asm__(
    ".section .text.func_00192818,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00192818\n"
    ".type func_00192818, @function\n"
    "func_00192818:\n"
    "addiu $29,$29,-48\n"
    "daddu $15,$6,$0\n"
    "sd $31,32($29)\n"
    "lw $9,20($6)\n"
    "lw $13,4($15)\n"
    "lw $12,8($15)\n"
    "daddu $6,$29,$0\n"
    "lw $11,12($15)\n"
    "lw $10,16($15)\n"
    "lw $14,0($15)\n"
    "sw $12,8($29)\n"
    "sw $14,0($29)\n"
    "sw $13,4($29)\n"
    "sw $11,12($29)\n"
    "sw $10,16($29)\n"
    "jal 0x192800\n"
    "sw $9,20($29)\n"
    "ld $31,32($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".set pop\n"
    ".size func_00192818, .-func_00192818\n"
    ".text\n");
