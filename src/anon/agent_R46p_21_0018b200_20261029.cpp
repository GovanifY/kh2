#include "../common/types.h"

// Agent R46p_21 (2026-10-29): FUN_0018b200 (108 bytes), SLPM_666.75.
// When the byte at +4 of the record at a0+8 equals 15, calls YS::ACT::is_exist(a0+768, 0x36cbb0)
// and, if it returns non-zero, tail-calls YS::ACT::push(a0+768, 0x36cbb0). The object pointer lives
// in s1 and the string address in s0. The original builds the string after the byte test, and
// plain C put the ld s0 in the bne delay slot, so this is whole-body asm. The callees are
// called by numeric address because their rows are mangled.

void r_FUN_0018b200(void) asm("func_0018b200");
#if 0
void r_FUN_0018b200(void) {
}
#endif

__asm__(
    ".section .text.func_0018b200,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0018b200\n"
    ".type func_0018b200, @function\n"
    "func_0018b200:\n"
    "addiu $29,$29,-32\n"
    "addiu $15,$0,15\n"
    "sd $17,8($29)\n"
    "sd $16,0($29)\n"
    "sd $31,16($29)\n"
    "addiu $17,$4,768\n"
    "lw $13,8($4)\n"
    "lbu $14,4($13)\n"
    "bne $14,$15,1f\n"
    "daddu $4,$17,$0\n"
    "lui $16,0x37\n"
    "addiu $16,$16,-13392\n"
    "jal 0x1883d8\n"
    "daddu $5,$16,$0\n"
    "daddu $4,$17,$0\n"
    "beq $2,$0,1f\n"
    "daddu $5,$16,$0\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "j 0x1880b0\n"
    "addiu $29,$29,32\n"
    "1:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_0018b200, .-func_0018b200\n"
    ".text\n");
