#include "../common/types.h"

// FUN_00198700 (56 bytes): loops calling FUN_001b9bc8() until it returns 0 or the record it returns
// has bit 0 of the word at +1416 set; returns that record (or 0).
// Matching: whole-body noreorder asm. The original keeps move a0,v0 in the beqz delay slot, and
// the loop back-edge is a beqz to the jal, which plain C did not reproduce.
// The jal is numeric; gcc's trailing jr/nop falls past the 56-byte boundary.
void r_FUN_00198700(void) asm("func_00198700");

void r_FUN_00198700(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "1:\n\t"
        "jal 0x1b9bc8\n\t"
        " nop\n\t"
        "beqz $2,2f\n\t"
        " daddu $4,$2,$0\n\t"
        "lw $15,1416($2)\n\t"
        "andi $15,$15,0x1\n\t"
        "andi $15,$15,0xff\n\t"
        "beqz $15,1b\n\t"
        " nop\n\t"
        "2:\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
