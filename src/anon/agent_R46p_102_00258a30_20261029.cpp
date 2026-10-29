#include "../common/types.h"

// Agent R46p_102: func_00258a30 (88 bytes), SLPM_666.75.
// Tests the word at D_00360000 - 3972 with the predicate at 0x139d78; if that result is zero,
// tests the word at D_00360000 - 3976 the same way. Returns the result as 0 or 1.
// Whole-body asm (form b): plain C gives the epilogue on the zero path, the original branches
// straight to jr ra, skipping the second ld ra. Numeric jal and labels.
void r_FUN_00258a30(void) asm("func_00258a30");
#if 0
void r_FUN_00258a30(void) {
}
#endif

__asm__(
    ".section .text.func_00258a30,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00258a30\n"
    ".type func_00258a30, @function\n"
    "func_00258a30:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x36\n"
    "sd $31,0($29)\n"
    "daddu $2,$0,$0\n"
    "lw $14,-3972($15)\n"
    "beq $14,$0,1f\n"
    "daddu $4,$14,$0\n"
    "jal 0x139d78\n"
    "nop\n"
    "sltu $2,$0,$2\n"
    "1: bne $2,$0,2f\n"
    "ld $31,0($29)\n"
    "lui $15,0x36\n"
    "lw $14,-3976($15)\n"
    "beq $14,$0,2f\n"
    "daddu $4,$14,$0\n"
    "jal 0x139d78\n"
    "nop\n"
    "sltu $2,$0,$2\n"
    "ld $31,0($29)\n"
    "2: jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00258a30, .-func_00258a30\n"
    ".text\n");
