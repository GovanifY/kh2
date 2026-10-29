#include "../common/types.h"

// FUN_001bbdb8 (92 bytes), whole-body asm.
// Code: frame of 16 with sd s0 and sd ra. If YS::MISSION::IsExec (0x1bb4a0) returns 0, result 0.
// Otherwise p = GetCurrent (0x1bbcb0); if (word at p+752) & 4 is zero, result 0. Else calls
// GetCurrent again and FUN_001d4fa8(p + 740, a0) and returns 1. The result lives in $2 throughout
// (plain C kept it in t6, which differs from the original).
void func_001bbdb8(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "jal 0x1bb4a0\n\t"
        "daddu $16,$4,$0\n\t"
        "beqz $2,1f\n\t"
        "daddu $2,$0,$0\n\t"
        "jal 0x1bbcb0\n\t"
        "nop\n\t"
        "lw $15,752($2)\n\t"
        "andi $15,$15,0x4\n\t"
        "beqz $15,1f\n\t"
        "daddu $2,$0,$0\n\t"
        "jal 0x1bbcb0\n\t"
        "nop\n\t"
        "addiu $4,$2,740\n\t"
        "jal 0x1d4fa8\n\t"
        "daddu $5,$16,$0\n\t"
        "addiu $2,$0,1\n\t"
        "1:\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
