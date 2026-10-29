#include "../common/types.h"

// Agent R46p_109 (2026-10-29): FUN_002924d0 (76 bytes, align flag), SLPM_666.75.
// If a1 is zero, returns a0 + 11068 (branch-taken path, the b shares the ld s0 block). Otherwise calls
// FUN_001a80c8(a1) and FUN_001a8190(result), then returns movz(v0 = a0+11068 selected by v0 == 0).
// Whole-body noreorder asm: the branch-free movz tail and the b path keep the original's order, and
// the second call's delay slot holds move a0,v0.

void r_FUN_002924d0(void) asm("func_002924d0");

void r_FUN_002924d0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "daddu $4,$5,$0\n\t"
        "beq $5,$0,3f\n\t"
        "addiu $2,$16,11068\n\t"
        "jal 0x1a80c8\n\t"
        "nop\n\t"
        "jal 0x1a8190\n\t"
        "daddu $4,$2,$0\n\t"
        "addiu $4,$16,11068\n\t"
        "4:\n\t"
        "ld $16,0($29)\n\t"
        "movz $2,$4,$2\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        "3:\n\t"
        "beq $0,$0,4b\n\t"
        "daddu $4,$2,$0\n\t"
        ".set reorder"
        ::: "memory");
}
