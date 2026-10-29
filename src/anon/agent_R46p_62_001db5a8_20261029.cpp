#include "../common/types.h"

// Agent R46p_62 (2026-10-29): FUN_001db5a8 (104 bytes), SLPM_666.75.
// Whole-body asm (form b). Two calls to 0x2fd248 with t0 = 0x321b28; the second
// call runs only when the first returns 0 (bne v0,0,1f). Operand order follows the reference.
void r_FUN_001db5a8(void) asm("func_001db5a8");
#if 0
void r_FUN_001db5a8(void) {
}
#endif

__asm__(
    ".section .text.func_001db5a8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001db5a8\n"
    ".type func_001db5a8, @function\n"
    "func_001db5a8:\n"
    "addiu $29,$29,-32\n"
    "addiu $7,$0,92\n"
    "sd $17,8($29)\n"
    "sd $16,0($29)\n"
    "lui $17,0x1d6\n"
    "sd $31,16($29)\n"
    "lw $5,-17748($17)\n"
    "lui $16,0x32\n"
    "addiu $16,$16,6952\n"
    "lw $6,4($5)\n"
    "daddu $8,$16,$0\n"
    "jal 0x2fd248\n"
    "addiu $5,$5,8\n"
    "daddu $8,$16,$0\n"
    "addiu $4,$0,69\n"
    "bne $2,$0,1f\n"
    "addiu $7,$0,92\n"
    "lw $15,-17748($17)\n"
    "lw $6,4($15)\n"
    "jal 0x2fd248\n"
    "addiu $5,$15,8\n"
    "1:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001db5a8, .-func_001db5a8\n"
    ".text\n");
