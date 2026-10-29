#include "../common/types.h"

// Agent R46p_21 (2026-10-29): FUN_00192940 (80 bytes), SLPM_666.75.
// Copies the six-word record at a2 to a 24-byte stack temporary, using a load/store order that
// plain C does not reproduce (loads 5,1,2,3,4,0 and stores 2,0,1,3,4,5 by word index).
// Then calls the unnamed function at 0x192868 with (a0, a1, sp, a3) and returns its result.
// Whole-body asm: the callee has no functions.tsv row, so it is called by its numeric address.

void r_FUN_00192940(void) asm("func_00192940");
#if 0
void r_FUN_00192940(void) {
}
#endif

__asm__(
    ".section .text.func_00192940,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00192940\n"
    ".type func_00192940, @function\n"
    "func_00192940:\n"
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
    "jal 0x192868\n"
    "sw $9,20($29)\n"
    "ld $31,32($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".set pop\n"
    ".size func_00192940, .-func_00192940\n"
    ".text\n");
