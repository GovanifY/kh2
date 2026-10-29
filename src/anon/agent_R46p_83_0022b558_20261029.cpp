#include "../common/types.h"

// Agent R46p_83 (2026-10-29): FUN_0022b558 (104 bytes), SLPM_666.75.
// Saves s0..s2 and ra. s0 = a2, s1 = a0, s2 = a1. Calls the MUSICAL_2D getSqd helper at 0x22b9e0
// (no func_ row, reached by a numeric jal), then calls func_001386e0(s1, 2500, v0, s0, s2, 11).
// Stores the float constant at 0x371134 to the word at s1 + 384, then restores and returns.
// Whole-body asm: the jal delay slots carry the argument moves (move a0,s1 / move a3,s0 /
// move t0,s2 / li t1,11), and the epilogue restores interleave with the float store, which plain C
// does not reproduce.

void r_FUN_0022b558(void) asm("func_0022b558");

void r_FUN_0022b558(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $18,16($29)\n\t"
        "daddu $16,$6,$0\n\t"
        "sd $31,24($29)\n\t"
        "daddu $17,$4,$0\n\t"
        "jal 0x22b9e0\n\t"
        " daddu $18,$5,$0\n\t"
        "daddu $4,$17,$0\n\t"
        "daddu $7,$16,$0\n\t"
        "daddu $8,$18,$0\n\t"
        "daddu $6,$2,$0\n\t"
        "addiu $5,$0,2500\n\t"
        "jal func_001386e0\n\t"
        " addiu $9,$0,11\n\t"
        "lui $15,0x37\n\t"
        "ld $16,0($29)\n\t"
        "addiu $15,$15,4404\n\t"
        "ld $18,16($29)\n\t"
        "lwc1 $f0,0($15)\n\t"
        "ld $31,24($29)\n\t"
        "swc1 $f0,384($17)\n\t"
        "ld $17,8($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}
