#include "../common/types.h"

// Agent R46p_27 (2026-10-29): FUN_001a5928 (72 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves ra and s0. Calls FUN_001c70e8(), then s0 = FUN_001050d8(2560),
// then v0 = FUN_0016e920(1475), and tail-jumps to FUN_001a4df0(s0, v0, 256, 96).
// Matching: the whole function is one noreorder asm block with no C locals. The epilogue restores
// (ld ra, ld s0) sit between the second call and the tail jump, which plain C does not reproduce.
// Callees without a functions.tsv row are reached by numeric jal/j targets.
// The 8 bytes of gcc's trailing jr ra; nop fall past the 72-byte boundary.
// The symbol is bound with an asm label so the source lookup finds this file.

void r_FUN_001a5928(void) asm("func_001a5928");

void r_FUN_001a5928(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,8($29)\n\t"
        "sd $16,0($29)\n\t"
        "jal 0x1c70e8\n\t"
        " nop\n\t"
        "jal 0x1050d8\n\t"
        " addiu $4,$0,2560\n\t"
        "daddu $16,$2,$0\n\t"
        "jal 0x16e920\n\t"
        " addiu $4,$0,1475\n\t"
        "daddu $4,$16,$0\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "daddu $5,$2,$0\n\t"
        "addiu $6,$0,256\n\t"
        "addiu $7,$0,96\n\t"
        "j 0x1a4df0\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}
