#include "../common/types.h"

// Agent R46p_49 (2026-10-29): func_001bf6a8 (104 bytes), SLPM_666.75.
// Loop: s0 = 0; s0 = 0x1b9bc8(s0) (numeric jal, delay slot a0 = s0). Each nonzero result is kept
// in s0 and a0; when it is nonzero and (word at +1416) & 0x40000 is nonzero, calls the vtable
// slot +40 of the object at s0 (jalr through t6). Returns v0 once the call returns zero.
// Plain C is not used: the jal target has no functions.tsv row and the delay slots hold moves,
// so this is form (b): whole-body asm with numeric jal and local labels.
void r_FUN_001bf6a8(void) asm("func_001bf6a8");
#if 0
void r_FUN_001bf6a8(void) {
}
#endif

__asm__(
    ".section .text.func_001bf6a8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001bf6a8\n"
    ".type func_001bf6a8, @function\n"
    "func_001bf6a8:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "daddu $16,$0,$0\n"
    "lui $17,0x4\n"
    "1: jal 0x1b9bc8\n"
    "daddu $4,$16,$0\n"
    "daddu $16,$2,$0\n"
    "bnez $2,2f\n"
    "daddu $4,$2,$0\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    "2: lw $15,1416($16)\n"
    "and $15,$15,$17\n"
    "beqz $15,1b\n"
    "nop\n"
    "lw $15,0($16)\n"
    "lw $14,40($15)\n"
    "jalr $14\n"
    "nop\n"
    "b 1b\n"
    "nop\n"
    ".set pop\n"
    ".size func_001bf6a8, .-func_001bf6a8\n"
    ".text\n");
