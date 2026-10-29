#include "../common/types.h"

// Agent R46p_9 (2026-10-29): func_00182ab0 (100 bytes), SLPM_666.75.
// Reads a count from 0x34ed00 (via t6 = 0x350000). If the count is positive, it calls func_00182910(p)
// for each index, with p starting at 0x1c6588 and stepping 12 bytes. The count is re-read each pass.
// Plain C (for-loop with the call) gave a different prologue and loop shape, so this is form (b):
// whole-body asm with the original sequence. The jal target is numeric.
void r_FUN_00182ab0(void) asm("func_00182ab0");
#if 0
void r_FUN_00182ab0(void) {
}
#endif

__asm__(
    ".section .text.func_00182ab0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00182ab0\n"
    ".type func_00182ab0, @function\n"
    "func_00182ab0:\n"
    "addiu $29,$29,-32\n"
    "lui $14,0x35\n"
    "sd $17,8($29)\n"
    "sd $16,0($29)\n"
    "sd $18,16($29)\n"
    "sd $31,24($29)\n"
    "lw $15,-4864($14)\n"
    "blez $15,3f\n"
    "daddu $17,$0,$0\n"
    "lui $15,0x1c6\n"
    "daddu $18,$14,$0\n"
    "addiu $16,$15,1416\n"
    "1: daddu $4,$16,$0\n"
    "jal 0x182910\n"
    "addiu $17,$17,1\n"
    "lw $15,-4864($18)\n"
    "slt $15,$17,$15\n"
    "bnez $15,1b\n"
    "addiu $16,$16,12\n"
    "3: ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "ld $31,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_00182ab0, .-func_00182ab0\n"
    ".text\n");
