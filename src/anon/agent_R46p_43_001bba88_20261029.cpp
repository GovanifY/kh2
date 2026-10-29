#include "../common/types.h"

// FUN_001bba88 (52 bytes), whole-body asm.
// Code: frame of 16, sd ra, jal YS::MISSION::IsExec (0x1bb4a0). If it returns 0, the result is 0
// (out-of-line b with move v0,zero). Otherwise calls FUN_001bba30 with D_01d49320 (lui t7 in the
// beqz delay slot, lw in the jal delay slot), then ld ra and jr.
// A plain-C tail call and a branch to a shared epilogue both differed from the original.
void func_001bba88(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "jal 0x1bb4a0\n\t"
        "nop\n\t"
        "beqz $2,1f\n\t"
        "lui $15,0x1d5\n\t"
        "jal 0x1bba30\n\t"
        "lw $4,-27872($15)\n\t"
        "2:\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        "1:\n\t"
        "b 2b\n\t"
        "daddu $2,$0,$0\n\t"
        ".set reorder"
        ::: "memory");
}
