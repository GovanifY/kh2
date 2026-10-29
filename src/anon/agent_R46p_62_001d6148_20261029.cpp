#include "../common/types.h"

// Agent R46p_62 (2026-10-29): FUN_001d6148 (108 bytes), SLPM_666.75.
// Whole-body asm (form b). Shared epilogue label "6" sits on the jr ra at offset 0x3c.
void r_FUN_001d6148(void) asm("func_001d6148");
#if 0
void r_FUN_001d6148(void) {
}
#endif

__asm__(
    ".section .text.func_001d6148,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001d6148\n"
    ".type func_001d6148, @function\n"
    "func_001d6148:\n"
    "addiu $29,$29,-16\n"
    "daddu $13,$5,$0\n"
    "sd $31,0($29)\n"
    "addiu $15,$0,3\n"
    "lw $14,2896($4)\n"
    "bne $14,$15,1f\n"
    "addiu $5,$0,1\n"
    "addiu $15,$0,700\n"
    "beq $13,$15,2f\n"
    "slti $15,$13,701\n"
    "beqz $15,3f\n"
    "addiu $15,$0,686\n"
    "beq $13,$15,4f\n"
    "ld $31,0($29)\n"
    "1:\n"
    "ld $31,0($29)\n"
    "6:\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "2:\n"
    "ld $31,0($29)\n"
    "4:\n"
    "j 0x1d5f30\n"
    "addiu $29,$29,16\n"
    "3:\n"
    "addiu $15,$0,703\n"
    "beq $13,$15,2b\n"
    "addiu $15,$0,706\n"
    "bne $13,$15,6b\n"
    "ld $31,0($29)\n"
    "b 4b\n"
    "nop\n"
    ".set pop\n"
    ".size func_001d6148, .-func_001d6148\n"
    ".text\n");
