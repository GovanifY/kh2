#include "../common/types.h"

// Agent R46p_34 (2026-10-29): FUN_001b58b8 (52 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves ra. Loads the pointer at 0x01d48cb0 (lui 0x1d5 plus -29520), then tail-jumps
// to 0x16cfa0 with a0 = that pointer's word at +52, a1 = 0, a2 = the caller's a0, a3 = a1, t0 = a2.
// Matching: whole-body noreorder asm; the register moves and the lw are placed in the original order.
// The tail callee is reached by a numeric j target.

void func_001b58b8(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x1d5\n\t"
        "sd $31,0($29)\n\t"
        "daddu $13,$4,$0\n\t"
        "lw $14,-29520($15)\n\t"
        "daddu $7,$5,$0\n\t"
        "daddu $8,$6,$0\n\t"
        "ld $31,0($29)\n\t"
        "lw $4,52($14)\n\t"
        "daddu $6,$13,$0\n\t"
        "daddu $5,$0,$0\n\t"
        "j 0x16cfa0\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
