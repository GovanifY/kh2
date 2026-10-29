#include "../common/types.h"

// Agent R46p_61 (2026-10-29): FUN_001d59b0 (108 bytes), SLPM_666.75.
// Whole-body asm (bnezl loop). Walks the record array at the global pointer stored at
// 0x1d5xxx (word -17812 of s2 = 0x1d60000). For each record of 60 bytes (count at +4),
// calls func_001d5960(record) with the record pointer advanced by 8.
void r_FUN_001d59b0(void) asm("func_001d59b0");
#if 0
void r_FUN_001d59b0(void) {
}
#endif

__asm__(
    ".section .text.func_001d59b0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001d59b0\n"
    ".type func_001d59b0, @function\n"
    "func_001d59b0:\n"
    "addiu $29,$29,-32\n"
    "sd $18,16($29)\n"
    "sd $17,8($29)\n"
    "lui $18,0x1d6\n"
    "sd $16,0($29)\n"
    "sd $31,24($29)\n"
    "lw $4,-17812($18)\n"
    "lw $15,4($4)\n"
    "blez $15,1f\n"
    "daddu $17,$0,$0\n"
    "daddu $16,$0,$0\n"
    "addu $4,$4,$16\n"
    "2:\n"
    "addiu $17,$17,1\n"
    "addiu $4,$4,8\n"
    "jal 0x1d5960\n"
    "addiu $16,$16,60\n"
    "lw $4,-17812($18)\n"
    "lw $15,4($4)\n"
    "slt $15,$17,$15\n"
    "bnezl $15,2b\n"
    "addu $4,$4,$16\n"
    "1:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $18,16($29)\n"
    "ld $31,24($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001d59b0, .-func_001d59b0\n"
    ".text\n");
