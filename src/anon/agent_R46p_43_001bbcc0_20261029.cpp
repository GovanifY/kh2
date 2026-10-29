#include "../common/types.h"

// FUN_001bbcc0 (52 bytes), whole-body asm.
// Code: frame of 16, sd ra, jal YS::MISSION::IsExec (0x1bb4a0). If it returns 0, the result is 1
// (li v0,1 in the beqz delay slot). Otherwise calls YS::MISSION::GetCurrent (0x1bbcb0), loads the
// record at +8 and returns the byte at +14 directly in v0 (plain C returned through t7).
void func_001bbcc0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "jal 0x1bb4a0\n\t"
        "nop\n\t"
        "beqz $2,1f\n\t"
        "addiu $2,$0,1\n\t"
        "jal 0x1bbcb0\n\t"
        "nop\n\t"
        "lw $15,8($2)\n\t"
        "lbu $2,14($15)\n\t"
        "1:\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
